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

#include <cinttypes>
#include <cstddef>

#include <libhal-arm-mcu/dwt_counter.hpp>
#include <libhal-arm-mcu/lpc40/clock.hpp>
#include <libhal-arm-mcu/lpc40/output_pin.hpp>
#include <libhal-arm-mcu/lpc40/uart.hpp>
#include <libhal-exceptions/control.hpp>
#include <libhal-util/serial.hpp>
#include <libhal-util/steady_clock.hpp>

#include <platform.hpp>

hal::lpc40::output_pin* time_signal = nullptr;
hal::serial* analyzer_serial = nullptr;
hal::cortex_m::dwt_counter* counter = nullptr;

void initialize_platform()
{
  using namespace hal::literals;
  using namespace std::literals;

  // Set the MCU to the maximum clock speed
  hal::lpc40::maximum(12.0_MHz);

  static hal::cortex_m::dwt_counter dwt_steady_clock(
    hal::lpc40::get_frequency(hal::lpc40::peripheral::cpu));

  counter = &dwt_steady_clock;

  hal::delay(*counter, 1ms);

  static hal::lpc40::output_pin signal(1, 15);
  time_signal = &signal;

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

  static std::array<hal::byte, 64> uart0_buffer{};
  static hal::lpc40::uart console(0,
                                  uart0_buffer,
                                  hal::serial::settings{
                                    .baud_rate = 115200,
                                  });
  analyzer_serial = &console;
}

void log_start(std::string_view p_message)
{
  hal::print<64>(*analyzer_serial, "%.*s", p_message.size(), p_message.data());
}

std::array<hal::u64, 100> cycles{};
auto cycle_index = 0Uz;
constexpr auto use_cycle_counter = false;

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

hal::u64 search_time = 0;

void start_sub()
{
  search_time = counter->uptime();
}

void end_sub()
{
  search_time = counter->uptime() - search_time;
  hal::print<64>(*analyzer_serial, "search_time = %" PRIu64 "\n", search_time);
}

void end_benchmark()
{
  while (true) {
    continue;
  }
}

hal::u64 get_uptime()
{
  return counter->uptime();
}

// libhal-arm-mcu specific APIs defined to reduce code size
extern "C"
{
  // This gets rid of an issue with libhal-exceptions in Debug mode.

  void __assert_func(char const*, int, char const*, char const*)  // NOLINT
  {
    while (true) {
      continue;
    }
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
