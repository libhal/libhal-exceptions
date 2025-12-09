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
#include <libhal-arm-mcu/lpc40/clock.hpp>

#include <resource_list.hpp>

hal::cortex_m::dwt_counter* counter;

void initialize_platform()
{
  using namespace hal::literals;

  // Set the MCU to the maximum clock speed
#ifndef DEBUG
  hal::lpc40::maximum(12.0_MHz);
#endif

  static hal::cortex_m::dwt_counter dwt_steady_clock(
    hal::lpc40::get_frequency(hal::lpc40::peripheral::cpu));

  counter = &dwt_steady_clock;
}

hal::u64 get_uptime()
{
  return counter->uptime();
}
