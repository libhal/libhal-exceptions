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

#pragma once

#include <array>
#include <bit>
#include <cstddef>
#include <cstdint>
#include <exception>
#include <typeinfo>

#include <libhal-util/bit.hpp>

namespace ke {
using exception_ptr = void*;
exception_ptr current_exception() noexcept;

using destructor_t = void(void*);

struct register_t
{
  std::uint32_t data;

  register_t()
    : data(0)
  {
  }

  register_t(std::uint32_t p_data)
    : data(p_data)
  {
  }

  register_t(void const* p_data)
    : data(reinterpret_cast<std::uint32_t>(p_data))
  {
  }

  operator std::uint32_t() const
  {
    return data;
  }

  std::uint32_t* operator*()
  {
    return reinterpret_cast<std::uint32_t*>(data);
  }
};

namespace arm_ehabi {
constexpr std::uint8_t finish = 0xb0;
constexpr std::uint32_t end_descriptor = 0x0000'0000;
constexpr std::uint32_t su16_mask = 0b1111'1111'1111'1110;
}  // namespace arm_ehabi

inline std::uint32_t to_absolute_address(void const* p_object)
{
  auto const object_address = std::bit_cast<std::int32_t>(p_object);
  auto offset = *std::bit_cast<std::int32_t const*>(p_object);

  // Shift bits to the end
  offset <<= 1;
  // Arithmetic shift to the right to sign extend.
  offset >>= 1;

  auto const final_address = object_address + offset;
  return static_cast<std::uint32_t>(final_address);
}

[[gnu::used]] inline std::uint32_t runtime_to_absolute_address(
  void const* p_object)
{
  return to_absolute_address(p_object);
}

inline std::uint32_t* to_absolute_address_ptr(void const* p_object)
{
  return std::bit_cast<std::uint32_t*>(to_absolute_address(p_object));
}

// This is only to make GDB debugging easier, the functions are never actually
// called so it is not important to include the correct types.
struct function_t
{
  using callable_t = void();

  callable_t* address;

  function_t(std::uint32_t p_address)
    : address(reinterpret_cast<callable_t*>(p_address))
  {
  }

  operator std::uint32_t()
  {
    return reinterpret_cast<std::uint32_t>(address);
  }

  operator void*()
  {
    return reinterpret_cast<void*>(address);
  }

  bool operator<(function_t const& p_other) const
  {
    return address < p_other.address;  // NOLINT
  }

  bool operator==(function_t const& p_other) const
  {
    return address == p_other.address;
  }
};

namespace su16 {
constexpr auto instruction0 = hal::bit_mask{ .position = 16, .width = 8 };
constexpr auto instruction1 = hal::bit_mask{ .position = 8, .width = 8 };
constexpr auto instruction2 = hal::bit_mask{ .position = 0, .width = 8 };
}  // namespace su16

namespace lu16_32 {
constexpr auto length = hal::bit_mask::from<16, 23>();
constexpr auto instruction0 = hal::bit_mask::from<15, 8>();
constexpr auto instruction1 = hal::bit_mask::from<7, 0>();
constexpr auto instruction2 = hal::bit_mask::from<31, 24>();
constexpr auto instruction3 = hal::bit_mask::from<23, 16>();
constexpr auto instruction4 = hal::bit_mask::from<15, 8>();
constexpr auto instruction5 = hal::bit_mask::from<7, 0>();
constexpr auto instruction6 = hal::bit_mask::from<24, 31>();
}  // namespace lu16_32

struct index_entry_t
{
  std::uint32_t function_offset;
  std::uint32_t personality_offset;

  [[gnu::always_inline]] inline constexpr bool has_inlined_personality() const
  {
    // 31st bit is `1` when the personality/unwind information is inlined, other
    // otherwise, personality_offset is an offset.
    constexpr auto mask = hal::bit_mask::from<31>();
    return hal::bit_extract<mask>(personality_offset);
  }

  [[gnu::always_inline]] inline bool is_noexcept() const
  {
    return personality_offset == 0x1;
  }

  [[gnu::always_inline]] inline std::uint32_t const* personality() const
  {
    return to_absolute_address_ptr(&personality_offset);
  }

  [[gnu::always_inline]] static inline std::uint32_t const* lsda_data(
    std::uint32_t const* p_personality)
  {
    constexpr auto personality_type = hal::bit_mask::from<24, 27>();
    // +1 to skip the prel31 offset to the personality function
    auto const* header = p_personality + 1;
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

  /**
   * @brief Returns the pointer to the personality's descriptor data
   *
   * Descriptor data is data that comes after the unwind instructions.
   *
   * @param p_personality - pointer to the function's personality data within
   * the exception table.
   * @return std::uint32_t const* - pointer to the descriptor start area. Always
   * valid so long as p_personality is valid.
   */
  [[gnu::always_inline]] inline static std::uint32_t const* descriptor_start(
    std::uint32_t const* p_personality)
  {
    constexpr hal::bit_mask personality_type_mask{ .position = 24, .width = 4 };
    auto const type = hal::bit_extract<personality_type_mask>(*p_personality);

    // If the personality type is 0 (SU16), then the descriptor start is right
    // after the first word.
    if (type == 0) {
      return p_personality + 1;
    }

    // The limit for ARM exceptions instructions is 7. LD optimizes the ARM
    // exception spec by removing the "word length" specifier allowing the
    // instructions to fit in 2 words.
    return p_personality + 2;
  }

  [[gnu::always_inline]] function_t function() const
  {
    return function_t(to_absolute_address(&function_offset));
  }
};

struct cortex_m_cpu
{
  // NOTE: We could consider removing r0 to r3. Technically, these are not
  // callee preserved. We also destroy the state of R0 and R1 when we drop into
  // a function to either run destructors or to execute a catch block.
  //
  // The only real issue issue is vsp = r[nnnn] where `nnnn` can be 0
  // to 3. Pop r0 to r3 could be instructions we ignore by moving the stack
  // pointer but ignoring the results. For now, we will support all operations
  // on these registers until we know we can safely remove them.
  register_t r0;
  register_t r1;
  register_t r2;
  register_t r3;
  register_t r4;
  register_t r5;
  register_t r6;
  register_t r7;
  register_t r8;
  register_t r9;
  register_t r10;
  register_t r11;
  register_t ip;
  register_t sp;
  register_t lr;
  register_t pc;

  register_t& operator[](size_t p_size)
  {
    using register_file = std::array<register_t, 16>;
    static_assert(sizeof(cortex_m_cpu) == sizeof(register_file));
    static_assert(sizeof(std::uint32_t) == sizeof(register_t));

    register_file* file = reinterpret_cast<register_file*>(this);
    return (*file)[p_size];
  }
};

enum class runtime_state : std::uint8_t
{
  get_next_frame = 0,
  enter_function = 1,
  unwind_frame = 2,
  // TODO(#37): Add handled state
};

struct cache_t
{
  index_entry_t const* entry_ptr = nullptr;
  std::uint32_t const* personality = nullptr;
  std::uint32_t rel_address;
  runtime_state inner_state;
  bool previously_rethrown = false;

  static constexpr auto state_mask = hal::bit_mask{
    .position = 24,
    .width = 4,
  };
  static constexpr auto rethrown_mask = hal::bit_mask{
    .position = 28,
    .width = 1,
  };
  static constexpr auto relative_address_mask = hal::bit_mask{
    .position = 0,
    .width = 24,
  };

  constexpr inline runtime_state state() const
  {
    return inner_state;
  }

  constexpr inline std::uint32_t relative_address() const
  {
    return rel_address;
  }

  constexpr inline void state(runtime_state p_state)
  {
    inner_state = p_state;
  }

  constexpr inline void rethrown(bool p_rethrown)
  {
    previously_rethrown = p_rethrown;
  }

  constexpr inline bool rethrown() const
  {
    return previously_rethrown;
  }

  constexpr inline void relative_address(std::uint32_t p_rel_address)
  {
    rel_address = p_rel_address;
  }
};

struct base_class_type_info
{
  void const* type_info = nullptr;
  std::int32_t offset = 0;
};

template<std::size_t max_count>
struct flattened_hierarchy
{
  static_assert(max_count > 0);
  static constexpr auto capacity = max_count;

  std::array<base_class_type_info, max_count> bases{};
  std::uint32_t size = 0;

  explicit flattened_hierarchy(std::type_info const* p_info)
  {
    bases[0].type_info = p_info;
    bases[0].offset = 0;
    size++;
  }

  flattened_hierarchy()
  {
  }

  auto begin()
  {
    return bases.begin();
  }

  auto end()
  {
    return bases.begin() + size;
  }

  auto cbegin() const
  {
    return bases.cbegin();
  }

  auto cend() const
  {
    return bases.cbegin() + size;
  }

  void push_back(base_class_type_info const& p_info)
  {
    if (size > max_count) {
      std::terminate();
    }
    bases[size++] = p_info;
  }
};

struct exception_object
{
  cortex_m_cpu cpu{};
  flattened_hierarchy<12> type_info{};
  std::size_t choosen_type_offset = 0;
  destructor_t* destructor = nullptr;
  cache_t cache{};
};

constexpr size_t exception_object_size = sizeof(exception_object);

exception_object& get_exception_object(void* p_thrown_exception);

inline exception_object& extract_exception_object(void* p_thrown_exception)
{
  auto thrown_address = reinterpret_cast<std::intptr_t>(p_thrown_exception);
  auto start_of_exception_object = thrown_address - sizeof(exception_object);
  return *reinterpret_cast<exception_object*>(start_of_exception_object);
}

inline void* extract_thrown_object(exception_object* p_exception_object)
{
  auto object_address = reinterpret_cast<std::intptr_t>(p_exception_object);
  auto start_of_thrown = object_address + sizeof(exception_object) +
                         p_exception_object->choosen_type_offset;
  return reinterpret_cast<void*>(start_of_thrown);
}

inline constexpr auto eo_size = sizeof(exception_object);
}  // namespace ke

struct [[gnu::packed]] su16_t
{
  std::uint8_t instruction0 : 8;
  std::uint8_t instruction1 : 8;
  std::uint8_t instruction2 : 8;
  std::uint8_t type : 4;
  std::uint8_t reserved : 3;
  std::uint8_t handler_data_flag : 1;
};

struct [[gnu::packed]] lu_t
{
  std::uint8_t instruction0 : 8;
  std::uint8_t instruction1 : 8;
  std::uint8_t length : 8;
  std::uint8_t type : 4;
  std::uint8_t reserved : 3;
  std::uint8_t handler_data_flag : 1;
};

extern "C"
{
  extern ke::index_entry_t __exidx_start;
  extern ke::index_entry_t __exidx_end;
  extern std::uint32_t __extab_start;
  extern std::uint32_t __extab_end;
}
