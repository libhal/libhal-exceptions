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

#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <exception>

#include "bit.hpp"

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

  register_t(const void* p_data)
    : data(reinterpret_cast<std::uint32_t>(p_data))
  {
  }

  operator std::uint32_t() const
  {
    return data;
  }

  const std::uint32_t* operator*()
  {
    return reinterpret_cast<const std::uint32_t*>(data);
  }
};

namespace arm_ehabi {
constexpr std::uint8_t finish = 0xb0;
constexpr std::uint32_t end_descriptor = 0x0000'0000;
constexpr std::uint32_t su16_mask = 0b1111'1111'1111'1110;
}  // namespace arm_ehabi

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

  bool operator<(const function_t& p_other) const
  {
    return address < p_other.address;
  }

  bool operator==(const function_t& p_other) const
  {
    return address == p_other.address;
  }
};

struct index_entry_t
{
  std::uint32_t function_offset;
  std::uint32_t personality_offset;

  bool has_inlined_personality() const;
  bool is_noexcept() const;
  bool short_instructions() const;
  const std::uint32_t* personality() const;
  const std::uint32_t* lsda_data() const;
  const std::uint32_t* descriptor_start() const;
  function_t function() const;
};

struct cortex_m_cpu
{
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

enum class runtime_state : std::uint8_t
{
  get_next_frame = 0,
  gcc_lsda_cleanup_catch_phase = 1,
  unwind_frame = 2,
};

struct cache_t
{
  std::uint32_t state_and_rel_address;
  const index_entry_t* entry_ptr = nullptr;

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

  constexpr runtime_state state() const
  {
    auto state_integer = hal::bit_extract<state_mask>(state_and_rel_address);
    return static_cast<runtime_state>(state_integer);
  }

  constexpr std::uint32_t relative_address() const
  {
    return hal::bit_extract<relative_address_mask>(state_and_rel_address);
  }

  constexpr void state(runtime_state p_state)
  {
    auto state_int = static_cast<std::uint8_t>(p_state);
    hal::bit_modify(state_and_rel_address).insert<state_mask>(state_int);
  }

  constexpr void rethrown(bool p_rethrown)
  {
    hal::bit_modify(state_and_rel_address).insert<rethrown_mask>(p_rethrown);
  }

  constexpr bool rethrown() const
  {
    return hal::bit_extract<rethrown_mask>(state_and_rel_address);
  }

  constexpr void relative_address(std::uint32_t p_rel_address)
  {
    hal::bit_modify(state_and_rel_address)
      .insert<relative_address_mask>(p_rel_address);
  }
};

struct exception_object
{
  cortex_m_cpu cpu{};
  std::type_info* type_info = nullptr;
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

inline void* extract_thrown_object(void* p_exception_object)
{
  auto object_address = reinterpret_cast<std::intptr_t>(p_exception_object);
  auto start_of_thrown = object_address + sizeof(exception_object);
  return reinterpret_cast<exception_object*>(start_of_thrown);
}

[[gnu::always_inline]] inline void restore_cpu_core(
  ke::cortex_m_cpu& p_cpu_core)
{
  asm volatile(
    "ldr r0, [%[regs], #0]\n"  // Load R0
    "ldr r1, [%[regs], #4]\n"  // Load R1
    "ldr r2, [%[regs], #8]\n"  // Load R2
    // "ldr r3, [%[regs], #12]\n"   // Load R3
    "ldr r4, [%[regs], #16]\n"   // Load R4
    "ldr r5, [%[regs], #20]\n"   // Load R5
    "ldr r6, [%[regs], #24]\n"   // Load R6
    "ldr r7, [%[regs], #28]\n"   // Load R7
    "ldr r8, [%[regs], #32]\n"   // Load R8
    "ldr r9, [%[regs], #36]\n"   // Load R9
    "ldr r10, [%[regs], #40]\n"  // Load R10
    "ldr r11, [%[regs], #44]\n"  // Load R11
    "ldr r12, [%[regs], #48]\n"  // Load R12
    // Stack Pointer (R13/SP) and Link Register (R14/LR) require special
    // handling
    "ldr sp, [%[regs], #52]\n"  // Load SP
    "ldr lr, [%[regs], #56]\n"  // Load LR
    // PC and xPSR restoration is more complex due to ARM's execution state and
    // alignment requirements Directly loading PC can be dangerous and is
    // typically managed through a pop or an exception return mechanism
    "ldr pc, [%[regs], #60]\n"
    :
    : [regs] "r"(&p_cpu_core)
    : "memory",
      "r0",
      "r1",
      "r2",
      // "r3",
      "r4",
      "r5",
      "r6",
      "r7",
      "fp",
      "r8",
      "r9",
      "r10",
      "r11",
      "r12");
}

constexpr std::uint32_t to_absolute_address(const void* p_object)
{
  constexpr auto signed_bit_31 = hal::bit_mask::from<30>();
  constexpr auto signed_bit_32 = hal::bit_mask::from<31>();
  auto object_address = reinterpret_cast<std::int32_t>(p_object);
  auto offset = *reinterpret_cast<const std::uint32_t*>(p_object);

  // Sign extend the offset to 32-bits
  if (hal::bit_extract<signed_bit_31>(offset)) {
    hal::bit_modify(offset).set<signed_bit_32>();
  } else {
    hal::bit_modify(offset).clear<signed_bit_32>();
  }

  auto signed_offset = static_cast<std::int32_t>(offset);
  std::int32_t final_address = object_address + signed_offset;
  return static_cast<std::uint32_t>(final_address);
}

[[gnu::used]] inline std::uint32_t runtime_to_absolute_address(
  const void* p_object)
{
  return to_absolute_address(p_object);
}

inline std::uint32_t* to_absolute_address_ptr(const void* p_object)
{
  return reinterpret_cast<std::uint32_t*>(to_absolute_address(p_object));
}
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
  extern std::uint32_t __exidx_start;
  extern std::uint32_t __exidx_end;
  extern std::uint32_t __extab_start;
  extern std::uint32_t __extab_end;
}