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

struct virtual_base_v
{
  int inner_detail_v = 0;
};

struct virtual_base_m
{
  int inner_detail_m = 0x8888;
};

struct base1 : public virtual virtual_base_v
{
  int inner_detail_r1 = 0;
};

struct base2 : public virtual virtual_base_v
{
  int inner_detail_r2 = 0;
};

struct multi_inheritor
  : public base1
  , protected virtual virtual_base_m
  , public base2
{
  int inner_detail_r = 0;
};

struct error : public multi_inheritor
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
    error obj{};
    obj.inner_detail_r = 0x1111;
    obj.inner_detail_r1 = 0x2222;
    obj.inner_detail_r2 = 0x3333;
    obj.inner_detail_v = 0x6666;
    obj.data = 0x9999;
    start = get_uptime();
    throw obj;
  }
}

std::uint32_t global = 0;

void application()
{
  try {
    foo();
  } catch (virtual_base_m const& p_error) {
    end = get_uptime();
    global = p_error.inner_detail_m;
  } catch (virtual_base_v const& p_error) {
    end = get_uptime();
    global = p_error.inner_detail_v;
  }
  while (true) {
    // print out `global` in gdb to see its contents. Check to see if it matches
    // the expected value in error for that sub-object.
    continue;
  }
}
