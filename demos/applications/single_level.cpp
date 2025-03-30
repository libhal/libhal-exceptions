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

resource_list* resources;

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
    start = resources->clock->uptime();
    error obj;
    obj.data = 0x9999;
    obj.data = value;
    throw obj;
  }
}

std::uint32_t global = 0;

void application(resource_list& p_resources)
{
  [[maybe_unused]] static constexpr auto error_size = sizeof(error);
  resources = &p_resources;

  try {
    foo();
  } catch (error const& p_error) {
    end = resources->clock->uptime();
    global = p_error.data;
  }
  while (true) {
    // print out `global` in gdb to see its contents. Check to see if it matches
    // the expected value in error for that sub-object.
    continue;
  }
}
