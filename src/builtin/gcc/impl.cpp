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

#include <cstdint>

#include <algorithm>
#include <array>
#include <exception>
#include <span>

#include <libhal-exceptions/control.hpp>

#include "../../internal.hpp"

extern "C"
{
  void _exit([[maybe_unused]] int rc)  // NOLINT
  {
    std::terminate();
  }

  void* __wrap___cxa_allocate_exception(unsigned int p_size) noexcept  // NOLINT
  {
    // Size of the GCC exception object header is 128 bytes. Will have to update
    // this if the size of the EO increases. 😅
    // Might need to add some GCC macro flags here to keep track of all of the
    // EO sizes over the versions.
    constexpr size_t header_size = 128;

    auto exception_memory =
      hal::get_exception_allocator().allocate(header_size + p_size);

    if (exception_memory.empty()) {
      std::terminate();
    }

    // Required for GCC's impl to work correctly as it assumes that all bytes
    // default to 0. The Estell impl will utilize the same technique.
    auto trimmed_memory = exception_memory.first(header_size + p_size);
    std::fill(trimmed_memory.begin(), trimmed_memory.end(), 0U);

    // Return the pointer to the memory after the header, which is the start of
    // the thrown object's allocated memory.
    return trimmed_memory.data() + header_size;
  }

  void __wrap___cxa_call_unexpected(void*)  // NOLINT
  {
    std::terminate();
  }

  void __wrap___cxa_free_exception(void* p_exception) noexcept  // NOLINT
  {
    hal::get_exception_allocator().deallocate(p_exception);
  }
}  // extern "C"
