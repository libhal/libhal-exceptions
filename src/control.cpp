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
#include <memory_resource>

namespace __cxxabiv1 {                                // NOLINT
std::terminate_handler __terminate_handler = +[]() {  // NOLINT
  while (true) {
    continue;
  }
};
}  // namespace __cxxabiv1

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

/**
 * @brief Simple exception allocator
 *
 * This allocator can only allocates space for a single exception object at a
 * time.
 *
 * @tparam size - size of the exception object memory buffer. If this is set too
 * small (less than 128 bytes), then it is likely that the memory will not be
 * enough for any exception runtime and will result in terminate being called.
 */
template<size_t size>
class single_exception_allocator : public std::pmr::memory_resource
{
public:
  single_exception_allocator() = default;
  ~single_exception_allocator() = default;

private:
  void* do_allocate(std::size_t p_size,
                    [[maybe_unused]] std::size_t p_alignment) override
  {
    if (m_allocated || p_size > m_buffer.size()) {
      return nullptr;
    }
    m_allocated = true;
    return m_buffer.data();
  }

  void do_deallocate(void* p_address,
                     [[maybe_unused]] std::size_t p_size,
                     [[maybe_unused]] std::size_t p_alignment) override
  {
    if (p_address != m_buffer.data()) {
      std::terminate();
    }
    m_allocated = false;
  }

  bool do_is_equal(
    std::pmr::memory_resource const& other) const noexcept override
  {
    return this == &other;
  }

  std::array<std::uint8_t, size> m_buffer{};
  bool m_allocated = false;
};

// TODO(#11): Add macro to IFDEF this out if the user want to save 256 bytes.
using default_exception_allocator = single_exception_allocator<256>;
default_exception_allocator _default_allocator{};  // NOLINT
std::pmr::memory_resource* _exception_allocator =
  &_default_allocator;  // NOLINT

void set_exception_allocator(std::pmr::memory_resource* p_allocator) noexcept
{
  _exception_allocator = p_allocator;
}

std::pmr::memory_resource& get_exception_allocator() noexcept
{
  return *_exception_allocator;
}
}  // namespace hal
