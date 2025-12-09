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
#include <cstdio>

#include <array>
#include <exception>

#include <libhal-exceptions/new.hpp>

// NOLINTBEGIN(readability-identifier-naming)
struct V  // NOLINT(readability-identifier-naming)
{
  int inner_detail_v = 0;
};

struct R1  // NOLINT(readability-identifier-naming)
{
  int inner_detail_r1 = 0;
};

struct R2  // NOLINT(readability-identifier-naming)
{
  int inner_detail_r2 = 0;
};

struct R3  // NOLINT(readability-identifier-naming)
{
  int inner_detail_r3 = 0;
};

struct R4  // NOLINT(readability-identifier-naming)
{
  int inner_detail_r4 = 0;
};

struct R5
{
  int inner_detail_r5 = 0;
};

struct R6
{
  int inner_detail_r6 = 0;
};

struct R
  : public R1
  , public R2
  , public R3
  , public R5
  , public R6
{
  int inner_detail_r = 0;
};

struct T : public R
{
  int inner_detail_t = 0;
};

struct S
  : public V
  , public T
{
  int detail_s = 0;
};
// NOLINTEND(readability-identifier-naming)

struct error : public S
{
  int data = 0;
};

void foo()
{
  throw error{};
}

#if defined(LIBHAL_ESTELL_EXCEPTIONS) || 1

std::array<std::byte, 128> m_buffer{};

void* operator new(std::size_t, std::align_val_t, ke::exception_allocation_tag)
{
  m_buffer.fill(std::byte{ 0 });
  return m_buffer.data();
}

void operator delete(void*,
                     std::size_t,
                     std::align_val_t,
                     ke::exception_allocation_tag)
{
  m_buffer.fill(std::byte{ 0 });
}
#endif  // defined(LIBHAL_ESTELL_EXCEPTIONS)

int main()
{
  [[maybe_unused]] static constexpr auto error_size = sizeof(error);
  std::set_terminate(+[]() { puts("terminating application!"); });

  try {
    foo();
  } catch (error const&) {
    return 0;
  }

  return -1;
}
