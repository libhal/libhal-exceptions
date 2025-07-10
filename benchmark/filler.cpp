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

/**
 * @file filler.cpp
 *
 * This file includes filler functions which are added to both result and
 * exceptions. The hypothesis and expectation is that the additional functions
 * will have no effect on the result experiment and will have an effect on the
 * exceptions experiment. Exceptions are effected because exceptions perform a
 * binary search through the exception index to find the handling info for each
 * function.
 *
 */

#include <platform.hpp>

void link_filler_functions()
{
  // TODO(79): Fill in file with linker information
}
