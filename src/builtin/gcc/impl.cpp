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
#include <cstdint>

#include <algorithm>
#include <exception>

#include <libhal-exceptions/control.hpp>

extern "C"
{
  void _exit([[maybe_unused]] int rc)  // NOLINT
  {
    std::terminate();
  }

  // Size of the GCC exception object header is 128 bytes. Will have to update
  // this if the size of the EO increases. 😅
  // Might need to add some GCC macro flags here to keep track of all of the
  // EO sizes over the versions.
  constexpr size_t gcc_header_size = 128;
  constexpr auto header_size = sizeof(std::size_t) + gcc_header_size;

  void* __wrap___cxa_allocate_exception(std::size_t p_size) noexcept  // NOLINT
  {
    auto const total_allocation = header_size + p_size;
    auto* exception_memory = reinterpret_cast<std::uint8_t*>(
      hal::get_exception_allocator().allocate(total_allocation));

    if (exception_memory == nullptr) {
      std::terminate();
    }

    // Required for GCC's impl to work correctly as it assumes that all bytes
    // default to 0.
    std::fill_n(exception_memory, total_allocation, 0U);

    // Set the first std::size_t bytes to the header size for deallocation
    reinterpret_cast<std::size_t*>(exception_memory)[0] = total_allocation;

    // Return the pointer to the memory after the header, which is the start of
    // the thrown object's allocated memory.
    return exception_memory + header_size;
  }

  void __wrap___cxa_call_unexpected(void*)  // NOLINT
  {
    std::terminate();
  }

  void __wrap___cxa_free_exception(void* p_exception) noexcept  // NOLINT
  {
    auto* exception = reinterpret_cast<std::uint8_t*>(p_exception);
    auto* original_pointer = exception - header_size;
    auto exception_size = *reinterpret_cast<std::size_t*>(original_pointer);
    hal::get_exception_allocator().deallocate(original_pointer, exception_size);
  }
}  // extern "C"
