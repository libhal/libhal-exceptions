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

struct V
{
  int inner_detail_v = 0;
};

struct M
{
  int inner_detail_m = 0x8888;
};

struct R1 : public virtual V
{
  int inner_detail_r1 = 0;
};

struct R2 : public virtual V
{
  int inner_detail_r2 = 0;
};

struct R3
  : protected virtual M
  , public virtual V
{
  int inner_detail_r3 = 0;
};

struct R4
{
  int inner_detail_r4 = 0;
};

struct R
  : public R1
  , protected virtual M
  , public R2
  , public R3
  , public R4
{
  int inner_detail_r = 0;
};

struct error : public R
{
  int data = 0;

  // Extra virtual class functions to add to the complexity
  virtual void foo()
  {
    inner_detail_r++;
  }
  virtual void bar()
  {
    inner_detail_r++;
  }
};

int volatile value = 5;
std::uint64_t start = 0;
std::uint64_t end = 0;

void foo()
{
  if (value) {
    start = resources->clock->uptime();
    error obj{};
    obj.inner_detail_r = 0x1111;
    obj.inner_detail_r1 = 0x2222;
    obj.inner_detail_r2 = 0x3333;
    obj.inner_detail_r3 = 0x4444;
    obj.inner_detail_r4 = 0x5555;
    obj.inner_detail_v = 0x6666;
    obj.data = 0x9999;
    throw obj;
  }
}

std::uint32_t global = 0;

void application(resource_list& p_resources)
{
  resources = &p_resources;

  try {
    foo();
  } catch (M const& p_error) {
    end = resources->clock->uptime();
    global = p_error.inner_detail_m;
  } catch (V const& p_error) {
    end = resources->clock->uptime();
    global = p_error.inner_detail_v;
  }

  while (true) {
    // print out `global` in gdb to see its contents. Check to see if it matches
    // the expected value in error for that sub-object.
    continue;
  }
}
