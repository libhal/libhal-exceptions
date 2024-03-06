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

#pragma once

#include <cstddef>
#include <cstdint>
#include <exception>
#include <span>

namespace hal {
/**
 * @brief Interface for an object that allocates memory specifically for
 * exceptions
 *
 */
class exception_allocator
{
public:
  /**
   * @brief Allocate/retrieve memory for the exception object allocation
   *
   * If memory has run out, this function must return an empty span.
   *
   * @param p_size - Amount of memory to be allocated
   * @return std::span<std::uint8_t> - block of memory equal to or greater than
   * the size of p_size or and empty span if no memory is available.
   */
  std::span<std::uint8_t> allocate(std::size_t p_size) noexcept
  {
    return do_allocate(p_size);
  }

  /**
   * @brief Deallocate the memory for the exception object
   *
   * @param p_exception_object - pointer to the allocated exception object
   */
  void deallocate(void* p_exception_object) noexcept
  {
    do_deallocate(p_exception_object);
  }

  virtual ~exception_allocator() = default;

private:
  virtual std::span<std::uint8_t> do_allocate(std::size_t p_size) noexcept = 0;
  virtual void do_deallocate(void* p_exception_object) noexcept = 0;
};

/**
 * @brief Set the global exception allocator function
 *
 * More details on how you should use this API to come in the future.
 *
 * @param p_allocator - exception memory allocator implementation
 */
void set_exception_allocator(exception_allocator& p_allocator) noexcept;

/**
 * @brief Set the terminate handler
 *
 * @param p_terminate_handler - new global terminate handler
 */
std::terminate_handler set_terminate(
  std::terminate_handler p_terminate_handler) noexcept;

/**
 * @brief Get the terminate handler
 *
 * @return std::terminate_handler - the currently set terminate handler
 */
std::terminate_handler get_terminate() noexcept;

/**
 * @brief Simple single threaded exception allocator
 *
 * @tparam size - size of the exception object memory buffer. If this is set too
 * small (less than 128 bytes), then it is likely that the memory will not be
 * enough for any exception runtime and will result in terminate being called.
 */
template<size_t size>
class single_thread_exception_allocator : public exception_allocator
{
public:
  single_thread_exception_allocator() = default;
  ~single_thread_exception_allocator() override = default;

private:
  std::span<std::uint8_t> do_allocate(std::size_t p_size) noexcept override
  {
    if (m_allocated || p_size > m_buffer.size()) {
      return {};
    }
    m_allocated = true;
    return m_buffer;
  }

  void do_deallocate(
    [[maybe_unused]] void* p_exception_object) noexcept override
  {
    m_allocated = false;
  }

  std::array<std::uint8_t, size> m_buffer{};
  bool m_allocated = false;
};
}  // namespace hal