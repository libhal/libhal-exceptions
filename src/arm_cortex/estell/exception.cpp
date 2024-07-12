// Copyright 2024 Khalil Estell
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
#include <exception>
#include <span>
#include <typeinfo>

#include "internal.hpp"

#define Debug 1
#define MinSizeRel 2
#define RelWithDebInfo 3
#define Release 4

#if !defined(OPTIMIZATION_LEVEL)
#error "OPTIMIZATION LEVEL MUST BE DEFINED!"
#endif

namespace ke {

using instructions_t = std::array<std::uint8_t, 7>;

namespace {
exception_ptr active_exception = nullptr;
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

void capture_cpu_core(ke::cortex_m_cpu& p_cpu_core)
{
  asm volatile("mrs r0, MSP\n"         // Move Main Stack Pointer to r0
               "stmia %0, {r0-r12}\n"  // Store r0 to r12 into the array
               "mov r0, SP\n"          // Move SP to r0
               "str r0, [%0, #52]\n"   // Store SP at the appropriate index
               "mov r0, LR\n"          // Move LR to r0
               "str r0, [%0, #56]\n"   // Store LR at the appropriate index
               "mov r0, PC\n"          // Move PC to r0
               "str r0, [%0, #60]\n"   // Store PC at the appropriate index
               :                       // no output
               : "r"(&p_cpu_core)      // input is the address of the array
               : "r0"                  // r0 is being modified
  );
}

bool index_entry_t::has_inlined_personality() const
{
  // 31st bit is `1` when the personality/unwind information is inlined, other
  // otherwise, personality_offset is an offset.
  constexpr auto mask = hal::bit_mask::from<31>();
  return hal::bit_extract<mask>(personality_offset);
}

bool index_entry_t::is_noexcept() const
{
  return personality_offset == 0x1;
}

std::uint32_t const* index_entry_t::personality() const
{
  return to_absolute_address_ptr(&personality_offset);
}

std::uint32_t const* index_entry_t::lsda_data() const
{
  constexpr auto personality_type = hal::bit_mask::from<24, 27>();
  // +1 to skip the prel31 offset to the personality function
  auto const* header = personality() + 1;
  if (hal::bit_extract<personality_type>(*header) == 0x0) {
    return header + 1;
  }
  if (hal::bit_extract<lu16_32::length>(*header) == 1) {
    return header + 2;
  }
  if (hal::bit_extract<lu16_32::length>(*header) > 2) {
    return header + 2;
  }
  return header + 3;
}

std::uint32_t const* index_entry_t::descriptor_start() const
{
  constexpr auto type_mask = hal::bit_mask{ .position = 24, .width = 8 };

  auto* personality_address = personality();
  auto type = hal::bit_extract<type_mask>(*personality_address);

  // TODO(kammce): comment why each of these works!
  if (type == 0x0) {
    return personality_address + 1;
  }

  // The limit for ARM exceptions instructions is 7. LD optimizes the ARM
  // exception spec by removing the "word length" specifier allowing the
  // instructions to fit in 2 words.
  return personality_address + 2;
}

function_t index_entry_t::function() const
{
  return function_t(to_absolute_address(&function_offset));
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

void pop_registers(cortex_m_cpu& p_cpu, std::uint32_t mask)
{
  // The mask may not demand that the stack pointer be popped, but the
  // stack pointer will still need to be popped anyway, so this check
  // determines if the mask handles this or not.
#if 0
  constexpr auto sp_mask = hal::bit_mask::from<cortex_m_cpu::sp_index>();
  bool set_stack_pointer_afterwards = hal::bit_extract<sp_mask>(mask);
#endif

  std::uint32_t const* stack_pointer = *p_cpu.sp;

  while (mask) {
    auto reg_to_restore = std::countr_zero(mask);
    mask &= ~(1 << reg_to_restore);
    p_cpu[reg_to_restore] = *(stack_pointer++);
  }

  p_cpu.sp = stack_pointer;
}

std::uint32_t read_uleb128(std::uint8_t const volatile** p_ptr)
{
  std::uint32_t result = 0;
  std::uint8_t shift_amount = 0;

  while (true) {
    constexpr auto more_data = hal::bit_mask::from<7>();
    constexpr auto data = hal::bit_mask::from<0, 6>();
    std::uint8_t const uleb128 = **p_ptr;

    result |= hal::bit_extract<data>(uleb128) << shift_amount;
    shift_amount += 7;
    (*p_ptr)++;

    if (not hal::bit_extract<more_data>(uleb128)) {
      break;
    }
  }

  return result;
}

template<typename T>
T const volatile* as(void const volatile* p_ptr)
{
  return reinterpret_cast<T const volatile*>(p_ptr);
}

/**
 * @brief Dwarf exception handling personality encodings
 *
 */
enum class personality_encoding : std::uint8_t
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

personality_encoding operator&(personality_encoding const& p_encoding,
                               std::uint8_t const& p_byte)
{
  return static_cast<personality_encoding>(
    static_cast<std::uint8_t>(p_encoding) & p_byte);
}
personality_encoding operator&(personality_encoding const& p_encoding,
                               personality_encoding const& p_byte)
{
  return static_cast<personality_encoding>(
    static_cast<std::uint8_t>(p_encoding) & static_cast<std::uint8_t>(p_byte));
}

std::uintptr_t read_encoded_data(std::uint8_t const volatile** p_data,
                                 personality_encoding p_encoding)
{
  std::uint8_t const volatile* ptr = *p_data;
  std::uintptr_t result = 0;
  auto const encoding = static_cast<personality_encoding>(p_encoding);

  if (encoding == personality_encoding::omit) {
    return 0;
  }

  // TODO: convert to hal::bit_extract w/ bit mask
  auto const encoding_type = p_encoding & 0x0F;

  switch (encoding_type) {
    case personality_encoding::absptr:
      result = *as<uintptr_t>(ptr);
      ptr += sizeof(uintptr_t);
      break;
    case personality_encoding::uleb128:
      result = read_uleb128(&ptr);
      break;
    case personality_encoding::udata2:
      result = *as<uint16_t>(ptr);
      ptr += sizeof(uint16_t);
      break;
    case personality_encoding::udata4:
      result = *as<uint32_t>(ptr);
      ptr += sizeof(uint32_t);
      break;
    case personality_encoding::sdata2:
      result = *as<int16_t>(ptr);
      ptr += sizeof(int16_t);
      break;
    case personality_encoding::sdata4:
      result = *as<int32_t>(ptr);
      ptr += sizeof(int32_t);
      break;
    case personality_encoding::sleb128:
    case personality_encoding::sdata8:
    case personality_encoding::udata8:
    default:
      std::terminate();
      break;
  }

  // TODO: convert to hal::bit_extract w/ bit mask
  auto const encoding_offset = p_encoding & 0x70;

  switch (encoding_offset) {
    case personality_encoding::pcrel:
    case personality_encoding::absptr:
    case personality_encoding::textrel:
    case personality_encoding::datarel:
    case personality_encoding::funcrel:
    case personality_encoding::aligned:
    default:
      break;
  }

  // Handle indirection GCC extension
  // TODO: convert to hal::bit_extract w/ bit mask
  if (static_cast<bool>(p_encoding & 0x80)) {
    result = *reinterpret_cast<std::uintptr_t const*>(result);
  }

  *p_data = ptr;
  return result;
}

class action_decoder
{
public:
  action_decoder(std::uint8_t const volatile* p_type_table_end,
                 std::uint8_t const volatile* p_action_table_start,
                 std::uint32_t p_action)
    : m_type_table_end(
        reinterpret_cast<std::uint32_t const volatile*>(p_type_table_end))
    , m_action(p_action_table_start + p_action)
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

  std::type_info const* get_next_catch_type()
  {
    if (m_action == nullptr) {
      return nullptr;
    }

    m_filter = m_action[-1];
    auto const unsigned_offset = m_action[0] | 0x80;
    auto const offset = static_cast<std::int8_t>(unsigned_offset);

    if (offset == 0) {
      m_action = nullptr;
    } else {
      m_action += (offset + 1);
    }

    std::uint32_t const volatile* current_type = &m_type_table_end[-m_filter];

    if (m_filter == 0 || *current_type == 0x0) {
      return install_context_type();
    }

    return to_type_info(const_cast<std::uint32_t const*>(current_type));
  }

  std::uint8_t filter()
  {
    return m_filter;
  }

private:
  std::uint32_t const volatile* m_type_table_end = nullptr;
  std::uint8_t const volatile* m_action = nullptr;
  std::uint8_t m_filter = 0;
};

int global_int = 0;

void enter_function(exception_object& p_exception_object)
{
  std::uint8_t const volatile* lsda_data =
    reinterpret_cast<std::uint8_t const*>(
      p_exception_object.cache.entry_ptr->lsda_data());

  auto const dwarf_offset_info_format = personality_encoding{ *(lsda_data++) };
  if (dwarf_offset_info_format != personality_encoding::omit) {
    // Ignore this because we don't need it for unwinding.
    read_encoded_data(&lsda_data, dwarf_offset_info_format);
  }

  [[maybe_unused]] auto const end_of_type_table_format =
    personality_encoding{ *(lsda_data++) };
  auto const offset_to_end_of_tt_table = read_uleb128(&lsda_data);
  auto const* end_of_tt_table = lsda_data + offset_to_end_of_tt_table;
  auto const call_site_format = personality_encoding{ *(lsda_data++) };
  auto const call_site_length = read_uleb128(&lsda_data);
  auto const* call_site_end = lsda_data + call_site_length;

  auto const rel_pc = p_exception_object.cache.relative_address() & ~1;
  std::uint32_t landing_pad = 0;
  std::uint32_t action = 0;

  do {
    auto start = read_encoded_data(&lsda_data, call_site_format);
    auto length = read_encoded_data(&lsda_data, call_site_format);
    landing_pad = read_encoded_data(&lsda_data, call_site_format);
    action = read_uleb128(&lsda_data);

    if (start <= rel_pc && rel_pc <= start + length) {
      if (landing_pad == 0) {
        p_exception_object.cache.state(runtime_state::unwind_frame);
        return;
      }
      break;
    }
  } while (lsda_data < call_site_end);

  action_decoder a_decoder(end_of_tt_table, call_site_end, action);

  auto& cpu = p_exception_object.cpu;
  auto* entry_ptr = p_exception_object.cache.entry_ptr;
  for (auto const* type_info = a_decoder.get_next_catch_type();
       type_info != nullptr;
       type_info = a_decoder.get_next_catch_type()) {
    if (type_info == p_exception_object.type_info ||
        type_info == action_decoder::install_context_type()) {
      cpu[0] = &p_exception_object;
      cpu[1] = a_decoder.filter();
      // Set the LSB to 1 for some reason. Cortex-mX is interesting
      auto final_destination = (entry_ptr->function() + landing_pad) | 0b1;
      cpu.pc = final_destination;
      restore_cpu_core(cpu);
    }
  }
}

void unwind_frame(instructions_t const& p_instructions,
                  exception_object& p_exception_object)
{
  auto& virtual_cpu = p_exception_object.cpu;
  bool set_pc = false;

  for (auto instruction = p_instructions.begin();
       instruction != p_instructions.end() && *instruction != arm_ehabi::finish;
       instruction++) {
    // Extract the first 4 bits
    int main_bits = (*instruction & 0b11110000) >> 4;

    switch (main_bits) {
      case 0b0000:
      case 0b0001:
      case 0b0010:
      case 0b0011: {
        // vsp = vsp + (xxxxxx << 2) + 4. Covers range 0x04-0x100 inclusive
        int shift_amount = *instruction & 0b111111;
        virtual_cpu.sp = virtual_cpu.sp + ((shift_amount << 2) + 4);
        break;
      }
      case 0b0100:
      case 0b0101:
      case 0b0110:
      case 0b0111: {
        // vsp = vsp - (xxxxxx << 2) + 4. Covers range 0x04-0x100 inclusive
        int shift_amount = *instruction & 0b111111;
        virtual_cpu.sp = virtual_cpu.sp - ((shift_amount << 2) + 4);
        break;
      }
      case 0b1001: {
        // Handle "1001nnnn"
        int nnnn = *instruction & 0xF;
        if (nnnn != 13 && nnnn != 15) {
          // Set vsp = r[nnnn]
          virtual_cpu.sp = virtual_cpu[nnnn];
        } else {
          // Handle "10011101" or "10011111"
          // Reserved as prefix for Arm register to register moves
          // Reserved as prefix for Intel Wireless MMX register to register
          // moves
          std::terminate();
        }
        break;
      }
      case 0b1010: {
        // Handle:
        //
        //     "10100nnn" (Pop r4-r[4+nnn]), and
        //     "10101nnn" (Pop r4-r[4+nnn], r14)
        //
        std::uint32_t const* sp_ptr = *virtual_cpu.sp;
        int nnn = *instruction & 0b111;  // Extract the last 3 bits
        switch (nnn) {
          case 7:
            virtual_cpu[11] = sp_ptr[7];
            [[fallthrough]];
          case 6:
            virtual_cpu[10] = sp_ptr[6];
            [[fallthrough]];
          case 5:
            virtual_cpu[9] = sp_ptr[5];
            [[fallthrough]];
          case 4:
            virtual_cpu[8] = sp_ptr[4];
            [[fallthrough]];
          case 3:
            virtual_cpu[7] = sp_ptr[3];
            [[fallthrough]];
          case 2:
            virtual_cpu[6] = sp_ptr[2];
            [[fallthrough]];
          case 1:
            virtual_cpu[5] = sp_ptr[1];
            [[fallthrough]];
          case 0:
            virtual_cpu[4] = sp_ptr[0];
        }

        if (*instruction & 0b1000) {
          virtual_cpu.lr = sp_ptr[nnn + 1];
          // +1 because "nnn" starts at zero and we need to decrement something.
          // The second +1 is for popping the LR register.
          sp_ptr += (nnn + 2);
        } else {
          // See above comments.
          sp_ptr += (nnn + 1);
        }

        virtual_cpu.sp = sp_ptr;
        break;
      }
      case 0b1011: {
        // Handle "10110000", and "1011011n"
        if (*instruction == arm_ehabi::finish) {
          // "10110000"
          // Finish (see remark c)
          goto exit_loop;
        } else if ((*instruction & 0b1100) == 0b1100) {
          // "1011011n"
          // Spare (was Pop FPA)
          std::terminate();
        } else if (*instruction == 0xB1) {
          std::uint32_t mask = *(++instruction);
          pop_registers(virtual_cpu, mask);
        }
        break;
      }
      case 0b1000: {
        std::uint32_t mask = (*instruction & 0xF) << (8 + 4);
        instruction++;
        mask |= (*instruction << 4);
        pop_registers(virtual_cpu, mask);
        break;
      }
      // No additional groupings are left as all provided instructions are
      // covered
      default: {
        // Handle unknown or undefined instruction
        std::terminate();
      }
    }
  }

exit_loop:
  if (!set_pc) {
    virtual_cpu.pc = virtual_cpu.lr;
  }
}

instructions_t create_instructions_from_entry(index_entry_t const& p_entry)
{
  constexpr auto personality_type = hal::bit_mask::from<24, 27>();
  constexpr auto generic = hal::bit_mask::from<31>();

  instructions_t instructions{};

  // Fill the whole thing with finish flags such that the code below only
  // needs to overwrite the values from the start.
  instructions.fill(arm_ehabi::finish);

  std::uint32_t const* handler_data = nullptr;

  if (p_entry.has_inlined_personality()) {
    handler_data = &p_entry.personality_offset;
  } else if (hal::bit_extract<generic>(p_entry.personality()[0])) {
    handler_data = &p_entry.personality()[0];
  } else {
    handler_data = &p_entry.personality()[1];
  }

  std::uint32_t header = handler_data[0];

  if (hal::bit_extract<personality_type>(header) == 0x0) {
    instructions[0] = hal::bit_extract<su16::instruction0>(header);
    instructions[1] = hal::bit_extract<su16::instruction1>(header);
    instructions[2] = hal::bit_extract<su16::instruction2>(header);
  } else {
    std::uint32_t first_word = handler_data[1];
    std::uint32_t length = hal::bit_extract<lu16_32::length>(header);
    switch (length) {
      case 1: {
        instructions[0] = hal::bit_extract<lu16_32::instruction0>(header);
        instructions[1] = hal::bit_extract<lu16_32::instruction1>(header);
        instructions[2] = hal::bit_extract<lu16_32::instruction2>(first_word);
        instructions[3] = hal::bit_extract<lu16_32::instruction3>(first_word);
        instructions[4] = hal::bit_extract<lu16_32::instruction4>(first_word);
        instructions[5] = hal::bit_extract<lu16_32::instruction5>(first_word);
        break;
      }
      case 2: {
        uint32_t last_word = handler_data[2];
        instructions[0] = hal::bit_extract<lu16_32::instruction0>(header);
        instructions[1] = hal::bit_extract<lu16_32::instruction1>(header);
        instructions[2] = hal::bit_extract<lu16_32::instruction2>(first_word);
        instructions[3] = hal::bit_extract<lu16_32::instruction3>(first_word);
        instructions[4] = hal::bit_extract<lu16_32::instruction4>(first_word);
        instructions[5] = hal::bit_extract<lu16_32::instruction5>(first_word);
        instructions[6] = hal::bit_extract<lu16_32::instruction6>(last_word);
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
        instructions[0] = hal::bit_extract<su16::instruction0>(header);
        instructions[1] = hal::bit_extract<su16::instruction1>(header);
        instructions[2] = hal::bit_extract<su16::instruction2>(header);
        instructions[3] = hal::bit_extract<lu16_32::instruction2>(first_word);
        instructions[4] = hal::bit_extract<lu16_32::instruction3>(first_word);
        instructions[5] = hal::bit_extract<lu16_32::instruction4>(first_word);
        instructions[6] = hal::bit_extract<lu16_32::instruction5>(first_word);
      }
    }
  }

  return instructions;
}

void raise_exception(exception_object& p_exception_object)
{
  while (true) {
    switch (p_exception_object.cache.state()) {
      case runtime_state::get_next_frame: {
        auto const& index_entry = get_index_entry(p_exception_object.cpu.pc);
        p_exception_object.cache.entry_ptr = &index_entry;
        if (index_entry.has_inlined_personality()) {
          p_exception_object.cache.state(runtime_state::unwind_frame);
          break;
        }
        auto const* descriptor_start = index_entry.descriptor_start();
        if (*descriptor_start == 0x0000'0000) {
          p_exception_object.cache.state(runtime_state::unwind_frame);
          break;
        }
        p_exception_object.cache.relative_address(p_exception_object.cpu.pc -
                                                  index_entry.function());
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
        auto const& entry = *p_exception_object.cache.entry_ptr;
        auto const instructions = create_instructions_from_entry(entry);
        unwind_frame(instructions, p_exception_object);
        p_exception_object.cache.state(runtime_state::get_next_frame);
      }
    }
  }
}
}  // namespace ke

extern "C"
{

  void _exit([[maybe_unused]] int rc)  // NOLINT
  {
    std::terminate();
  }

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
    return ke::extract_thrown_object(p_exception_object);
  }

  void __wrap___cxa_end_cleanup()
  {
    auto& exception_object = ke::extract_exception_object(ke::active_exception);
    exception_object.cache.state(ke::runtime_state::unwind_frame);
    // Raise exception returns when an error or call to terminate has been found
    ke::raise_exception(exception_object);
    std::terminate();
  }

  void __wrap___cxa_rethrow()
  {
    auto& exception_object = ke::extract_exception_object(ke::active_exception);

    ke::capture_cpu_core(exception_object.cpu);

    exception_object.cache.state(ke::runtime_state::get_next_frame);
    exception_object.cache.rethrown(true);

    // Perform an inline trivial unwind __cxa_throw:
#if defined(OPTIMIZATION_LEVEL) || 1
#if OPTIMIZATION_LEVEL == Debug || 0
    std::uint32_t const* stack_pointer = *exception_object.cpu.sp;
    stack_pointer += 5;
    exception_object.cpu.pc = stack_pointer[0];
    exception_object.cpu.sp = stack_pointer + 1;
#elif OPTIMIZATION_LEVEL == MinSizeRel || 1
    std::uint32_t const* stack_pointer = *exception_object.cpu.sp;
    exception_object.cpu.r4 = stack_pointer[0];
    exception_object.cpu.pc = stack_pointer[1];
    exception_object.cpu.sp = stack_pointer + 2;
#elif OPTIMIZATION_LEVEL == Release || 0
#endif
#endif

    // Raise exception returns when an error or call to terminate has been found
    ke::raise_exception(exception_object);
    std::terminate();
  }

  void __wrap___cxa_throw(ke::exception_ptr p_thrown_exception,
                          std::type_info* p_type_info,
                          ke::destructor_t p_destructor) noexcept(false)
  {
    ke::active_exception = p_thrown_exception;
    auto& exception_object = ke::extract_exception_object(p_thrown_exception);
    exception_object.type_info = p_type_info;
    exception_object.destructor = p_destructor;
    ke::capture_cpu_core(exception_object.cpu);

    // Perform an inline trivial unwind __cxa_throw:
#if defined(OPTIMIZATION_LEVEL)
#if OPTIMIZATION_LEVEL == Debug
    std::uint32_t const* stack_pointer = *exception_object.cpu.sp;
    exception_object.cpu.r3 = stack_pointer[0];
    exception_object.cpu.r4 = stack_pointer[1];
    exception_object.cpu.r5 = stack_pointer[2];
    exception_object.cpu.pc = stack_pointer[3];
    exception_object.cpu.sp = stack_pointer + 5;
#elif OPTIMIZATION_LEVEL == MinSizeRel
    std::uint32_t const* stack_pointer = *exception_object.cpu.sp;
    exception_object.cpu.r4 = stack_pointer[0];
    exception_object.cpu.pc = stack_pointer[1];
    exception_object.cpu.sp = stack_pointer + 2;
#elif OPTIMIZATION_LEVEL == Release
#endif
#endif

    // Raise exception returns when an error or call to terminate has been found
    ke::raise_exception(exception_object);
    std::terminate();
  }
}  // extern "C"