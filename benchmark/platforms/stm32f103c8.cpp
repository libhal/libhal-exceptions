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

#include <libhal-arm-mcu/dwt_counter.hpp>
#include <libhal-arm-mcu/stm32f1/clock.hpp>
#include <libhal-arm-mcu/stm32f1/constants.hpp>
#include <libhal-arm-mcu/stm32f1/gpio.hpp>
#include <libhal-arm-mcu/stm32f1/uart.hpp>
#include <libhal-util/serial.hpp>
#include <libhal-util/steady_clock.hpp>

using output_pin =
  decltype(hal::stm32f1::gpio<hal::stm32f1::peripheral::gpio_a>()
             .acquire_output_pin(0));

output_pin* time_signal = nullptr;
hal::serial* analyzer_serial = nullptr;
hal::cortex_m::dwt_counter* counter = nullptr;

void initialize_platform()
{
  using namespace std::literals;
  using namespace hal::literals;
  hal::stm32f1::maximum_speed_using_internal_oscillator();

  static hal::stm32f1::gpio<hal::stm32f1::peripheral::gpio_a> gpio_a;
  static auto signal_pin = gpio_a.acquire_output_pin(0);
  time_signal = &signal_pin;

  time_signal->level(true);
  time_signal->level(false);
  time_signal->level(true);
  time_signal->level(false);
  time_signal->level(true);
  time_signal->level(false);
  time_signal->level(true);
  time_signal->level(false);
  time_signal->level(true);
  time_signal->level(false);
  time_signal->level(true);

  static hal::cortex_m::dwt_counter dwt_steady_clock(
    hal::stm32f1::frequency(hal::stm32f1::peripheral::cpu));
  counter = &dwt_steady_clock;

  hal::delay(dwt_steady_clock, 1ms);

  static hal::stm32f1::uart serial(hal::port<1>, hal::buffer<128>);
  analyzer_serial = &serial;
}

void log_start(std::string_view p_message)
{
  hal::print<64>(*analyzer_serial, "%.*s", p_message.size(), p_message.data());
}

void start()
{
  time_signal->level(false);
}

void pause()
{
  using namespace std::literals;
  hal::delay(*counter, 1ms);
}

void end()
{
  time_signal->level(true);
}

void end_benchmark()
{
  while (true) {
    continue;
  }
}
