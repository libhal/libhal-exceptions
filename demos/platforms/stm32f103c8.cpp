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

#include <libhal-armcortex/dwt_counter.hpp>
#include <libhal-stm32f1/clock.hpp>

#include "../resource_list.hpp"

resource_list initialize_platform()
{
  using namespace hal::literals;
  hal::stm32f1::maximum_speed_using_internal_oscillator();

  auto cpu_frequency = hal::stm32f1::frequency(hal::stm32f1::peripheral::cpu);
  static hal::cortex_m::dwt_counter dwt_steady_clock(cpu_frequency);

  return {
    .clock = &dwt_steady_clock,
  };
}
