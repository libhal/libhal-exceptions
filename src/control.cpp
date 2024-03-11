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

#include <array>
#include <cstdint>
#include <exception>

#include <libhal-exceptions/control.hpp>

namespace __cxxabiv1 {                                // NOLINT
std::terminate_handler __terminate_handler = +[]() {  // NOLINT
  while (true) {
    continue;
  }
};
}

namespace hal {
std::terminate_handler set_terminate(
  std::terminate_handler p_terminate_handler) noexcept
{
  auto copy = __cxxabiv1::__terminate_handler;
  __cxxabiv1::__terminate_handler = p_terminate_handler;
  return copy;
}

std::terminate_handler get_terminate() noexcept
{
  return __cxxabiv1::__terminate_handler;
}

// TODO(#11): Add macro to IFDEF this out if the user want to save 256 bytes.
using default_exception_allocator = single_thread_exception_allocator<256>;
default_exception_allocator _default_allocator{};                 // NOLINT
exception_allocator* _exception_allocator = &_default_allocator;  // NOLINT

void set_exception_allocator(exception_allocator& p_allocator) noexcept
{
  _exception_allocator = &p_allocator;
}

exception_allocator* get_exception_allocator() noexcept
{
  return _exception_allocator;
}
}  // namespace hal
