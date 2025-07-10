// Copyright 2024 - 2025 Khalil Estell and the libhal contributors
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <algorithm>
#include <bit>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <exception>
#include <span>
#include <typeinfo>

#include "internal.hpp"

namespace ke {

union instructions_t
{
  // Why the length of 8? ARM unwind instructions are capped at 7 bytes for all
  // possible functions. The 8th instruction will always be the finish byte.
  // This allows the unwinder to iterate through the whole list without needing
  // to compare a length variable which would decrease performance.
  std::array<std::uint8_t, 8> data{
    arm_ehabi::finish, arm_ehabi::finish, arm_ehabi::finish, arm_ehabi::finish,
    arm_ehabi::finish, arm_ehabi::finish, arm_ehabi::finish, arm_ehabi::finish,
  };
};

namespace {
// TODO(#19): Make this thread local and figure out how to support is using
// emutls.
exception_ptr active_exception = nullptr;
// TODO(#42): Use the applications's polymorphic allocator, not our own space.
std::array<std::uint8_t, 256> exception_buffer{};
}  // namespace

su16_t* get_su16(void* p_ptr)
{
  return reinterpret_cast<su16_t*>(p_ptr);
}
lu_t* get_lu(void* p_ptr)
{
  return reinterpret_cast<lu_t*>(p_ptr);
}

exception_ptr current_exception() noexcept
{
  return active_exception;
}

inline void capture_cpu_core(ke::cortex_m_cpu& p_cpu_core)
{
  register std::uint32_t* res asm("r3") = &p_cpu_core.r4.data;

  // We only capture r4 to r12 because __cxa_throw & __cxa_rethrow should be
  // normal functions. Meaning they will not utilize the `sp = r[nnnn]`
  // instruction, meaning that the callee unpreserved registers can be left
  // alone.
  asm volatile("mov r0, pc\n"          // Move PC to r0 (Before pipeline)
               "stmia r3, {r4-r12}\n"  // Store r4 to r12 into the array @ &r4
               "str sp, [r3, #36]\n"   // Store SP @ 36
               "str lr, [r3, #40]\n"   // Store LR @ 40
               "str r0, [r3, #44]\n"   // Store PC @ 44
               :                       // no output
               : "r"(res)              // input is the address of the array
               : "memory", "r0");
}

struct index_less_than
{
  bool operator()(index_entry_t const& left, index_entry_t const& right)
  {
    return left.function() < right.function();
  }
  bool operator()(index_entry_t const& left, std::uint32_t right)
  {
    // De Morgan's laws to flip the < sign. Otherwise I have to cast.
    return right >= left.function();
  }
  bool operator()(std::uint32_t left, index_entry_t const& right)
  {
    return left < right.function();
  }
};

std::span<index_entry_t const> get_arm_exception_index()
{
  return { reinterpret_cast<index_entry_t const*>(&__exidx_start),
           reinterpret_cast<index_entry_t const*>(&__exidx_end) };
}

// [[gnu::used]] std::span<std::uint32_t const> get_arm_exception_table()
// {
//   return { &__extab_start, &__extab_end };
// }

index_entry_t const& get_index_entry(std::uint32_t p_program_counter)
{
  auto const index_table = get_arm_exception_index();
  auto const& index = std::upper_bound(index_table.begin(),
                                       index_table.end(),
                                       p_program_counter,
                                       index_less_than{});

  if (index == index_table.begin()) {
    return *index;
  }
  return *(index - 1);
}

[[gnu::always_inline]] inline void pop_registers(cortex_m_cpu& p_cpu,
                                                 std::uint32_t mask)
{
  // The mask may not demand that the stack pointer be popped, but the
  // stack pointer will still need to be popped anyway, so this check
  // determines if the mask handles this or not.
  std::uint32_t const* stack_pointer = *p_cpu.sp;

  while (mask) {
    auto reg_to_restore = std::countr_zero(mask);
    mask &= ~(1 << reg_to_restore);
    p_cpu[reg_to_restore] = *(stack_pointer++);
  }

  p_cpu.sp = stack_pointer;
}

[[gnu::always_inline]] inline constexpr std::uint32_t read_uleb128(
  std::uint8_t const** p_ptr)
{
  std::uint32_t result = 0;
  std::uint8_t shift_amount = 0;

  while (true) {
    std::uint8_t const uleb128 = **p_ptr;

    result |= (uleb128 & 0x7F) << shift_amount;
    (*p_ptr)++;

    if ((uleb128 == 0x80) == 0x00) {
      break;
    }

    shift_amount += 7;
  }

  return result;
}

[[gnu::always_inline]] inline constexpr std::int32_t read_sleb128(
  std::uint8_t const** p_ptr)
{
  constexpr std::uint8_t leb128_bits = 7;
  std::int32_t result = 0;
  std::uint32_t shift_amount = 0;

  // No number we deal with on the 32-bit system will or should exceed 31-bits
  // of information
  for (std::size_t i = 0; i < sizeof(std::int32_t); i++) {
    std::uint8_t const sleb128 = **p_ptr;

    result |= (sleb128 & 0x7F) << shift_amount;
    (*p_ptr)++;

    if ((sleb128 & 0x80) == 0x00) {
      auto const bytes_consumed = i + 1;
      auto const loaded_bits = bytes_consumed * leb128_bits;
      auto const ext_shift_amount = (32 - loaded_bits);
      // Shift to the left up to the signed MSB bit
      result <<= ext_shift_amount;
      // Arithmetic shift right to sign extend number
      result >>= ext_shift_amount;
      break;
    }

    shift_amount += 7;
  }

  return result;
}

template<size_t DecodedCount>
struct decoded_uleb128_t
{
  std::array<std::uint32_t, DecodedCount> data{};
  std::uint8_t const* last_read;
};

template<size_t N>
inline constexpr decoded_uleb128_t<N> multi_read_uleb128(
  std::uint8_t const* p_ptr)
{
  decoded_uleb128_t<N> result{};
  auto iter = result.data.begin();
  std::uint32_t shift_amount = 0;

  // THIS IS WRONG! ULEB is LSB first then ends on MSB. This is big endian
  while (iter != result.data.end()) {
    std::uint8_t const uleb128 = *(p_ptr++);

    *iter |= (uleb128 & 0x7F) << shift_amount;

    if ((uleb128 & 0x80) == 0x00) {
      iter++;
      shift_amount = 0;
      continue;
    }

    shift_amount += 7;
  }

  result.last_read = p_ptr;

  return result;
}

template<typename T>
T const* as(void const* p_ptr)
{
  return reinterpret_cast<T const*>(p_ptr);
}

/**
 * @brief Dwarf exception handling personality encodings
 *
 * Spec:
 * https://refspecs.linuxfoundation.org/LSB_1.3.0/gLSB/gLSB/ehframehdr.html
 */
enum class lsda_encoding : std::uint8_t
{
  absptr = 0x00,
  uleb128 = 0x01,
  udata2 = 0x02,
  udata4 = 0x03,
  udata8 = 0x04,
  sleb128 = 0x09,
  sdata2 = 0x0A,
  sdata4 = 0x0B,
  sdata8 = 0x0C,

  pcrel = 0x10,
  textrel = 0x20,
  datarel = 0x30,
  funcrel = 0x40,
  aligned = 0x50,

  // no data follows
  omit = 0xff,
};

constexpr lsda_encoding operator&(lsda_encoding const& p_encoding,
                                  std::uint8_t const& p_byte)
{
  return static_cast<lsda_encoding>(static_cast<std::uint8_t>(p_encoding) &
                                    p_byte);
}
constexpr lsda_encoding operator&(lsda_encoding const& p_encoding,
                                  lsda_encoding const& p_byte)
{
  return static_cast<lsda_encoding>(static_cast<std::uint8_t>(p_encoding) &
                                    static_cast<std::uint8_t>(p_byte));
}

template<lsda_encoding encoding>
[[gnu::always_inline]] inline std::uintptr_t read_encoded_data(
  std::uint8_t const** p_data)
{
  std::uint8_t const* ptr = *p_data;
  std::uintptr_t result = 0;

  if constexpr (encoding == lsda_encoding::omit) {
    return 0;
  }

  static constexpr auto encoding_type = encoding & 0x0F;

  if constexpr (encoding_type == lsda_encoding::absptr) {
    result = *as<uintptr_t>(ptr);
    ptr += sizeof(uintptr_t);
  }
  if constexpr (encoding_type == lsda_encoding::uleb128) {
    result = read_uleb128(&ptr);
  }
  if constexpr (encoding_type == lsda_encoding::udata2) {
    result = *as<uint16_t>(ptr);
    ptr += sizeof(uint16_t);
  }
  if constexpr (encoding_type == lsda_encoding::udata4) {
    result = *as<uint32_t>(ptr);
    ptr += sizeof(uint32_t);
  }
  if constexpr (encoding_type == lsda_encoding::sdata2) {
    result = *as<int16_t>(ptr);
    ptr += sizeof(int16_t);
  }
  if constexpr (encoding_type == lsda_encoding::sdata4) {
    result = *as<int32_t>(ptr);
    ptr += sizeof(int32_t);
  }
  if constexpr (encoding_type == lsda_encoding::sdata8) {
    result = *as<int64_t>(ptr);
    ptr += sizeof(int64_t);
  }
  if constexpr (encoding_type == lsda_encoding::udata8) {
    result = *as<uint64_t>(ptr);
    ptr += sizeof(uint64_t);
  }
  if constexpr (encoding_type == lsda_encoding::sleb128) {
    result = read_sleb128(&ptr);
  }

  // Handle indirection GCC extension
  if constexpr (static_cast<bool>(encoding & 0x80)) {
    result = *reinterpret_cast<std::uintptr_t const*>(result);
  }

  *p_data = ptr;

  return result;
}

[[gnu::always_inline]] inline std::uintptr_t read_encoded_data(
  std::uint8_t const** p_data,
  lsda_encoding p_encoding)
{
  std::uintptr_t result = 0;

  if (p_encoding == lsda_encoding::omit) {
    return 0;
  }

  auto const encoding_type = p_encoding & 0x0F;

  switch (encoding_type) {
    case lsda_encoding::absptr:
      result = read_encoded_data<lsda_encoding::absptr>(p_data);
      break;
    case lsda_encoding::uleb128:
      result = read_encoded_data<lsda_encoding::uleb128>(p_data);
      break;
    case lsda_encoding::udata2:
      result = read_encoded_data<lsda_encoding::udata2>(p_data);
      break;
    case lsda_encoding::udata4:
      result = read_encoded_data<lsda_encoding::udata4>(p_data);
      break;
    case lsda_encoding::sdata2:
      result = read_encoded_data<lsda_encoding::sdata2>(p_data);
      break;
    case lsda_encoding::sdata4:
      result = read_encoded_data<lsda_encoding::sdata4>(p_data);
      break;
    case lsda_encoding::sdata8:
      result = read_encoded_data<lsda_encoding::sdata8>(p_data);
      break;
    case lsda_encoding::udata8:
      result = read_encoded_data<lsda_encoding::udata8>(p_data);
      break;
    case lsda_encoding::sleb128:
      result = read_encoded_data<lsda_encoding::sleb128>(p_data);
      break;
    default:
      std::terminate();
      break;
  }

  // Handle indirection GCC extension
  if (static_cast<bool>(p_encoding & 0x80)) {
    result = *reinterpret_cast<std::uintptr_t const*>(result);
  }

  return result;
}

inline void restore_cpu_core(ke::cortex_m_cpu& p_cpu_core)
{
  // Skip R2 because it is not used in the exception unwinding
  // Skip R3 because we are using it
  asm volatile("ldmia.w	%[reg], {r0, r1}\n"  // R3 is incremented by 8
               "add     %[reg], #16\n"       // Skip Past R2 + R3
               "ldmia.w	%[reg], {r4, r5, r6, r7, r8, r9, r10, r11, r12}\n"
               "ldr sp, [%[reg], #36]\n"  // Load SP
               "ldr lr, [%[reg], #40]\n"  // Load LR
               "ldr pc, [%[reg], #44]\n"  // Load PC
               :
               : [reg] "r"(&p_cpu_core)
               : "memory",
                 "r0",
                 "r1",
                 "r2",
                 // skip r3 & use it as the offset register
                 "r4",
                 "r5",
                 "r6",
                 "r7",
                 "fp",
                 "r8",
                 "r9",
                 "r10",
                 "r11",
                 "r12",
                 // sp skipped here as it is deprecated
                 "lr",
                 "pc");
}

inline void skip_dwarf_info(std::uint8_t const** p_lsda)
{
  auto const* lsda = *p_lsda;
  auto const format = lsda_encoding{ *(lsda++) };
  if (format != lsda_encoding::omit) {
    // Ignore this because we don't need it for unwinding.
    read_encoded_data(&lsda, format);
  }
  *p_lsda = lsda;
}

struct lsda_header_info
{
  std::uint8_t const* call_site_end = nullptr;
  /// If this pointer is behind the call_site end, then there is no type table
  /// available.
  std::uint8_t const* type_table_end = nullptr;
  lsda_encoding type_table_encoding;
  lsda_encoding call_site_encoding;
};

inline lsda_header_info parse_header(std::uint8_t const** p_lsda)
{
  lsda_header_info info{};

  skip_dwarf_info(p_lsda);

  // Capture type table end. Will be before call_site_end if it did not exist
  auto const* lsda = *p_lsda;
  info.type_table_encoding = lsda_encoding{ *(lsda++) };
  if (info.type_table_encoding != lsda_encoding::omit) {
    auto const offset = read_uleb128(&lsda);
    info.type_table_end = lsda + offset;
  } else {
    info.type_table_end = lsda;
  }

  info.call_site_encoding = lsda_encoding{ *(lsda++) };
  auto const offset = read_uleb128(&lsda);
  info.call_site_end = lsda + offset;

  *p_lsda = lsda;

  return info;
}

inline auto const* to_lsda(exception_object& p_exception_object)
{
  return reinterpret_cast<std::uint8_t const*>(
    index_entry_t::lsda_data(p_exception_object.cache.personality));
}

inline auto calculate_relative_pc(exception_object& p_exception_object)
{
  return p_exception_object.cache.relative_address() & ~1;
}

struct call_site_info
{
  std::uint32_t landing_pad = 0;
  std::uint32_t action = 0;
  bool unwind = false;
};

template<lsda_encoding encoding>
inline call_site_info parse_call_site(std::uint8_t const** p_lsda,
                                      std::uint32_t p_rel_pc,
                                      std::uint8_t const* p_call_site_end)
{
  call_site_info info;

  do {
    auto start = read_encoded_data<encoding>(p_lsda);
    auto length = read_encoded_data<encoding>(p_lsda);
    info.landing_pad = read_encoded_data<encoding>(p_lsda);
    info.action = read_encoded_data<encoding>(p_lsda);

    if (start <= p_rel_pc && p_rel_pc <= start + length) {
      if (info.landing_pad == 0) {
        info.unwind = true;
      }
      break;
    }
  } while (*p_lsda < p_call_site_end);

  return info;
}

inline call_site_info parse_uleb128_call_site(
  std::uint8_t const* p_lsda,
  std::uint32_t p_rel_pc,
  std::uint8_t const* p_call_site_end)
{
  call_site_info info;

  do {
    auto const values = multi_read_uleb128<4>(p_lsda);
    auto const& start = values.data[0];
    auto const& length = values.data[1];
    auto const& landing_pad = values.data[2];
    auto const& action = values.data[3];
    if (start <= p_rel_pc && p_rel_pc <= start + length) {
      if (landing_pad == 0) {
        info.unwind = true;
      } else {
        info.landing_pad = landing_pad;
        info.action = action;
      }
      break;
    }
    p_lsda = values.last_read;
  } while (p_lsda < p_call_site_end);

  return info;
}

class action_decoder
{
public:
  action_decoder(std::uint8_t const* p_type_table_end,
                 std::uint8_t const* p_end_of_callsite,
                 std::uint32_t p_action)
    : m_type_table_end(p_type_table_end)
    , m_action_position(p_end_of_callsite + (p_action - 1))
  {
  }

  static std::type_info const* to_type_info(void const* p_type_info_address)
  {
    return reinterpret_cast<std::type_info const*>(
      to_absolute_address(p_type_info_address));
  }

  static std::type_info const* install_context_type()
  {
    return reinterpret_cast<std::type_info const*>(0xFFFF'FFFF);
  }

  std::type_info const* get_current_type_info_from_filter()
  {
    auto const* type_table = as<std::uintptr_t const*>(m_type_table_end);

    // We assume prel here because all other options are deprecated
    // TODO(#39): Consider using the type table encoding format for decoding
    // the type table info rather than assuming that the values here are
    // prel31_offsets
    auto const* current_type = &type_table[-m_filter];

    if (*current_type == 0x0) {
      return install_context_type();
    }

    auto const* test = to_absolute_address_ptr(current_type);
    return reinterpret_cast<std::type_info const*>(test);
  }

  std::type_info const* get_next_catch_type()
  {
    if (m_action_position == nullptr) {
      return nullptr;
    }

    do {
      m_filter = read_sleb128(&m_action_position);
      auto const previous_next_offset_position = m_action_position;
      auto const next_action_offset = read_sleb128(&m_action_position);

      if (next_action_offset == 0) {
        m_action_position = nullptr;
      } else {
        m_action_position = previous_next_offset_position + next_action_offset;
      }
      // Negative numbers are for the deprecated `throws()` specifier that we do
      // not support. We throw those away and continue looking through the
      // action table.
    } while (m_filter < 0);

    if (m_filter == 0) {
      return install_context_type();
    }

    return get_current_type_info_from_filter();
  }

  std::uint8_t filter()
  {
    return m_filter;
  }

private:
  std::uint8_t const* m_type_table_end = nullptr;
  std::uint8_t const* m_action_position = nullptr;
  std::int32_t m_filter = 0;
};

inline void enter_function(exception_object& p_exception_object)
{
  auto const* lsda = to_lsda(p_exception_object);
  auto info = parse_header(&lsda);
  auto const rel_pc = calculate_relative_pc(p_exception_object);

  call_site_info site_info{};

  switch (info.call_site_encoding) {
    case lsda_encoding::uleb128: {
      site_info = parse_uleb128_call_site(lsda, rel_pc, info.call_site_end);
      break;
    }
    case lsda_encoding::udata2: {
      site_info = parse_call_site<lsda_encoding::udata2>(
        &lsda, rel_pc, info.call_site_end);
      break;
    }
    case lsda_encoding::udata4: {
      site_info = parse_call_site<lsda_encoding::udata4>(
        &lsda, rel_pc, info.call_site_end);
      break;
    }
    case lsda_encoding::udata8: {
      site_info = parse_call_site<lsda_encoding::udata8>(
        &lsda, rel_pc, info.call_site_end);
      break;
    }
    case lsda_encoding::sdata2: {
      site_info = parse_call_site<lsda_encoding::sdata2>(
        &lsda, rel_pc, info.call_site_end);
      break;
    }
    case lsda_encoding::sdata4: {
      site_info = parse_call_site<lsda_encoding::sdata4>(
        &lsda, rel_pc, info.call_site_end);
      break;
    }
    case lsda_encoding::sdata8: {
      site_info = parse_call_site<lsda_encoding::sdata8>(
        &lsda, rel_pc, info.call_site_end);
      break;
    }
    case lsda_encoding::sleb128: {
      site_info = parse_call_site<lsda_encoding::sleb128>(
        &lsda, rel_pc, info.call_site_end);
      break;
    }
    default: {
      std::terminate();
    }
  }

  if (site_info.unwind) {
    p_exception_object.cache.state(runtime_state::unwind_frame);
    return;
  }

  auto& cpu = p_exception_object.cpu;
  auto* entry_ptr = p_exception_object.cache.entry_ptr;

  // This occurs when a frame has destructors that need cleaning up but no
  // try/catch blocks resulting in there being no action table or type table. In
  // such a case, then the scope found should be entered immediately!
  if (info.type_table_end < info.call_site_end) {
    // LSB must be set to 1 to jump to an address
    auto const final_destination =
      (entry_ptr->function() + site_info.landing_pad) | 0b1;

    // Set PC to the cleanup destination
    cpu.pc = final_destination;

    // Install CPU state
    restore_cpu_core(cpu);
  }

  action_decoder a_decoder(
    info.type_table_end, info.call_site_end, site_info.action);

  for (auto const* type_info = a_decoder.get_next_catch_type();
       type_info != nullptr;
       type_info = a_decoder.get_next_catch_type()) {

    // This is our dynamic cast :P
    auto position = std::find_if(p_exception_object.type_info.begin(),
                                 p_exception_object.type_info.end(),
                                 [&type_info](auto const& element) -> bool {
                                   return element.type_info == type_info;
                                 });

    if (position == p_exception_object.type_info.end() &&
        type_info != action_decoder::install_context_type()) {
      continue;
    }

    p_exception_object.choosen_type_offset = position->offset;
    // ====== Prepare to Install context!! =====
    cpu[0] = &p_exception_object;
    cpu[1] = a_decoder.filter();

    // LSB must be set to 1 to jump to an address
    auto const final_destination =
      (entry_ptr->function() + site_info.landing_pad) | 0b1;

    // Set PC to the cleanup destination
    cpu.pc = final_destination;

    // Install CPU state
    restore_cpu_core(cpu);
  }
}

template<size_t Amount>
constexpr std::uint32_t vsp_deallocate_amount()
{
  return Amount + 1;
}

enum class pop_lr
{
  skip = 0,
  do_it = 1,
};

template<size_t PopCount, pop_lr PopLinkRegister = pop_lr::skip>
[[nodiscard("You MUST set the unwind function's stack pointer to this "
            "value after executing it!")]]
inline std::uint32_t const* pop_register_range(std::uint32_t const* sp_ptr,
                                               cortex_m_cpu& p_cpu)
{
  // We pull these pointers out in order to access them incrementally, which
  // will give the hint to the compiler to convert them into a sequence of
  // immediate load and stores.
  auto* r4_pointer = &p_cpu.r4.data;

  static_assert(PopCount <= 7, "Pop Count cannot be above 7");

  // NOTE: A for loop has the same cycle count, and is more compact

  if constexpr (PopCount == 0) {
    *r4_pointer = *sp_ptr;
  } else {
    for (std::size_t i = 0; i < PopCount + 1; i++) {
      r4_pointer[i] = sp_ptr[i];
    }
  }

  if constexpr (PopLinkRegister == pop_lr::do_it) {
    p_cpu.lr = sp_ptr[PopCount + 1];
  }

  return sp_ptr + PopCount + 1 + unsigned{ PopLinkRegister == pop_lr::do_it };
}

void unwind_frame(instructions_t const& p_instructions, cortex_m_cpu& p_cpu)
{
  static constexpr std::array<void*, 256> jump_table{
    &&vsp_add_0,   // [0]
    &&vsp_add_1,   // [1]
    &&vsp_add_2,   // [2]
    &&vsp_add_3,   // [3]
    &&vsp_add_4,   // [4]
    &&vsp_add_5,   // [5]
    &&vsp_add_6,   // [6]
    &&vsp_add_7,   // [7]
    &&vsp_add_8,   // [8]
    &&vsp_add_9,   // [9]
    &&vsp_add_10,  // [10]
    &&vsp_add_11,  // [11]
    &&vsp_add_12,  // [12]
    &&vsp_add_13,  // [13]
    &&vsp_add_14,  // [14]
    &&vsp_add_15,  // [15]
    &&vsp_add_16,  // [16]
    &&vsp_add_17,  // [17]
    &&vsp_add_18,  // [18]
    &&vsp_add_19,  // [19]
    &&vsp_add_20,  // [20]
    &&vsp_add_21,  // [21]
    &&vsp_add_22,  // [22]
    &&vsp_add_23,  // [23]
    &&vsp_add_24,  // [24]
    &&vsp_add_25,  // [25]
    &&vsp_add_26,  // [26]
    &&vsp_add_27,  // [27]
    &&vsp_add_28,  // [28]
    &&vsp_add_29,  // [29]
    &&vsp_add_30,  // [30]
    &&vsp_add_31,  // [31]
    &&vsp_add_32,  // [32]
    &&vsp_add_33,  // [33]
    &&vsp_add_34,  // [34]
    &&vsp_add_35,  // [35]
    &&vsp_add_36,  // [36]
    &&vsp_add_37,  // [37]
    &&vsp_add_38,  // [38]
    &&vsp_add_39,  // [39]
    &&vsp_add_40,  // [40]
    &&vsp_add_41,  // [41]
    &&vsp_add_42,  // [42]
    &&vsp_add_43,  // [43]
    &&vsp_add_44,  // [44]
    &&vsp_add_45,  // [45]
    &&vsp_add_46,  // [46]
    &&vsp_add_47,  // [47]
    &&vsp_add_48,  // [48]
    &&vsp_add_49,  // [49]
    &&vsp_add_50,  // [50]
    &&vsp_add_51,  // [51]
    &&vsp_add_52,  // [52]
    &&vsp_add_53,  // [53]
    &&vsp_add_54,  // [54]
    &&vsp_add_55,  // [55]
    &&vsp_add_56,  // [56]
    &&vsp_add_57,  // [57]
    &&vsp_add_58,  // [58]
    &&vsp_add_59,  // [59]
    &&vsp_add_60,  // [60]
    &&vsp_add_61,  // [61]
    &&vsp_add_62,  // [62]
    &&vsp_add_63,  // [63]

    &&vsp_sub_0,   // [64]
    &&vsp_sub_1,   // [65]
    &&vsp_sub_2,   // [66]
    &&vsp_sub_3,   // [67]
    &&vsp_sub_4,   // [68]
    &&vsp_sub_5,   // [69]
    &&vsp_sub_6,   // [70]
    &&vsp_sub_7,   // [71]
    &&vsp_sub_8,   // [72]
    &&vsp_sub_9,   // [73]
    &&vsp_sub_10,  // [74]
    &&vsp_sub_11,  // [75]
    &&vsp_sub_12,  // [76]
    &&vsp_sub_13,  // [77]
    &&vsp_sub_14,  // [78]
    &&vsp_sub_15,  // [79]
    &&vsp_sub_16,  // [80]
    &&vsp_sub_17,  // [81]
    &&vsp_sub_18,  // [82]
    &&vsp_sub_19,  // [83]
    &&vsp_sub_20,  // [84]
    &&vsp_sub_21,  // [85]
    &&vsp_sub_22,  // [86]
    &&vsp_sub_23,  // [87]
    &&vsp_sub_24,  // [88]
    &&vsp_sub_25,  // [89]
    &&vsp_sub_26,  // [90]
    &&vsp_sub_27,  // [91]
    &&vsp_sub_28,  // [92]
    &&vsp_sub_29,  // [93]
    &&vsp_sub_30,  // [94]
    &&vsp_sub_31,  // [95]
    &&vsp_sub_32,  // [96]
    &&vsp_sub_33,  // [97]
    &&vsp_sub_34,  // [98]
    &&vsp_sub_35,  // [99]
    &&vsp_sub_36,  // [100]
    &&vsp_sub_37,  // [101]
    &&vsp_sub_38,  // [102]
    &&vsp_sub_39,  // [103]
    &&vsp_sub_40,  // [104]
    &&vsp_sub_41,  // [105]
    &&vsp_sub_42,  // [106]
    &&vsp_sub_43,  // [107]
    &&vsp_sub_44,  // [108]
    &&vsp_sub_45,  // [109]
    &&vsp_sub_46,  // [110]
    &&vsp_sub_47,  // [111]
    &&vsp_sub_48,  // [112]
    &&vsp_sub_49,  // [113]
    &&vsp_sub_50,  // [114]
    &&vsp_sub_51,  // [115]
    &&vsp_sub_52,  // [116]
    &&vsp_sub_53,  // [117]
    &&vsp_sub_54,  // [118]
    &&vsp_sub_55,  // [119]
    &&vsp_sub_56,  // [120]
    &&vsp_sub_57,  // [121]
    &&vsp_sub_58,  // [122]
    &&vsp_sub_59,  // [123]
    &&vsp_sub_60,  // [124]
    &&vsp_sub_61,  // [125]
    &&vsp_sub_62,  // [126]
    &&vsp_sub_63,  // [127]

    // 10000000
    &&refuse_unwind_or_pop,  // [0b1000'0000 = 128]

    // 1000iiii ...
    &&pop_under_mask,  // [0b1000'0001 = 129]
    &&pop_under_mask,  // [0b1000'0010 = 130]
    &&pop_under_mask,  // [0b1000'0011 = 131]
    &&pop_under_mask,  // [0b1000'0100 = 132]
    &&pop_under_mask,  // [0b1000'0101 = 133]
    &&pop_under_mask,  // [0b1000'0110 = 134]
    &&pop_under_mask,  // [0b1000'0111 = 135]
    &&pop_under_mask,  // [0b1000'1000 = 136]
    &&pop_under_mask,  // [0b1000'1001 = 137]
    &&pop_under_mask,  // [0b1000'1010 = 138]
    &&pop_under_mask,  // [0b1000'1011 = 139]
    &&pop_under_mask,  // [0b1000'1100 = 140]
    &&pop_under_mask,  // [0b1000'1101 = 141]
    &&pop_under_mask,  // [0b1000'1110 = 142]
    &&pop_under_mask,  // [0b1000'1111 = 143] (128 + 15)

    // 1001nnnn
    // NOTE: Consider split up assignments to make them faster. We can remove
    // the need to actually compute the register and then assign it to vsp when
    // the register number is encoded in the instruction. This would add more
    // space cost though. It is an option. But this particular instruction
    // should be very rare and typically never used in almost any code so making
    // this faster is not a priority. Only do this if there is a client need for
    // such a feature.
    &&assign_to_vsp_to_reg_nnnn,  // [0b1001'0000 = 144]
    &&assign_to_vsp_to_reg_nnnn,  // [0b1001'0001 = 145]
    &&assign_to_vsp_to_reg_nnnn,  // [0b1001'0010 = 146]
    &&assign_to_vsp_to_reg_nnnn,  // [0b1001'0011 = 147]
    &&assign_to_vsp_to_reg_nnnn,  // [0b1001'0100 = 148]
    &&assign_to_vsp_to_reg_nnnn,  // [0b1001'0101 = 149]
    &&assign_to_vsp_to_reg_nnnn,  // [0b1001'0110 = 150]
    &&assign_to_vsp_to_reg_nnnn,  // [0b1001'0111 = 151]
    &&assign_to_vsp_to_reg_nnnn,  // [0b1001'1000 = 152]
    &&assign_to_vsp_to_reg_nnnn,  // [0b1001'1001 = 153]
    &&assign_to_vsp_to_reg_nnnn,  // [0b1001'1010 = 154]
    &&assign_to_vsp_to_reg_nnnn,  // [0b1001'1011 = 155]
    &&assign_to_vsp_to_reg_nnnn,  // [0b1001'1100 = 156]
    // Reserved as prefix for Arm register to register moves
    &&reserved_or_spare_thus_terminate,  // [0b1001'1101 = 157]
    // Reserved as prefix for Intel Wireless MMX register to register moves
    &&assign_to_vsp_to_reg_nnnn,         // [0b1001'1110 = 158]
    &&reserved_or_spare_thus_terminate,  // [0b1001'1111 = 159 reg 15 reserved]

    // 10100nnn
    &&pop_off_stack_r4_to_r4,   // 0b10100'000 [160]
    &&pop_off_stack_r4_to_r5,   // 0b10100'001 [161]
    &&pop_off_stack_r4_to_r6,   // 0b10100'010 [162]
    &&pop_off_stack_r4_to_r7,   // 0b10100'011 [163]
    &&pop_off_stack_r4_to_r8,   // 0b10100'100 [164]
    &&pop_off_stack_r4_to_r9,   // 0b10100'101 [165]
    &&pop_off_stack_r4_to_r10,  // 0b10100'110 [166]
    &&pop_off_stack_r4_to_r11,  // 0b10100'111 [167]

    // 10101nnn
    &&pop_off_stack_r4_to_r4_and_lr,   // 0b10101'000 [168]
    &&pop_off_stack_r4_to_r5_and_lr,   // 0b10101'001 [169]
    &&pop_off_stack_r4_to_r6_and_lr,   // 0b10101'010 [170]
    &&pop_off_stack_r4_to_r7_and_lr,   // 0b10101'011 [171]
    &&pop_off_stack_r4_to_r8_and_lr,   // 0b10101'100 [172]
    &&pop_off_stack_r4_to_r9_and_lr,   // 0b10101'101 [173]
    &&pop_off_stack_r4_to_r10_and_lr,  // 0b10101'110 [174]
    &&pop_off_stack_r4_to_r11_and_lr,  // 0b10101'111 [175]

    // Finish (0xB0)
    &&finish_unwind,  // 10110000 [176]

    // Spare (refuse unwind)
    &&pop_integer_registers_under_mask_r3_r2_r1_r0,  // 10110001 [177]

    // Subtract VSP using uleb128
    &&subtract_vsp_using_uleb128,  // 10110010 [178]

    // Pop VFP double-precision registers
    // TODO(#27): Add support for this
    &&reserved_or_spare_thus_terminate,  // 10110011 [179]

    // Pop Return Address Authentication Code pseudo-register
    // TODO(#28): Add support for this
    &&reserved_or_spare_thus_terminate,  // 10110100 [180]

    // Use current vsp as modifier in Return Address Authentication
    // TODO(#29): Add support for this
    &&reserved_or_spare_thus_terminate,  // 10110101 [181]

    // Spare (was Pop FPA) 1011011n
    &&reserved_or_spare_thus_terminate,  // 10110110 [182]
    &&reserved_or_spare_thus_terminate,  // 10110111 [183]

    // Pop VFP double-precision registers D[8]-D[8+nnn] saved 10111nnn
    // TODO(#30): Add support for this
    &&reserved_or_spare_thus_terminate,  // 10111'000 [184]
    &&reserved_or_spare_thus_terminate,  // 10111'001 [185]
    &&reserved_or_spare_thus_terminate,  // 10111'010 [186]
    &&reserved_or_spare_thus_terminate,  // 10111'011 [187]
    &&reserved_or_spare_thus_terminate,  // 10111'100 [188]
    &&reserved_or_spare_thus_terminate,  // 10111'101 [189]
    &&reserved_or_spare_thus_terminate,  // 10111'110 [190]
    &&reserved_or_spare_thus_terminate,  // 10111'111 [191]

    // Intel Wireless MMX pop wR[10]-wR[10+nnn] 11000nnn
    // NOTE: We will probably never support these. No modern ARM device is still
    // using the Intel MMX registers. We will only consider adding support for
    // this if a user/client/developer specifically requests it and has a dire
    // need for it.
    &&reserved_or_spare_thus_terminate,  // 11000'000 [192]
    &&reserved_or_spare_thus_terminate,  // 11000'001 [193]
    &&reserved_or_spare_thus_terminate,  // 11000'010 [194]
    &&reserved_or_spare_thus_terminate,  // 11000'011 [195]
    &&reserved_or_spare_thus_terminate,  // 11000'100 [196]
    &&reserved_or_spare_thus_terminate,  // 11000'101 [197]

    // Intel Wireless MMX pop wR[ssss]-wR[ssss+cccc]
    // See NOTE in above section...
    &&reserved_or_spare_thus_terminate,  // 11000'110 [198]

    // Spare (11000111)
    &&reserved_or_spare_thus_terminate,  // 11000'111 [199]

    // Pop VFP double precision registers D[ssss]-D[ssss+cccc] saved (as if) by
    // VPUSH (11001000)
    // TODO(#31): Add support for this
    &&reserved_or_spare_thus_terminate,  // 11001000 [200]

    // Pop VFP double precision registers D[ssss]-D[ssss+cccc] saved (as if) by
    // VPUSH (11001001)
    // TODO(#32): Add support for this
    &&reserved_or_spare_thus_terminate,  // 11001001 [201]

    // Spare (yyy != 000, 001) 11001yyy
    &&reserved_or_spare_thus_terminate,  // 11001'010 [202]
    &&reserved_or_spare_thus_terminate,  // 11001'011 [203]
    &&reserved_or_spare_thus_terminate,  // 11001'100 [204]
    &&reserved_or_spare_thus_terminate,  // 11001'101 [205]
    &&reserved_or_spare_thus_terminate,  // 11001'110 [206]
    &&reserved_or_spare_thus_terminate,  // 11001'111 [207]

    // Pop VFP double-precision registers D[8]-D[8+nnn] saved by VPUSH 11010nnn
    // TODO(#33): Add support for this
    &&reserved_or_spare_thus_terminate,  // 11010'000 [208]
    &&reserved_or_spare_thus_terminate,  // 11010'001 [209]
    &&reserved_or_spare_thus_terminate,  // 11010'010 [210]
    &&reserved_or_spare_thus_terminate,  // 11010'011 [211]
    &&reserved_or_spare_thus_terminate,  // 11010'100 [212]
    &&reserved_or_spare_thus_terminate,  // 11010'101 [213]
    &&reserved_or_spare_thus_terminate,  // 11010'110 [214]
    &&reserved_or_spare_thus_terminate,  // 11010'111 [215]

    // Spare (xxx != 000, 001, 010) 11xxxyyy

    &&reserved_or_spare_thus_terminate,  // 11011'000 [216]
    &&reserved_or_spare_thus_terminate,  // 11011'001 []
    &&reserved_or_spare_thus_terminate,  // 11011'010 []
    &&reserved_or_spare_thus_terminate,  // 11011'011 []
    &&reserved_or_spare_thus_terminate,  // 11011'100 []
    &&reserved_or_spare_thus_terminate,  // 11011'101 []
    &&reserved_or_spare_thus_terminate,  // 11011'110 []
    &&reserved_or_spare_thus_terminate,  // 11011'111 []
    &&reserved_or_spare_thus_terminate,  // 11011'000 []
    &&reserved_or_spare_thus_terminate,  // 11011'001 []
    &&reserved_or_spare_thus_terminate,  // 11011'010 []
    &&reserved_or_spare_thus_terminate,  // 11011'011 []
    &&reserved_or_spare_thus_terminate,  // 11011'100 []
    &&reserved_or_spare_thus_terminate,  // 11011'101 []
    &&reserved_or_spare_thus_terminate,  // 11011'110 []
    &&reserved_or_spare_thus_terminate,  // 11011'111 [231]
    &&reserved_or_spare_thus_terminate,  // 11011'000 []
    &&reserved_or_spare_thus_terminate,  // 11011'001 []
    &&reserved_or_spare_thus_terminate,  // 11011'010 []
    &&reserved_or_spare_thus_terminate,  // 11011'011 []
    &&reserved_or_spare_thus_terminate,  // 11011'100 []
    &&reserved_or_spare_thus_terminate,  // 11011'101 []
    &&reserved_or_spare_thus_terminate,  // 11011'110 []
    &&reserved_or_spare_thus_terminate,  // 11011'111 []
    &&reserved_or_spare_thus_terminate,  // 11011'000 []
    &&reserved_or_spare_thus_terminate,  // 11011'001 []
    &&reserved_or_spare_thus_terminate,  // 11011'010 []
    &&reserved_or_spare_thus_terminate,  // 11011'011 []
    &&reserved_or_spare_thus_terminate,  // 11011'100 []
    &&reserved_or_spare_thus_terminate,  // 11011'101 []
    &&reserved_or_spare_thus_terminate,  // 11011'110 []
    &&reserved_or_spare_thus_terminate,  // 11011'111 [247]

    &&reserved_or_spare_thus_terminate,  // 11011'000 [248]
    &&reserved_or_spare_thus_terminate,  // 11011'001 []
    &&reserved_or_spare_thus_terminate,  // 11011'010 []
    &&reserved_or_spare_thus_terminate,  // 11011'011 []
    &&reserved_or_spare_thus_terminate,  // 11011'100 []
    &&reserved_or_spare_thus_terminate,  // 11011'101 []
    &&reserved_or_spare_thus_terminate,  // 11011'110 []
    &&reserved_or_spare_thus_terminate,  // 11111'111 [255]
  };

  bool move_lr_to_pc = true;
  std::uint32_t u32_storage = 0;
  auto const* instruction_ptr = p_instructions.data.data();
  auto const* sp_ptr = *p_cpu.sp;

  while (true) {
    auto const* instruction_handler = jump_table[*instruction_ptr];
    instruction_ptr++;
    goto* instruction_handler;

  // +=========================================================================+
  // |                                 Finish!                                 |
  // +=========================================================================+
  finish_unwind:
    p_cpu.sp = sp_ptr;
    [[likely]] if (move_lr_to_pc) {
      p_cpu.pc = p_cpu.lr;
    }
    break;

  reserved_or_spare_thus_terminate:
    std::terminate();
    break;

  subtract_vsp_using_uleb128:
    static constexpr auto uleb128_offset = 0x204 / sizeof(std::uint32_t);
    sp_ptr += read_uleb128(&instruction_ptr) + uleb128_offset;
    continue;

  pop_integer_registers_under_mask_r3_r2_r1_r0:
    // If the next unwind instruction equals 0, or if the bits from 4 or 7
    // contains any 1s, then its time to terminate
    if (*instruction_ptr == 0b0000'0000 || (*instruction_ptr & 0xF0) != 0) {
      goto reserved_or_spare_thus_terminate;
    }

    u32_storage = *instruction_ptr;

    while (u32_storage) {
      // The first bit corresponds to the R0
      std::uint32_t lsb_bit_position = std::countr_zero(u32_storage);
      // Copy value from the stack, increment stack pointer.
      p_cpu[lsb_bit_position] = *(sp_ptr++);
      // Clear the bit for the lsb_bit_position
      u32_storage = u32_storage & ~(1 << lsb_bit_position);
    }
    instruction_ptr++;
    continue;

  refuse_unwind_or_pop:
    // If the next unwind instruction equals 0, then its time to terminate
    if (*instruction_ptr == 0b0000'0000) {
      goto reserved_or_spare_thus_terminate;
    }

    // *************************************************************************
    //                            !!!! WARNING !!!!
    //
    //     `refuse_unwind_or_pop` MUST BE directly above `pop_under_mask`
    //
    //      refuse_unwind_or_pop ---> [[fallthrough]] --> pop_under_mask
    // *************************************************************************

  pop_under_mask:
    // Because this unwind instruction is meant to be rare, we will use a while
    // loop here rather than unroll this loop. Unless there is some incentive to
    // improve the performance for this instruction.

    // Save the lower 4-bits of the previous instruction and the 8-bits of the
    // current instruction and combine them.
    u32_storage = *(instruction_ptr - 1) & 0xF;
    u32_storage <<= 8;
    u32_storage |= *(instruction_ptr);

    if (u32_storage & (1 << 3)) {
      move_lr_to_pc = false;
    }

    // TODO(#40): consider (remark b)
    // ========================================================================
    // > ‘Pop’ generally denotes removal from the stack commencing at current
    // > vsp, with subsequent increment of vsp to beyond the removed quantities.
    // > The sole exception to this rule is popping r13, when the writeback of
    // > the loaded value to vsp is delayed until after the whole instruction
    // > has completed. When multiple registers are popped by a single
    // > instruction they are taken as lowest numbered register at lowest stack
    // > address.
    // =========================================================================

    while (u32_storage) {
      // Get the first 1's distance from the right. We add 12 because the
      // mask's first bit represents r4 and increases from there. The first
      // byte, the instruction byte, only contains the registers from 12
      // to 15.
      std::uint32_t lsb_bit_position = std::countr_zero(u32_storage);
      // Clear the bit for the lsb_bit_position
      u32_storage = u32_storage & ~(1 << lsb_bit_position);
      // Copy value from the stack, increment stack pointer.
      p_cpu[lsb_bit_position + 4U] = *(sp_ptr++);
    }

    instruction_ptr++;
    continue;

  // +=========================================================================+
  // |                            VSP = R[nnnn]                                |
  // +=========================================================================+
  assign_to_vsp_to_reg_nnnn:
    // Get the current instruction and get all lower 4-bits
    u32_storage = *(instruction_ptr - 1U) & 0xF;
    sp_ptr = *p_cpu[u32_storage];
    continue;

  // +=========================================================================+
  // |                     Sequentially Pop Registers + LR                     |
  // +=========================================================================+
  pop_off_stack_r4_to_r11_and_lr:
    sp_ptr = pop_register_range<7, pop_lr::do_it>(sp_ptr, p_cpu);
    continue;
  pop_off_stack_r4_to_r10_and_lr:
    sp_ptr = pop_register_range<6, pop_lr::do_it>(sp_ptr, p_cpu);
    continue;
  pop_off_stack_r4_to_r9_and_lr:
    sp_ptr = pop_register_range<5, pop_lr::do_it>(sp_ptr, p_cpu);
    continue;
  pop_off_stack_r4_to_r8_and_lr:
    sp_ptr = pop_register_range<4, pop_lr::do_it>(sp_ptr, p_cpu);
    continue;
  pop_off_stack_r4_to_r7_and_lr:
    sp_ptr = pop_register_range<3, pop_lr::do_it>(sp_ptr, p_cpu);
    continue;
  pop_off_stack_r4_to_r6_and_lr:
    sp_ptr = pop_register_range<2, pop_lr::do_it>(sp_ptr, p_cpu);
    continue;
  pop_off_stack_r4_to_r5_and_lr:
    sp_ptr = pop_register_range<1, pop_lr::do_it>(sp_ptr, p_cpu);
    continue;
  pop_off_stack_r4_to_r4_and_lr:
    sp_ptr = pop_register_range<0, pop_lr::do_it>(sp_ptr, p_cpu);
    continue;

  // +=========================================================================+
  // |                      Sequentially Pop Registers                         |
  // +=========================================================================+
  pop_off_stack_r4_to_r11:
    sp_ptr = pop_register_range<7>(sp_ptr, p_cpu);
    continue;
  pop_off_stack_r4_to_r10:
    sp_ptr = pop_register_range<6>(sp_ptr, p_cpu);
    continue;
  pop_off_stack_r4_to_r9:
    sp_ptr = pop_register_range<5>(sp_ptr, p_cpu);
    continue;
  pop_off_stack_r4_to_r8:
    sp_ptr = pop_register_range<4>(sp_ptr, p_cpu);
    continue;
  pop_off_stack_r4_to_r7:
    sp_ptr = pop_register_range<3>(sp_ptr, p_cpu);
    continue;
  pop_off_stack_r4_to_r6:
    sp_ptr = pop_register_range<2>(sp_ptr, p_cpu);
    continue;
  pop_off_stack_r4_to_r5:
    sp_ptr = pop_register_range<1>(sp_ptr, p_cpu);
    continue;
  pop_off_stack_r4_to_r4:
    sp_ptr = pop_register_range<0>(sp_ptr, p_cpu);
    continue;

  // +=========================================================================+
  // |                                Add VSP                                  |
  // +=========================================================================+
  vsp_add_0:
    sp_ptr = sp_ptr + vsp_deallocate_amount<0>();
    continue;
  vsp_add_1:
    sp_ptr = sp_ptr + vsp_deallocate_amount<1>();
    continue;
  vsp_add_2:
    sp_ptr = sp_ptr + vsp_deallocate_amount<2>();
    continue;
  vsp_add_3:
    sp_ptr = sp_ptr + vsp_deallocate_amount<3>();
    continue;
  vsp_add_4:
    sp_ptr = sp_ptr + vsp_deallocate_amount<4>();
    continue;
  vsp_add_5:
    sp_ptr = sp_ptr + vsp_deallocate_amount<5>();
    continue;
  vsp_add_6:
    sp_ptr = sp_ptr + vsp_deallocate_amount<6>();
    continue;
  vsp_add_7:
    sp_ptr = sp_ptr + vsp_deallocate_amount<7>();
    continue;
  vsp_add_8:
    sp_ptr = sp_ptr + vsp_deallocate_amount<8>();
    continue;
  vsp_add_9:
    sp_ptr = sp_ptr + vsp_deallocate_amount<9>();
    continue;
  vsp_add_10:
    sp_ptr = sp_ptr + vsp_deallocate_amount<10>();
    continue;
  vsp_add_11:
    sp_ptr = sp_ptr + vsp_deallocate_amount<11>();
    continue;
  vsp_add_12:
    sp_ptr = sp_ptr + vsp_deallocate_amount<12>();
    continue;
  vsp_add_13:
    sp_ptr = sp_ptr + vsp_deallocate_amount<13>();
    continue;
  vsp_add_14:
    sp_ptr = sp_ptr + vsp_deallocate_amount<14>();
    continue;
  vsp_add_15:
    sp_ptr = sp_ptr + vsp_deallocate_amount<15>();
    continue;
  vsp_add_16:
    sp_ptr = sp_ptr + vsp_deallocate_amount<16>();
    continue;
  vsp_add_17:
    sp_ptr = sp_ptr + vsp_deallocate_amount<17>();
    continue;
  vsp_add_18:
    sp_ptr = sp_ptr + vsp_deallocate_amount<18>();
    continue;
  vsp_add_19:
    sp_ptr = sp_ptr + vsp_deallocate_amount<19>();
    continue;
  vsp_add_20:
    sp_ptr = sp_ptr + vsp_deallocate_amount<20>();
    continue;
  vsp_add_21:
    sp_ptr = sp_ptr + vsp_deallocate_amount<21>();
    continue;
  vsp_add_22:
    sp_ptr = sp_ptr + vsp_deallocate_amount<22>();
    continue;
  vsp_add_23:
    sp_ptr = sp_ptr + vsp_deallocate_amount<23>();
    continue;
  vsp_add_24:
    sp_ptr = sp_ptr + vsp_deallocate_amount<24>();
    continue;
  vsp_add_25:
    sp_ptr = sp_ptr + vsp_deallocate_amount<25>();
    continue;
  vsp_add_26:
    sp_ptr = sp_ptr + vsp_deallocate_amount<26>();
    continue;
  vsp_add_27:
    sp_ptr = sp_ptr + vsp_deallocate_amount<27>();
    continue;
  vsp_add_28:
    sp_ptr = sp_ptr + vsp_deallocate_amount<28>();
    continue;
  vsp_add_29:
    sp_ptr = sp_ptr + vsp_deallocate_amount<29>();
    continue;
  vsp_add_30:
    sp_ptr = sp_ptr + vsp_deallocate_amount<30>();
    continue;
  vsp_add_31:
    sp_ptr = sp_ptr + vsp_deallocate_amount<31>();
    continue;
  vsp_add_32:
    sp_ptr = sp_ptr + vsp_deallocate_amount<32>();
    continue;
  vsp_add_33:
    sp_ptr = sp_ptr + vsp_deallocate_amount<33>();
    continue;
  vsp_add_34:
    sp_ptr = sp_ptr + vsp_deallocate_amount<34>();
    continue;
  vsp_add_35:
    sp_ptr = sp_ptr + vsp_deallocate_amount<35>();
    continue;
  vsp_add_36:
    sp_ptr = sp_ptr + vsp_deallocate_amount<36>();
    continue;
  vsp_add_37:
    sp_ptr = sp_ptr + vsp_deallocate_amount<37>();
    continue;
  vsp_add_38:
    sp_ptr = sp_ptr + vsp_deallocate_amount<38>();
    continue;
  vsp_add_39:
    sp_ptr = sp_ptr + vsp_deallocate_amount<39>();
    continue;
  vsp_add_40:
    sp_ptr = sp_ptr + vsp_deallocate_amount<40>();
    continue;
  vsp_add_41:
    sp_ptr = sp_ptr + vsp_deallocate_amount<41>();
    continue;
  vsp_add_42:
    sp_ptr = sp_ptr + vsp_deallocate_amount<42>();
    continue;
  vsp_add_43:
    sp_ptr = sp_ptr + vsp_deallocate_amount<43>();
    continue;
  vsp_add_44:
    sp_ptr = sp_ptr + vsp_deallocate_amount<44>();
    continue;
  vsp_add_45:
    sp_ptr = sp_ptr + vsp_deallocate_amount<45>();
    continue;
  vsp_add_46:
    sp_ptr = sp_ptr + vsp_deallocate_amount<46>();
    continue;
  vsp_add_47:
    sp_ptr = sp_ptr + vsp_deallocate_amount<47>();
    continue;
  vsp_add_48:
    sp_ptr = sp_ptr + vsp_deallocate_amount<48>();
    continue;
  vsp_add_49:
    sp_ptr = sp_ptr + vsp_deallocate_amount<49>();
    continue;
  vsp_add_50:
    sp_ptr = sp_ptr + vsp_deallocate_amount<50>();
    continue;
  vsp_add_51:
    sp_ptr = sp_ptr + vsp_deallocate_amount<51>();
    continue;
  vsp_add_52:
    sp_ptr = sp_ptr + vsp_deallocate_amount<52>();
    continue;
  vsp_add_53:
    sp_ptr = sp_ptr + vsp_deallocate_amount<53>();
    continue;
  vsp_add_54:
    sp_ptr = sp_ptr + vsp_deallocate_amount<54>();
    continue;
  vsp_add_55:
    sp_ptr = sp_ptr + vsp_deallocate_amount<55>();
    continue;
  vsp_add_56:
    sp_ptr = sp_ptr + vsp_deallocate_amount<56>();
    continue;
  vsp_add_57:
    sp_ptr = sp_ptr + vsp_deallocate_amount<57>();
    continue;
  vsp_add_58:
    sp_ptr = sp_ptr + vsp_deallocate_amount<58>();
    continue;
  vsp_add_59:
    sp_ptr = sp_ptr + vsp_deallocate_amount<59>();
    continue;
  vsp_add_60:
    sp_ptr = sp_ptr + vsp_deallocate_amount<60>();
    continue;
  vsp_add_61:
    sp_ptr = sp_ptr + vsp_deallocate_amount<61>();
    continue;
  vsp_add_62:
    sp_ptr = sp_ptr + vsp_deallocate_amount<62>();
    continue;
  vsp_add_63:
    sp_ptr = sp_ptr + vsp_deallocate_amount<63>();
    continue;

  // +=========================================================================+
  // |                                Sub VSP                                  |
  // +=========================================================================+
  vsp_sub_0:
    sp_ptr = sp_ptr + vsp_deallocate_amount<0>();
    continue;
  vsp_sub_1:
    sp_ptr = sp_ptr + vsp_deallocate_amount<1>();
    continue;
  vsp_sub_2:
    sp_ptr = sp_ptr + vsp_deallocate_amount<2>();
    continue;
  vsp_sub_3:
    sp_ptr = sp_ptr + vsp_deallocate_amount<3>();
    continue;
  vsp_sub_4:
    sp_ptr = sp_ptr + vsp_deallocate_amount<4>();
    continue;
  vsp_sub_5:
    sp_ptr = sp_ptr + vsp_deallocate_amount<5>();
    continue;
  vsp_sub_6:
    sp_ptr = sp_ptr + vsp_deallocate_amount<6>();
    continue;
  vsp_sub_7:
    sp_ptr = sp_ptr + vsp_deallocate_amount<7>();
    continue;
  vsp_sub_8:
    sp_ptr = sp_ptr + vsp_deallocate_amount<8>();
    continue;
  vsp_sub_9:
    sp_ptr = sp_ptr + vsp_deallocate_amount<9>();
    continue;
  vsp_sub_10:
    sp_ptr = sp_ptr + vsp_deallocate_amount<10>();
    continue;
  vsp_sub_11:
    sp_ptr = sp_ptr + vsp_deallocate_amount<11>();
    continue;
  vsp_sub_12:
    sp_ptr = sp_ptr + vsp_deallocate_amount<12>();
    continue;
  vsp_sub_13:
    sp_ptr = sp_ptr + vsp_deallocate_amount<13>();
    continue;
  vsp_sub_14:
    sp_ptr = sp_ptr + vsp_deallocate_amount<14>();
    continue;
  vsp_sub_15:
    sp_ptr = sp_ptr + vsp_deallocate_amount<15>();
    continue;
  vsp_sub_16:
    sp_ptr = sp_ptr + vsp_deallocate_amount<16>();
    continue;
  vsp_sub_17:
    sp_ptr = sp_ptr + vsp_deallocate_amount<17>();
    continue;
  vsp_sub_18:
    sp_ptr = sp_ptr + vsp_deallocate_amount<18>();
    continue;
  vsp_sub_19:
    sp_ptr = sp_ptr + vsp_deallocate_amount<19>();
    continue;
  vsp_sub_20:
    sp_ptr = sp_ptr + vsp_deallocate_amount<20>();
    continue;
  vsp_sub_21:
    sp_ptr = sp_ptr + vsp_deallocate_amount<21>();
    continue;
  vsp_sub_22:
    sp_ptr = sp_ptr + vsp_deallocate_amount<22>();
    continue;
  vsp_sub_23:
    sp_ptr = sp_ptr + vsp_deallocate_amount<23>();
    continue;
  vsp_sub_24:
    sp_ptr = sp_ptr + vsp_deallocate_amount<24>();
    continue;
  vsp_sub_25:
    sp_ptr = sp_ptr + vsp_deallocate_amount<25>();
    continue;
  vsp_sub_26:
    sp_ptr = sp_ptr + vsp_deallocate_amount<26>();
    continue;
  vsp_sub_27:
    sp_ptr = sp_ptr + vsp_deallocate_amount<27>();
    continue;
  vsp_sub_28:
    sp_ptr = sp_ptr + vsp_deallocate_amount<28>();
    continue;
  vsp_sub_29:
    sp_ptr = sp_ptr + vsp_deallocate_amount<29>();
    continue;
  vsp_sub_30:
    sp_ptr = sp_ptr + vsp_deallocate_amount<30>();
    continue;
  vsp_sub_31:
    sp_ptr = sp_ptr + vsp_deallocate_amount<31>();
    continue;
  vsp_sub_32:
    sp_ptr = sp_ptr + vsp_deallocate_amount<32>();
    continue;
  vsp_sub_33:
    sp_ptr = sp_ptr + vsp_deallocate_amount<33>();
    continue;
  vsp_sub_34:
    sp_ptr = sp_ptr + vsp_deallocate_amount<34>();
    continue;
  vsp_sub_35:
    sp_ptr = sp_ptr + vsp_deallocate_amount<35>();
    continue;
  vsp_sub_36:
    sp_ptr = sp_ptr + vsp_deallocate_amount<36>();
    continue;
  vsp_sub_37:
    sp_ptr = sp_ptr + vsp_deallocate_amount<37>();
    continue;
  vsp_sub_38:
    sp_ptr = sp_ptr + vsp_deallocate_amount<38>();
    continue;
  vsp_sub_39:
    sp_ptr = sp_ptr + vsp_deallocate_amount<39>();
    continue;
  vsp_sub_40:
    sp_ptr = sp_ptr + vsp_deallocate_amount<40>();
    continue;
  vsp_sub_41:
    sp_ptr = sp_ptr + vsp_deallocate_amount<41>();
    continue;
  vsp_sub_42:
    sp_ptr = sp_ptr + vsp_deallocate_amount<42>();
    continue;
  vsp_sub_43:
    sp_ptr = sp_ptr + vsp_deallocate_amount<43>();
    continue;
  vsp_sub_44:
    sp_ptr = sp_ptr + vsp_deallocate_amount<44>();
    continue;
  vsp_sub_45:
    sp_ptr = sp_ptr + vsp_deallocate_amount<45>();
    continue;
  vsp_sub_46:
    sp_ptr = sp_ptr + vsp_deallocate_amount<46>();
    continue;
  vsp_sub_47:
    sp_ptr = sp_ptr + vsp_deallocate_amount<47>();
    continue;
  vsp_sub_48:
    sp_ptr = sp_ptr + vsp_deallocate_amount<48>();
    continue;
  vsp_sub_49:
    sp_ptr = sp_ptr + vsp_deallocate_amount<49>();
    continue;
  vsp_sub_50:
    sp_ptr = sp_ptr + vsp_deallocate_amount<50>();
    continue;
  vsp_sub_51:
    sp_ptr = sp_ptr + vsp_deallocate_amount<51>();
    continue;
  vsp_sub_52:
    sp_ptr = sp_ptr + vsp_deallocate_amount<52>();
    continue;
  vsp_sub_53:
    sp_ptr = sp_ptr + vsp_deallocate_amount<53>();
    continue;
  vsp_sub_54:
    sp_ptr = sp_ptr + vsp_deallocate_amount<54>();
    continue;
  vsp_sub_55:
    sp_ptr = sp_ptr + vsp_deallocate_amount<55>();
    continue;
  vsp_sub_56:
    sp_ptr = sp_ptr + vsp_deallocate_amount<56>();
    continue;
  vsp_sub_57:
    sp_ptr = sp_ptr + vsp_deallocate_amount<57>();
    continue;
  vsp_sub_58:
    sp_ptr = sp_ptr + vsp_deallocate_amount<58>();
    continue;
  vsp_sub_59:
    sp_ptr = sp_ptr + vsp_deallocate_amount<59>();
    continue;
  vsp_sub_60:
    sp_ptr = sp_ptr + vsp_deallocate_amount<60>();
    continue;
  vsp_sub_61:
    sp_ptr = sp_ptr + vsp_deallocate_amount<61>();
    continue;
  vsp_sub_62:
    sp_ptr = sp_ptr + vsp_deallocate_amount<62>();
    continue;
  vsp_sub_63:
    sp_ptr = sp_ptr + vsp_deallocate_amount<63>();
    continue;
  }
}

[[gnu::always_inline]]
inline instructions_t create_instructions_from_entry(
  exception_object const& p_exception_object)
{
  constexpr auto personality_type = hal::bit_mask::from<24, 27>();
  constexpr auto generic = hal::bit_mask::from<31>();

  instructions_t unwind{};

  std::uint32_t const* handler_data = nullptr;
  auto const& entry = *p_exception_object.cache.entry_ptr;
  if (entry.has_inlined_personality()) {
    handler_data = &entry.personality_offset;
  } else {
    auto const* personality = p_exception_object.cache.personality;
    if (hal::bit_extract<generic>(personality[0])) {
      handler_data = &personality[0];
    } else {
      handler_data = &personality[1];
    }
  }

  std::uint32_t header = handler_data[0];

  if (hal::bit_extract<personality_type>(header) == 0x0) {
    unwind.data[0] = hal::bit_extract<su16::instruction0>(header);
    unwind.data[1] = hal::bit_extract<su16::instruction1>(header);
    unwind.data[2] = hal::bit_extract<su16::instruction2>(header);
  } else {
    std::uint32_t first_word = handler_data[1];
    std::uint32_t length = hal::bit_extract<lu16_32::length>(header);
    switch (length) {
      case 1: {
        unwind.data[0] = hal::bit_extract<lu16_32::instruction0>(header);
        unwind.data[1] = hal::bit_extract<lu16_32::instruction1>(header);
        unwind.data[2] = hal::bit_extract<lu16_32::instruction2>(first_word);
        unwind.data[3] = hal::bit_extract<lu16_32::instruction3>(first_word);
        unwind.data[4] = hal::bit_extract<lu16_32::instruction4>(first_word);
        unwind.data[5] = hal::bit_extract<lu16_32::instruction5>(first_word);
        break;
      }
      case 2: {
        uint32_t last_word = handler_data[2];
        unwind.data[0] = hal::bit_extract<lu16_32::instruction0>(header);
        unwind.data[1] = hal::bit_extract<lu16_32::instruction1>(header);
        unwind.data[2] = hal::bit_extract<lu16_32::instruction2>(first_word);
        unwind.data[3] = hal::bit_extract<lu16_32::instruction3>(first_word);
        unwind.data[4] = hal::bit_extract<lu16_32::instruction4>(first_word);
        unwind.data[5] = hal::bit_extract<lu16_32::instruction5>(first_word);
        unwind.data[6] = hal::bit_extract<lu16_32::instruction6>(last_word);
        break;
      }
      default: {
        // When a function uses rethrow, this seems to cause a glitch with
        // GCC's handler data. For example I've seen: 0x01'b1'08'84 for the
        // first word and 0x00'b0'b0'b0 for the second word.
        // This doesn't makes sense because the PR index is 1 but the length
        // is 0xB1 which is too large. But it does make sense if you simply
        // assume that 0xB1 is the first instruction, then 0x08, then 0x84
        // 0x00. This works. So when we see this mix, we just collect
        // instructions in that order as if it were a 2-word PR0.
        unwind.data[0] = hal::bit_extract<su16::instruction0>(header);
        unwind.data[1] = hal::bit_extract<su16::instruction1>(header);
        unwind.data[2] = hal::bit_extract<su16::instruction2>(header);
        unwind.data[3] = hal::bit_extract<lu16_32::instruction2>(first_word);
        unwind.data[4] = hal::bit_extract<lu16_32::instruction3>(first_word);
        unwind.data[5] = hal::bit_extract<lu16_32::instruction4>(first_word);
        unwind.data[6] = hal::bit_extract<lu16_32::instruction5>(first_word);
      }
    }
  }

  return unwind;
}

void raise_exception(exception_object& p_exception_object)
{
  while (true) {
    switch (p_exception_object.cache.state()) {
      case runtime_state::get_next_frame: {
        auto const& index_entry = get_index_entry(p_exception_object.cpu.pc);
        p_exception_object.cache.entry_ptr = &index_entry;
        // SU16 data
        if (index_entry.has_inlined_personality()) {
          p_exception_object.cache.state(runtime_state::unwind_frame);
          break;
        }
        if (index_entry.personality_offset == 0x1) {
          return;
        }
        p_exception_object.cache.personality = index_entry.personality();
        auto const* descriptor_start =
          index_entry_t::descriptor_start(p_exception_object.cache.personality);
        // The descriptor start value can only be 0x0 if there is LU16 data and
        // no LSDA. In such cases, simply unwind the frame.
        if (*descriptor_start == 0x0000'0000) {
          p_exception_object.cache.state(runtime_state::unwind_frame);
          break;
        }
        // LSDA is present!
        p_exception_object.cache.relative_address(
          (p_exception_object.cpu.pc - index_entry.function()));
        p_exception_object.cache.state(runtime_state::enter_function);
        [[fallthrough]];
      }
      case runtime_state::enter_function: {
        enter_function(p_exception_object);
        // enter function returns normally if it determines that there was no
        // reason to enter the function, thus the function should be unwound.
        [[fallthrough]];
      }
      case runtime_state::unwind_frame: {
        auto const instructions =
          create_instructions_from_entry(p_exception_object);
        unwind_frame(instructions, p_exception_object.cpu);
        p_exception_object.cache.state(runtime_state::get_next_frame);
      }
    }
  }
}
}  // namespace ke

extern "C"
{
  // mangled name for vtable for __cxxabi::__class_type_info
  extern void* _ZTVN10__cxxabiv117__class_type_infoE[];
  // mangled name for vtable for __cxxabi::__si_class_type_info
  extern void* _ZTVN10__cxxabiv120__si_class_type_infoE[];
  // mangled name for vtable for __cxxabi::__vmi_class_type_info
  extern void* _ZTVN10__cxxabiv121__vmi_class_type_infoE[];
}

namespace ke {
enum class rtti_type
{
  class_type,
  single_inheritance,
  virtual_or_multi_inheritance,
  anything_else,
};

rtti_type get_rtti_type(void const* p_type_info)
{
  auto const* word_pointer =
    reinterpret_cast<std::uint32_t const*>(p_type_info);
  auto const vtable_method_location = word_pointer[0];
  auto const vtable_start = vtable_method_location - 8;
  auto const* vtable_address = reinterpret_cast<void const*>(vtable_start);

  if (vtable_address == &_ZTVN10__cxxabiv117__class_type_infoE) {
    return rtti_type::class_type;
  } else if (vtable_address == &_ZTVN10__cxxabiv120__si_class_type_infoE) {
    return rtti_type::single_inheritance;
  } else if (vtable_address == &_ZTVN10__cxxabiv121__vmi_class_type_infoE) {
    return rtti_type::virtual_or_multi_inheritance;
  } else {
    return rtti_type::anything_else;
  }
}

std::type_info const* extract_si_parent_info(void const* p_info)
{
  [[maybe_unused]] constexpr std::size_t vtable_entry = 0;
  [[maybe_unused]] constexpr std::size_t name = 1;
  [[maybe_unused]] constexpr std::size_t parent_info_address = 2;

  auto const* word_pointer = reinterpret_cast<std::uint32_t const*>(p_info);
  auto const address = word_pointer[parent_info_address];

  return reinterpret_cast<std::type_info const*>(address);
}

template<std::size_t map_length>
void push_vmi_info(ke::exception_ptr p_thrown_exception,
                   base_class_type_info& p_info,
                   flattened_hierarchy<map_length>& p_map)
{
  [[maybe_unused]] constexpr std::size_t vtable_entry = 0;
  [[maybe_unused]] constexpr std::size_t name = 1;
  [[maybe_unused]] constexpr std::size_t flags = 2;
  [[maybe_unused]] constexpr std::size_t vla_length = 3;
  [[maybe_unused]] constexpr std::size_t vla_start = 4;

  auto const* word_pointer =
    reinterpret_cast<std::uint32_t const*>(p_info.type_info);
  auto const length = word_pointer[vla_length];
  for (std::size_t i = vla_start; i < vla_start + (length * 2); i += 2) {
    base_class_type_info parent_info{};
    auto const parent_address = word_pointer[i];
    // Shift by 8 to remove the first byte which is just flags
    auto const offset_flags = static_cast<std::int32_t>(word_pointer[i + 1]);

    constexpr auto public_mask = 0x2;
    bool const public_parent = offset_flags & public_mask;

    if (not public_parent) {
      continue;
    }

    auto const offset = offset_flags >> 8;
    parent_info.type_info = reinterpret_cast<void*>(parent_address);
    if (offset >= 0) {
      // Shift the lower 8-bits of flag information
      parent_info.offset = p_info.offset + offset;
    } else {
      // Use a byte array to allow pointer arithmetic
      constexpr std::ptrdiff_t ptr_diff_size = sizeof(std::ptrdiff_t);
      auto const* byte_accessor = as<uint8_t const>(p_thrown_exception);
      // Get the address of the child object with this virtual parent
      auto const* child_object = byte_accessor + p_info.offset;
      // The first word is a pointer to the child object's vtable, so lets
      // access it.
      auto const* vtable = *as<std::intptr_t const*>(child_object);
      // The location of the virtual parent relative to this object is found
      // behind the vtable, which is why the offset is negative. Because we are
      // indexing by word (pointer) lengths, we need to divide the offset by the
      // size of a intptr_t. ARM objects are word aligned so this works safely.
      auto const index_of_parent_offset_in_vtable = offset / ptr_diff_size;
      // Because the offset is negative, look behind the object's vtable to find
      // the offset to the start of the virtual class.
      auto const offset_to_virtual = vtable[index_of_parent_offset_in_vtable];
      // The virtual base of the child does not include the full offset from the
      // start of the thrown object. We need to add the offset from the
      // sub-object to get the correct location.
      parent_info.offset = offset_to_virtual + p_info.offset;
    }
    p_map.push_back(parent_info);
  }
}

template<std::size_t length>
void flatten_rtti(ke::exception_ptr p_thrown_exception,
                  flattened_hierarchy<length>& p_map,
                  std::type_info const* p_type_info)
{
  // Add first element to the list
  p_map.push_back({ .type_info = p_type_info, .offset = 0 });
  auto iter = p_map.begin();
  auto info = get_rtti_type(p_type_info);

  // If this is a non-class type, then there is in hierarchy and this first
  // element we pushed is the only one.
  if (info == rtti_type::anything_else) {
    return;
  }

  for (; iter != p_map.begin() + p_map.size; iter++) {
    info = get_rtti_type(iter->type_info);

    if (info == rtti_type::class_type) {
      // There is nothing to do in this case. This entry is are already in the
      // list from being something else's parent either via VMI or SI.
      continue;
    } else if (info == rtti_type::single_inheritance) {
      base_class_type_info parent_info{};
      parent_info.type_info = extract_si_parent_info(iter->type_info);
      // Assign your offset to your direct parent because their memory is within
      // you.
      parent_info.offset += iter->offset;
      p_map.push_back(parent_info);
    } else if (info == rtti_type::virtual_or_multi_inheritance) {
      push_vmi_info(p_thrown_exception, *iter, p_map);
    }
  }
}
}  // namespace ke

namespace {
bool const volatile libhal_convince_compiler_to_emit_metadata = false;
}

extern "C"
{
  void _exit([[maybe_unused]] int rc)  // NOLINT
  {
    std::terminate();
  }
  // TODO(#42): Use the applications's polymorphic allocator, not our own space.
  void* __wrap___cxa_allocate_exception(size_t p_thrown_size)
  {
    if (p_thrown_size >
        ke::exception_buffer.size() + sizeof(ke::exception_object)) {
      std::terminate();
    }

    return ke::exception_buffer.data() + sizeof(ke::exception_object);
  }

  void __wrap___cxa_free_exception([[maybe_unused]] void* p_thrown_exception)
  {
    ke::exception_buffer.fill(0);
  }

  void __wrap___cxa_call_unexpected(void*)  // NOLINT
  {
    std::terminate();
  }

  void __wrap___cxa_end_catch()
  {
    auto& exception_object = ke::extract_exception_object(ke::active_exception);
    if (exception_object.cache.rethrown()) {
      exception_object.cache.rethrown(false);
    } else {
      __wrap___cxa_free_exception(ke::active_exception);
    }
  }

  void* __wrap___cxa_begin_catch(void* p_exception_object)
  {
    auto* eo = reinterpret_cast<ke::exception_object*>(p_exception_object);
    auto* thrown_object = ke::extract_thrown_object(eo);
    return thrown_object;
  }

  void __wrap___cxa_end_cleanup()
  {
    auto& exception_object = ke::extract_exception_object(ke::active_exception);
    exception_object.cache.state(ke::runtime_state::unwind_frame);
    // Raise exception returns when an error or call to terminate has been found
    ke::raise_exception(exception_object);
    std::terminate();
  }

  void __wrap___cxa_rethrow() noexcept(false)
  {
    auto& exception_object = ke::extract_exception_object(ke::active_exception);

    ke::capture_cpu_core(exception_object.cpu);

    exception_object.cache.state(ke::runtime_state::get_next_frame);
    exception_object.cache.rethrown(true);

    // This must ALWAYS evaluate to false. But since the variable is volatile,
    // the compiler will not optimize it away and thus, __wrap___cxa_throw will
    // require unwind information. This prevents the compiler from optimizing
    // the data away.
    if (libhal_convince_compiler_to_emit_metadata) {
      throw std::bad_alloc();  // What is thrown is not important, just that we
                               // throw something and since bad_alloc is a MUST
                               // have in the C++ throw RTTI list, might as well
                               // reuse it here.
    }
    // Raise exception returns when an error or call to terminate has been found
    ke::raise_exception(exception_object);
    // TODO(#38): this area is considered a catch block, meaning that the
    // exception is handled at this point. We should mark it as such.
    std::terminate();
  }

  void __wrap___cxa_throw(ke::exception_ptr p_thrown_exception,
                          std::type_info* p_type_info,
                          ke::destructor_t p_destructor) noexcept(false)
  {
    ke::active_exception = p_thrown_exception;
    auto& exception_object = ke::extract_exception_object(p_thrown_exception);
    exception_object.destructor = p_destructor;
    ke::capture_cpu_core(exception_object.cpu);
    ke::flatten_rtti<12>(
      p_thrown_exception, exception_object.type_info, p_type_info);

    // This must ALWAYS evaluate to false. But since the variable is volatile,
    // the compiler will not optimize it away and thus, __wrap___cxa_throw will
    // require unwind information. This prevents the compiler from optimizing
    // the data away.
    if (libhal_convince_compiler_to_emit_metadata) {
      throw std::bad_alloc();  // What is thrown is not important, just that we
                               // throw something and since bad_alloc is a MUST
                               // have in the C++ throw RTTI list, might as well
                               // reuse it here.
    }
    // Raise exception returns when an error or call to terminate has been found
    ke::raise_exception(exception_object);
    // TODO(#38): this area is considered a catch block, meaning that the
    // exception is handled at this point. We should mark it as such.
    std::terminate();
  }
}  // extern "C"
