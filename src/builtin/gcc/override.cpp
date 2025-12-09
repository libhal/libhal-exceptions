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

#include <exception>

namespace __cxxabiv1 {  // NOLINT
/**
 * @brief Implementation of the terminate handler that simply halts
 *
 * This will override the weak symbol used in GCC's exception runtime. The
 * original implementation prints a message to stdout for the user. The code
 * that performs the message rendering can result in 40kb to 80kB added to ROM.
 * By replacing that symbol with one that does nothing besides halt, all of
 * those dependencies on those functions are unnecessary and can be garbage
 * collected.
 *
 * NOTE: If for some reason in the future, this stops working or the linker
 * complains of duplicate symbols, then we should wrap the symbol using.
 * `-Wl,--wrap=__terminate_handler`
 *
 */
std::terminate_handler __terminate_handler = +[]() {  // NOLINT
  while (true) {
    continue;
  }
};
}  // namespace __cxxabiv1
