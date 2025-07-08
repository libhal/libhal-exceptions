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

#include <array>
#include <expected>

struct my_error_t
{
  std::array<std::uint8_t, 4> data;
};

std::expected<int, my_error_t> start();

void application()
{
  [[maybe_unused]] int volatile return_code = 0;
  auto result = start();
  if (!result) {
    return_code = result.error().data[0];
  } else {
    return_code = result.value();
  }
  while (true) {
    continue;
  }
}

std::array<std::uint64_t, 25> cycle_map{};
std::array<std::uint64_t, 25> happy_cycle_map{};

std::expected<int, my_error_t> funct_group0_0();
std::expected<int, my_error_t> funct_group1_0();
std::expected<int, my_error_t> funct_group2_0();
std::expected<int, my_error_t> funct_group3_0();
std::expected<int, my_error_t> funct_group4_0();
std::expected<int, my_error_t> funct_group5_0();
std::expected<int, my_error_t> funct_group6_0();
std::expected<int, my_error_t> funct_group7_0();
std::expected<int, my_error_t> funct_group8_0();
std::expected<int, my_error_t> funct_group9_0();
std::expected<int, my_error_t> funct_group10_0();
std::expected<int, my_error_t> funct_group11_0();
std::expected<int, my_error_t> funct_group12_0();
std::expected<int, my_error_t> funct_group13_0();
std::expected<int, my_error_t> funct_group14_0();
std::expected<int, my_error_t> funct_group15_0();
std::expected<int, my_error_t> funct_group16_0();
std::expected<int, my_error_t> funct_group17_0();
std::expected<int, my_error_t> funct_group18_0();
std::expected<int, my_error_t> funct_group19_0();
std::expected<int, my_error_t> funct_group20_0();
std::expected<int, my_error_t> funct_group21_0();
std::expected<int, my_error_t> funct_group22_0();
std::expected<int, my_error_t> funct_group23_0();
std::expected<int, my_error_t> funct_group24_0();

using signature = std::expected<int, my_error_t>(void);

std::array<signature*, 25> functions = {
  funct_group0_0,  funct_group1_0,  funct_group2_0,  funct_group3_0,
  funct_group4_0,  funct_group5_0,  funct_group6_0,  funct_group7_0,
  funct_group8_0,  funct_group9_0,  funct_group10_0, funct_group11_0,
  funct_group12_0, funct_group13_0,
  // funct_group14_0, funct_group15_0,
  // funct_group16_0, funct_group17_0, funct_group18_0, funct_group19_0,
  // funct_group20_0, funct_group21_0, funct_group22_0, funct_group23_0,
  // funct_group24_0
};

std::int32_t volatile side_effect = 0;
std::uint64_t start_cycles = 0;
std::uint64_t end_cycles = 0;

std::expected<int, my_error_t> start()
{
  cycle_map.fill(0);
  happy_cycle_map.fill(std::numeric_limits<std::int32_t>::max());
  std::uint32_t index = 0;
  for (auto& funct : functions) {
    start_cycles = get_uptime();
    if (auto result = funct(); !result) {
      end_cycles = get_uptime();
      cycle_map[index++] = end_cycles - start_cycles;
    }
  }
  index = 0;
  for (auto& funct : functions) {
    // should prevent result from being unexpected
    side_effect = -1'000'000'000;
    start_cycles = get_uptime();
    if (auto result = funct(); result) {
      end_cycles = get_uptime();
      happy_cycle_map[index++] = end_cycles - start_cycles;
    }
  }
  return side_effect;
}

class class_0
{
public:
  static std::expected<class_0, my_error_t> create(std::int32_t p_channel)
  {
    if (p_channel >= 1'000'000'000) {
      return std::unexpected(my_error_t{ .data = { 0x55, 0xAA, 0x33, 0x44 } });
    }
    side_effect = side_effect + 1;
    return class_0(p_channel);
  }

  class_0(class_0&) = delete;
  class_0& operator=(class_0&) = delete;
  class_0(class_0&&) noexcept = default;
  class_0& operator=(class_0&&) noexcept = default;
  ~class_0() = default;
  std::expected<void, my_error_t> trigger()
  {
    if (m_channel >= 1'000'000'000) {
      return std::unexpected(my_error_t{ .data = { 0xAA, 0xBB, 0x33, 0x44 } });
    }
    side_effect = side_effect + 1;

    return {};
  }

private:
  class_0(std::int32_t p_channel)
    : m_channel(p_channel)
  {
  }

  std::int32_t m_channel = 0;
};

class class_1
{
public:
  static std::expected<class_1, my_error_t> create(std::int32_t p_channel)
  {
    if (p_channel >= 1'000'000'000) {
      return std::unexpected(my_error_t{ .data = { 0x55, 0xAA, 0x33, 0x44 } });
    }
    side_effect = side_effect + 1;
    return class_1(p_channel);
  }

  class_1(class_1&) = delete;
  class_1& operator=(class_1&) = delete;
  class_1(class_1&&) noexcept = default;
  class_1& operator=(class_1&&) noexcept = default;
  ~class_1()
  {
    side_effect = side_effect & ~(1 << m_channel);
  }

  std::expected<void, my_error_t> trigger()
  {
    if (m_channel >= 1'000'000'000) {
      return std::unexpected(my_error_t{ .data = { 0xAA, 0xBB, 0x33, 0x44 } });
    }
    side_effect = side_effect + 1;

    return {};
  }

private:
  class_1(std::int32_t p_channel)
    : m_channel(p_channel)
  {
  }

  std::int32_t m_channel = 0;
};

std::expected<int, my_error_t> funct_group0_1();

std::expected<int, my_error_t> funct_group0_0()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group0_1(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group0_2();

std::expected<int, my_error_t> funct_group0_1()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group0_2(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group0_3();

std::expected<int, my_error_t> funct_group0_2()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group0_3(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group0_4();

std::expected<int, my_error_t> funct_group0_3()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group0_4(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group0_5();

std::expected<int, my_error_t> funct_group0_4()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group0_5(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group0_5()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (side_effect > 0) {
    return std::unexpected(my_error_t{ .data = { 0xDE, 0xAD } });
  }

  return side_effect;
}

std::expected<int, my_error_t> funct_group1_1();

std::expected<int, my_error_t> funct_group1_0()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group1_1(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group1_2();

std::expected<int, my_error_t> funct_group1_1()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group1_2(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group1_3();

std::expected<int, my_error_t> funct_group1_2()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group1_3(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group1_4();

std::expected<int, my_error_t> funct_group1_3()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group1_4(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group1_5();

std::expected<int, my_error_t> funct_group1_4()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group1_5(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group1_6();

std::expected<int, my_error_t> funct_group1_5()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group1_6(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group1_7();

std::expected<int, my_error_t> funct_group1_6()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group1_7(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group1_8();

std::expected<int, my_error_t> funct_group1_7()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group1_8(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group1_9();

std::expected<int, my_error_t> funct_group1_8()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group1_9(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group1_10();

std::expected<int, my_error_t> funct_group1_9()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group1_10(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group1_11();

std::expected<int, my_error_t> funct_group1_10()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group1_11(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group1_11()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (side_effect > 0) {
    return std::unexpected(my_error_t{ .data = { 0xDE, 0xAD } });
  }

  return side_effect;
}

std::expected<int, my_error_t> funct_group2_1();

std::expected<int, my_error_t> funct_group2_0()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group2_1(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group2_2();

std::expected<int, my_error_t> funct_group2_1()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group2_2(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group2_3();

std::expected<int, my_error_t> funct_group2_2()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group2_3(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group2_4();

std::expected<int, my_error_t> funct_group2_3()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group2_4(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group2_5();

std::expected<int, my_error_t> funct_group2_4()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group2_5(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group2_6();

std::expected<int, my_error_t> funct_group2_5()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group2_6(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group2_7();

std::expected<int, my_error_t> funct_group2_6()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group2_7(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group2_8();

std::expected<int, my_error_t> funct_group2_7()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group2_8(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group2_9();

std::expected<int, my_error_t> funct_group2_8()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group2_9(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group2_10();

std::expected<int, my_error_t> funct_group2_9()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group2_10(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group2_11();

std::expected<int, my_error_t> funct_group2_10()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group2_11(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group2_12();

std::expected<int, my_error_t> funct_group2_11()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group2_12(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group2_13();

std::expected<int, my_error_t> funct_group2_12()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group2_13(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group2_14();

std::expected<int, my_error_t> funct_group2_13()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group2_14(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group2_15();

std::expected<int, my_error_t> funct_group2_14()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group2_15(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group2_16();

std::expected<int, my_error_t> funct_group2_15()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group2_16(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group2_17();

std::expected<int, my_error_t> funct_group2_16()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group2_17(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group2_18();

std::expected<int, my_error_t> funct_group2_17()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group2_18(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group2_19();

std::expected<int, my_error_t> funct_group2_18()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group2_19(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group2_20();

std::expected<int, my_error_t> funct_group2_19()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group2_20(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group2_21();

std::expected<int, my_error_t> funct_group2_20()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group2_21(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group2_22();

std::expected<int, my_error_t> funct_group2_21()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group2_22(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group2_23();

std::expected<int, my_error_t> funct_group2_22()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group2_23(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group2_23()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (side_effect > 0) {
    return std::unexpected(my_error_t{ .data = { 0xDE, 0xAD } });
  }

  return side_effect;
}

std::expected<int, my_error_t> funct_group3_1();

std::expected<int, my_error_t> funct_group3_0()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group3_1(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group3_2();

std::expected<int, my_error_t> funct_group3_1()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group3_2(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group3_3();

std::expected<int, my_error_t> funct_group3_2()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group3_3(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group3_4();

std::expected<int, my_error_t> funct_group3_3()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group3_4(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group3_5();

std::expected<int, my_error_t> funct_group3_4()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group3_5(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group3_6();

std::expected<int, my_error_t> funct_group3_5()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group3_6(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group3_7();

std::expected<int, my_error_t> funct_group3_6()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group3_7(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group3_8();

std::expected<int, my_error_t> funct_group3_7()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group3_8(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group3_9();

std::expected<int, my_error_t> funct_group3_8()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group3_9(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group3_10();

std::expected<int, my_error_t> funct_group3_9()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group3_10(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group3_11();

std::expected<int, my_error_t> funct_group3_10()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group3_11(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group3_12();

std::expected<int, my_error_t> funct_group3_11()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group3_12(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group3_13();

std::expected<int, my_error_t> funct_group3_12()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group3_13(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group3_14();

std::expected<int, my_error_t> funct_group3_13()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group3_14(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group3_15();

std::expected<int, my_error_t> funct_group3_14()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group3_15(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group3_16();

std::expected<int, my_error_t> funct_group3_15()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group3_16(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group3_17();

std::expected<int, my_error_t> funct_group3_16()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group3_17(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group3_18();

std::expected<int, my_error_t> funct_group3_17()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group3_18(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group3_19();

std::expected<int, my_error_t> funct_group3_18()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group3_19(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group3_20();

std::expected<int, my_error_t> funct_group3_19()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group3_20(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group3_21();

std::expected<int, my_error_t> funct_group3_20()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group3_21(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group3_22();

std::expected<int, my_error_t> funct_group3_21()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group3_22(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group3_23();

std::expected<int, my_error_t> funct_group3_22()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group3_23(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group3_24();

std::expected<int, my_error_t> funct_group3_23()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group3_24(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group3_25();

std::expected<int, my_error_t> funct_group3_24()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group3_25(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group3_26();

std::expected<int, my_error_t> funct_group3_25()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group3_26(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group3_27();

std::expected<int, my_error_t> funct_group3_26()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group3_27(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group3_28();

std::expected<int, my_error_t> funct_group3_27()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group3_28(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group3_29();

std::expected<int, my_error_t> funct_group3_28()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group3_29(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group3_30();

std::expected<int, my_error_t> funct_group3_29()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group3_30(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group3_31();

std::expected<int, my_error_t> funct_group3_30()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group3_31(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group3_32();

std::expected<int, my_error_t> funct_group3_31()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group3_32(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group3_33();

std::expected<int, my_error_t> funct_group3_32()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group3_33(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group3_34();

std::expected<int, my_error_t> funct_group3_33()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group3_34(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group3_35();

std::expected<int, my_error_t> funct_group3_34()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group3_35(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group3_36();

std::expected<int, my_error_t> funct_group3_35()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group3_36(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group3_37();

std::expected<int, my_error_t> funct_group3_36()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group3_37(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group3_38();

std::expected<int, my_error_t> funct_group3_37()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group3_38(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group3_39();

std::expected<int, my_error_t> funct_group3_38()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group3_39(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group3_40();

std::expected<int, my_error_t> funct_group3_39()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group3_40(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group3_41();

std::expected<int, my_error_t> funct_group3_40()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group3_41(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group3_42();

std::expected<int, my_error_t> funct_group3_41()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group3_42(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group3_43();

std::expected<int, my_error_t> funct_group3_42()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group3_43(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group3_44();

std::expected<int, my_error_t> funct_group3_43()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group3_44(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group3_45();

std::expected<int, my_error_t> funct_group3_44()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group3_45(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group3_46();

std::expected<int, my_error_t> funct_group3_45()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group3_46(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group3_47();

std::expected<int, my_error_t> funct_group3_46()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group3_47(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group3_47()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (side_effect > 0) {
    return std::unexpected(my_error_t{ .data = { 0xDE, 0xAD } });
  }

  return side_effect;
}

std::expected<int, my_error_t> funct_group4_1();

std::expected<int, my_error_t> funct_group4_0()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_1(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_2();

std::expected<int, my_error_t> funct_group4_1()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_2(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_3();

std::expected<int, my_error_t> funct_group4_2()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_3(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_4();

std::expected<int, my_error_t> funct_group4_3()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_4(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_5();

std::expected<int, my_error_t> funct_group4_4()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_5(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_6();

std::expected<int, my_error_t> funct_group4_5()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_6(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_7();

std::expected<int, my_error_t> funct_group4_6()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_7(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_8();

std::expected<int, my_error_t> funct_group4_7()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_8(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_9();

std::expected<int, my_error_t> funct_group4_8()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_9(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_10();

std::expected<int, my_error_t> funct_group4_9()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_10(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_11();

std::expected<int, my_error_t> funct_group4_10()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_11(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_12();

std::expected<int, my_error_t> funct_group4_11()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_12(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_13();

std::expected<int, my_error_t> funct_group4_12()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_13(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_14();

std::expected<int, my_error_t> funct_group4_13()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_14(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_15();

std::expected<int, my_error_t> funct_group4_14()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_15(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_16();

std::expected<int, my_error_t> funct_group4_15()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_16(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_17();

std::expected<int, my_error_t> funct_group4_16()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_17(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_18();

std::expected<int, my_error_t> funct_group4_17()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_18(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_19();

std::expected<int, my_error_t> funct_group4_18()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_19(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_20();

std::expected<int, my_error_t> funct_group4_19()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_20(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_21();

std::expected<int, my_error_t> funct_group4_20()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_21(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_22();

std::expected<int, my_error_t> funct_group4_21()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_22(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_23();

std::expected<int, my_error_t> funct_group4_22()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_23(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_24();

std::expected<int, my_error_t> funct_group4_23()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_24(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_25();

std::expected<int, my_error_t> funct_group4_24()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_25(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_26();

std::expected<int, my_error_t> funct_group4_25()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_26(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_27();

std::expected<int, my_error_t> funct_group4_26()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_27(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_28();

std::expected<int, my_error_t> funct_group4_27()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_28(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_29();

std::expected<int, my_error_t> funct_group4_28()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_29(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_30();

std::expected<int, my_error_t> funct_group4_29()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_30(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_31();

std::expected<int, my_error_t> funct_group4_30()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_31(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_32();

std::expected<int, my_error_t> funct_group4_31()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_32(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_33();

std::expected<int, my_error_t> funct_group4_32()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_33(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_34();

std::expected<int, my_error_t> funct_group4_33()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_34(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_35();

std::expected<int, my_error_t> funct_group4_34()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_35(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_36();

std::expected<int, my_error_t> funct_group4_35()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_36(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_37();

std::expected<int, my_error_t> funct_group4_36()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_37(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_38();

std::expected<int, my_error_t> funct_group4_37()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_38(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_39();

std::expected<int, my_error_t> funct_group4_38()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_39(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_40();

std::expected<int, my_error_t> funct_group4_39()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_40(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_41();

std::expected<int, my_error_t> funct_group4_40()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_41(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_42();

std::expected<int, my_error_t> funct_group4_41()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_42(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_43();

std::expected<int, my_error_t> funct_group4_42()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_43(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_44();

std::expected<int, my_error_t> funct_group4_43()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_44(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_45();

std::expected<int, my_error_t> funct_group4_44()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_45(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_46();

std::expected<int, my_error_t> funct_group4_45()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_46(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_47();

std::expected<int, my_error_t> funct_group4_46()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_47(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_48();

std::expected<int, my_error_t> funct_group4_47()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_48(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_49();

std::expected<int, my_error_t> funct_group4_48()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_49(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_50();

std::expected<int, my_error_t> funct_group4_49()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_50(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_51();

std::expected<int, my_error_t> funct_group4_50()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_51(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_52();

std::expected<int, my_error_t> funct_group4_51()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_52(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_53();

std::expected<int, my_error_t> funct_group4_52()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_53(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_54();

std::expected<int, my_error_t> funct_group4_53()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_54(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_55();

std::expected<int, my_error_t> funct_group4_54()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_55(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_56();

std::expected<int, my_error_t> funct_group4_55()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_56(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_57();

std::expected<int, my_error_t> funct_group4_56()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_57(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_58();

std::expected<int, my_error_t> funct_group4_57()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_58(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_59();

std::expected<int, my_error_t> funct_group4_58()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_59(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_60();

std::expected<int, my_error_t> funct_group4_59()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_60(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_61();

std::expected<int, my_error_t> funct_group4_60()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_61(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_62();

std::expected<int, my_error_t> funct_group4_61()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_62(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_63();

std::expected<int, my_error_t> funct_group4_62()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_63(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_64();

std::expected<int, my_error_t> funct_group4_63()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_64(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_65();

std::expected<int, my_error_t> funct_group4_64()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_65(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_66();

std::expected<int, my_error_t> funct_group4_65()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_66(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_67();

std::expected<int, my_error_t> funct_group4_66()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_67(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_68();

std::expected<int, my_error_t> funct_group4_67()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_68(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_69();

std::expected<int, my_error_t> funct_group4_68()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_69(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_70();

std::expected<int, my_error_t> funct_group4_69()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_70(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_71();

std::expected<int, my_error_t> funct_group4_70()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_71(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_72();

std::expected<int, my_error_t> funct_group4_71()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_72(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_73();

std::expected<int, my_error_t> funct_group4_72()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_73(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_74();

std::expected<int, my_error_t> funct_group4_73()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_74(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_75();

std::expected<int, my_error_t> funct_group4_74()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_75(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_76();

std::expected<int, my_error_t> funct_group4_75()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_76(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_77();

std::expected<int, my_error_t> funct_group4_76()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_77(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_78();

std::expected<int, my_error_t> funct_group4_77()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_78(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_79();

std::expected<int, my_error_t> funct_group4_78()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_79(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_80();

std::expected<int, my_error_t> funct_group4_79()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_80(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_81();

std::expected<int, my_error_t> funct_group4_80()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_81(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_82();

std::expected<int, my_error_t> funct_group4_81()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_82(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_83();

std::expected<int, my_error_t> funct_group4_82()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_83(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_84();

std::expected<int, my_error_t> funct_group4_83()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_84(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_85();

std::expected<int, my_error_t> funct_group4_84()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_85(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_86();

std::expected<int, my_error_t> funct_group4_85()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_86(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_87();

std::expected<int, my_error_t> funct_group4_86()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_87(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_88();

std::expected<int, my_error_t> funct_group4_87()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_88(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_89();

std::expected<int, my_error_t> funct_group4_88()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_89(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_90();

std::expected<int, my_error_t> funct_group4_89()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_90(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_91();

std::expected<int, my_error_t> funct_group4_90()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_91(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_92();

std::expected<int, my_error_t> funct_group4_91()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_92(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_93();

std::expected<int, my_error_t> funct_group4_92()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_93(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_94();

std::expected<int, my_error_t> funct_group4_93()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_94(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_95();

std::expected<int, my_error_t> funct_group4_94()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group4_95(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group4_95()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (side_effect > 0) {
    return std::unexpected(my_error_t{ .data = { 0xDE, 0xAD } });
  }

  return side_effect;
}

std::expected<int, my_error_t> funct_group5_1();

std::expected<int, my_error_t> funct_group5_0()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group5_1(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group5_2();

std::expected<int, my_error_t> funct_group5_1()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group5_2(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group5_3();

std::expected<int, my_error_t> funct_group5_2()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group5_3(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group5_4();

std::expected<int, my_error_t> funct_group5_3()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group5_4(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group5_5();

std::expected<int, my_error_t> funct_group5_4()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group5_5(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group5_5()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (side_effect > 0) {
    return std::unexpected(my_error_t{ .data = { 0xDE, 0xAD } });
  }

  return side_effect;
}

std::expected<int, my_error_t> funct_group6_1();

std::expected<int, my_error_t> funct_group6_0()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group6_1(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group6_2();

std::expected<int, my_error_t> funct_group6_1()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group6_2(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group6_3();

std::expected<int, my_error_t> funct_group6_2()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group6_3(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group6_4();

std::expected<int, my_error_t> funct_group6_3()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group6_4(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group6_5();

std::expected<int, my_error_t> funct_group6_4()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group6_5(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group6_6();

std::expected<int, my_error_t> funct_group6_5()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group6_6(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group6_7();

std::expected<int, my_error_t> funct_group6_6()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group6_7(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group6_8();

std::expected<int, my_error_t> funct_group6_7()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group6_8(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group6_9();

std::expected<int, my_error_t> funct_group6_8()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group6_9(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group6_10();

std::expected<int, my_error_t> funct_group6_9()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group6_10(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group6_11();

std::expected<int, my_error_t> funct_group6_10()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group6_11(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group6_11()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (side_effect > 0) {
    return std::unexpected(my_error_t{ .data = { 0xDE, 0xAD } });
  }

  return side_effect;
}

std::expected<int, my_error_t> funct_group7_1();

std::expected<int, my_error_t> funct_group7_0()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group7_1(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group7_2();

std::expected<int, my_error_t> funct_group7_1()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group7_2(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group7_3();

std::expected<int, my_error_t> funct_group7_2()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group7_3(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group7_4();

std::expected<int, my_error_t> funct_group7_3()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group7_4(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group7_5();

std::expected<int, my_error_t> funct_group7_4()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group7_5(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group7_6();

std::expected<int, my_error_t> funct_group7_5()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group7_6(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group7_7();

std::expected<int, my_error_t> funct_group7_6()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group7_7(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group7_8();

std::expected<int, my_error_t> funct_group7_7()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group7_8(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group7_9();

std::expected<int, my_error_t> funct_group7_8()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group7_9(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group7_10();

std::expected<int, my_error_t> funct_group7_9()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group7_10(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group7_11();

std::expected<int, my_error_t> funct_group7_10()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group7_11(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group7_12();

std::expected<int, my_error_t> funct_group7_11()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group7_12(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group7_13();

std::expected<int, my_error_t> funct_group7_12()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group7_13(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group7_14();

std::expected<int, my_error_t> funct_group7_13()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group7_14(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group7_15();

std::expected<int, my_error_t> funct_group7_14()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group7_15(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group7_16();

std::expected<int, my_error_t> funct_group7_15()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group7_16(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group7_17();

std::expected<int, my_error_t> funct_group7_16()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group7_17(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group7_18();

std::expected<int, my_error_t> funct_group7_17()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group7_18(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group7_19();

std::expected<int, my_error_t> funct_group7_18()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group7_19(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group7_20();

std::expected<int, my_error_t> funct_group7_19()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group7_20(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group7_21();

std::expected<int, my_error_t> funct_group7_20()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group7_21(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group7_22();

std::expected<int, my_error_t> funct_group7_21()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group7_22(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group7_23();

std::expected<int, my_error_t> funct_group7_22()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group7_23(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group7_23()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (side_effect > 0) {
    return std::unexpected(my_error_t{ .data = { 0xDE, 0xAD } });
  }

  return side_effect;
}

std::expected<int, my_error_t> funct_group8_1();

std::expected<int, my_error_t> funct_group8_0()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group8_1(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group8_2();

std::expected<int, my_error_t> funct_group8_1()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group8_2(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group8_3();

std::expected<int, my_error_t> funct_group8_2()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group8_3(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group8_4();

std::expected<int, my_error_t> funct_group8_3()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group8_4(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group8_5();

std::expected<int, my_error_t> funct_group8_4()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group8_5(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group8_6();

std::expected<int, my_error_t> funct_group8_5()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group8_6(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group8_7();

std::expected<int, my_error_t> funct_group8_6()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group8_7(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group8_8();

std::expected<int, my_error_t> funct_group8_7()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group8_8(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group8_9();

std::expected<int, my_error_t> funct_group8_8()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group8_9(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group8_10();

std::expected<int, my_error_t> funct_group8_9()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group8_10(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group8_11();

std::expected<int, my_error_t> funct_group8_10()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group8_11(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group8_12();

std::expected<int, my_error_t> funct_group8_11()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group8_12(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group8_13();

std::expected<int, my_error_t> funct_group8_12()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group8_13(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group8_14();

std::expected<int, my_error_t> funct_group8_13()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group8_14(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group8_15();

std::expected<int, my_error_t> funct_group8_14()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group8_15(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group8_16();

std::expected<int, my_error_t> funct_group8_15()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group8_16(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group8_17();

std::expected<int, my_error_t> funct_group8_16()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group8_17(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group8_18();

std::expected<int, my_error_t> funct_group8_17()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group8_18(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group8_19();

std::expected<int, my_error_t> funct_group8_18()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group8_19(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group8_20();

std::expected<int, my_error_t> funct_group8_19()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group8_20(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group8_21();

std::expected<int, my_error_t> funct_group8_20()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group8_21(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group8_22();

std::expected<int, my_error_t> funct_group8_21()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group8_22(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group8_23();

std::expected<int, my_error_t> funct_group8_22()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group8_23(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group8_24();

std::expected<int, my_error_t> funct_group8_23()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group8_24(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group8_25();

std::expected<int, my_error_t> funct_group8_24()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group8_25(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group8_26();

std::expected<int, my_error_t> funct_group8_25()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group8_26(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group8_27();

std::expected<int, my_error_t> funct_group8_26()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group8_27(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group8_28();

std::expected<int, my_error_t> funct_group8_27()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group8_28(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group8_29();

std::expected<int, my_error_t> funct_group8_28()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group8_29(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group8_30();

std::expected<int, my_error_t> funct_group8_29()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group8_30(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group8_31();

std::expected<int, my_error_t> funct_group8_30()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group8_31(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group8_32();

std::expected<int, my_error_t> funct_group8_31()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group8_32(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group8_33();

std::expected<int, my_error_t> funct_group8_32()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group8_33(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group8_34();

std::expected<int, my_error_t> funct_group8_33()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group8_34(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group8_35();

std::expected<int, my_error_t> funct_group8_34()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group8_35(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group8_36();

std::expected<int, my_error_t> funct_group8_35()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group8_36(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group8_37();

std::expected<int, my_error_t> funct_group8_36()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group8_37(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group8_38();

std::expected<int, my_error_t> funct_group8_37()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group8_38(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group8_39();

std::expected<int, my_error_t> funct_group8_38()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group8_39(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group8_40();

std::expected<int, my_error_t> funct_group8_39()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group8_40(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group8_41();

std::expected<int, my_error_t> funct_group8_40()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group8_41(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group8_42();

std::expected<int, my_error_t> funct_group8_41()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group8_42(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group8_43();

std::expected<int, my_error_t> funct_group8_42()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group8_43(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group8_44();

std::expected<int, my_error_t> funct_group8_43()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group8_44(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group8_45();

std::expected<int, my_error_t> funct_group8_44()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group8_45(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group8_46();

std::expected<int, my_error_t> funct_group8_45()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group8_46(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group8_47();

std::expected<int, my_error_t> funct_group8_46()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group8_47(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group8_47()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (side_effect > 0) {
    return std::unexpected(my_error_t{ .data = { 0xDE, 0xAD } });
  }

  return side_effect;
}

std::expected<int, my_error_t> funct_group9_1();

std::expected<int, my_error_t> funct_group9_0()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_1(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_2();

std::expected<int, my_error_t> funct_group9_1()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_2(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_3();

std::expected<int, my_error_t> funct_group9_2()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_3(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_4();

std::expected<int, my_error_t> funct_group9_3()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_4(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_5();

std::expected<int, my_error_t> funct_group9_4()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_5(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_6();

std::expected<int, my_error_t> funct_group9_5()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_6(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_7();

std::expected<int, my_error_t> funct_group9_6()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_7(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_8();

std::expected<int, my_error_t> funct_group9_7()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_8(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_9();

std::expected<int, my_error_t> funct_group9_8()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_9(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_10();

std::expected<int, my_error_t> funct_group9_9()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_10(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_11();

std::expected<int, my_error_t> funct_group9_10()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_11(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_12();

std::expected<int, my_error_t> funct_group9_11()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_12(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_13();

std::expected<int, my_error_t> funct_group9_12()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_13(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_14();

std::expected<int, my_error_t> funct_group9_13()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_14(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_15();

std::expected<int, my_error_t> funct_group9_14()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_15(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_16();

std::expected<int, my_error_t> funct_group9_15()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_16(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_17();

std::expected<int, my_error_t> funct_group9_16()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_17(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_18();

std::expected<int, my_error_t> funct_group9_17()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_18(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_19();

std::expected<int, my_error_t> funct_group9_18()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_19(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_20();

std::expected<int, my_error_t> funct_group9_19()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_20(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_21();

std::expected<int, my_error_t> funct_group9_20()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_21(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_22();

std::expected<int, my_error_t> funct_group9_21()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_22(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_23();

std::expected<int, my_error_t> funct_group9_22()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_23(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_24();

std::expected<int, my_error_t> funct_group9_23()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_24(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_25();

std::expected<int, my_error_t> funct_group9_24()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_25(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_26();

std::expected<int, my_error_t> funct_group9_25()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_26(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_27();

std::expected<int, my_error_t> funct_group9_26()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_27(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_28();

std::expected<int, my_error_t> funct_group9_27()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_28(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_29();

std::expected<int, my_error_t> funct_group9_28()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_29(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_30();

std::expected<int, my_error_t> funct_group9_29()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_30(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_31();

std::expected<int, my_error_t> funct_group9_30()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_31(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_32();

std::expected<int, my_error_t> funct_group9_31()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_32(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_33();

std::expected<int, my_error_t> funct_group9_32()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_33(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_34();

std::expected<int, my_error_t> funct_group9_33()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_34(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_35();

std::expected<int, my_error_t> funct_group9_34()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_35(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_36();

std::expected<int, my_error_t> funct_group9_35()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_36(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_37();

std::expected<int, my_error_t> funct_group9_36()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_37(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_38();

std::expected<int, my_error_t> funct_group9_37()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_38(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_39();

std::expected<int, my_error_t> funct_group9_38()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_39(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_40();

std::expected<int, my_error_t> funct_group9_39()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_40(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_41();

std::expected<int, my_error_t> funct_group9_40()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_41(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_42();

std::expected<int, my_error_t> funct_group9_41()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_42(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_43();

std::expected<int, my_error_t> funct_group9_42()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_43(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_44();

std::expected<int, my_error_t> funct_group9_43()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_44(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_45();

std::expected<int, my_error_t> funct_group9_44()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_45(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_46();

std::expected<int, my_error_t> funct_group9_45()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_46(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_47();

std::expected<int, my_error_t> funct_group9_46()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_47(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_48();

std::expected<int, my_error_t> funct_group9_47()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_48(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_49();

std::expected<int, my_error_t> funct_group9_48()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_49(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_50();

std::expected<int, my_error_t> funct_group9_49()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_50(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_51();

std::expected<int, my_error_t> funct_group9_50()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_51(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_52();

std::expected<int, my_error_t> funct_group9_51()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_52(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_53();

std::expected<int, my_error_t> funct_group9_52()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_53(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_54();

std::expected<int, my_error_t> funct_group9_53()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_54(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_55();

std::expected<int, my_error_t> funct_group9_54()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_55(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_56();

std::expected<int, my_error_t> funct_group9_55()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_56(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_57();

std::expected<int, my_error_t> funct_group9_56()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_57(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_58();

std::expected<int, my_error_t> funct_group9_57()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_58(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_59();

std::expected<int, my_error_t> funct_group9_58()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_59(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_60();

std::expected<int, my_error_t> funct_group9_59()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_60(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_61();

std::expected<int, my_error_t> funct_group9_60()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_61(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_62();

std::expected<int, my_error_t> funct_group9_61()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_62(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_63();

std::expected<int, my_error_t> funct_group9_62()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_63(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_64();

std::expected<int, my_error_t> funct_group9_63()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_64(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_65();

std::expected<int, my_error_t> funct_group9_64()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_65(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_66();

std::expected<int, my_error_t> funct_group9_65()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_66(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_67();

std::expected<int, my_error_t> funct_group9_66()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_67(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_68();

std::expected<int, my_error_t> funct_group9_67()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_68(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_69();

std::expected<int, my_error_t> funct_group9_68()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_69(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_70();

std::expected<int, my_error_t> funct_group9_69()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_70(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_71();

std::expected<int, my_error_t> funct_group9_70()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_71(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_72();

std::expected<int, my_error_t> funct_group9_71()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_72(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_73();

std::expected<int, my_error_t> funct_group9_72()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_73(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_74();

std::expected<int, my_error_t> funct_group9_73()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_74(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_75();

std::expected<int, my_error_t> funct_group9_74()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_75(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_76();

std::expected<int, my_error_t> funct_group9_75()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_76(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_77();

std::expected<int, my_error_t> funct_group9_76()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_77(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_78();

std::expected<int, my_error_t> funct_group9_77()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_78(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_79();

std::expected<int, my_error_t> funct_group9_78()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_79(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_80();

std::expected<int, my_error_t> funct_group9_79()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_80(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_81();

std::expected<int, my_error_t> funct_group9_80()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_81(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_82();

std::expected<int, my_error_t> funct_group9_81()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_82(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_83();

std::expected<int, my_error_t> funct_group9_82()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_83(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_84();

std::expected<int, my_error_t> funct_group9_83()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_84(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_85();

std::expected<int, my_error_t> funct_group9_84()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_85(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_86();

std::expected<int, my_error_t> funct_group9_85()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_86(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_87();

std::expected<int, my_error_t> funct_group9_86()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_87(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_88();

std::expected<int, my_error_t> funct_group9_87()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_88(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_89();

std::expected<int, my_error_t> funct_group9_88()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_89(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_90();

std::expected<int, my_error_t> funct_group9_89()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_90(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_91();

std::expected<int, my_error_t> funct_group9_90()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_91(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_92();

std::expected<int, my_error_t> funct_group9_91()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_92(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_93();

std::expected<int, my_error_t> funct_group9_92()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_93(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_94();

std::expected<int, my_error_t> funct_group9_93()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_94(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_95();

std::expected<int, my_error_t> funct_group9_94()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group9_95(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group9_95()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (side_effect > 0) {
    return std::unexpected(my_error_t{ .data = { 0xDE, 0xAD } });
  }

  return side_effect;
}

std::expected<int, my_error_t> funct_group10_1();

std::expected<int, my_error_t> funct_group10_0()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group10_1(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group10_2();

std::expected<int, my_error_t> funct_group10_1()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group10_2(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group10_3();

std::expected<int, my_error_t> funct_group10_2()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group10_3(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group10_4();

std::expected<int, my_error_t> funct_group10_3()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group10_4(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group10_5();

std::expected<int, my_error_t> funct_group10_4()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group10_5(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group10_5()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (side_effect > 0) {
    return std::unexpected(my_error_t{ .data = { 0xDE, 0xAD } });
  }

  return side_effect;
}

std::expected<int, my_error_t> funct_group11_1();

std::expected<int, my_error_t> funct_group11_0()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group11_1(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group11_2();

std::expected<int, my_error_t> funct_group11_1()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group11_2(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group11_3();

std::expected<int, my_error_t> funct_group11_2()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group11_3(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group11_4();

std::expected<int, my_error_t> funct_group11_3()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group11_4(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group11_5();

std::expected<int, my_error_t> funct_group11_4()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group11_5(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group11_6();

std::expected<int, my_error_t> funct_group11_5()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group11_6(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group11_7();

std::expected<int, my_error_t> funct_group11_6()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group11_7(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group11_8();

std::expected<int, my_error_t> funct_group11_7()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group11_8(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group11_9();

std::expected<int, my_error_t> funct_group11_8()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group11_9(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group11_10();

std::expected<int, my_error_t> funct_group11_9()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group11_10(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group11_11();

std::expected<int, my_error_t> funct_group11_10()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group11_11(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group11_11()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (side_effect > 0) {
    return std::unexpected(my_error_t{ .data = { 0xDE, 0xAD } });
  }

  return side_effect;
}

std::expected<int, my_error_t> funct_group12_1();

std::expected<int, my_error_t> funct_group12_0()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group12_1(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group12_2();

std::expected<int, my_error_t> funct_group12_1()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group12_2(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group12_3();

std::expected<int, my_error_t> funct_group12_2()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group12_3(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group12_4();

std::expected<int, my_error_t> funct_group12_3()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group12_4(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group12_5();

std::expected<int, my_error_t> funct_group12_4()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group12_5(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group12_6();

std::expected<int, my_error_t> funct_group12_5()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group12_6(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group12_7();

std::expected<int, my_error_t> funct_group12_6()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group12_7(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group12_8();

std::expected<int, my_error_t> funct_group12_7()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group12_8(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group12_9();

std::expected<int, my_error_t> funct_group12_8()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group12_9(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group12_10();

std::expected<int, my_error_t> funct_group12_9()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group12_10(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group12_11();

std::expected<int, my_error_t> funct_group12_10()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group12_11(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group12_12();

std::expected<int, my_error_t> funct_group12_11()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group12_12(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group12_13();

std::expected<int, my_error_t> funct_group12_12()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group12_13(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group12_14();

std::expected<int, my_error_t> funct_group12_13()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group12_14(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group12_15();

std::expected<int, my_error_t> funct_group12_14()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group12_15(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group12_16();

std::expected<int, my_error_t> funct_group12_15()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group12_16(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group12_17();

std::expected<int, my_error_t> funct_group12_16()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group12_17(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group12_18();

std::expected<int, my_error_t> funct_group12_17()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group12_18(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group12_19();

std::expected<int, my_error_t> funct_group12_18()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group12_19(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group12_20();

std::expected<int, my_error_t> funct_group12_19()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group12_20(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group12_21();

std::expected<int, my_error_t> funct_group12_20()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group12_21(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group12_22();

std::expected<int, my_error_t> funct_group12_21()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group12_22(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group12_23();

std::expected<int, my_error_t> funct_group12_22()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group12_23(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group12_23()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (side_effect > 0) {
    return std::unexpected(my_error_t{ .data = { 0xDE, 0xAD } });
  }

  return side_effect;
}

std::expected<int, my_error_t> funct_group13_1();

std::expected<int, my_error_t> funct_group13_0()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group13_1(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group13_2();

std::expected<int, my_error_t> funct_group13_1()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group13_2(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group13_3();

std::expected<int, my_error_t> funct_group13_2()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group13_3(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group13_4();

std::expected<int, my_error_t> funct_group13_3()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group13_4(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group13_5();

std::expected<int, my_error_t> funct_group13_4()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group13_5(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group13_6();

std::expected<int, my_error_t> funct_group13_5()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group13_6(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group13_7();

std::expected<int, my_error_t> funct_group13_6()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group13_7(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group13_8();

std::expected<int, my_error_t> funct_group13_7()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group13_8(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group13_9();

std::expected<int, my_error_t> funct_group13_8()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group13_9(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group13_10();

std::expected<int, my_error_t> funct_group13_9()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group13_10(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group13_11();

std::expected<int, my_error_t> funct_group13_10()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group13_11(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group13_12();

std::expected<int, my_error_t> funct_group13_11()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group13_12(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group13_13();

std::expected<int, my_error_t> funct_group13_12()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group13_13(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group13_14();

std::expected<int, my_error_t> funct_group13_13()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group13_14(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group13_15();

std::expected<int, my_error_t> funct_group13_14()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group13_15(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group13_16();

std::expected<int, my_error_t> funct_group13_15()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group13_16(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group13_17();

std::expected<int, my_error_t> funct_group13_16()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group13_17(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group13_18();

std::expected<int, my_error_t> funct_group13_17()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group13_18(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group13_19();

std::expected<int, my_error_t> funct_group13_18()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group13_19(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group13_20();

std::expected<int, my_error_t> funct_group13_19()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group13_20(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group13_21();

std::expected<int, my_error_t> funct_group13_20()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group13_21(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group13_22();

std::expected<int, my_error_t> funct_group13_21()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group13_22(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group13_23();

std::expected<int, my_error_t> funct_group13_22()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group13_23(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group13_24();

std::expected<int, my_error_t> funct_group13_23()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group13_24(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group13_25();

std::expected<int, my_error_t> funct_group13_24()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group13_25(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group13_26();

std::expected<int, my_error_t> funct_group13_25()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group13_26(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group13_27();

std::expected<int, my_error_t> funct_group13_26()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group13_27(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group13_28();

std::expected<int, my_error_t> funct_group13_27()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group13_28(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group13_29();

std::expected<int, my_error_t> funct_group13_28()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group13_29(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group13_30();

std::expected<int, my_error_t> funct_group13_29()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group13_30(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group13_31();

std::expected<int, my_error_t> funct_group13_30()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group13_31(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group13_32();

std::expected<int, my_error_t> funct_group13_31()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group13_32(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group13_33();

std::expected<int, my_error_t> funct_group13_32()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group13_33(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group13_34();

std::expected<int, my_error_t> funct_group13_33()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group13_34(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group13_35();

std::expected<int, my_error_t> funct_group13_34()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group13_35(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group13_36();

std::expected<int, my_error_t> funct_group13_35()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group13_36(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group13_37();

std::expected<int, my_error_t> funct_group13_36()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group13_37(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group13_38();

std::expected<int, my_error_t> funct_group13_37()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group13_38(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group13_39();

std::expected<int, my_error_t> funct_group13_38()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group13_39(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group13_40();

std::expected<int, my_error_t> funct_group13_39()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group13_40(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group13_41();

std::expected<int, my_error_t> funct_group13_40()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group13_41(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group13_42();

std::expected<int, my_error_t> funct_group13_41()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group13_42(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group13_43();

std::expected<int, my_error_t> funct_group13_42()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group13_43(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group13_44();

std::expected<int, my_error_t> funct_group13_43()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group13_44(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group13_45();

std::expected<int, my_error_t> funct_group13_44()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group13_45(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group13_46();

std::expected<int, my_error_t> funct_group13_45()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group13_46(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group13_47();

std::expected<int, my_error_t> funct_group13_46()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group13_47(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group13_47()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (side_effect > 0) {
    return std::unexpected(my_error_t{ .data = { 0xDE, 0xAD } });
  }

  return side_effect;
}

std::expected<int, my_error_t> funct_group14_1();

std::expected<int, my_error_t> funct_group14_0()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_1(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_2();

std::expected<int, my_error_t> funct_group14_1()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_2(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_3();

std::expected<int, my_error_t> funct_group14_2()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_3(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_4();

std::expected<int, my_error_t> funct_group14_3()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_4(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_5();

std::expected<int, my_error_t> funct_group14_4()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_5(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_6();

std::expected<int, my_error_t> funct_group14_5()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_6(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_7();

std::expected<int, my_error_t> funct_group14_6()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_7(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_8();

std::expected<int, my_error_t> funct_group14_7()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_8(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_9();

std::expected<int, my_error_t> funct_group14_8()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_9(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_10();

std::expected<int, my_error_t> funct_group14_9()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_10(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_11();

std::expected<int, my_error_t> funct_group14_10()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_11(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_12();

std::expected<int, my_error_t> funct_group14_11()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_12(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_13();

std::expected<int, my_error_t> funct_group14_12()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_13(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_14();

std::expected<int, my_error_t> funct_group14_13()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_14(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_15();

std::expected<int, my_error_t> funct_group14_14()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_15(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_16();

std::expected<int, my_error_t> funct_group14_15()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_16(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_17();

std::expected<int, my_error_t> funct_group14_16()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_17(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_18();

std::expected<int, my_error_t> funct_group14_17()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_18(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_19();

std::expected<int, my_error_t> funct_group14_18()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_19(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_20();

std::expected<int, my_error_t> funct_group14_19()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_20(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_21();

std::expected<int, my_error_t> funct_group14_20()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_21(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_22();

std::expected<int, my_error_t> funct_group14_21()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_22(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_23();

std::expected<int, my_error_t> funct_group14_22()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_23(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_24();

std::expected<int, my_error_t> funct_group14_23()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_24(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_25();

std::expected<int, my_error_t> funct_group14_24()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_25(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_26();

std::expected<int, my_error_t> funct_group14_25()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_26(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_27();

std::expected<int, my_error_t> funct_group14_26()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_27(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_28();

std::expected<int, my_error_t> funct_group14_27()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_28(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_29();

std::expected<int, my_error_t> funct_group14_28()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_29(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_30();

std::expected<int, my_error_t> funct_group14_29()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_30(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_31();

std::expected<int, my_error_t> funct_group14_30()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_31(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_32();

std::expected<int, my_error_t> funct_group14_31()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_32(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_33();

std::expected<int, my_error_t> funct_group14_32()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_33(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_34();

std::expected<int, my_error_t> funct_group14_33()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_34(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_35();

std::expected<int, my_error_t> funct_group14_34()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_35(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_36();

std::expected<int, my_error_t> funct_group14_35()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_36(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_37();

std::expected<int, my_error_t> funct_group14_36()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_37(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_38();

std::expected<int, my_error_t> funct_group14_37()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_38(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_39();

std::expected<int, my_error_t> funct_group14_38()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_39(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_40();

std::expected<int, my_error_t> funct_group14_39()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_40(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_41();

std::expected<int, my_error_t> funct_group14_40()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_41(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_42();

std::expected<int, my_error_t> funct_group14_41()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_42(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_43();

std::expected<int, my_error_t> funct_group14_42()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_43(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_44();

std::expected<int, my_error_t> funct_group14_43()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_44(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_45();

std::expected<int, my_error_t> funct_group14_44()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_45(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_46();

std::expected<int, my_error_t> funct_group14_45()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_46(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_47();

std::expected<int, my_error_t> funct_group14_46()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_47(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_48();

std::expected<int, my_error_t> funct_group14_47()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_48(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_49();

std::expected<int, my_error_t> funct_group14_48()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_49(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_50();

std::expected<int, my_error_t> funct_group14_49()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_50(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_51();

std::expected<int, my_error_t> funct_group14_50()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_51(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_52();

std::expected<int, my_error_t> funct_group14_51()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_52(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_53();

std::expected<int, my_error_t> funct_group14_52()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_53(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_54();

std::expected<int, my_error_t> funct_group14_53()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_54(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_55();

std::expected<int, my_error_t> funct_group14_54()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_55(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_56();

std::expected<int, my_error_t> funct_group14_55()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_56(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_57();

std::expected<int, my_error_t> funct_group14_56()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_57(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_58();

std::expected<int, my_error_t> funct_group14_57()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_58(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_59();

std::expected<int, my_error_t> funct_group14_58()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_59(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_60();

std::expected<int, my_error_t> funct_group14_59()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_60(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_61();

std::expected<int, my_error_t> funct_group14_60()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_61(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_62();

std::expected<int, my_error_t> funct_group14_61()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_62(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_63();

std::expected<int, my_error_t> funct_group14_62()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_63(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_64();

std::expected<int, my_error_t> funct_group14_63()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_64(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_65();

std::expected<int, my_error_t> funct_group14_64()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_65(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_66();

std::expected<int, my_error_t> funct_group14_65()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_66(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_67();

std::expected<int, my_error_t> funct_group14_66()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_67(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_68();

std::expected<int, my_error_t> funct_group14_67()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_68(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_69();

std::expected<int, my_error_t> funct_group14_68()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_69(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_70();

std::expected<int, my_error_t> funct_group14_69()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_70(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_71();

std::expected<int, my_error_t> funct_group14_70()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_71(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_72();

std::expected<int, my_error_t> funct_group14_71()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_72(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_73();

std::expected<int, my_error_t> funct_group14_72()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_73(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_74();

std::expected<int, my_error_t> funct_group14_73()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_74(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_75();

std::expected<int, my_error_t> funct_group14_74()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_75(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_76();

std::expected<int, my_error_t> funct_group14_75()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_76(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_77();

std::expected<int, my_error_t> funct_group14_76()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_77(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_78();

std::expected<int, my_error_t> funct_group14_77()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_78(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_79();

std::expected<int, my_error_t> funct_group14_78()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_79(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_80();

std::expected<int, my_error_t> funct_group14_79()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_80(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_81();

std::expected<int, my_error_t> funct_group14_80()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_81(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_82();

std::expected<int, my_error_t> funct_group14_81()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_82(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_83();

std::expected<int, my_error_t> funct_group14_82()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_83(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_84();

std::expected<int, my_error_t> funct_group14_83()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_84(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_85();

std::expected<int, my_error_t> funct_group14_84()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_85(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_86();

std::expected<int, my_error_t> funct_group14_85()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_86(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_87();

std::expected<int, my_error_t> funct_group14_86()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_87(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_88();

std::expected<int, my_error_t> funct_group14_87()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_88(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_89();

std::expected<int, my_error_t> funct_group14_88()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_89(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_90();

std::expected<int, my_error_t> funct_group14_89()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_90(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_91();

std::expected<int, my_error_t> funct_group14_90()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_91(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_92();

std::expected<int, my_error_t> funct_group14_91()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_92(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_93();

std::expected<int, my_error_t> funct_group14_92()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_93(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_94();

std::expected<int, my_error_t> funct_group14_93()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_94(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_95();

std::expected<int, my_error_t> funct_group14_94()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group14_95(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group14_95()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (side_effect > 0) {
    return std::unexpected(my_error_t{ .data = { 0xDE, 0xAD } });
  }

  return side_effect;
}

std::expected<int, my_error_t> funct_group15_1();

std::expected<int, my_error_t> funct_group15_0()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group15_1(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group15_2();

std::expected<int, my_error_t> funct_group15_1()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group15_2(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group15_3();

std::expected<int, my_error_t> funct_group15_2()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group15_3(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group15_4();

std::expected<int, my_error_t> funct_group15_3()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group15_4(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group15_5();

std::expected<int, my_error_t> funct_group15_4()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group15_5(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group15_5()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (side_effect > 0) {
    return std::unexpected(my_error_t{ .data = { 0xDE, 0xAD } });
  }

  return side_effect;
}

std::expected<int, my_error_t> funct_group16_1();

std::expected<int, my_error_t> funct_group16_0()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group16_1(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group16_2();

std::expected<int, my_error_t> funct_group16_1()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group16_2(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group16_3();

std::expected<int, my_error_t> funct_group16_2()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group16_3(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group16_4();

std::expected<int, my_error_t> funct_group16_3()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group16_4(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group16_5();

std::expected<int, my_error_t> funct_group16_4()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group16_5(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group16_6();

std::expected<int, my_error_t> funct_group16_5()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group16_6(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group16_7();

std::expected<int, my_error_t> funct_group16_6()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group16_7(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group16_8();

std::expected<int, my_error_t> funct_group16_7()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group16_8(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group16_9();

std::expected<int, my_error_t> funct_group16_8()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group16_9(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group16_10();

std::expected<int, my_error_t> funct_group16_9()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group16_10(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group16_11();

std::expected<int, my_error_t> funct_group16_10()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group16_11(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group16_11()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (side_effect > 0) {
    return std::unexpected(my_error_t{ .data = { 0xDE, 0xAD } });
  }

  return side_effect;
}

std::expected<int, my_error_t> funct_group17_1();

std::expected<int, my_error_t> funct_group17_0()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group17_1(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group17_2();

std::expected<int, my_error_t> funct_group17_1()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group17_2(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group17_3();

std::expected<int, my_error_t> funct_group17_2()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group17_3(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group17_4();

std::expected<int, my_error_t> funct_group17_3()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group17_4(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group17_5();

std::expected<int, my_error_t> funct_group17_4()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group17_5(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group17_6();

std::expected<int, my_error_t> funct_group17_5()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group17_6(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group17_7();

std::expected<int, my_error_t> funct_group17_6()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group17_7(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group17_8();

std::expected<int, my_error_t> funct_group17_7()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group17_8(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group17_9();

std::expected<int, my_error_t> funct_group17_8()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group17_9(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group17_10();

std::expected<int, my_error_t> funct_group17_9()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group17_10(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group17_11();

std::expected<int, my_error_t> funct_group17_10()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group17_11(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group17_12();

std::expected<int, my_error_t> funct_group17_11()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group17_12(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group17_13();

std::expected<int, my_error_t> funct_group17_12()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group17_13(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group17_14();

std::expected<int, my_error_t> funct_group17_13()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group17_14(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group17_15();

std::expected<int, my_error_t> funct_group17_14()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group17_15(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group17_16();

std::expected<int, my_error_t> funct_group17_15()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group17_16(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group17_17();

std::expected<int, my_error_t> funct_group17_16()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group17_17(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group17_18();

std::expected<int, my_error_t> funct_group17_17()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group17_18(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group17_19();

std::expected<int, my_error_t> funct_group17_18()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group17_19(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group17_20();

std::expected<int, my_error_t> funct_group17_19()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group17_20(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group17_21();

std::expected<int, my_error_t> funct_group17_20()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group17_21(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group17_22();

std::expected<int, my_error_t> funct_group17_21()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group17_22(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group17_23();

std::expected<int, my_error_t> funct_group17_22()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group17_23(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group17_23()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (side_effect > 0) {
    return std::unexpected(my_error_t{ .data = { 0xDE, 0xAD } });
  }

  return side_effect;
}

std::expected<int, my_error_t> funct_group18_1();

std::expected<int, my_error_t> funct_group18_0()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group18_1(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group18_2();

std::expected<int, my_error_t> funct_group18_1()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group18_2(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group18_3();

std::expected<int, my_error_t> funct_group18_2()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group18_3(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group18_4();

std::expected<int, my_error_t> funct_group18_3()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group18_4(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group18_5();

std::expected<int, my_error_t> funct_group18_4()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group18_5(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group18_6();

std::expected<int, my_error_t> funct_group18_5()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group18_6(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group18_7();

std::expected<int, my_error_t> funct_group18_6()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group18_7(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group18_8();

std::expected<int, my_error_t> funct_group18_7()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group18_8(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group18_9();

std::expected<int, my_error_t> funct_group18_8()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group18_9(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group18_10();

std::expected<int, my_error_t> funct_group18_9()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group18_10(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group18_11();

std::expected<int, my_error_t> funct_group18_10()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group18_11(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group18_12();

std::expected<int, my_error_t> funct_group18_11()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group18_12(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group18_13();

std::expected<int, my_error_t> funct_group18_12()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group18_13(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group18_14();

std::expected<int, my_error_t> funct_group18_13()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group18_14(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group18_15();

std::expected<int, my_error_t> funct_group18_14()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group18_15(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group18_16();

std::expected<int, my_error_t> funct_group18_15()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group18_16(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group18_17();

std::expected<int, my_error_t> funct_group18_16()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group18_17(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group18_18();

std::expected<int, my_error_t> funct_group18_17()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group18_18(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group18_19();

std::expected<int, my_error_t> funct_group18_18()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group18_19(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group18_20();

std::expected<int, my_error_t> funct_group18_19()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group18_20(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group18_21();

std::expected<int, my_error_t> funct_group18_20()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group18_21(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group18_22();

std::expected<int, my_error_t> funct_group18_21()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group18_22(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group18_23();

std::expected<int, my_error_t> funct_group18_22()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group18_23(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group18_24();

std::expected<int, my_error_t> funct_group18_23()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group18_24(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group18_25();

std::expected<int, my_error_t> funct_group18_24()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group18_25(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group18_26();

std::expected<int, my_error_t> funct_group18_25()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group18_26(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group18_27();

std::expected<int, my_error_t> funct_group18_26()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group18_27(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group18_28();

std::expected<int, my_error_t> funct_group18_27()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group18_28(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group18_29();

std::expected<int, my_error_t> funct_group18_28()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group18_29(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group18_30();

std::expected<int, my_error_t> funct_group18_29()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group18_30(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group18_31();

std::expected<int, my_error_t> funct_group18_30()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group18_31(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group18_32();

std::expected<int, my_error_t> funct_group18_31()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group18_32(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group18_33();

std::expected<int, my_error_t> funct_group18_32()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group18_33(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group18_34();

std::expected<int, my_error_t> funct_group18_33()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group18_34(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group18_35();

std::expected<int, my_error_t> funct_group18_34()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group18_35(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group18_36();

std::expected<int, my_error_t> funct_group18_35()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group18_36(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group18_37();

std::expected<int, my_error_t> funct_group18_36()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group18_37(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group18_38();

std::expected<int, my_error_t> funct_group18_37()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group18_38(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group18_39();

std::expected<int, my_error_t> funct_group18_38()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group18_39(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group18_40();

std::expected<int, my_error_t> funct_group18_39()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group18_40(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group18_41();

std::expected<int, my_error_t> funct_group18_40()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group18_41(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group18_42();

std::expected<int, my_error_t> funct_group18_41()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group18_42(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group18_43();

std::expected<int, my_error_t> funct_group18_42()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group18_43(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group18_44();

std::expected<int, my_error_t> funct_group18_43()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group18_44(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group18_45();

std::expected<int, my_error_t> funct_group18_44()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group18_45(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group18_46();

std::expected<int, my_error_t> funct_group18_45()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group18_46(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group18_47();

std::expected<int, my_error_t> funct_group18_46()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group18_47(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group18_47()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (side_effect > 0) {
    return std::unexpected(my_error_t{ .data = { 0xDE, 0xAD } });
  }

  return side_effect;
}

std::expected<int, my_error_t> funct_group19_1();

std::expected<int, my_error_t> funct_group19_0()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_1(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_2();

std::expected<int, my_error_t> funct_group19_1()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_2(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_3();

std::expected<int, my_error_t> funct_group19_2()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_3(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_4();

std::expected<int, my_error_t> funct_group19_3()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_4(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_5();

std::expected<int, my_error_t> funct_group19_4()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_5(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_6();

std::expected<int, my_error_t> funct_group19_5()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_6(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_7();

std::expected<int, my_error_t> funct_group19_6()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_7(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_8();

std::expected<int, my_error_t> funct_group19_7()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_8(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_9();

std::expected<int, my_error_t> funct_group19_8()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_9(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_10();

std::expected<int, my_error_t> funct_group19_9()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_10(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_11();

std::expected<int, my_error_t> funct_group19_10()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_11(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_12();

std::expected<int, my_error_t> funct_group19_11()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_12(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_13();

std::expected<int, my_error_t> funct_group19_12()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_13(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_14();

std::expected<int, my_error_t> funct_group19_13()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_14(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_15();

std::expected<int, my_error_t> funct_group19_14()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_15(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_16();

std::expected<int, my_error_t> funct_group19_15()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_16(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_17();

std::expected<int, my_error_t> funct_group19_16()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_17(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_18();

std::expected<int, my_error_t> funct_group19_17()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_18(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_19();

std::expected<int, my_error_t> funct_group19_18()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_19(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_20();

std::expected<int, my_error_t> funct_group19_19()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_20(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_21();

std::expected<int, my_error_t> funct_group19_20()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_21(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_22();

std::expected<int, my_error_t> funct_group19_21()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_22(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_23();

std::expected<int, my_error_t> funct_group19_22()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_23(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_24();

std::expected<int, my_error_t> funct_group19_23()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_24(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_25();

std::expected<int, my_error_t> funct_group19_24()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_25(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_26();

std::expected<int, my_error_t> funct_group19_25()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_26(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_27();

std::expected<int, my_error_t> funct_group19_26()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_27(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_28();

std::expected<int, my_error_t> funct_group19_27()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_28(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_29();

std::expected<int, my_error_t> funct_group19_28()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_29(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_30();

std::expected<int, my_error_t> funct_group19_29()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_30(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_31();

std::expected<int, my_error_t> funct_group19_30()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_31(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_32();

std::expected<int, my_error_t> funct_group19_31()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_32(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_33();

std::expected<int, my_error_t> funct_group19_32()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_33(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_34();

std::expected<int, my_error_t> funct_group19_33()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_34(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_35();

std::expected<int, my_error_t> funct_group19_34()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_35(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_36();

std::expected<int, my_error_t> funct_group19_35()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_36(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_37();

std::expected<int, my_error_t> funct_group19_36()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_37(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_38();

std::expected<int, my_error_t> funct_group19_37()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_38(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_39();

std::expected<int, my_error_t> funct_group19_38()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_39(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_40();

std::expected<int, my_error_t> funct_group19_39()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_40(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_41();

std::expected<int, my_error_t> funct_group19_40()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_41(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_42();

std::expected<int, my_error_t> funct_group19_41()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_42(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_43();

std::expected<int, my_error_t> funct_group19_42()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_43(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_44();

std::expected<int, my_error_t> funct_group19_43()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_44(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_45();

std::expected<int, my_error_t> funct_group19_44()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_45(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_46();

std::expected<int, my_error_t> funct_group19_45()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_46(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_47();

std::expected<int, my_error_t> funct_group19_46()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_47(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_48();

std::expected<int, my_error_t> funct_group19_47()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_48(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_49();

std::expected<int, my_error_t> funct_group19_48()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_49(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_50();

std::expected<int, my_error_t> funct_group19_49()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_50(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_51();

std::expected<int, my_error_t> funct_group19_50()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_51(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_52();

std::expected<int, my_error_t> funct_group19_51()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_52(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_53();

std::expected<int, my_error_t> funct_group19_52()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_53(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_54();

std::expected<int, my_error_t> funct_group19_53()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_54(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_55();

std::expected<int, my_error_t> funct_group19_54()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_55(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_56();

std::expected<int, my_error_t> funct_group19_55()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_56(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_57();

std::expected<int, my_error_t> funct_group19_56()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_57(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_58();

std::expected<int, my_error_t> funct_group19_57()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_58(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_59();

std::expected<int, my_error_t> funct_group19_58()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_59(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_60();

std::expected<int, my_error_t> funct_group19_59()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_60(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_61();

std::expected<int, my_error_t> funct_group19_60()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_61(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_62();

std::expected<int, my_error_t> funct_group19_61()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_62(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_63();

std::expected<int, my_error_t> funct_group19_62()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_63(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_64();

std::expected<int, my_error_t> funct_group19_63()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_64(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_65();

std::expected<int, my_error_t> funct_group19_64()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_65(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_66();

std::expected<int, my_error_t> funct_group19_65()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_66(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_67();

std::expected<int, my_error_t> funct_group19_66()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_67(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_68();

std::expected<int, my_error_t> funct_group19_67()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_68(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_69();

std::expected<int, my_error_t> funct_group19_68()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_69(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_70();

std::expected<int, my_error_t> funct_group19_69()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_70(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_71();

std::expected<int, my_error_t> funct_group19_70()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_71(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_72();

std::expected<int, my_error_t> funct_group19_71()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_72(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_73();

std::expected<int, my_error_t> funct_group19_72()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_73(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_74();

std::expected<int, my_error_t> funct_group19_73()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_74(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_75();

std::expected<int, my_error_t> funct_group19_74()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_75(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_76();

std::expected<int, my_error_t> funct_group19_75()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_76(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_77();

std::expected<int, my_error_t> funct_group19_76()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_77(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_78();

std::expected<int, my_error_t> funct_group19_77()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_78(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_79();

std::expected<int, my_error_t> funct_group19_78()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_79(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_80();

std::expected<int, my_error_t> funct_group19_79()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_80(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_81();

std::expected<int, my_error_t> funct_group19_80()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_81(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_82();

std::expected<int, my_error_t> funct_group19_81()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_82(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_83();

std::expected<int, my_error_t> funct_group19_82()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_83(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_84();

std::expected<int, my_error_t> funct_group19_83()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_84(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_85();

std::expected<int, my_error_t> funct_group19_84()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_85(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_86();

std::expected<int, my_error_t> funct_group19_85()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_86(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_87();

std::expected<int, my_error_t> funct_group19_86()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_87(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_88();

std::expected<int, my_error_t> funct_group19_87()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_88(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_89();

std::expected<int, my_error_t> funct_group19_88()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_89(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_90();

std::expected<int, my_error_t> funct_group19_89()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_90(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_91();

std::expected<int, my_error_t> funct_group19_90()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_91(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_92();

std::expected<int, my_error_t> funct_group19_91()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_92(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_93();

std::expected<int, my_error_t> funct_group19_92()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_93(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_94();

std::expected<int, my_error_t> funct_group19_93()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_94(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_95();

std::expected<int, my_error_t> funct_group19_94()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_0::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group19_95(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group19_95()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (side_effect > 0) {
    return std::unexpected(my_error_t{ .data = { 0xDE, 0xAD } });
  }

  return side_effect;
}

std::expected<int, my_error_t> funct_group20_1();

std::expected<int, my_error_t> funct_group20_0()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group20_1(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group20_2();

std::expected<int, my_error_t> funct_group20_1()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group20_2(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group20_3();

std::expected<int, my_error_t> funct_group20_2()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group20_3(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group20_4();

std::expected<int, my_error_t> funct_group20_3()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group20_4(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group20_5();

std::expected<int, my_error_t> funct_group20_4()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group20_5(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group20_5()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (side_effect > 0) {
    return std::unexpected(my_error_t{ .data = { 0xDE, 0xAD } });
  }

  return side_effect;
}

std::expected<int, my_error_t> funct_group21_1();

std::expected<int, my_error_t> funct_group21_0()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group21_1(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group21_2();

std::expected<int, my_error_t> funct_group21_1()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group21_2(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group21_3();

std::expected<int, my_error_t> funct_group21_2()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group21_3(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group21_4();

std::expected<int, my_error_t> funct_group21_3()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group21_4(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group21_5();

std::expected<int, my_error_t> funct_group21_4()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group21_5(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group21_6();

std::expected<int, my_error_t> funct_group21_5()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group21_6(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group21_7();

std::expected<int, my_error_t> funct_group21_6()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group21_7(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group21_8();

std::expected<int, my_error_t> funct_group21_7()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group21_8(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group21_9();

std::expected<int, my_error_t> funct_group21_8()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group21_9(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group21_10();

std::expected<int, my_error_t> funct_group21_9()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group21_10(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group21_11();

std::expected<int, my_error_t> funct_group21_10()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group21_11(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group21_11()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (side_effect > 0) {
    return std::unexpected(my_error_t{ .data = { 0xDE, 0xAD } });
  }

  return side_effect;
}

std::expected<int, my_error_t> funct_group22_1();

std::expected<int, my_error_t> funct_group22_0()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group22_1(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group22_2();

std::expected<int, my_error_t> funct_group22_1()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group22_2(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group22_3();

std::expected<int, my_error_t> funct_group22_2()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group22_3(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group22_4();

std::expected<int, my_error_t> funct_group22_3()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group22_4(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group22_5();

std::expected<int, my_error_t> funct_group22_4()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group22_5(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group22_6();

std::expected<int, my_error_t> funct_group22_5()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group22_6(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group22_7();

std::expected<int, my_error_t> funct_group22_6()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group22_7(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group22_8();

std::expected<int, my_error_t> funct_group22_7()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group22_8(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group22_9();

std::expected<int, my_error_t> funct_group22_8()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group22_9(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group22_10();

std::expected<int, my_error_t> funct_group22_9()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group22_10(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group22_11();

std::expected<int, my_error_t> funct_group22_10()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group22_11(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group22_12();

std::expected<int, my_error_t> funct_group22_11()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group22_12(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group22_13();

std::expected<int, my_error_t> funct_group22_12()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group22_13(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group22_14();

std::expected<int, my_error_t> funct_group22_13()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group22_14(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group22_15();

std::expected<int, my_error_t> funct_group22_14()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group22_15(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group22_16();

std::expected<int, my_error_t> funct_group22_15()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group22_16(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group22_17();

std::expected<int, my_error_t> funct_group22_16()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group22_17(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group22_18();

std::expected<int, my_error_t> funct_group22_17()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group22_18(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group22_19();

std::expected<int, my_error_t> funct_group22_18()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group22_19(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group22_20();

std::expected<int, my_error_t> funct_group22_19()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group22_20(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group22_21();

std::expected<int, my_error_t> funct_group22_20()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group22_21(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group22_22();

std::expected<int, my_error_t> funct_group22_21()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group22_22(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group22_23();

std::expected<int, my_error_t> funct_group22_22()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group22_23(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group22_23()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (side_effect > 0) {
    return std::unexpected(my_error_t{ .data = { 0xDE, 0xAD } });
  }

  return side_effect;
}

std::expected<int, my_error_t> funct_group23_1();

std::expected<int, my_error_t> funct_group23_0()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group23_1(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group23_2();

std::expected<int, my_error_t> funct_group23_1()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group23_2(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group23_3();

std::expected<int, my_error_t> funct_group23_2()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group23_3(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group23_4();

std::expected<int, my_error_t> funct_group23_3()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group23_4(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group23_5();

std::expected<int, my_error_t> funct_group23_4()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group23_5(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group23_6();

std::expected<int, my_error_t> funct_group23_5()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group23_6(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group23_7();

std::expected<int, my_error_t> funct_group23_6()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group23_7(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group23_8();

std::expected<int, my_error_t> funct_group23_7()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group23_8(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group23_9();

std::expected<int, my_error_t> funct_group23_8()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group23_9(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group23_10();

std::expected<int, my_error_t> funct_group23_9()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group23_10(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group23_11();

std::expected<int, my_error_t> funct_group23_10()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group23_11(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group23_12();

std::expected<int, my_error_t> funct_group23_11()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group23_12(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group23_13();

std::expected<int, my_error_t> funct_group23_12()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group23_13(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group23_14();

std::expected<int, my_error_t> funct_group23_13()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group23_14(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group23_15();

std::expected<int, my_error_t> funct_group23_14()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group23_15(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group23_16();

std::expected<int, my_error_t> funct_group23_15()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group23_16(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group23_17();

std::expected<int, my_error_t> funct_group23_16()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group23_17(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group23_18();

std::expected<int, my_error_t> funct_group23_17()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group23_18(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group23_19();

std::expected<int, my_error_t> funct_group23_18()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group23_19(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group23_20();

std::expected<int, my_error_t> funct_group23_19()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group23_20(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group23_21();

std::expected<int, my_error_t> funct_group23_20()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group23_21(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group23_22();

std::expected<int, my_error_t> funct_group23_21()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group23_22(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group23_23();

std::expected<int, my_error_t> funct_group23_22()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group23_23(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group23_24();

std::expected<int, my_error_t> funct_group23_23()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group23_24(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group23_25();

std::expected<int, my_error_t> funct_group23_24()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group23_25(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group23_26();

std::expected<int, my_error_t> funct_group23_25()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group23_26(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group23_27();

std::expected<int, my_error_t> funct_group23_26()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group23_27(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group23_28();

std::expected<int, my_error_t> funct_group23_27()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group23_28(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group23_29();

std::expected<int, my_error_t> funct_group23_28()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group23_29(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group23_30();

std::expected<int, my_error_t> funct_group23_29()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group23_30(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group23_31();

std::expected<int, my_error_t> funct_group23_30()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group23_31(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group23_32();

std::expected<int, my_error_t> funct_group23_31()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group23_32(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group23_33();

std::expected<int, my_error_t> funct_group23_32()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group23_33(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group23_34();

std::expected<int, my_error_t> funct_group23_33()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group23_34(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group23_35();

std::expected<int, my_error_t> funct_group23_34()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group23_35(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group23_36();

std::expected<int, my_error_t> funct_group23_35()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group23_36(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group23_37();

std::expected<int, my_error_t> funct_group23_36()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group23_37(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group23_38();

std::expected<int, my_error_t> funct_group23_37()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group23_38(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group23_39();

std::expected<int, my_error_t> funct_group23_38()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group23_39(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group23_40();

std::expected<int, my_error_t> funct_group23_39()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group23_40(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group23_41();

std::expected<int, my_error_t> funct_group23_40()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group23_41(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group23_42();

std::expected<int, my_error_t> funct_group23_41()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group23_42(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group23_43();

std::expected<int, my_error_t> funct_group23_42()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group23_43(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group23_44();

std::expected<int, my_error_t> funct_group23_43()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group23_44(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group23_45();

std::expected<int, my_error_t> funct_group23_44()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group23_45(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group23_46();

std::expected<int, my_error_t> funct_group23_45()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group23_46(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group23_47();

std::expected<int, my_error_t> funct_group23_46()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group23_47(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group23_47()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (side_effect > 0) {
    return std::unexpected(my_error_t{ .data = { 0xDE, 0xAD } });
  }

  return side_effect;
}

std::expected<int, my_error_t> funct_group24_1();

std::expected<int, my_error_t> funct_group24_0()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_1(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_2();

std::expected<int, my_error_t> funct_group24_1()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_2(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_3();

std::expected<int, my_error_t> funct_group24_2()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_3(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_4();

std::expected<int, my_error_t> funct_group24_3()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_4(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_5();

std::expected<int, my_error_t> funct_group24_4()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_5(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_6();

std::expected<int, my_error_t> funct_group24_5()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_6(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_7();

std::expected<int, my_error_t> funct_group24_6()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_7(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_8();

std::expected<int, my_error_t> funct_group24_7()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_8(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_9();

std::expected<int, my_error_t> funct_group24_8()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_9(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_10();

std::expected<int, my_error_t> funct_group24_9()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_10(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_11();

std::expected<int, my_error_t> funct_group24_10()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_11(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_12();

std::expected<int, my_error_t> funct_group24_11()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_12(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_13();

std::expected<int, my_error_t> funct_group24_12()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_13(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_14();

std::expected<int, my_error_t> funct_group24_13()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_14(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_15();

std::expected<int, my_error_t> funct_group24_14()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_15(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_16();

std::expected<int, my_error_t> funct_group24_15()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_16(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_17();

std::expected<int, my_error_t> funct_group24_16()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_17(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_18();

std::expected<int, my_error_t> funct_group24_17()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_18(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_19();

std::expected<int, my_error_t> funct_group24_18()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_19(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_20();

std::expected<int, my_error_t> funct_group24_19()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_20(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_21();

std::expected<int, my_error_t> funct_group24_20()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_21(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_22();

std::expected<int, my_error_t> funct_group24_21()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_22(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_23();

std::expected<int, my_error_t> funct_group24_22()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_23(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_24();

std::expected<int, my_error_t> funct_group24_23()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_24(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_25();

std::expected<int, my_error_t> funct_group24_24()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_25(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_26();

std::expected<int, my_error_t> funct_group24_25()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_26(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_27();

std::expected<int, my_error_t> funct_group24_26()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_27(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_28();

std::expected<int, my_error_t> funct_group24_27()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_28(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_29();

std::expected<int, my_error_t> funct_group24_28()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_29(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_30();

std::expected<int, my_error_t> funct_group24_29()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_30(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_31();

std::expected<int, my_error_t> funct_group24_30()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_31(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_32();

std::expected<int, my_error_t> funct_group24_31()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_32(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_33();

std::expected<int, my_error_t> funct_group24_32()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_33(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_34();

std::expected<int, my_error_t> funct_group24_33()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_34(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_35();

std::expected<int, my_error_t> funct_group24_34()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_35(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_36();

std::expected<int, my_error_t> funct_group24_35()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_36(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_37();

std::expected<int, my_error_t> funct_group24_36()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_37(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_38();

std::expected<int, my_error_t> funct_group24_37()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_38(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_39();

std::expected<int, my_error_t> funct_group24_38()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_39(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_40();

std::expected<int, my_error_t> funct_group24_39()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_40(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_41();

std::expected<int, my_error_t> funct_group24_40()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_41(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_42();

std::expected<int, my_error_t> funct_group24_41()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_42(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_43();

std::expected<int, my_error_t> funct_group24_42()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_43(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_44();

std::expected<int, my_error_t> funct_group24_43()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_44(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_45();

std::expected<int, my_error_t> funct_group24_44()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_45(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_46();

std::expected<int, my_error_t> funct_group24_45()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_46(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_47();

std::expected<int, my_error_t> funct_group24_46()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_47(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_48();

std::expected<int, my_error_t> funct_group24_47()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_48(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_49();

std::expected<int, my_error_t> funct_group24_48()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_49(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_50();

std::expected<int, my_error_t> funct_group24_49()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_50(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_51();

std::expected<int, my_error_t> funct_group24_50()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_51(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_52();

std::expected<int, my_error_t> funct_group24_51()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_52(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_53();

std::expected<int, my_error_t> funct_group24_52()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_53(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_54();

std::expected<int, my_error_t> funct_group24_53()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_54(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_55();

std::expected<int, my_error_t> funct_group24_54()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_55(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_56();

std::expected<int, my_error_t> funct_group24_55()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_56(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_57();

std::expected<int, my_error_t> funct_group24_56()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_57(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_58();

std::expected<int, my_error_t> funct_group24_57()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_58(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_59();

std::expected<int, my_error_t> funct_group24_58()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_59(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_60();

std::expected<int, my_error_t> funct_group24_59()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_60(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_61();

std::expected<int, my_error_t> funct_group24_60()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_61(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_62();

std::expected<int, my_error_t> funct_group24_61()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_62(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_63();

std::expected<int, my_error_t> funct_group24_62()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_63(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_64();

std::expected<int, my_error_t> funct_group24_63()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_64(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_65();

std::expected<int, my_error_t> funct_group24_64()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_65(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_66();

std::expected<int, my_error_t> funct_group24_65()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_66(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_67();

std::expected<int, my_error_t> funct_group24_66()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_67(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_68();

std::expected<int, my_error_t> funct_group24_67()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_68(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_69();

std::expected<int, my_error_t> funct_group24_68()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_69(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_70();

std::expected<int, my_error_t> funct_group24_69()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_70(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_71();

std::expected<int, my_error_t> funct_group24_70()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_71(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_72();

std::expected<int, my_error_t> funct_group24_71()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_72(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_73();

std::expected<int, my_error_t> funct_group24_72()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_73(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_74();

std::expected<int, my_error_t> funct_group24_73()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_74(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_75();

std::expected<int, my_error_t> funct_group24_74()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_75(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_76();

std::expected<int, my_error_t> funct_group24_75()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_76(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_77();

std::expected<int, my_error_t> funct_group24_76()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_77(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_78();

std::expected<int, my_error_t> funct_group24_77()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_78(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_79();

std::expected<int, my_error_t> funct_group24_78()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_79(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_80();

std::expected<int, my_error_t> funct_group24_79()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_80(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_81();

std::expected<int, my_error_t> funct_group24_80()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_81(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_82();

std::expected<int, my_error_t> funct_group24_81()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_82(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_83();

std::expected<int, my_error_t> funct_group24_82()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_83(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_84();

std::expected<int, my_error_t> funct_group24_83()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_84(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_85();

std::expected<int, my_error_t> funct_group24_84()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_85(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_86();

std::expected<int, my_error_t> funct_group24_85()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_86(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_87();

std::expected<int, my_error_t> funct_group24_86()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_87(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_88();

std::expected<int, my_error_t> funct_group24_87()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_88(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_89();

std::expected<int, my_error_t> funct_group24_88()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_89(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_90();

std::expected<int, my_error_t> funct_group24_89()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_90(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_91();

std::expected<int, my_error_t> funct_group24_90()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_91(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_92();

std::expected<int, my_error_t> funct_group24_91()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_92(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_93();

std::expected<int, my_error_t> funct_group24_92()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_93(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_94();

std::expected<int, my_error_t> funct_group24_93()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_94(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_95();

std::expected<int, my_error_t> funct_group24_94()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (auto result = funct_group24_95(); !result) {
    return std::unexpected(result.error());
  } else {
    side_effect = side_effect + result.value();
  }
  return side_effect;
}

std::expected<int, my_error_t> funct_group24_95()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;

  auto instance_0 = class_1::create(side_effect);
  if (!instance_0) {
    return std::unexpected(instance_0.error());
  }
  {
    auto scoped_result = instance_0.value().trigger();
    if (!scoped_result) {
      return std::unexpected(scoped_result.error());
    }
  }
  if (side_effect > 0) {
    return std::unexpected(my_error_t{ .data = { 0xDE, 0xAD } });
  }

  return side_effect;
}
