#include <array>

#include "../resource_list.hpp"

int start();

std::int32_t volatile side_effect = 0;
std::uint32_t start_cycles = 0;
std::uint32_t end_cycles = 0;

resource_list* resources;

std::array<std::uint64_t, 25> cycle_map{};
std::array<std::uint64_t, 25> happy_cycle_map{};

struct my_error_t
{
  std::array<std::uint8_t, 4> data;
};

int funct_group0_0();
int funct_group1_0();
int funct_group2_0();
int funct_group3_0();
int funct_group4_0();
int funct_group5_0();
int funct_group6_0();
int funct_group7_0();
int funct_group8_0();
// int funct_group9_0();
// int funct_group10_0();
// int funct_group11_0();
// int funct_group12_0();
// int funct_group13_0();
// int funct_group14_0();
// int funct_group15_0();
// int funct_group16_0();
// int funct_group17_0();
// int funct_group18_0();
// int funct_group19_0();
// int funct_group20_0();
// int funct_group21_0();
// int funct_group22_0();
// int funct_group23_0();
// int funct_group24_0();

using signature = int(void);

std::array<signature*, 9> functions = {
  &funct_group0_0, &funct_group1_0, &funct_group2_0,
  &funct_group3_0, &funct_group4_0, &funct_group5_0,
  &funct_group6_0, &funct_group7_0, &funct_group8_0,
#if 0
  funct_group9_0,  funct_group10_0, funct_group11_0,
  funct_group12_0, funct_group13_0, funct_group14_0, funct_group15_0,
  funct_group16_0,
  funct_group17_0, funct_group18_0, funct_group19_0,
  funct_group20_0, funct_group21_0, funct_group22_0, funct_group23_0,
  funct_group24_0
#endif
};

std::uint64_t allocation_cycles = 0;

void application(resource_list& p_resources)
{
  resources = &p_resources;

  cycle_map.fill(std::numeric_limits<std::int32_t>::max());
  happy_cycle_map.fill(std::numeric_limits<std::int32_t>::max());
  for (std::size_t i = 0; i < functions.size(); i++) {
    try {
      functions.at(i)();
      // NOTE to Khalil before submission. Something is wrong with the unwinder
      // and we are jumping to different locations when it completes the first
      // time. Local variables are probably being damaged or the stack pointer
      // is not in the correct location.
    } catch ([[maybe_unused]] my_error_t const& p_error) {
      end_cycles = resources->clock->uptime();
      cycle_map[i] = end_cycles - start_cycles;
    }
  }

#if 1
  for (std::size_t i = 0; i < functions.size(); i++) {
    bool was_caught = false;
    try {
      // should prevent throw from executing
      side_effect = -1'000'000'000;
      functions.at(i)();
    } catch ([[maybe_unused]] my_error_t const& p_error) {
      was_caught = true;
    }
    if (!was_caught) {
      end_cycles = resources->clock->uptime();
      happy_cycle_map[i] = end_cycles - start_cycles;
    }
  }
#endif

  while (true) {
    continue;
  }
}

class class_0
{
public:
  class_0(std::int32_t p_channel)
    : m_channel(p_channel)
  {
    if (m_channel >= 1'000'000'000) {
      throw my_error_t{ .data = { 0x55, 0xAA, 0x33, 0x44 } };
    }
    side_effect = side_effect + 1;
  }

  class_0(class_0&) = delete;
  class_0& operator=(class_0&) = delete;
  class_0(class_0&&) noexcept = default;
  class_0& operator=(class_0&&) noexcept = default;
  ~class_0() = default;
  void trigger()
  {
    if (m_channel >= 1'000'000'000) {
      throw my_error_t{ .data = { 0xAA, 0xBB, 0x33, 0x44 } };
    }
    side_effect = side_effect + 1;
  }

private:
  std::int32_t m_channel = 0;
};

class class_1
{
public:
  class_1(std::int32_t p_channel)
    : m_channel(p_channel)
  {
    if (m_channel >= 1'000'000'000) {
      throw my_error_t{ .data = { 0x55, 0xAA, 0x33, 0x44 } };
    }
    side_effect = side_effect + 1;
  }

  class_1(class_1&) = delete;
  class_1& operator=(class_1&) = delete;
  class_1(class_1&&) noexcept = default;
  class_1& operator=(class_1&&) noexcept = default;
#if 0
  ~class_1() = default;
#else
  ~class_1()
  {
    side_effect = side_effect & ~(1 << m_channel);
  }
#endif

  void trigger()
  {
    if (m_channel >= 1'000'000'000) {
      throw my_error_t{ .data = { 0xAA, 0xBB, 0x33, 0x44 } };
    }
    side_effect = side_effect + 1;
  }

private:
  std::int32_t m_channel = 0;
};

int funct_group0_1();

int funct_group0_0()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group0_1();
  return side_effect;
}

int funct_group0_2();

int funct_group0_1()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group0_2();
  return side_effect;
}

int funct_group0_3();

int funct_group0_2()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group0_3();
  return side_effect;
}

int funct_group0_4();

int funct_group0_3()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group0_4();
  return side_effect;
}

int funct_group0_5();

int funct_group0_4()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  static float volatile my_float = 0.0f;
  my_float = my_float + 5.5f;
  instance_0.trigger();
  side_effect = side_effect + funct_group0_5();
  return side_effect;
}

int funct_group0_5()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();

  if (side_effect > 0) {
    start_cycles = resources->clock->uptime();
    throw my_error_t{ .data = { 0xDE, 0xAD } };
  }

  return side_effect;
}

int funct_group1_1();

int funct_group1_0()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group1_1();
  return side_effect;
}

int funct_group1_2();

int funct_group1_1()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group1_2();
  return side_effect;
}

int funct_group1_3();

int funct_group1_2()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group1_3();
  return side_effect;
}

int funct_group1_4();

int funct_group1_3()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group1_4();
  return side_effect;
}

int funct_group1_5();

int funct_group1_4()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group1_5();
  return side_effect;
}

int funct_group1_6();

int funct_group1_5()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group1_6();
  return side_effect;
}

int funct_group1_7();

int funct_group1_6()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group1_7();
  return side_effect;
}

int funct_group1_8();

int funct_group1_7()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group1_8();
  return side_effect;
}

int funct_group1_9();

int funct_group1_8()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group1_9();
  return side_effect;
}

int funct_group1_10();

int funct_group1_9()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group1_10();
  return side_effect;
}

int funct_group1_11();

int funct_group1_10()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group1_11();
  return side_effect;
}

int funct_group1_11()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();

  if (side_effect > 0) {
    start_cycles = resources->clock->uptime();
    throw my_error_t{ .data = { 0xBE, 0xEF } };
  }

  return side_effect;
}

int funct_group2_1();

int funct_group2_0()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group2_1();
  return side_effect;
}

int funct_group2_2();

int funct_group2_1()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group2_2();
  return side_effect;
}

int funct_group2_3();

int funct_group2_2()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group2_3();
  return side_effect;
}

int funct_group2_4();

int funct_group2_3()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group2_4();
  return side_effect;
}

int funct_group2_5();

int funct_group2_4()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group2_5();
  return side_effect;
}

int funct_group2_6();

int funct_group2_5()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group2_6();
  return side_effect;
}

int funct_group2_7();

int funct_group2_6()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group2_7();
  return side_effect;
}

int funct_group2_8();

int funct_group2_7()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group2_8();
  return side_effect;
}

int funct_group2_9();

int funct_group2_8()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group2_9();
  return side_effect;
}

int funct_group2_10();

int funct_group2_9()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group2_10();
  return side_effect;
}

int funct_group2_11();

int funct_group2_10()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group2_11();
  return side_effect;
}

int funct_group2_12();

int funct_group2_11()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group2_12();
  return side_effect;
}

int funct_group2_13();

int funct_group2_12()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group2_13();
  return side_effect;
}

int funct_group2_14();

int funct_group2_13()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group2_14();
  return side_effect;
}

int funct_group2_15();

int funct_group2_14()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group2_15();
  return side_effect;
}

int funct_group2_16();

int funct_group2_15()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group2_16();
  return side_effect;
}

int funct_group2_17();

int funct_group2_16()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group2_17();
  return side_effect;
}

int funct_group2_18();

int funct_group2_17()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group2_18();
  return side_effect;
}

int funct_group2_19();

int funct_group2_18()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group2_19();
  return side_effect;
}

int funct_group2_20();

int funct_group2_19()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group2_20();
  return side_effect;
}

int funct_group2_21();

int funct_group2_20()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group2_21();
  return side_effect;
}

int funct_group2_22();

int funct_group2_21()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group2_22();
  return side_effect;
}

int funct_group2_23();

int funct_group2_22()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group2_23();
  return side_effect;
}

int funct_group2_23()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();

  if (side_effect > 0) {
    start_cycles = resources->clock->uptime();
    throw my_error_t{ .data = { 0xDE, 0xAD } };
  }

  return side_effect;
}

int funct_group3_1();

int funct_group3_0()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group3_1();
  return side_effect;
}

int funct_group3_2();

int funct_group3_1()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group3_2();
  return side_effect;
}

int funct_group3_3();

int funct_group3_2()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group3_3();
  return side_effect;
}

int funct_group3_4();

int funct_group3_3()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group3_4();
  return side_effect;
}

int funct_group3_5();

int funct_group3_4()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group3_5();
  return side_effect;
}

int funct_group3_6();

int funct_group3_5()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group3_6();
  return side_effect;
}

int funct_group3_7();

int funct_group3_6()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group3_7();
  return side_effect;
}

int funct_group3_8();

int funct_group3_7()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group3_8();
  return side_effect;
}

int funct_group3_9();

int funct_group3_8()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group3_9();
  return side_effect;
}

int funct_group3_10();

int funct_group3_9()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group3_10();
  return side_effect;
}

int funct_group3_11();

int funct_group3_10()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group3_11();
  return side_effect;
}

int funct_group3_12();

int funct_group3_11()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group3_12();
  return side_effect;
}

int funct_group3_13();

int funct_group3_12()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group3_13();
  return side_effect;
}

int funct_group3_14();

int funct_group3_13()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group3_14();
  return side_effect;
}

int funct_group3_15();

int funct_group3_14()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group3_15();
  return side_effect;
}

int funct_group3_16();

int funct_group3_15()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group3_16();
  return side_effect;
}

int funct_group3_17();

int funct_group3_16()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group3_17();
  return side_effect;
}

int funct_group3_18();

int funct_group3_17()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group3_18();
  return side_effect;
}

int funct_group3_19();

int funct_group3_18()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group3_19();
  return side_effect;
}

int funct_group3_20();

int funct_group3_19()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group3_20();
  return side_effect;
}

int funct_group3_21();

int funct_group3_20()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group3_21();
  return side_effect;
}

int funct_group3_22();

int funct_group3_21()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group3_22();
  return side_effect;
}

int funct_group3_23();

int funct_group3_22()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group3_23();
  return side_effect;
}

int funct_group3_24();

int funct_group3_23()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group3_24();
  return side_effect;
}

int funct_group3_25();

int funct_group3_24()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group3_25();
  return side_effect;
}

int funct_group3_26();

int funct_group3_25()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group3_26();
  return side_effect;
}

int funct_group3_27();

int funct_group3_26()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group3_27();
  return side_effect;
}

int funct_group3_28();

int funct_group3_27()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group3_28();
  return side_effect;
}

int funct_group3_29();

int funct_group3_28()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group3_29();
  return side_effect;
}

int funct_group3_30();

int funct_group3_29()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group3_30();
  return side_effect;
}

int funct_group3_31();

int funct_group3_30()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group3_31();
  return side_effect;
}

int funct_group3_32();

int funct_group3_31()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group3_32();
  return side_effect;
}

int funct_group3_33();

int funct_group3_32()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group3_33();
  return side_effect;
}

int funct_group3_34();

int funct_group3_33()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group3_34();
  return side_effect;
}

int funct_group3_35();

int funct_group3_34()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group3_35();
  return side_effect;
}

int funct_group3_36();

int funct_group3_35()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group3_36();
  return side_effect;
}

int funct_group3_37();

int funct_group3_36()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group3_37();
  return side_effect;
}

int funct_group3_38();

int funct_group3_37()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group3_38();
  return side_effect;
}

int funct_group3_39();

int funct_group3_38()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group3_39();
  return side_effect;
}

int funct_group3_40();

int funct_group3_39()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group3_40();
  return side_effect;
}

int funct_group3_41();

int funct_group3_40()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group3_41();
  return side_effect;
}

int funct_group3_42();

int funct_group3_41()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group3_42();
  return side_effect;
}

int funct_group3_43();

int funct_group3_42()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group3_43();
  return side_effect;
}

int funct_group3_44();

int funct_group3_43()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group3_44();
  return side_effect;
}

int funct_group3_45();

int funct_group3_44()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group3_45();
  return side_effect;
}

int funct_group3_46();

int funct_group3_45()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group3_46();
  return side_effect;
}

int funct_group3_47();

int funct_group3_46()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group3_47();
  return side_effect;
}

int funct_group3_47()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();

  if (side_effect > 0) {
    start_cycles = resources->clock->uptime();
    throw my_error_t{ .data = { 0xDE, 0xAD } };
  }

  return side_effect;
}

int funct_group4_1();

int funct_group4_0()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_1();
  return side_effect;
}

int funct_group4_2();

int funct_group4_1()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_2();
  return side_effect;
}

int funct_group4_3();

int funct_group4_2()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_3();
  return side_effect;
}

int funct_group4_4();

int funct_group4_3()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_4();
  return side_effect;
}

int funct_group4_5();

int funct_group4_4()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_5();
  return side_effect;
}

int funct_group4_6();

int funct_group4_5()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_6();
  return side_effect;
}

int funct_group4_7();

int funct_group4_6()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_7();
  return side_effect;
}

int funct_group4_8();

int funct_group4_7()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_8();
  return side_effect;
}

int funct_group4_9();

int funct_group4_8()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_9();
  return side_effect;
}

int funct_group4_10();

int funct_group4_9()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_10();
  return side_effect;
}

int funct_group4_11();

int funct_group4_10()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_11();
  return side_effect;
}

int funct_group4_12();

int funct_group4_11()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_12();
  return side_effect;
}

int funct_group4_13();

int funct_group4_12()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_13();
  return side_effect;
}

int funct_group4_14();

int funct_group4_13()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_14();
  return side_effect;
}

int funct_group4_15();

int funct_group4_14()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_15();
  return side_effect;
}

int funct_group4_16();

int funct_group4_15()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_16();
  return side_effect;
}

int funct_group4_17();

int funct_group4_16()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_17();
  return side_effect;
}

int funct_group4_18();

int funct_group4_17()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_18();
  return side_effect;
}

int funct_group4_19();

int funct_group4_18()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_19();
  return side_effect;
}

int funct_group4_20();

int funct_group4_19()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_20();
  return side_effect;
}

int funct_group4_21();

int funct_group4_20()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_21();
  return side_effect;
}

int funct_group4_22();

int funct_group4_21()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_22();
  return side_effect;
}

int funct_group4_23();

int funct_group4_22()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_23();
  return side_effect;
}

int funct_group4_24();

int funct_group4_23()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_24();
  return side_effect;
}

int funct_group4_25();

int funct_group4_24()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_25();
  return side_effect;
}

int funct_group4_26();

int funct_group4_25()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_26();
  return side_effect;
}

int funct_group4_27();

int funct_group4_26()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_27();
  return side_effect;
}

int funct_group4_28();

int funct_group4_27()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_28();
  return side_effect;
}

int funct_group4_29();

int funct_group4_28()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_29();
  return side_effect;
}

int funct_group4_30();

int funct_group4_29()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_30();
  return side_effect;
}

int funct_group4_31();

int funct_group4_30()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_31();
  return side_effect;
}

int funct_group4_32();

int funct_group4_31()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_32();
  return side_effect;
}

int funct_group4_33();

int funct_group4_32()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_33();
  return side_effect;
}

int funct_group4_34();

int funct_group4_33()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_34();
  return side_effect;
}

int funct_group4_35();

int funct_group4_34()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_35();
  return side_effect;
}

int funct_group4_36();

int funct_group4_35()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_36();
  return side_effect;
}

int funct_group4_37();

int funct_group4_36()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_37();
  return side_effect;
}

int funct_group4_38();

int funct_group4_37()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_38();
  return side_effect;
}

int funct_group4_39();

int funct_group4_38()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_39();
  return side_effect;
}

int funct_group4_40();

int funct_group4_39()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_40();
  return side_effect;
}

int funct_group4_41();

int funct_group4_40()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_41();
  return side_effect;
}

int funct_group4_42();

int funct_group4_41()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_42();
  return side_effect;
}

int funct_group4_43();

int funct_group4_42()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_43();
  return side_effect;
}

int funct_group4_44();

int funct_group4_43()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_44();
  return side_effect;
}

int funct_group4_45();

int funct_group4_44()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_45();
  return side_effect;
}

int funct_group4_46();

int funct_group4_45()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_46();
  return side_effect;
}

int funct_group4_47();

int funct_group4_46()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_47();
  return side_effect;
}

int funct_group4_48();

int funct_group4_47()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_48();
  return side_effect;
}

int funct_group4_49();

int funct_group4_48()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_49();
  return side_effect;
}

int funct_group4_50();

int funct_group4_49()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_50();
  return side_effect;
}

int funct_group4_51();

int funct_group4_50()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_51();
  return side_effect;
}

int funct_group4_52();

int funct_group4_51()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_52();
  return side_effect;
}

int funct_group4_53();

int funct_group4_52()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_53();
  return side_effect;
}

int funct_group4_54();

int funct_group4_53()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_54();
  return side_effect;
}

int funct_group4_55();

int funct_group4_54()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_55();
  return side_effect;
}

int funct_group4_56();

int funct_group4_55()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_56();
  return side_effect;
}

int funct_group4_57();

int funct_group4_56()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_57();
  return side_effect;
}

int funct_group4_58();

int funct_group4_57()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_58();
  return side_effect;
}

int funct_group4_59();

int funct_group4_58()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_59();
  return side_effect;
}

int funct_group4_60();

int funct_group4_59()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_60();
  return side_effect;
}

int funct_group4_61();

int funct_group4_60()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_61();
  return side_effect;
}

int funct_group4_62();

int funct_group4_61()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_62();
  return side_effect;
}

int funct_group4_63();

int funct_group4_62()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_63();
  return side_effect;
}

int funct_group4_64();

int funct_group4_63()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_64();
  return side_effect;
}

int funct_group4_65();

int funct_group4_64()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_65();
  return side_effect;
}

int funct_group4_66();

int funct_group4_65()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_66();
  return side_effect;
}

int funct_group4_67();

int funct_group4_66()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_67();
  return side_effect;
}

int funct_group4_68();

int funct_group4_67()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_68();
  return side_effect;
}

int funct_group4_69();

int funct_group4_68()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_69();
  return side_effect;
}

int funct_group4_70();

int funct_group4_69()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_70();
  return side_effect;
}

int funct_group4_71();

int funct_group4_70()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_71();
  return side_effect;
}

int funct_group4_72();

int funct_group4_71()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_72();
  return side_effect;
}

int funct_group4_73();

int funct_group4_72()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_73();
  return side_effect;
}

int funct_group4_74();

int funct_group4_73()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_74();
  return side_effect;
}

int funct_group4_75();

int funct_group4_74()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_75();
  return side_effect;
}

int funct_group4_76();

int funct_group4_75()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_76();
  return side_effect;
}

int funct_group4_77();

int funct_group4_76()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_77();
  return side_effect;
}

int funct_group4_78();

int funct_group4_77()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_78();
  return side_effect;
}

int funct_group4_79();

int funct_group4_78()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_79();
  return side_effect;
}

int funct_group4_80();

int funct_group4_79()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_80();
  return side_effect;
}

int funct_group4_81();

int funct_group4_80()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_81();
  return side_effect;
}

int funct_group4_82();

int funct_group4_81()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_82();
  return side_effect;
}

int funct_group4_83();

int funct_group4_82()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_83();
  return side_effect;
}

int funct_group4_84();

int funct_group4_83()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_84();
  return side_effect;
}

int funct_group4_85();

int funct_group4_84()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_85();
  return side_effect;
}

int funct_group4_86();

int funct_group4_85()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_86();
  return side_effect;
}

int funct_group4_87();

int funct_group4_86()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_87();
  return side_effect;
}

int funct_group4_88();

int funct_group4_87()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_88();
  return side_effect;
}

int funct_group4_89();

int funct_group4_88()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_89();
  return side_effect;
}

int funct_group4_90();

int funct_group4_89()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_90();
  return side_effect;
}

int funct_group4_91();

int funct_group4_90()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_91();
  return side_effect;
}

int funct_group4_92();

int funct_group4_91()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_92();
  return side_effect;
}

int funct_group4_93();

int funct_group4_92()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_93();
  return side_effect;
}

int funct_group4_94();

int funct_group4_93()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_94();
  return side_effect;
}

int funct_group4_95();

int funct_group4_94()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group4_95();
  return side_effect;
}

int funct_group4_95()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();

  if (side_effect > 0) {
    start_cycles = resources->clock->uptime();
    throw my_error_t{ .data = { 0xDE, 0xAD } };
  }

  return side_effect;
}

int funct_group5_1();

int funct_group5_0()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group5_1();
  return side_effect;
}

int funct_group5_2();

int funct_group5_1()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group5_2();
  return side_effect;
}

int funct_group5_3();

int funct_group5_2()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group5_3();
  return side_effect;
}

int funct_group5_4();

int funct_group5_3()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group5_4();
  return side_effect;
}

int funct_group5_5();

int funct_group5_4()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group5_5();
  return side_effect;
}

int funct_group5_5()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();

  if (side_effect > 0) {
    start_cycles = resources->clock->uptime();
    throw my_error_t{ .data = { 0xDE, 0xAD } };
  }

  return side_effect;
}

int funct_group6_1();

int funct_group6_0()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group6_1();
  return side_effect;
}

int funct_group6_2();

int funct_group6_1()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group6_2();
  return side_effect;
}

int funct_group6_3();

int funct_group6_2()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group6_3();
  return side_effect;
}

int funct_group6_4();

int funct_group6_3()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group6_4();
  return side_effect;
}

int funct_group6_5();

int funct_group6_4()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group6_5();
  return side_effect;
}

int funct_group6_6();

int funct_group6_5()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group6_6();
  return side_effect;
}

int funct_group6_7();

int funct_group6_6()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group6_7();
  return side_effect;
}

int funct_group6_8();

int funct_group6_7()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group6_8();
  return side_effect;
}

int funct_group6_9();

int funct_group6_8()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group6_9();
  return side_effect;
}

int funct_group6_10();

int funct_group6_9()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group6_10();
  return side_effect;
}

int funct_group6_11();

int funct_group6_10()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group6_11();
  return side_effect;
}

int funct_group6_11()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();

  if (side_effect > 0) {
    start_cycles = resources->clock->uptime();
    throw my_error_t{ .data = { 0x11, 0x22 } };
  }

  return side_effect;
}

int funct_group7_1();

int funct_group7_0()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group7_1();
  return side_effect;
}

int funct_group7_2();

int funct_group7_1()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group7_2();
  return side_effect;
}

int funct_group7_3();

int funct_group7_2()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group7_3();
  return side_effect;
}

int funct_group7_4();

int funct_group7_3()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group7_4();
  return side_effect;
}

int funct_group7_5();

int funct_group7_4()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group7_5();
  return side_effect;
}

int funct_group7_6();

int funct_group7_5()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group7_6();
  return side_effect;
}

int funct_group7_7();

int funct_group7_6()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group7_7();
  return side_effect;
}

int funct_group7_8();

int funct_group7_7()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group7_8();
  return side_effect;
}

int funct_group7_9();

int funct_group7_8()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group7_9();
  return side_effect;
}

int funct_group7_10();

int funct_group7_9()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group7_10();
  return side_effect;
}

int funct_group7_11();

int funct_group7_10()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group7_11();
  return side_effect;
}

int funct_group7_12();

int funct_group7_11()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group7_12();
  return side_effect;
}

int funct_group7_13();

int funct_group7_12()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group7_13();
  return side_effect;
}

int funct_group7_14();

int funct_group7_13()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group7_14();
  return side_effect;
}

int funct_group7_15();

int funct_group7_14()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group7_15();
  return side_effect;
}

int funct_group7_16();

int funct_group7_15()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group7_16();
  return side_effect;
}

int funct_group7_17();

int funct_group7_16()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group7_17();
  return side_effect;
}

int funct_group7_18();

int funct_group7_17()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group7_18();
  return side_effect;
}

int funct_group7_19();

int funct_group7_18()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group7_19();
  return side_effect;
}

int funct_group7_20();

int funct_group7_19()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group7_20();
  return side_effect;
}

int funct_group7_21();

int funct_group7_20()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group7_21();
  return side_effect;
}

int funct_group7_22();

int funct_group7_21()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group7_22();
  return side_effect;
}

int funct_group7_23();

int funct_group7_22()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group7_23();
  return side_effect;
}

int funct_group7_23()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();

  if (side_effect > 0) {
    start_cycles = resources->clock->uptime();
    throw my_error_t{ .data = { 0xDE, 0xAD } };
  }

  return side_effect;
}

int funct_group8_1();

int funct_group8_0()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group8_1();
  return side_effect;
}

int funct_group8_2();

int funct_group8_1()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group8_2();
  return side_effect;
}

int funct_group8_3();

int funct_group8_2()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group8_3();
  return side_effect;
}

int funct_group8_4();

int funct_group8_3()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group8_4();
  return side_effect;
}

int funct_group8_5();

int funct_group8_4()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group8_5();
  return side_effect;
}

int funct_group8_6();

int funct_group8_5()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group8_6();
  return side_effect;
}

int funct_group8_7();

int funct_group8_6()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group8_7();
  return side_effect;
}

int funct_group8_8();

int funct_group8_7()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group8_8();
  return side_effect;
}

int funct_group8_9();

int funct_group8_8()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group8_9();
  return side_effect;
}

int funct_group8_10();

int funct_group8_9()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group8_10();
  return side_effect;
}

int funct_group8_11();

int funct_group8_10()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group8_11();
  return side_effect;
}

int funct_group8_12();

int funct_group8_11()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group8_12();
  return side_effect;
}

int funct_group8_13();

int funct_group8_12()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group8_13();
  return side_effect;
}

int funct_group8_14();

int funct_group8_13()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group8_14();
  return side_effect;
}

int funct_group8_15();

int funct_group8_14()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group8_15();
  return side_effect;
}

int funct_group8_16();

int funct_group8_15()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group8_16();
  return side_effect;
}

int funct_group8_17();

int funct_group8_16()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group8_17();
  return side_effect;
}

int funct_group8_18();

int funct_group8_17()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group8_18();
  return side_effect;
}

int funct_group8_19();

int funct_group8_18()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group8_19();
  return side_effect;
}

int funct_group8_20();

int funct_group8_19()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group8_20();
  return side_effect;
}

int funct_group8_21();

int funct_group8_20()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group8_21();
  return side_effect;
}

int funct_group8_22();

int funct_group8_21()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group8_22();
  return side_effect;
}

int funct_group8_23();

int funct_group8_22()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group8_23();
  return side_effect;
}

int funct_group8_24();

int funct_group8_23()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group8_24();
  return side_effect;
}

int funct_group8_25();

int funct_group8_24()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group8_25();
  return side_effect;
}

int funct_group8_26();

int funct_group8_25()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group8_26();
  return side_effect;
}

int funct_group8_27();

int funct_group8_26()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group8_27();
  return side_effect;
}

int funct_group8_28();

int funct_group8_27()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group8_28();
  return side_effect;
}

int funct_group8_29();

int funct_group8_28()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group8_29();
  return side_effect;
}

int funct_group8_30();

int funct_group8_29()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group8_30();
  return side_effect;
}

int funct_group8_31();

int funct_group8_30()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group8_31();
  return side_effect;
}

int funct_group8_32();

int funct_group8_31()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group8_32();
  return side_effect;
}

int funct_group8_33();

int funct_group8_32()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group8_33();
  return side_effect;
}

int funct_group8_34();

int funct_group8_33()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group8_34();
  return side_effect;
}

int funct_group8_35();

int funct_group8_34()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group8_35();
  return side_effect;
}

int funct_group8_36();

int funct_group8_35()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group8_36();
  return side_effect;
}

int funct_group8_37();

int funct_group8_36()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group8_37();
  return side_effect;
}

int funct_group8_38();

int funct_group8_37()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group8_38();
  return side_effect;
}

int funct_group8_39();

int funct_group8_38()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group8_39();
  return side_effect;
}

int funct_group8_40();

int funct_group8_39()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group8_40();
  return side_effect;
}

int funct_group8_41();

int funct_group8_40()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group8_41();
  return side_effect;
}

int funct_group8_42();

int funct_group8_41()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group8_42();
  return side_effect;
}

int funct_group8_43();

int funct_group8_42()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group8_43();
  return side_effect;
}

int funct_group8_44();

int funct_group8_43()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group8_44();
  return side_effect;
}

int funct_group8_45();

int funct_group8_44()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group8_45();
  return side_effect;
}

int funct_group8_46();

int funct_group8_45()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group8_46();
  return side_effect;
}

int funct_group8_47();

int funct_group8_46()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group8_47();
  return side_effect;
}

int funct_group8_47()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();

  if (side_effect > 0) {
    start_cycles = resources->clock->uptime();
    throw my_error_t{ .data = { 0xDE, 0xAD } };
  }

  return side_effect;
}

#if 0

int funct_group9_1();

int funct_group9_0()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_1();
  return side_effect;
}

int funct_group9_2();

int funct_group9_1()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_2();
  return side_effect;
}

int funct_group9_3();

int funct_group9_2()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_3();
  return side_effect;
}

int funct_group9_4();

int funct_group9_3()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_4();
  return side_effect;
}

int funct_group9_5();

int funct_group9_4()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_5();
  return side_effect;
}

int funct_group9_6();

int funct_group9_5()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_6();
  return side_effect;
}

int funct_group9_7();

int funct_group9_6()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_7();
  return side_effect;
}

int funct_group9_8();

int funct_group9_7()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_8();
  return side_effect;
}

int funct_group9_9();

int funct_group9_8()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_9();
  return side_effect;
}

int funct_group9_10();

int funct_group9_9()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_10();
  return side_effect;
}

int funct_group9_11();

int funct_group9_10()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_11();
  return side_effect;
}

int funct_group9_12();

int funct_group9_11()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_12();
  return side_effect;
}

int funct_group9_13();

int funct_group9_12()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_13();
  return side_effect;
}

int funct_group9_14();

int funct_group9_13()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_14();
  return side_effect;
}

int funct_group9_15();

int funct_group9_14()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_15();
  return side_effect;
}

int funct_group9_16();

int funct_group9_15()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_16();
  return side_effect;
}

int funct_group9_17();

int funct_group9_16()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_17();
  return side_effect;
}

int funct_group9_18();

int funct_group9_17()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_18();
  return side_effect;
}

int funct_group9_19();

int funct_group9_18()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_19();
  return side_effect;
}

int funct_group9_20();

int funct_group9_19()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_20();
  return side_effect;
}

int funct_group9_21();

int funct_group9_20()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_21();
  return side_effect;
}

int funct_group9_22();

int funct_group9_21()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_22();
  return side_effect;
}

int funct_group9_23();

int funct_group9_22()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_23();
  return side_effect;
}

int funct_group9_24();

int funct_group9_23()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_24();
  return side_effect;
}

int funct_group9_25();

int funct_group9_24()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_25();
  return side_effect;
}

int funct_group9_26();

int funct_group9_25()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_26();
  return side_effect;
}

int funct_group9_27();

int funct_group9_26()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_27();
  return side_effect;
}

int funct_group9_28();

int funct_group9_27()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_28();
  return side_effect;
}

int funct_group9_29();

int funct_group9_28()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_29();
  return side_effect;
}

int funct_group9_30();

int funct_group9_29()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_30();
  return side_effect;
}

int funct_group9_31();

int funct_group9_30()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_31();
  return side_effect;
}

int funct_group9_32();

int funct_group9_31()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_32();
  return side_effect;
}

int funct_group9_33();

int funct_group9_32()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_33();
  return side_effect;
}

int funct_group9_34();

int funct_group9_33()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_34();
  return side_effect;
}

int funct_group9_35();

int funct_group9_34()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_35();
  return side_effect;
}

int funct_group9_36();

int funct_group9_35()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_36();
  return side_effect;
}

int funct_group9_37();

int funct_group9_36()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_37();
  return side_effect;
}

int funct_group9_38();

int funct_group9_37()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_38();
  return side_effect;
}

int funct_group9_39();

int funct_group9_38()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_39();
  return side_effect;
}

int funct_group9_40();

int funct_group9_39()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_40();
  return side_effect;
}

int funct_group9_41();

int funct_group9_40()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_41();
  return side_effect;
}

int funct_group9_42();

int funct_group9_41()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_42();
  return side_effect;
}

int funct_group9_43();

int funct_group9_42()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_43();
  return side_effect;
}

int funct_group9_44();

int funct_group9_43()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_44();
  return side_effect;
}

int funct_group9_45();

int funct_group9_44()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_45();
  return side_effect;
}

int funct_group9_46();

int funct_group9_45()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_46();
  return side_effect;
}

int funct_group9_47();

int funct_group9_46()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_47();
  return side_effect;
}

int funct_group9_48();

int funct_group9_47()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_48();
  return side_effect;
}

int funct_group9_49();

int funct_group9_48()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_49();
  return side_effect;
}

int funct_group9_50();

int funct_group9_49()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_50();
  return side_effect;
}

int funct_group9_51();

int funct_group9_50()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_51();
  return side_effect;
}

int funct_group9_52();

int funct_group9_51()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_52();
  return side_effect;
}

int funct_group9_53();

int funct_group9_52()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_53();
  return side_effect;
}

int funct_group9_54();

int funct_group9_53()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_54();
  return side_effect;
}

int funct_group9_55();

int funct_group9_54()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_55();
  return side_effect;
}

int funct_group9_56();

int funct_group9_55()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_56();
  return side_effect;
}

int funct_group9_57();

int funct_group9_56()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_57();
  return side_effect;
}

int funct_group9_58();

int funct_group9_57()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_58();
  return side_effect;
}

int funct_group9_59();

int funct_group9_58()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_59();
  return side_effect;
}

int funct_group9_60();

int funct_group9_59()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_60();
  return side_effect;
}

int funct_group9_61();

int funct_group9_60()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_61();
  return side_effect;
}

int funct_group9_62();

int funct_group9_61()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_62();
  return side_effect;
}

int funct_group9_63();

int funct_group9_62()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_63();
  return side_effect;
}

int funct_group9_64();

int funct_group9_63()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_64();
  return side_effect;
}

int funct_group9_65();

int funct_group9_64()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_65();
  return side_effect;
}

int funct_group9_66();

int funct_group9_65()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_66();
  return side_effect;
}

int funct_group9_67();

int funct_group9_66()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_67();
  return side_effect;
}

int funct_group9_68();

int funct_group9_67()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_68();
  return side_effect;
}

int funct_group9_69();

int funct_group9_68()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_69();
  return side_effect;
}

int funct_group9_70();

int funct_group9_69()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_70();
  return side_effect;
}

int funct_group9_71();

int funct_group9_70()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_71();
  return side_effect;
}

int funct_group9_72();

int funct_group9_71()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_72();
  return side_effect;
}

int funct_group9_73();

int funct_group9_72()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_73();
  return side_effect;
}

int funct_group9_74();

int funct_group9_73()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_74();
  return side_effect;
}

int funct_group9_75();

int funct_group9_74()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_75();
  return side_effect;
}

int funct_group9_76();

int funct_group9_75()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_76();
  return side_effect;
}

int funct_group9_77();

int funct_group9_76()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_77();
  return side_effect;
}

int funct_group9_78();

int funct_group9_77()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_78();
  return side_effect;
}

int funct_group9_79();

int funct_group9_78()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_79();
  return side_effect;
}

int funct_group9_80();

int funct_group9_79()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_80();
  return side_effect;
}

int funct_group9_81();

int funct_group9_80()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_81();
  return side_effect;
}

int funct_group9_82();

int funct_group9_81()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_82();
  return side_effect;
}

int funct_group9_83();

int funct_group9_82()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_83();
  return side_effect;
}

int funct_group9_84();

int funct_group9_83()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_84();
  return side_effect;
}

int funct_group9_85();

int funct_group9_84()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_85();
  return side_effect;
}

int funct_group9_86();

int funct_group9_85()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_86();
  return side_effect;
}

int funct_group9_87();

int funct_group9_86()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_87();
  return side_effect;
}

int funct_group9_88();

int funct_group9_87()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_88();
  return side_effect;
}

int funct_group9_89();

int funct_group9_88()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_89();
  return side_effect;
}

int funct_group9_90();

int funct_group9_89()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_90();
  return side_effect;
}

int funct_group9_91();

int funct_group9_90()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_91();
  return side_effect;
}

int funct_group9_92();

int funct_group9_91()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_92();
  return side_effect;
}

int funct_group9_93();

int funct_group9_92()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_93();
  return side_effect;
}

int funct_group9_94();

int funct_group9_93()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_94();
  return side_effect;
}

int funct_group9_95();

int funct_group9_94()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group9_95();
  return side_effect;
}

int funct_group9_95()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();

  if (side_effect > 0) {
    start_cycles = resources->clock->uptime();
    throw my_error_t{ .data = { 0xDE, 0xAD } };
  }

  return side_effect;
}

int funct_group10_1();

int funct_group10_0()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group10_1();
  return side_effect;
}

int funct_group10_2();

int funct_group10_1()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group10_2();
  return side_effect;
}

int funct_group10_3();

int funct_group10_2()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group10_3();
  return side_effect;
}

int funct_group10_4();

int funct_group10_3()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group10_4();
  return side_effect;
}

int funct_group10_5();

int funct_group10_4()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group10_5();
  return side_effect;
}

int funct_group10_5()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();

  if (side_effect > 0) {
    start_cycles = resources->clock->uptime();
    throw my_error_t{ .data = { 0xDE, 0xAD } };
  }

  return side_effect;
}

int funct_group11_1();

int funct_group11_0()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group11_1();
  return side_effect;
}

int funct_group11_2();

int funct_group11_1()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group11_2();
  return side_effect;
}

int funct_group11_3();

int funct_group11_2()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group11_3();
  return side_effect;
}

int funct_group11_4();

int funct_group11_3()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group11_4();
  return side_effect;
}

int funct_group11_5();

int funct_group11_4()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group11_5();
  return side_effect;
}

int funct_group11_6();

int funct_group11_5()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group11_6();
  return side_effect;
}

int funct_group11_7();

int funct_group11_6()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group11_7();
  return side_effect;
}

int funct_group11_8();

int funct_group11_7()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group11_8();
  return side_effect;
}

int funct_group11_9();

int funct_group11_8()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group11_9();
  return side_effect;
}

int funct_group11_10();

int funct_group11_9()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group11_10();
  return side_effect;
}

int funct_group11_11();

int funct_group11_10()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group11_11();
  return side_effect;
}

int funct_group11_11()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();

  if (side_effect > 0) {
    start_cycles = resources->clock->uptime();
    throw my_error_t{ .data = { 0xDE, 0xAD } };
  }

  return side_effect;
}

int funct_group12_1();

int funct_group12_0()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group12_1();
  return side_effect;
}

int funct_group12_2();

int funct_group12_1()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group12_2();
  return side_effect;
}

int funct_group12_3();

int funct_group12_2()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group12_3();
  return side_effect;
}

int funct_group12_4();

int funct_group12_3()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group12_4();
  return side_effect;
}

int funct_group12_5();

int funct_group12_4()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group12_5();
  return side_effect;
}

int funct_group12_6();

int funct_group12_5()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group12_6();
  return side_effect;
}

int funct_group12_7();

int funct_group12_6()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group12_7();
  return side_effect;
}

int funct_group12_8();

int funct_group12_7()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group12_8();
  return side_effect;
}

int funct_group12_9();

int funct_group12_8()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group12_9();
  return side_effect;
}

int funct_group12_10();

int funct_group12_9()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group12_10();
  return side_effect;
}

int funct_group12_11();

int funct_group12_10()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group12_11();
  return side_effect;
}

int funct_group12_12();

int funct_group12_11()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group12_12();
  return side_effect;
}

int funct_group12_13();

int funct_group12_12()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group12_13();
  return side_effect;
}

int funct_group12_14();

int funct_group12_13()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group12_14();
  return side_effect;
}

int funct_group12_15();

int funct_group12_14()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group12_15();
  return side_effect;
}

int funct_group12_16();

int funct_group12_15()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group12_16();
  return side_effect;
}

int funct_group12_17();

int funct_group12_16()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group12_17();
  return side_effect;
}

int funct_group12_18();

int funct_group12_17()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group12_18();
  return side_effect;
}

int funct_group12_19();

int funct_group12_18()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group12_19();
  return side_effect;
}

int funct_group12_20();

int funct_group12_19()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group12_20();
  return side_effect;
}

int funct_group12_21();

int funct_group12_20()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group12_21();
  return side_effect;
}

int funct_group12_22();

int funct_group12_21()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group12_22();
  return side_effect;
}

int funct_group12_23();

int funct_group12_22()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group12_23();
  return side_effect;
}

int funct_group12_23()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();

  if (side_effect > 0) {
    start_cycles = resources->clock->uptime();
    throw my_error_t{ .data = { 0xDE, 0xAD } };
  }

  return side_effect;
}

int funct_group13_1();

int funct_group13_0()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group13_1();
  return side_effect;
}

int funct_group13_2();

int funct_group13_1()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group13_2();
  return side_effect;
}

int funct_group13_3();

int funct_group13_2()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group13_3();
  return side_effect;
}

int funct_group13_4();

int funct_group13_3()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group13_4();
  return side_effect;
}

int funct_group13_5();

int funct_group13_4()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group13_5();
  return side_effect;
}

int funct_group13_6();

int funct_group13_5()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group13_6();
  return side_effect;
}

int funct_group13_7();

int funct_group13_6()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group13_7();
  return side_effect;
}

int funct_group13_8();

int funct_group13_7()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group13_8();
  return side_effect;
}

int funct_group13_9();

int funct_group13_8()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group13_9();
  return side_effect;
}

int funct_group13_10();

int funct_group13_9()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group13_10();
  return side_effect;
}

int funct_group13_11();

int funct_group13_10()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group13_11();
  return side_effect;
}

int funct_group13_12();

int funct_group13_11()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group13_12();
  return side_effect;
}

int funct_group13_13();

int funct_group13_12()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group13_13();
  return side_effect;
}

int funct_group13_14();

int funct_group13_13()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group13_14();
  return side_effect;
}

int funct_group13_15();

int funct_group13_14()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group13_15();
  return side_effect;
}

int funct_group13_16();

int funct_group13_15()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group13_16();
  return side_effect;
}

int funct_group13_17();

int funct_group13_16()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group13_17();
  return side_effect;
}

int funct_group13_18();

int funct_group13_17()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group13_18();
  return side_effect;
}

int funct_group13_19();

int funct_group13_18()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group13_19();
  return side_effect;
}

int funct_group13_20();

int funct_group13_19()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group13_20();
  return side_effect;
}

int funct_group13_21();

int funct_group13_20()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group13_21();
  return side_effect;
}

int funct_group13_22();

int funct_group13_21()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group13_22();
  return side_effect;
}

int funct_group13_23();

int funct_group13_22()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group13_23();
  return side_effect;
}

int funct_group13_24();

int funct_group13_23()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group13_24();
  return side_effect;
}

int funct_group13_25();

int funct_group13_24()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group13_25();
  return side_effect;
}

int funct_group13_26();

int funct_group13_25()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group13_26();
  return side_effect;
}

int funct_group13_27();

int funct_group13_26()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group13_27();
  return side_effect;
}

int funct_group13_28();

int funct_group13_27()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group13_28();
  return side_effect;
}

int funct_group13_29();

int funct_group13_28()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group13_29();
  return side_effect;
}

int funct_group13_30();

int funct_group13_29()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group13_30();
  return side_effect;
}

int funct_group13_31();

int funct_group13_30()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group13_31();
  return side_effect;
}

int funct_group13_32();

int funct_group13_31()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group13_32();
  return side_effect;
}

int funct_group13_33();

int funct_group13_32()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group13_33();
  return side_effect;
}

int funct_group13_34();

int funct_group13_33()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group13_34();
  return side_effect;
}

int funct_group13_35();

int funct_group13_34()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group13_35();
  return side_effect;
}

int funct_group13_36();

int funct_group13_35()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group13_36();
  return side_effect;
}

int funct_group13_37();

int funct_group13_36()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group13_37();
  return side_effect;
}

int funct_group13_38();

int funct_group13_37()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group13_38();
  return side_effect;
}

int funct_group13_39();

int funct_group13_38()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group13_39();
  return side_effect;
}

int funct_group13_40();

int funct_group13_39()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group13_40();
  return side_effect;
}

int funct_group13_41();

int funct_group13_40()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group13_41();
  return side_effect;
}

int funct_group13_42();

int funct_group13_41()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group13_42();
  return side_effect;
}

int funct_group13_43();

int funct_group13_42()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group13_43();
  return side_effect;
}

int funct_group13_44();

int funct_group13_43()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group13_44();
  return side_effect;
}

int funct_group13_45();

int funct_group13_44()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group13_45();
  return side_effect;
}

int funct_group13_46();

int funct_group13_45()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group13_46();
  return side_effect;
}

int funct_group13_47();

int funct_group13_46()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group13_47();
  return side_effect;
}

int funct_group13_47()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();

  if (side_effect > 0) {
    start_cycles = resources->clock->uptime();
    throw my_error_t{ .data = { 0xDE, 0xAD } };
  }

  return side_effect;
}

int funct_group14_1();

int funct_group14_0()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_1();
  return side_effect;
}

int funct_group14_2();

int funct_group14_1()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_2();
  return side_effect;
}

int funct_group14_3();

int funct_group14_2()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_3();
  return side_effect;
}

int funct_group14_4();

int funct_group14_3()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_4();
  return side_effect;
}

int funct_group14_5();

int funct_group14_4()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_5();
  return side_effect;
}

int funct_group14_6();

int funct_group14_5()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_6();
  return side_effect;
}

int funct_group14_7();

int funct_group14_6()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_7();
  return side_effect;
}

int funct_group14_8();

int funct_group14_7()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_8();
  return side_effect;
}

int funct_group14_9();

int funct_group14_8()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_9();
  return side_effect;
}

int funct_group14_10();

int funct_group14_9()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_10();
  return side_effect;
}

int funct_group14_11();

int funct_group14_10()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_11();
  return side_effect;
}

int funct_group14_12();

int funct_group14_11()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_12();
  return side_effect;
}

int funct_group14_13();

int funct_group14_12()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_13();
  return side_effect;
}

int funct_group14_14();

int funct_group14_13()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_14();
  return side_effect;
}

int funct_group14_15();

int funct_group14_14()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_15();
  return side_effect;
}

int funct_group14_16();

int funct_group14_15()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_16();
  return side_effect;
}

int funct_group14_17();

int funct_group14_16()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_17();
  return side_effect;
}

int funct_group14_18();

int funct_group14_17()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_18();
  return side_effect;
}

int funct_group14_19();

int funct_group14_18()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_19();
  return side_effect;
}

int funct_group14_20();

int funct_group14_19()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_20();
  return side_effect;
}

int funct_group14_21();

int funct_group14_20()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_21();
  return side_effect;
}

int funct_group14_22();

int funct_group14_21()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_22();
  return side_effect;
}

int funct_group14_23();

int funct_group14_22()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_23();
  return side_effect;
}

int funct_group14_24();

int funct_group14_23()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_24();
  return side_effect;
}

int funct_group14_25();

int funct_group14_24()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_25();
  return side_effect;
}

int funct_group14_26();

int funct_group14_25()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_26();
  return side_effect;
}

int funct_group14_27();

int funct_group14_26()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_27();
  return side_effect;
}

int funct_group14_28();

int funct_group14_27()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_28();
  return side_effect;
}

int funct_group14_29();

int funct_group14_28()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_29();
  return side_effect;
}

int funct_group14_30();

int funct_group14_29()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_30();
  return side_effect;
}

int funct_group14_31();

int funct_group14_30()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_31();
  return side_effect;
}

int funct_group14_32();

int funct_group14_31()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_32();
  return side_effect;
}

int funct_group14_33();

int funct_group14_32()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_33();
  return side_effect;
}

int funct_group14_34();

int funct_group14_33()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_34();
  return side_effect;
}

int funct_group14_35();

int funct_group14_34()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_35();
  return side_effect;
}

int funct_group14_36();

int funct_group14_35()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_36();
  return side_effect;
}

int funct_group14_37();

int funct_group14_36()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_37();
  return side_effect;
}

int funct_group14_38();

int funct_group14_37()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_38();
  return side_effect;
}

int funct_group14_39();

int funct_group14_38()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_39();
  return side_effect;
}

int funct_group14_40();

int funct_group14_39()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_40();
  return side_effect;
}

int funct_group14_41();

int funct_group14_40()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_41();
  return side_effect;
}

int funct_group14_42();

int funct_group14_41()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_42();
  return side_effect;
}

int funct_group14_43();

int funct_group14_42()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_43();
  return side_effect;
}

int funct_group14_44();

int funct_group14_43()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_44();
  return side_effect;
}

int funct_group14_45();

int funct_group14_44()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_45();
  return side_effect;
}

int funct_group14_46();

int funct_group14_45()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_46();
  return side_effect;
}

int funct_group14_47();

int funct_group14_46()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_47();
  return side_effect;
}

int funct_group14_48();

int funct_group14_47()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_48();
  return side_effect;
}

int funct_group14_49();

int funct_group14_48()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_49();
  return side_effect;
}

int funct_group14_50();

int funct_group14_49()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_50();
  return side_effect;
}

int funct_group14_51();

int funct_group14_50()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_51();
  return side_effect;
}

int funct_group14_52();

int funct_group14_51()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_52();
  return side_effect;
}

int funct_group14_53();

int funct_group14_52()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_53();
  return side_effect;
}

int funct_group14_54();

int funct_group14_53()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_54();
  return side_effect;
}

int funct_group14_55();

int funct_group14_54()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_55();
  return side_effect;
}

int funct_group14_56();

int funct_group14_55()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_56();
  return side_effect;
}

int funct_group14_57();

int funct_group14_56()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_57();
  return side_effect;
}

int funct_group14_58();

int funct_group14_57()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_58();
  return side_effect;
}

int funct_group14_59();

int funct_group14_58()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_59();
  return side_effect;
}

int funct_group14_60();

int funct_group14_59()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_60();
  return side_effect;
}

int funct_group14_61();

int funct_group14_60()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_61();
  return side_effect;
}

int funct_group14_62();

int funct_group14_61()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_62();
  return side_effect;
}

int funct_group14_63();

int funct_group14_62()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_63();
  return side_effect;
}

int funct_group14_64();

int funct_group14_63()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_64();
  return side_effect;
}

int funct_group14_65();

int funct_group14_64()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_65();
  return side_effect;
}

int funct_group14_66();

int funct_group14_65()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_66();
  return side_effect;
}

int funct_group14_67();

int funct_group14_66()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_67();
  return side_effect;
}

int funct_group14_68();

int funct_group14_67()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_68();
  return side_effect;
}

int funct_group14_69();

int funct_group14_68()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_69();
  return side_effect;
}

int funct_group14_70();

int funct_group14_69()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_70();
  return side_effect;
}

int funct_group14_71();

int funct_group14_70()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_71();
  return side_effect;
}

int funct_group14_72();

int funct_group14_71()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_72();
  return side_effect;
}

int funct_group14_73();

int funct_group14_72()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_73();
  return side_effect;
}

int funct_group14_74();

int funct_group14_73()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_74();
  return side_effect;
}

int funct_group14_75();

int funct_group14_74()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_75();
  return side_effect;
}

int funct_group14_76();

int funct_group14_75()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_76();
  return side_effect;
}

int funct_group14_77();

int funct_group14_76()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_77();
  return side_effect;
}

int funct_group14_78();

int funct_group14_77()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_78();
  return side_effect;
}

int funct_group14_79();

int funct_group14_78()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_79();
  return side_effect;
}

int funct_group14_80();

int funct_group14_79()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_80();
  return side_effect;
}

int funct_group14_81();

int funct_group14_80()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_81();
  return side_effect;
}

int funct_group14_82();

int funct_group14_81()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_82();
  return side_effect;
}

int funct_group14_83();

int funct_group14_82()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_83();
  return side_effect;
}

int funct_group14_84();

int funct_group14_83()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_84();
  return side_effect;
}

int funct_group14_85();

int funct_group14_84()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_85();
  return side_effect;
}

int funct_group14_86();

int funct_group14_85()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_86();
  return side_effect;
}

int funct_group14_87();

int funct_group14_86()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_87();
  return side_effect;
}

int funct_group14_88();

int funct_group14_87()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_88();
  return side_effect;
}

int funct_group14_89();

int funct_group14_88()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_89();
  return side_effect;
}

int funct_group14_90();

int funct_group14_89()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_90();
  return side_effect;
}

int funct_group14_91();

int funct_group14_90()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_91();
  return side_effect;
}

int funct_group14_92();

int funct_group14_91()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_92();
  return side_effect;
}

int funct_group14_93();

int funct_group14_92()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_93();
  return side_effect;
}

int funct_group14_94();

int funct_group14_93()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_94();
  return side_effect;
}

int funct_group14_95();

int funct_group14_94()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group14_95();
  return side_effect;
}

int funct_group14_95()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();

  if (side_effect > 0) {
    start_cycles = resources->clock->uptime();
    throw my_error_t{ .data = { 0xDE, 0xAD } };
  }

  return side_effect;
}

int funct_group15_1();

int funct_group15_0()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group15_1();
  return side_effect;
}

int funct_group15_2();

int funct_group15_1()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group15_2();
  return side_effect;
}

int funct_group15_3();

int funct_group15_2()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group15_3();
  return side_effect;
}

int funct_group15_4();

int funct_group15_3()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group15_4();
  return side_effect;
}

int funct_group15_5();

int funct_group15_4()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group15_5();
  return side_effect;
}

int funct_group15_5()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();

  if (side_effect > 0) {
    start_cycles = resources->clock->uptime();
    throw my_error_t{ .data = { 0xDE, 0xAD } };
  }

  return side_effect;
}

int funct_group16_1();

int funct_group16_0()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group16_1();
  return side_effect;
}

int funct_group16_2();

int funct_group16_1()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group16_2();
  return side_effect;
}

int funct_group16_3();

int funct_group16_2()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group16_3();
  return side_effect;
}

int funct_group16_4();

int funct_group16_3()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group16_4();
  return side_effect;
}

int funct_group16_5();

int funct_group16_4()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group16_5();
  return side_effect;
}

int funct_group16_6();

int funct_group16_5()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group16_6();
  return side_effect;
}

int funct_group16_7();

int funct_group16_6()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group16_7();
  return side_effect;
}

int funct_group16_8();

int funct_group16_7()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group16_8();
  return side_effect;
}

int funct_group16_9();

int funct_group16_8()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group16_9();
  return side_effect;
}

int funct_group16_10();

int funct_group16_9()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group16_10();
  return side_effect;
}

int funct_group16_11();

int funct_group16_10()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group16_11();
  return side_effect;
}

int funct_group16_11()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();

  if (side_effect > 0) {
    start_cycles = resources->clock->uptime();
    throw my_error_t{ .data = { 0xDE, 0xAD } };
  }

  return side_effect;
}

int funct_group17_1();

int funct_group17_0()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group17_1();
  return side_effect;
}

int funct_group17_2();

int funct_group17_1()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group17_2();
  return side_effect;
}

int funct_group17_3();

int funct_group17_2()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group17_3();
  return side_effect;
}

int funct_group17_4();

int funct_group17_3()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group17_4();
  return side_effect;
}

int funct_group17_5();

int funct_group17_4()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group17_5();
  return side_effect;
}

int funct_group17_6();

int funct_group17_5()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group17_6();
  return side_effect;
}

int funct_group17_7();

int funct_group17_6()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group17_7();
  return side_effect;
}

int funct_group17_8();

int funct_group17_7()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group17_8();
  return side_effect;
}

int funct_group17_9();

int funct_group17_8()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group17_9();
  return side_effect;
}

int funct_group17_10();

int funct_group17_9()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group17_10();
  return side_effect;
}

int funct_group17_11();

int funct_group17_10()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group17_11();
  return side_effect;
}

int funct_group17_12();

int funct_group17_11()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group17_12();
  return side_effect;
}

int funct_group17_13();

int funct_group17_12()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group17_13();
  return side_effect;
}

int funct_group17_14();

int funct_group17_13()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group17_14();
  return side_effect;
}

int funct_group17_15();

int funct_group17_14()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group17_15();
  return side_effect;
}

int funct_group17_16();

int funct_group17_15()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group17_16();
  return side_effect;
}

int funct_group17_17();

int funct_group17_16()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group17_17();
  return side_effect;
}

int funct_group17_18();

int funct_group17_17()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group17_18();
  return side_effect;
}

int funct_group17_19();

int funct_group17_18()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group17_19();
  return side_effect;
}

int funct_group17_20();

int funct_group17_19()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group17_20();
  return side_effect;
}

int funct_group17_21();

int funct_group17_20()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group17_21();
  return side_effect;
}

int funct_group17_22();

int funct_group17_21()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group17_22();
  return side_effect;
}

int funct_group17_23();

int funct_group17_22()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group17_23();
  return side_effect;
}

int funct_group17_23()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();

  if (side_effect > 0) {
    start_cycles = resources->clock->uptime();
    throw my_error_t{ .data = { 0xDE, 0xAD } };
  }

  return side_effect;
}

int funct_group18_1();

int funct_group18_0()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group18_1();
  return side_effect;
}

int funct_group18_2();

int funct_group18_1()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group18_2();
  return side_effect;
}

int funct_group18_3();

int funct_group18_2()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group18_3();
  return side_effect;
}

int funct_group18_4();

int funct_group18_3()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group18_4();
  return side_effect;
}

int funct_group18_5();

int funct_group18_4()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group18_5();
  return side_effect;
}

int funct_group18_6();

int funct_group18_5()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group18_6();
  return side_effect;
}

int funct_group18_7();

int funct_group18_6()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group18_7();
  return side_effect;
}

int funct_group18_8();

int funct_group18_7()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group18_8();
  return side_effect;
}

int funct_group18_9();

int funct_group18_8()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group18_9();
  return side_effect;
}

int funct_group18_10();

int funct_group18_9()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group18_10();
  return side_effect;
}

int funct_group18_11();

int funct_group18_10()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group18_11();
  return side_effect;
}

int funct_group18_12();

int funct_group18_11()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group18_12();
  return side_effect;
}

int funct_group18_13();

int funct_group18_12()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group18_13();
  return side_effect;
}

int funct_group18_14();

int funct_group18_13()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group18_14();
  return side_effect;
}

int funct_group18_15();

int funct_group18_14()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group18_15();
  return side_effect;
}

int funct_group18_16();

int funct_group18_15()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group18_16();
  return side_effect;
}

int funct_group18_17();

int funct_group18_16()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group18_17();
  return side_effect;
}

int funct_group18_18();

int funct_group18_17()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group18_18();
  return side_effect;
}

int funct_group18_19();

int funct_group18_18()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group18_19();
  return side_effect;
}

int funct_group18_20();

int funct_group18_19()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group18_20();
  return side_effect;
}

int funct_group18_21();

int funct_group18_20()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group18_21();
  return side_effect;
}

int funct_group18_22();

int funct_group18_21()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group18_22();
  return side_effect;
}

int funct_group18_23();

int funct_group18_22()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group18_23();
  return side_effect;
}

int funct_group18_24();

int funct_group18_23()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group18_24();
  return side_effect;
}

int funct_group18_25();

int funct_group18_24()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group18_25();
  return side_effect;
}

int funct_group18_26();

int funct_group18_25()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group18_26();
  return side_effect;
}

int funct_group18_27();

int funct_group18_26()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group18_27();
  return side_effect;
}

int funct_group18_28();

int funct_group18_27()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group18_28();
  return side_effect;
}

int funct_group18_29();

int funct_group18_28()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group18_29();
  return side_effect;
}

int funct_group18_30();

int funct_group18_29()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group18_30();
  return side_effect;
}

int funct_group18_31();

int funct_group18_30()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group18_31();
  return side_effect;
}

int funct_group18_32();

int funct_group18_31()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group18_32();
  return side_effect;
}

int funct_group18_33();

int funct_group18_32()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group18_33();
  return side_effect;
}

int funct_group18_34();

int funct_group18_33()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group18_34();
  return side_effect;
}

int funct_group18_35();

int funct_group18_34()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group18_35();
  return side_effect;
}

int funct_group18_36();

int funct_group18_35()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group18_36();
  return side_effect;
}

int funct_group18_37();

int funct_group18_36()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group18_37();
  return side_effect;
}

int funct_group18_38();

int funct_group18_37()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group18_38();
  return side_effect;
}

int funct_group18_39();

int funct_group18_38()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group18_39();
  return side_effect;
}

int funct_group18_40();

int funct_group18_39()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group18_40();
  return side_effect;
}

int funct_group18_41();

int funct_group18_40()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group18_41();
  return side_effect;
}

int funct_group18_42();

int funct_group18_41()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group18_42();
  return side_effect;
}

int funct_group18_43();

int funct_group18_42()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group18_43();
  return side_effect;
}

int funct_group18_44();

int funct_group18_43()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group18_44();
  return side_effect;
}

int funct_group18_45();

int funct_group18_44()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group18_45();
  return side_effect;
}

int funct_group18_46();

int funct_group18_45()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group18_46();
  return side_effect;
}

int funct_group18_47();

int funct_group18_46()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group18_47();
  return side_effect;
}

int funct_group18_47()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();

  if (side_effect > 0) {
    start_cycles = resources->clock->uptime();
    throw my_error_t{ .data = { 0xDE, 0xAD } };
  }

  return side_effect;
}

int funct_group19_1();

int funct_group19_0()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_1();
  return side_effect;
}

int funct_group19_2();

int funct_group19_1()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_2();
  return side_effect;
}

int funct_group19_3();

int funct_group19_2()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_3();
  return side_effect;
}

int funct_group19_4();

int funct_group19_3()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_4();
  return side_effect;
}

int funct_group19_5();

int funct_group19_4()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_5();
  return side_effect;
}

int funct_group19_6();

int funct_group19_5()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_6();
  return side_effect;
}

int funct_group19_7();

int funct_group19_6()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_7();
  return side_effect;
}

int funct_group19_8();

int funct_group19_7()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_8();
  return side_effect;
}

int funct_group19_9();

int funct_group19_8()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_9();
  return side_effect;
}

int funct_group19_10();

int funct_group19_9()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_10();
  return side_effect;
}

int funct_group19_11();

int funct_group19_10()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_11();
  return side_effect;
}

int funct_group19_12();

int funct_group19_11()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_12();
  return side_effect;
}

int funct_group19_13();

int funct_group19_12()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_13();
  return side_effect;
}

int funct_group19_14();

int funct_group19_13()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_14();
  return side_effect;
}

int funct_group19_15();

int funct_group19_14()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_15();
  return side_effect;
}

int funct_group19_16();

int funct_group19_15()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_16();
  return side_effect;
}

int funct_group19_17();

int funct_group19_16()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_17();
  return side_effect;
}

int funct_group19_18();

int funct_group19_17()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_18();
  return side_effect;
}

int funct_group19_19();

int funct_group19_18()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_19();
  return side_effect;
}

int funct_group19_20();

int funct_group19_19()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_20();
  return side_effect;
}

int funct_group19_21();

int funct_group19_20()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_21();
  return side_effect;
}

int funct_group19_22();

int funct_group19_21()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_22();
  return side_effect;
}

int funct_group19_23();

int funct_group19_22()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_23();
  return side_effect;
}

int funct_group19_24();

int funct_group19_23()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_24();
  return side_effect;
}

int funct_group19_25();

int funct_group19_24()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_25();
  return side_effect;
}

int funct_group19_26();

int funct_group19_25()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_26();
  return side_effect;
}

int funct_group19_27();

int funct_group19_26()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_27();
  return side_effect;
}

int funct_group19_28();

int funct_group19_27()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_28();
  return side_effect;
}

int funct_group19_29();

int funct_group19_28()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_29();
  return side_effect;
}

int funct_group19_30();

int funct_group19_29()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_30();
  return side_effect;
}

int funct_group19_31();

int funct_group19_30()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_31();
  return side_effect;
}

int funct_group19_32();

int funct_group19_31()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_32();
  return side_effect;
}

int funct_group19_33();

int funct_group19_32()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_33();
  return side_effect;
}

int funct_group19_34();

int funct_group19_33()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_34();
  return side_effect;
}

int funct_group19_35();

int funct_group19_34()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_35();
  return side_effect;
}

int funct_group19_36();

int funct_group19_35()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_36();
  return side_effect;
}

int funct_group19_37();

int funct_group19_36()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_37();
  return side_effect;
}

int funct_group19_38();

int funct_group19_37()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_38();
  return side_effect;
}

int funct_group19_39();

int funct_group19_38()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_39();
  return side_effect;
}

int funct_group19_40();

int funct_group19_39()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_40();
  return side_effect;
}

int funct_group19_41();

int funct_group19_40()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_41();
  return side_effect;
}

int funct_group19_42();

int funct_group19_41()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_42();
  return side_effect;
}

int funct_group19_43();

int funct_group19_42()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_43();
  return side_effect;
}

int funct_group19_44();

int funct_group19_43()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_44();
  return side_effect;
}

int funct_group19_45();

int funct_group19_44()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_45();
  return side_effect;
}

int funct_group19_46();

int funct_group19_45()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_46();
  return side_effect;
}

int funct_group19_47();

int funct_group19_46()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_47();
  return side_effect;
}

int funct_group19_48();

int funct_group19_47()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_48();
  return side_effect;
}

int funct_group19_49();

int funct_group19_48()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_49();
  return side_effect;
}

int funct_group19_50();

int funct_group19_49()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_50();
  return side_effect;
}

int funct_group19_51();

int funct_group19_50()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_51();
  return side_effect;
}

int funct_group19_52();

int funct_group19_51()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_52();
  return side_effect;
}

int funct_group19_53();

int funct_group19_52()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_53();
  return side_effect;
}

int funct_group19_54();

int funct_group19_53()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_54();
  return side_effect;
}

int funct_group19_55();

int funct_group19_54()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_55();
  return side_effect;
}

int funct_group19_56();

int funct_group19_55()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_56();
  return side_effect;
}

int funct_group19_57();

int funct_group19_56()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_57();
  return side_effect;
}

int funct_group19_58();

int funct_group19_57()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_58();
  return side_effect;
}

int funct_group19_59();

int funct_group19_58()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_59();
  return side_effect;
}

int funct_group19_60();

int funct_group19_59()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_60();
  return side_effect;
}

int funct_group19_61();

int funct_group19_60()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_61();
  return side_effect;
}

int funct_group19_62();

int funct_group19_61()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_62();
  return side_effect;
}

int funct_group19_63();

int funct_group19_62()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_63();
  return side_effect;
}

int funct_group19_64();

int funct_group19_63()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_64();
  return side_effect;
}

int funct_group19_65();

int funct_group19_64()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_65();
  return side_effect;
}

int funct_group19_66();

int funct_group19_65()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_66();
  return side_effect;
}

int funct_group19_67();

int funct_group19_66()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_67();
  return side_effect;
}

int funct_group19_68();

int funct_group19_67()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_68();
  return side_effect;
}

int funct_group19_69();

int funct_group19_68()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_69();
  return side_effect;
}

int funct_group19_70();

int funct_group19_69()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_70();
  return side_effect;
}

int funct_group19_71();

int funct_group19_70()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_71();
  return side_effect;
}

int funct_group19_72();

int funct_group19_71()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_72();
  return side_effect;
}

int funct_group19_73();

int funct_group19_72()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_73();
  return side_effect;
}

int funct_group19_74();

int funct_group19_73()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_74();
  return side_effect;
}

int funct_group19_75();

int funct_group19_74()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_75();
  return side_effect;
}

int funct_group19_76();

int funct_group19_75()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_76();
  return side_effect;
}

int funct_group19_77();

int funct_group19_76()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_77();
  return side_effect;
}

int funct_group19_78();

int funct_group19_77()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_78();
  return side_effect;
}

int funct_group19_79();

int funct_group19_78()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_79();
  return side_effect;
}

int funct_group19_80();

int funct_group19_79()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_80();
  return side_effect;
}

int funct_group19_81();

int funct_group19_80()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_81();
  return side_effect;
}

int funct_group19_82();

int funct_group19_81()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_82();
  return side_effect;
}

int funct_group19_83();

int funct_group19_82()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_83();
  return side_effect;
}

int funct_group19_84();

int funct_group19_83()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_84();
  return side_effect;
}

int funct_group19_85();

int funct_group19_84()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_85();
  return side_effect;
}

int funct_group19_86();

int funct_group19_85()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_86();
  return side_effect;
}

int funct_group19_87();

int funct_group19_86()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_87();
  return side_effect;
}

int funct_group19_88();

int funct_group19_87()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_88();
  return side_effect;
}

int funct_group19_89();

int funct_group19_88()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_89();
  return side_effect;
}

int funct_group19_90();

int funct_group19_89()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_90();
  return side_effect;
}

int funct_group19_91();

int funct_group19_90()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_91();
  return side_effect;
}

int funct_group19_92();

int funct_group19_91()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_92();
  return side_effect;
}

int funct_group19_93();

int funct_group19_92()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_93();
  return side_effect;
}

int funct_group19_94();

int funct_group19_93()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_94();
  return side_effect;
}

int funct_group19_95();

int funct_group19_94()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_0 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group19_95();
  return side_effect;
}

int funct_group19_95()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();

  if (side_effect > 0) {
    start_cycles = resources->clock->uptime();
    throw my_error_t{ .data = { 0xDE, 0xAD } };
  }

  return side_effect;
}

int funct_group20_1();

int funct_group20_0()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group20_1();
  return side_effect;
}

int funct_group20_2();

int funct_group20_1()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group20_2();
  return side_effect;
}

int funct_group20_3();

int funct_group20_2()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group20_3();
  return side_effect;
}

int funct_group20_4();

int funct_group20_3()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group20_4();
  return side_effect;
}

int funct_group20_5();

int funct_group20_4()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group20_5();
  return side_effect;
}

int funct_group20_5()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();

  if (side_effect > 0) {
    start_cycles = resources->clock->uptime();
    throw my_error_t{ .data = { 0xDE, 0xAD } };
  }

  return side_effect;
}

int funct_group21_1();

int funct_group21_0()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group21_1();
  return side_effect;
}

int funct_group21_2();

int funct_group21_1()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group21_2();
  return side_effect;
}

int funct_group21_3();

int funct_group21_2()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group21_3();
  return side_effect;
}

int funct_group21_4();

int funct_group21_3()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group21_4();
  return side_effect;
}

int funct_group21_5();

int funct_group21_4()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group21_5();
  return side_effect;
}

int funct_group21_6();

int funct_group21_5()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group21_6();
  return side_effect;
}

int funct_group21_7();

int funct_group21_6()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group21_7();
  return side_effect;
}

int funct_group21_8();

int funct_group21_7()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group21_8();
  return side_effect;
}

int funct_group21_9();

int funct_group21_8()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group21_9();
  return side_effect;
}

int funct_group21_10();

int funct_group21_9()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group21_10();
  return side_effect;
}

int funct_group21_11();

int funct_group21_10()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group21_11();
  return side_effect;
}

int funct_group21_11()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();

  if (side_effect > 0) {
    start_cycles = resources->clock->uptime();
    throw my_error_t{ .data = { 0xDE, 0xAD } };
  }

  return side_effect;
}

int funct_group22_1();

int funct_group22_0()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group22_1();
  return side_effect;
}

int funct_group22_2();

int funct_group22_1()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group22_2();
  return side_effect;
}

int funct_group22_3();

int funct_group22_2()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group22_3();
  return side_effect;
}

int funct_group22_4();

int funct_group22_3()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group22_4();
  return side_effect;
}

int funct_group22_5();

int funct_group22_4()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group22_5();
  return side_effect;
}

int funct_group22_6();

int funct_group22_5()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group22_6();
  return side_effect;
}

int funct_group22_7();

int funct_group22_6()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group22_7();
  return side_effect;
}

int funct_group22_8();

int funct_group22_7()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group22_8();
  return side_effect;
}

int funct_group22_9();

int funct_group22_8()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group22_9();
  return side_effect;
}

int funct_group22_10();

int funct_group22_9()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group22_10();
  return side_effect;
}

int funct_group22_11();

int funct_group22_10()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group22_11();
  return side_effect;
}

int funct_group22_12();

int funct_group22_11()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group22_12();
  return side_effect;
}

int funct_group22_13();

int funct_group22_12()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group22_13();
  return side_effect;
}

int funct_group22_14();

int funct_group22_13()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group22_14();
  return side_effect;
}

int funct_group22_15();

int funct_group22_14()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group22_15();
  return side_effect;
}

int funct_group22_16();

int funct_group22_15()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group22_16();
  return side_effect;
}

int funct_group22_17();

int funct_group22_16()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group22_17();
  return side_effect;
}

int funct_group22_18();

int funct_group22_17()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group22_18();
  return side_effect;
}

int funct_group22_19();

int funct_group22_18()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group22_19();
  return side_effect;
}

int funct_group22_20();

int funct_group22_19()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group22_20();
  return side_effect;
}

int funct_group22_21();

int funct_group22_20()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group22_21();
  return side_effect;
}

int funct_group22_22();

int funct_group22_21()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group22_22();
  return side_effect;
}

int funct_group22_23();

int funct_group22_22()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group22_23();
  return side_effect;
}

int funct_group22_23()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();

  if (side_effect > 0) {
    start_cycles = resources->clock->uptime();
    throw my_error_t{ .data = { 0xDE, 0xAD } };
  }

  return side_effect;
}

int funct_group23_1();

int funct_group23_0()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group23_1();
  return side_effect;
}

int funct_group23_2();

int funct_group23_1()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group23_2();
  return side_effect;
}

int funct_group23_3();

int funct_group23_2()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group23_3();
  return side_effect;
}

int funct_group23_4();

int funct_group23_3()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group23_4();
  return side_effect;
}

int funct_group23_5();

int funct_group23_4()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group23_5();
  return side_effect;
}

int funct_group23_6();

int funct_group23_5()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group23_6();
  return side_effect;
}

int funct_group23_7();

int funct_group23_6()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group23_7();
  return side_effect;
}

int funct_group23_8();

int funct_group23_7()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group23_8();
  return side_effect;
}

int funct_group23_9();

int funct_group23_8()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group23_9();
  return side_effect;
}

int funct_group23_10();

int funct_group23_9()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group23_10();
  return side_effect;
}

int funct_group23_11();

int funct_group23_10()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group23_11();
  return side_effect;
}

int funct_group23_12();

int funct_group23_11()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group23_12();
  return side_effect;
}

int funct_group23_13();

int funct_group23_12()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group23_13();
  return side_effect;
}

int funct_group23_14();

int funct_group23_13()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group23_14();
  return side_effect;
}

int funct_group23_15();

int funct_group23_14()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group23_15();
  return side_effect;
}

int funct_group23_16();

int funct_group23_15()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group23_16();
  return side_effect;
}

int funct_group23_17();

int funct_group23_16()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group23_17();
  return side_effect;
}

int funct_group23_18();

int funct_group23_17()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group23_18();
  return side_effect;
}

int funct_group23_19();

int funct_group23_18()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group23_19();
  return side_effect;
}

int funct_group23_20();

int funct_group23_19()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group23_20();
  return side_effect;
}

int funct_group23_21();

int funct_group23_20()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group23_21();
  return side_effect;
}

int funct_group23_22();

int funct_group23_21()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group23_22();
  return side_effect;
}

int funct_group23_23();

int funct_group23_22()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group23_23();
  return side_effect;
}

int funct_group23_24();

int funct_group23_23()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group23_24();
  return side_effect;
}

int funct_group23_25();

int funct_group23_24()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group23_25();
  return side_effect;
}

int funct_group23_26();

int funct_group23_25()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group23_26();
  return side_effect;
}

int funct_group23_27();

int funct_group23_26()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group23_27();
  return side_effect;
}

int funct_group23_28();

int funct_group23_27()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group23_28();
  return side_effect;
}

int funct_group23_29();

int funct_group23_28()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group23_29();
  return side_effect;
}

int funct_group23_30();

int funct_group23_29()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group23_30();
  return side_effect;
}

int funct_group23_31();

int funct_group23_30()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group23_31();
  return side_effect;
}

int funct_group23_32();

int funct_group23_31()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group23_32();
  return side_effect;
}

int funct_group23_33();

int funct_group23_32()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group23_33();
  return side_effect;
}

int funct_group23_34();

int funct_group23_33()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group23_34();
  return side_effect;
}

int funct_group23_35();

int funct_group23_34()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group23_35();
  return side_effect;
}

int funct_group23_36();

int funct_group23_35()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group23_36();
  return side_effect;
}

int funct_group23_37();

int funct_group23_36()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group23_37();
  return side_effect;
}

int funct_group23_38();

int funct_group23_37()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group23_38();
  return side_effect;
}

int funct_group23_39();

int funct_group23_38()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group23_39();
  return side_effect;
}

int funct_group23_40();

int funct_group23_39()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group23_40();
  return side_effect;
}

int funct_group23_41();

int funct_group23_40()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group23_41();
  return side_effect;
}

int funct_group23_42();

int funct_group23_41()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group23_42();
  return side_effect;
}

int funct_group23_43();

int funct_group23_42()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group23_43();
  return side_effect;
}

int funct_group23_44();

int funct_group23_43()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group23_44();
  return side_effect;
}

int funct_group23_45();

int funct_group23_44()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group23_45();
  return side_effect;
}

int funct_group23_46();

int funct_group23_45()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group23_46();
  return side_effect;
}

int funct_group23_47();

int funct_group23_46()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group23_47();
  return side_effect;
}

int funct_group23_47()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();

  if (side_effect > 0) {
    start_cycles = resources->clock->uptime();
    throw my_error_t{ .data = { 0xDE, 0xAD } };
  }

  return side_effect;
}

int funct_group24_1();

int funct_group24_0()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_1();
  return side_effect;
}

int funct_group24_2();

int funct_group24_1()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_2();
  return side_effect;
}

int funct_group24_3();

int funct_group24_2()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_3();
  return side_effect;
}

int funct_group24_4();

int funct_group24_3()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_4();
  return side_effect;
}

int funct_group24_5();

int funct_group24_4()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_5();
  return side_effect;
}

int funct_group24_6();

int funct_group24_5()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_6();
  return side_effect;
}

int funct_group24_7();

int funct_group24_6()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_7();
  return side_effect;
}

int funct_group24_8();

int funct_group24_7()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_8();
  return side_effect;
}

int funct_group24_9();

int funct_group24_8()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_9();
  return side_effect;
}

int funct_group24_10();

int funct_group24_9()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_10();
  return side_effect;
}

int funct_group24_11();

int funct_group24_10()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_11();
  return side_effect;
}

int funct_group24_12();

int funct_group24_11()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_12();
  return side_effect;
}

int funct_group24_13();

int funct_group24_12()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_13();
  return side_effect;
}

int funct_group24_14();

int funct_group24_13()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_14();
  return side_effect;
}

int funct_group24_15();

int funct_group24_14()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_15();
  return side_effect;
}

int funct_group24_16();

int funct_group24_15()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_16();
  return side_effect;
}

int funct_group24_17();

int funct_group24_16()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_17();
  return side_effect;
}

int funct_group24_18();

int funct_group24_17()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_18();
  return side_effect;
}

int funct_group24_19();

int funct_group24_18()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_19();
  return side_effect;
}

int funct_group24_20();

int funct_group24_19()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_20();
  return side_effect;
}

int funct_group24_21();

int funct_group24_20()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_21();
  return side_effect;
}

int funct_group24_22();

int funct_group24_21()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_22();
  return side_effect;
}

int funct_group24_23();

int funct_group24_22()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_23();
  return side_effect;
}

int funct_group24_24();

int funct_group24_23()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_24();
  return side_effect;
}

int funct_group24_25();

int funct_group24_24()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_25();
  return side_effect;
}

int funct_group24_26();

int funct_group24_25()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_26();
  return side_effect;
}

int funct_group24_27();

int funct_group24_26()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_27();
  return side_effect;
}

int funct_group24_28();

int funct_group24_27()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_28();
  return side_effect;
}

int funct_group24_29();

int funct_group24_28()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_29();
  return side_effect;
}

int funct_group24_30();

int funct_group24_29()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_30();
  return side_effect;
}

int funct_group24_31();

int funct_group24_30()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_31();
  return side_effect;
}

int funct_group24_32();

int funct_group24_31()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_32();
  return side_effect;
}

int funct_group24_33();

int funct_group24_32()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_33();
  return side_effect;
}

int funct_group24_34();

int funct_group24_33()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_34();
  return side_effect;
}

int funct_group24_35();

int funct_group24_34()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_35();
  return side_effect;
}

int funct_group24_36();

int funct_group24_35()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_36();
  return side_effect;
}

int funct_group24_37();

int funct_group24_36()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_37();
  return side_effect;
}

int funct_group24_38();

int funct_group24_37()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_38();
  return side_effect;
}

int funct_group24_39();

int funct_group24_38()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_39();
  return side_effect;
}

int funct_group24_40();

int funct_group24_39()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_40();
  return side_effect;
}

int funct_group24_41();

int funct_group24_40()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_41();
  return side_effect;
}

int funct_group24_42();

int funct_group24_41()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_42();
  return side_effect;
}

int funct_group24_43();

int funct_group24_42()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_43();
  return side_effect;
}

int funct_group24_44();

int funct_group24_43()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_44();
  return side_effect;
}

int funct_group24_45();

int funct_group24_44()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_45();
  return side_effect;
}

int funct_group24_46();

int funct_group24_45()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_46();
  return side_effect;
}

int funct_group24_47();

int funct_group24_46()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_47();
  return side_effect;
}

int funct_group24_48();

int funct_group24_47()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_48();
  return side_effect;
}

int funct_group24_49();

int funct_group24_48()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_49();
  return side_effect;
}

int funct_group24_50();

int funct_group24_49()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_50();
  return side_effect;
}

int funct_group24_51();

int funct_group24_50()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_51();
  return side_effect;
}

int funct_group24_52();

int funct_group24_51()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_52();
  return side_effect;
}

int funct_group24_53();

int funct_group24_52()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_53();
  return side_effect;
}

int funct_group24_54();

int funct_group24_53()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_54();
  return side_effect;
}

int funct_group24_55();

int funct_group24_54()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_55();
  return side_effect;
}

int funct_group24_56();

int funct_group24_55()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_56();
  return side_effect;
}

int funct_group24_57();

int funct_group24_56()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_57();
  return side_effect;
}

int funct_group24_58();

int funct_group24_57()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_58();
  return side_effect;
}

int funct_group24_59();

int funct_group24_58()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_59();
  return side_effect;
}

int funct_group24_60();

int funct_group24_59()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_60();
  return side_effect;
}

int funct_group24_61();

int funct_group24_60()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_61();
  return side_effect;
}

int funct_group24_62();

int funct_group24_61()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_62();
  return side_effect;
}

int funct_group24_63();

int funct_group24_62()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_63();
  return side_effect;
}

int funct_group24_64();

int funct_group24_63()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_64();
  return side_effect;
}

int funct_group24_65();

int funct_group24_64()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_65();
  return side_effect;
}

int funct_group24_66();

int funct_group24_65()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_66();
  return side_effect;
}

int funct_group24_67();

int funct_group24_66()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_67();
  return side_effect;
}

int funct_group24_68();

int funct_group24_67()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_68();
  return side_effect;
}

int funct_group24_69();

int funct_group24_68()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_69();
  return side_effect;
}

int funct_group24_70();

int funct_group24_69()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_70();
  return side_effect;
}

int funct_group24_71();

int funct_group24_70()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_71();
  return side_effect;
}

int funct_group24_72();

int funct_group24_71()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_72();
  return side_effect;
}

int funct_group24_73();

int funct_group24_72()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_73();
  return side_effect;
}

int funct_group24_74();

int funct_group24_73()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_74();
  return side_effect;
}

int funct_group24_75();

int funct_group24_74()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_75();
  return side_effect;
}

int funct_group24_76();

int funct_group24_75()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_76();
  return side_effect;
}

int funct_group24_77();

int funct_group24_76()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_77();
  return side_effect;
}

int funct_group24_78();

int funct_group24_77()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_78();
  return side_effect;
}

int funct_group24_79();

int funct_group24_78()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_79();
  return side_effect;
}

int funct_group24_80();

int funct_group24_79()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_80();
  return side_effect;
}

int funct_group24_81();

int funct_group24_80()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_81();
  return side_effect;
}

int funct_group24_82();

int funct_group24_81()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_82();
  return side_effect;
}

int funct_group24_83();

int funct_group24_82()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_83();
  return side_effect;
}

int funct_group24_84();

int funct_group24_83()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_84();
  return side_effect;
}

int funct_group24_85();

int funct_group24_84()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_85();
  return side_effect;
}

int funct_group24_86();

int funct_group24_85()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_86();
  return side_effect;
}

int funct_group24_87();

int funct_group24_86()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_87();
  return side_effect;
}

int funct_group24_88();

int funct_group24_87()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_88();
  return side_effect;
}

int funct_group24_89();

int funct_group24_88()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_89();
  return side_effect;
}

int funct_group24_90();

int funct_group24_89()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_90();
  return side_effect;
}

int funct_group24_91();

int funct_group24_90()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_91();
  return side_effect;
}

int funct_group24_92();

int funct_group24_91()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_92();
  return side_effect;
}

int funct_group24_93();

int funct_group24_92()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_93();
  return side_effect;
}

int funct_group24_94();

int funct_group24_93()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_94();
  return side_effect;
}

int funct_group24_95();

int funct_group24_94()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();
  side_effect = side_effect + funct_group24_95();
  return side_effect;
}

int funct_group24_95()
{
  static std::uint32_t volatile inner_side_effect = 0;
  inner_side_effect = inner_side_effect + 1;
  class_1 instance_0(side_effect);
  instance_0.trigger();

  if (side_effect > 0) {
    start_cycles = resources->clock->uptime();
    throw my_error_t{ .data = { 0xDE, 0xAD } };
  }

  return side_effect;
}
#endif