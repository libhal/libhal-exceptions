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

#include <resource_list.hpp>

struct error
{
  int data = 0;
};

std::uint64_t start = 0;
std::uint64_t end = 0;
int volatile value = 5;

void foo()
{
  if (value) {
    error obj;
    obj.data = 0x9999;
    obj.data = value;
    start = get_uptime();
    throw obj;
  }
}

std::uint32_t global = 0;

void application()
{
  [[maybe_unused]] static constexpr auto error_size = sizeof(error);

  try {
    foo();
  } catch (error const& p_error) {
    end = get_uptime();
    global = p_error.data;
  }
  while (true) {
    // print out `global` in gdb to see its contents. Check to see if it matches
    // the expected value in error for that sub-object.
    //
    // Subtract end from start to see the time it took to throw and catch the
    // error.
    continue;
  }
}
