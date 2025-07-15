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
#include <array>
#include <exception>
#include <memory_resource>

#include <libhal-exceptions/control.hpp>

namespace {

// Size of the GCC exception object header is 128 bytes. Will have to update
// this if the size of the EO increases. 😅
// Might need to add some GCC macro flags here to keep track of all of the
// EO sizes over the versions.
constexpr size_t gcc_header_size = 128;

template<typename T = std::byte>
struct exception_allocation
{
  std::size_t size;
  std::array<std::byte, gcc_header_size> header;
  alignas(std::max_align_t) T data;
};

template<typename T = std::byte>
exception_allocation<T>* get_allocation_from_exception(void* p_exception_ptr)
{
  auto const member_offset = offsetof(exception_allocation<T>, data);
  auto const exception_bytes = static_cast<std::byte*>(p_exception_ptr);
  return reinterpret_cast<exception_allocation<T>*>(exception_bytes -
                                                    member_offset);
}

}  // namespace

extern "C"
{
  void _exit([[maybe_unused]] int rc)  // NOLINT
  {
    std::terminate();
  }

  void* __wrap___cxa_allocate_exception(std::size_t p_size) noexcept  // NOLINT
  {

    auto const allocation_amount = sizeof(exception_allocation<>) + p_size;
    auto exception_memory_resource = &hal::get_exception_allocator();

    auto* object = static_cast<exception_allocation<>*>(
      exception_memory_resource->allocate(allocation_amount));

    if (object == nullptr) {
      std::terminate();
    }

    // Required for GCC's impl to work correctly as it assumes that all bytes
    // default to 0.
    object->header.fill(std::byte{ 0 });
    object->size = allocation_amount;
    return &object->data;
  }

  void __wrap___cxa_call_unexpected(void*)  // NOLINT
  {
    std::terminate();
  }

  void __wrap___cxa_free_exception(void* p_exception) noexcept  // NOLINT
  {
    auto* object = get_allocation_from_exception(p_exception);
    hal::get_exception_allocator().deallocate(object, object->size);
  }
}  // extern "C"

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
 */
class single_exception_allocator : public std::pmr::memory_resource
{
public:
  single_exception_allocator() = default;
  ~single_exception_allocator() override = default;

private:
  void* do_allocate(std::size_t p_size,  // NOLINT
                    [[maybe_unused]] std::size_t p_alignment) override
  {
    if (m_allocated || p_size > m_buffer.size()) {
      return nullptr;
    }
    m_allocated = true;
    return m_buffer.data();
  }

  void do_deallocate(void* p_address,
                     [[maybe_unused]] std::size_t p_size,  // NOLINT
                     [[maybe_unused]] std::size_t p_alignment) override
  {
    if (p_address != m_buffer.data()) {
      std::terminate();
    }
    m_allocated = false;
  }

  [[nodiscard]] bool do_is_equal(
    std::pmr::memory_resource const& other) const noexcept override
  {
    return this == &other;
  }

  alignas(std::max_align_t) std::array<std::uint8_t, 256> m_buffer{};
  bool m_allocated = false;
};

// TODO(#11): Add macro to IFDEF this out if the user want to save 64 bytes.
// NOLINTNEXTLINE
single_exception_allocator _default_allocator{};
// NOLINTNEXTLINE
std::pmr::memory_resource* _exception_allocator = &_default_allocator;

void set_exception_allocator(std::pmr::memory_resource& p_allocator) noexcept
{
  _exception_allocator = &p_allocator;
}

std::pmr::memory_resource& get_exception_allocator() noexcept
{
  return *_exception_allocator;
}
}  // namespace hal
