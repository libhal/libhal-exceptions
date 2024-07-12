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

#include "../resource_list.hpp"

int volatile value = 5;

resource_list* resources;

struct error
{
  int data = 0;
};

std::uint64_t start = 0;
std::uint64_t end = 0;

void foo()
{
  if (value) {
    start = resources->clock->uptime();
    throw error{ .data = value };
  }
}

void application(resource_list& p_resources)
{
  resources = &p_resources;
  try {
    foo();
  } catch (error const& p_error) {
    end = resources->clock->uptime();
    while (true) {
      continue;
    }
  }
}
