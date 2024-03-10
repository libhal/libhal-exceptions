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
  // So you may be wondering what this code is doing here? Its actually a
  // bit of weird circular logic. So the linker will garbage collect any
  // functions that are not used in your code. If you somehow have an
  // application without any exceptions thrown, the exception code will be
  // eliminated. This would be great, but due the fact that our build system
  // adds the `-Wl,--wrap=symbol` to the compiler to swap the function
  // implementations, this results in the compiler yelling at the user that
  // they are missing a wrapped function. In order to prevent the compiler
  // from throwing away this function and then turning around demanding that
  // we supply it, we simply need to call throw somewhere in the code. That
  // will force it to link in the original implementations which will be
  // swapped out with our wrapped implementations.
  //
  // Use a volatile bool that is always set to false to ensure that the
  // "throw 5" is NEVER called.
  //
  // This location was choosen because it always links in for GCC.
  volatile bool force_exceptions_to_link = false;
  if (force_exceptions_to_link) {
    throw 5;
  }

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
using default_single_thread_exception_allocator =
  single_thread_exception_allocator<256>;

default_single_thread_exception_allocator default_allocator{};
exception_allocator* __exception_allocator = &default_allocator;  // NOLINT

void set_exception_allocator(exception_allocator& p_allocator) noexcept
{
  __exception_allocator = &p_allocator;
}

exception_allocator* get_exception_allocator() noexcept
{
  return __exception_allocator;
}
}  // namespace hal