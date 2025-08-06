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

#include <cstddef>
#include <libhal-arm-mcu/dwt_counter.hpp>
#include <libhal-arm-mcu/stm32f1/clock.hpp>
#include <libhal-arm-mcu/stm32f1/constants.hpp>
#include <libhal-arm-mcu/stm32f1/gpio.hpp>
#include <libhal-arm-mcu/stm32f1/uart.hpp>
#include <libhal-exceptions/control.hpp>
#include <libhal-util/serial.hpp>
#include <libhal-util/steady_clock.hpp>

#include <platform.hpp>

using output_pin =
  decltype(hal::stm32f1::gpio<hal::stm32f1::peripheral::gpio_a>()
             .acquire_output_pin(0));

output_pin* time_signal = nullptr;
hal::serial* analyzer_serial = nullptr;
hal::cortex_m::dwt_counter* counter = nullptr;

template<std::size_t N>
class single_block_memory_resource : public std::pmr::memory_resource
{
public:
  single_block_memory_resource() = default;

private:
  void* do_allocate(std::size_t p_bytes, std::size_t) override
  {
    if (m_allocated || p_bytes > N) {
      std::terminate();
    }
    m_allocated = true;
    return m_buffer.data();
  }

  void do_deallocate(void* p_ptr, std::size_t, std::size_t) override
  {
    if (p_ptr != m_buffer.data()) {
      std::terminate();
    }
    m_buffer.fill(0);
    m_allocated = false;
  }

  [[nodiscard]] bool do_is_equal(
    std::pmr::memory_resource const& other) const noexcept override
  {
    return this == &other;
  }

private:
  alignas(std::max_align_t) std::array<hal::byte, N> m_buffer;
  bool m_allocated = false;
};

single_block_memory_resource<256> exception_memory_resource{};

void initialize_platform()
{
  using namespace std::literals;
  using namespace hal::literals;
  hal::stm32f1::maximum_speed_using_internal_oscillator();
  hal::set_terminate([]() {
    while (true) {
      continue;
    }
  });

  hal::set_exception_allocator(exception_memory_resource);

  static hal::stm32f1::gpio<hal::stm32f1::peripheral::gpio_a> gpio_a;
  static auto signal_pin = gpio_a.acquire_output_pin(0);
  time_signal = &signal_pin;

  static hal::cortex_m::dwt_counter dwt_steady_clock(
    hal::stm32f1::frequency(hal::stm32f1::peripheral::cpu));
  counter = &dwt_steady_clock;

  hal::delay(dwt_steady_clock, 1ms);

  start();
  end();
  start();
  end();
  start();
  end();
  start();
  end();
  start();
  end();
  pause();

  static hal::stm32f1::uart serial(hal::port<1>, hal::buffer<128>);
  analyzer_serial = &serial;
}

void log_start(std::string_view p_message)
{
  hal::print<64>(*analyzer_serial, "%.*s", p_message.size(), p_message.data());
}

std::array<hal::u64, 100> cycles{};
auto cycle_index = 0Uz;
constexpr auto use_cycle_counter = true;

void start()
{
  if constexpr (use_cycle_counter) {
    // Set time stamp at this index to the current uptime
    cycles[cycle_index] = counter->uptime();
  } else {
    time_signal->level(false);
  }
}

void pause()
{
  using namespace std::literals;
  hal::delay(*counter, 1ms);
}

void end()
{
  if constexpr (use_cycle_counter) {
    // Subtract the current uptime from the previous to get the time
    cycles[cycle_index] = counter->uptime() - cycles[cycle_index];
    cycle_index++;
  } else {
    time_signal->level(true);
  }
}

void end_benchmark()
{
  while (true) {
    continue;
  }
}

// libhal-arm-mcu specific APIs defined to reduce code size
extern "C"
{
  // This gets rid of an issue with libhal-exceptions in Debug mode.
  void __assert_func()  // NOLINT
  {
  }
}

// Override global new operator
void* operator new(std::size_t)
{
  std::terminate();
}

// Override global new[] operator
void* operator new[](std::size_t)
{
  std::terminate();
}

void* operator new(unsigned int, std::align_val_t)
{
  std::terminate();
}

// Override global delete operator
void operator delete(void*) noexcept
{
}

// Override global delete[] operator
void operator delete[](void*) noexcept
{
}

// Optional: Override sized delete operators (C++14 and later)
void operator delete(void*, std::size_t) noexcept
{
}

void operator delete[](void*, std::size_t) noexcept
{
}

void operator delete[](void*, std::align_val_t) noexcept
{
}

void operator delete(void*, std::align_val_t) noexcept
{
}
