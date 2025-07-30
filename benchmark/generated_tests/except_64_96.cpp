#include <cstdint>

#include <array>

#include <platform.hpp>

// Global side effect to prevent optimization
std::int32_t volatile side_effect = 0;

// Simple class without destructor
class simple_object
{
public:
  explicit simple_object(std::int32_t value)
    : m_value(value)
  {
    side_effect = side_effect + 1;
  }

  void do_work()
  {
    side_effect = side_effect + m_value;
  }

private:
  std::int32_t m_value;
};

// Class with destructor for testing destructor impact
class destructor_object
{
public:
  explicit destructor_object(std::int32_t value)
    : m_value(value)
  {
    side_effect = side_effect + 1;
  }

  ~destructor_object()
  {
    side_effect = side_effect + 1;
  }

  void do_work()
  {
    side_effect = side_effect + m_value;
  }

private:
  std::int32_t m_value;
};

auto volatile error_size_select = 0U;

// Error type for testing
struct test_error_64
{
  std::array<std::uint8_t, 64> data;
};
// Error type for testing
struct test_error_96
{
  std::array<std::uint8_t, 96> data;
};
int depth_70_percent_0();
int depth_69_percent_0();
int depth_68_percent_0();
int depth_67_percent_0();
int depth_66_percent_0();
int depth_65_percent_0();
int depth_64_percent_0();
int depth_63_percent_0();
int depth_62_percent_0();
int depth_61_percent_0();
int depth_60_percent_0();
int depth_59_percent_0();
int depth_58_percent_0();
int depth_57_percent_0();
int depth_56_percent_0();
int depth_55_percent_0();
int depth_54_percent_0();
int depth_53_percent_0();
int depth_52_percent_0();
int depth_51_percent_0();
int depth_50_percent_0();
int depth_49_percent_0();
int depth_48_percent_0();
int depth_47_percent_0();
int depth_46_percent_0();
int depth_45_percent_0();
int depth_44_percent_0();
int depth_43_percent_0();
int depth_42_percent_0();
int depth_41_percent_0();
int depth_40_percent_0();
int depth_39_percent_0();
int depth_38_percent_0();
int depth_37_percent_0();
int depth_36_percent_0();
int depth_35_percent_0();
int depth_34_percent_0();
int depth_33_percent_0();
int depth_32_percent_0();
int depth_31_percent_0();
int depth_30_percent_0();
int depth_29_percent_0();
int depth_28_percent_0();
int depth_27_percent_0();
int depth_26_percent_0();
int depth_25_percent_0();
int depth_24_percent_0();
int depth_23_percent_0();
int depth_22_percent_0();
int depth_21_percent_0();
int depth_20_percent_0();
int depth_19_percent_0();
int depth_18_percent_0();
int depth_17_percent_0();
int depth_16_percent_0();
int depth_15_percent_0();
int depth_14_percent_0();
int depth_13_percent_0();
int depth_12_percent_0();
int depth_11_percent_0();
int depth_10_percent_0();
int depth_09_percent_0();
int depth_08_percent_0();
int depth_07_percent_0();
int depth_06_percent_0();
int depth_05_percent_0();
int depth_04_percent_0();
int depth_03_percent_0();
int depth_02_percent_0();
int depth_01_percent_0();
[[gnu::noinline]]
int depth_70_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 25> preserve_frame = {
    side_effect,
  };

  int result = depth_69_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_69_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 27> preserve_frame = {
    side_effect,
  };

  int result = depth_68_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_68_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 3> preserve_frame = {
    side_effect,
  };

  int result = depth_67_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_67_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 17> preserve_frame = {
    side_effect,
  };

  int result = depth_66_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_66_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 32> preserve_frame = {
    side_effect,
  };

  int result = depth_65_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_65_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 26> preserve_frame = {
    side_effect,
  };

  int result = depth_64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_64_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 20> preserve_frame = {
    side_effect,
  };

  int result = depth_63_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_63_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 31> preserve_frame = {
    side_effect,
  };

  int result = depth_62_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_62_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 23> preserve_frame = {
    side_effect,
  };

  int result = depth_61_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_61_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 14> preserve_frame = {
    side_effect,
  };

  int result = depth_60_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_60_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 9> preserve_frame = {
    side_effect,
  };

  int result = depth_59_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_59_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 19> preserve_frame = {
    side_effect,
  };

  int result = depth_58_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_58_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 9> preserve_frame = {
    side_effect,
  };

  int result = depth_57_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_57_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 7> preserve_frame = {
    side_effect,
  };

  int result = depth_56_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_56_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 17> preserve_frame = {
    side_effect,
  };

  int result = depth_55_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_55_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 10> preserve_frame = {
    side_effect,
  };

  int result = depth_54_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_54_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 20> preserve_frame = {
    side_effect,
  };

  int result = depth_53_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_53_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 7> preserve_frame = {
    side_effect,
  };

  int result = depth_52_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_52_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 5> preserve_frame = {
    side_effect,
  };

  int result = depth_51_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_51_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 22> preserve_frame = {
    side_effect,
  };

  int result = depth_50_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_50_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 31> preserve_frame = {
    side_effect,
  };

  int result = depth_49_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_49_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 7> preserve_frame = {
    side_effect,
  };

  int result = depth_48_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_48_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 23> preserve_frame = {
    side_effect,
  };

  int result = depth_47_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_47_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 28> preserve_frame = {
    side_effect,
  };

  int result = depth_46_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_46_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 21> preserve_frame = {
    side_effect,
  };

  int result = depth_45_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_45_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 14> preserve_frame = {
    side_effect,
  };

  int result = depth_44_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_44_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 31> preserve_frame = {
    side_effect,
  };

  int result = depth_43_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_43_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 29> preserve_frame = {
    side_effect,
  };

  int result = depth_42_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_42_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 17> preserve_frame = {
    side_effect,
  };

  int result = depth_41_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_41_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 4> preserve_frame = {
    side_effect,
  };

  int result = depth_40_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_40_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 1> preserve_frame = {
    side_effect,
  };

  int result = depth_39_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_39_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 6> preserve_frame = {
    side_effect,
  };

  int result = depth_38_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_38_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 26> preserve_frame = {
    side_effect,
  };

  int result = depth_37_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_37_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 1> preserve_frame = {
    side_effect,
  };

  int result = depth_36_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_36_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 32> preserve_frame = {
    side_effect,
  };

  int result = depth_35_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_35_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 22> preserve_frame = {
    side_effect,
  };

  int result = depth_34_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_34_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 16> preserve_frame = {
    side_effect,
  };

  int result = depth_33_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_33_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 21> preserve_frame = {
    side_effect,
  };

  int result = depth_32_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_32_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 5> preserve_frame = {
    side_effect,
  };

  int result = depth_31_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_31_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 13> preserve_frame = {
    side_effect,
  };

  int result = depth_30_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_30_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 15> preserve_frame = {
    side_effect,
  };

  int result = depth_29_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_29_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 16> preserve_frame = {
    side_effect,
  };

  int result = depth_28_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_28_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 10> preserve_frame = {
    side_effect,
  };

  int result = depth_27_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_27_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 29> preserve_frame = {
    side_effect,
  };

  int result = depth_26_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_26_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 6> preserve_frame = {
    side_effect,
  };

  int result = depth_25_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_25_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 6> preserve_frame = {
    side_effect,
  };

  int result = depth_24_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_24_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 21> preserve_frame = {
    side_effect,
  };

  int result = depth_23_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_23_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 32> preserve_frame = {
    side_effect,
  };

  int result = depth_22_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_22_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 7> preserve_frame = {
    side_effect,
  };

  int result = depth_21_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_21_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 20> preserve_frame = {
    side_effect,
  };

  int result = depth_20_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_20_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 19> preserve_frame = {
    side_effect,
  };

  int result = depth_19_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_19_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 8> preserve_frame = {
    side_effect,
  };

  int result = depth_18_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_18_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 22> preserve_frame = {
    side_effect,
  };

  int result = depth_17_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_17_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 14> preserve_frame = {
    side_effect,
  };

  int result = depth_16_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_16_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 19> preserve_frame = {
    side_effect,
  };

  int result = depth_15_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_15_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 29> preserve_frame = {
    side_effect,
  };

  int result = depth_14_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_14_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 6> preserve_frame = {
    side_effect,
  };

  int result = depth_13_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_13_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 25> preserve_frame = {
    side_effect,
  };

  int result = depth_12_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_12_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 21> preserve_frame = {
    side_effect,
  };

  int result = depth_11_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_11_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 16> preserve_frame = {
    side_effect,
  };

  int result = depth_10_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_10_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 19> preserve_frame = {
    side_effect,
  };

  int result = depth_09_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_09_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 12> preserve_frame = {
    side_effect,
  };

  int result = depth_08_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_08_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 13> preserve_frame = {
    side_effect,
  };

  int result = depth_07_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_07_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 12> preserve_frame = {
    side_effect,
  };

  int result = depth_06_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_06_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 3> preserve_frame = {
    side_effect,
  };

  int result = depth_05_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_05_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 17> preserve_frame = {
    side_effect,
  };

  int result = depth_04_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_04_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 31> preserve_frame = {
    side_effect,
  };

  int result = depth_03_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_03_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 5> preserve_frame = {
    side_effect,
  };

  int result = depth_02_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_02_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 6> preserve_frame = {
    side_effect,
  };

  int result = depth_01_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_01_percent_0()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 9> preserve_frame = {
    side_effect,
  };

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }

  // This is where the exception originates

  if (error_size_select == 64) {
    start();
    throw test_error_64{ .data = { 0xDE, 0xAD, 0xBE, 0xEF } };
  }

  if (error_size_select == 96) {
    start();
    throw test_error_96{ .data = { 0xDE, 0xAD, 0xBE, 0xEF } };
  }

  return side_effect;
}

int depth_70_percent_25();
int depth_69_percent_25();
int depth_68_percent_25();
int depth_67_percent_25();
int depth_66_percent_25();
int depth_65_percent_25();
int depth_64_percent_25();
int depth_63_percent_25();
int depth_62_percent_25();
int depth_61_percent_25();
int depth_60_percent_25();
int depth_59_percent_25();
int depth_58_percent_25();
int depth_57_percent_25();
int depth_56_percent_25();
int depth_55_percent_25();
int depth_54_percent_25();
int depth_53_percent_25();
int depth_52_percent_25();
int depth_51_percent_25();
int depth_50_percent_25();
int depth_49_percent_25();
int depth_48_percent_25();
int depth_47_percent_25();
int depth_46_percent_25();
int depth_45_percent_25();
int depth_44_percent_25();
int depth_43_percent_25();
int depth_42_percent_25();
int depth_41_percent_25();
int depth_40_percent_25();
int depth_39_percent_25();
int depth_38_percent_25();
int depth_37_percent_25();
int depth_36_percent_25();
int depth_35_percent_25();
int depth_34_percent_25();
int depth_33_percent_25();
int depth_32_percent_25();
int depth_31_percent_25();
int depth_30_percent_25();
int depth_29_percent_25();
int depth_28_percent_25();
int depth_27_percent_25();
int depth_26_percent_25();
int depth_25_percent_25();
int depth_24_percent_25();
int depth_23_percent_25();
int depth_22_percent_25();
int depth_21_percent_25();
int depth_20_percent_25();
int depth_19_percent_25();
int depth_18_percent_25();
int depth_17_percent_25();
int depth_16_percent_25();
int depth_15_percent_25();
int depth_14_percent_25();
int depth_13_percent_25();
int depth_12_percent_25();
int depth_11_percent_25();
int depth_10_percent_25();
int depth_09_percent_25();
int depth_08_percent_25();
int depth_07_percent_25();
int depth_06_percent_25();
int depth_05_percent_25();
int depth_04_percent_25();
int depth_03_percent_25();
int depth_02_percent_25();
int depth_01_percent_25();
[[gnu::noinline]]
int depth_70_percent_25()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 10> preserve_frame = {
    side_effect,
  };

  int result = depth_69_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_69_percent_25()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 3> preserve_frame = {
    side_effect,
  };

  int result = depth_68_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_68_percent_25()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 6> preserve_frame = {
    side_effect,
  };

  int result = depth_67_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_67_percent_25()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 26> preserve_frame = {
    side_effect,
  };

  int result = depth_66_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_66_percent_25()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 18> preserve_frame = {
    side_effect,
  };

  int result = depth_65_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_65_percent_25()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 16> preserve_frame = {
    side_effect,
  };

  int result = depth_64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_64_percent_25()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 14> preserve_frame = {
    side_effect,
  };

  int result = depth_63_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_63_percent_25()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 27> preserve_frame = {
    side_effect,
  };

  int result = depth_62_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_62_percent_25()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 18> preserve_frame = {
    side_effect,
  };

  int result = depth_61_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_61_percent_25()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 29> preserve_frame = {
    side_effect,
  };

  int result = depth_60_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_60_percent_25()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 32> preserve_frame = {
    side_effect,
  };

  int result = depth_59_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_59_percent_25()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 23> preserve_frame = {
    side_effect,
  };

  int result = depth_58_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_58_percent_25()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 6> preserve_frame = {
    side_effect,
  };

  int result = depth_57_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_57_percent_25()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 21> preserve_frame = {
    side_effect,
  };

  int result = depth_56_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_56_percent_25()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 8> preserve_frame = {
    side_effect,
  };

  int result = depth_55_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_55_percent_25()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 32> preserve_frame = {
    side_effect,
  };

  int result = depth_54_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_54_percent_25()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 22> preserve_frame = {
    side_effect,
  };

  int result = depth_53_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_53_percent_25()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 13> preserve_frame = {
    side_effect,
  };

  int result = depth_52_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_52_percent_25()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 16> preserve_frame = {
    side_effect,
  };

  int result = depth_51_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_51_percent_25()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 2> preserve_frame = {
    side_effect,
  };

  int result = depth_50_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_50_percent_25()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 18> preserve_frame = {
    side_effect,
  };

  int result = depth_49_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_49_percent_25()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 8> preserve_frame = {
    side_effect,
  };

  int result = depth_48_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_48_percent_25()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 15> preserve_frame = {
    side_effect,
  };

  int result = depth_47_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_47_percent_25()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 24> preserve_frame = {
    side_effect,
  };

  int result = depth_46_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_46_percent_25()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 11> preserve_frame = {
    side_effect,
  };

  int result = depth_45_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_45_percent_25()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 22> preserve_frame = {
    side_effect,
  };

  int result = depth_44_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_44_percent_25()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 28> preserve_frame = {
    side_effect,
  };

  int result = depth_43_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_43_percent_25()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 4> preserve_frame = {
    side_effect,
  };

  int result = depth_42_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_42_percent_25()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 7> preserve_frame = {
    side_effect,
  };

  int result = depth_41_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_41_percent_25()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 10> preserve_frame = {
    side_effect,
  };

  int result = depth_40_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_40_percent_25()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 15> preserve_frame = {
    side_effect,
  };

  int result = depth_39_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_39_percent_25()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 3> preserve_frame = {
    side_effect,
  };

  int result = depth_38_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_38_percent_25()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 5> preserve_frame = {
    side_effect,
  };

  int result = depth_37_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_37_percent_25()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 2> preserve_frame = {
    side_effect,
  };

  int result = depth_36_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_36_percent_25()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 8> preserve_frame = {
    side_effect,
  };

  int result = depth_35_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_35_percent_25()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 13> preserve_frame = {
    side_effect,
  };

  int result = depth_34_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_34_percent_25()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 8> preserve_frame = {
    side_effect,
  };

  int result = depth_33_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_33_percent_25()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 26> preserve_frame = {
    side_effect,
  };

  int result = depth_32_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_32_percent_25()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 6> preserve_frame = {
    side_effect,
  };

  int result = depth_31_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_31_percent_25()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 24> preserve_frame = {
    side_effect,
  };

  int result = depth_30_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_30_percent_25()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 8> preserve_frame = {
    side_effect,
  };

  int result = depth_29_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_29_percent_25()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 3> preserve_frame = {
    side_effect,
  };

  int result = depth_28_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_28_percent_25()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 2> preserve_frame = {
    side_effect,
  };

  int result = depth_27_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_27_percent_25()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 13> preserve_frame = {
    side_effect,
  };

  int result = depth_26_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_26_percent_25()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 12> preserve_frame = {
    side_effect,
  };

  int result = depth_25_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_25_percent_25()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 8> preserve_frame = {
    side_effect,
  };

  int result = depth_24_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_24_percent_25()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 31> preserve_frame = {
    side_effect,
  };

  int result = depth_23_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_23_percent_25()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 14> preserve_frame = {
    side_effect,
  };

  int result = depth_22_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_22_percent_25()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 4> preserve_frame = {
    side_effect,
  };

  int result = depth_21_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_21_percent_25()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 2> preserve_frame = {
    side_effect,
  };

  int result = depth_20_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_20_percent_25()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 28> preserve_frame = {
    side_effect,
  };

  int result = depth_19_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_19_percent_25()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 7> preserve_frame = {
    side_effect,
  };

  int result = depth_18_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_18_percent_25()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 17> preserve_frame = {
    side_effect,
  };

  int result = depth_17_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_17_percent_25()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 5> preserve_frame = {
    side_effect,
  };

  int result = depth_16_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_16_percent_25()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 15> preserve_frame = {
    side_effect,
  };

  int result = depth_15_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_15_percent_25()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 5> preserve_frame = {
    side_effect,
  };

  int result = depth_14_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_14_percent_25()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 20> preserve_frame = {
    side_effect,
  };

  int result = depth_13_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_13_percent_25()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 23> preserve_frame = {
    side_effect,
  };

  int result = depth_12_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_12_percent_25()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 28> preserve_frame = {
    side_effect,
  };

  int result = depth_11_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_11_percent_25()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 12> preserve_frame = {
    side_effect,
  };

  int result = depth_10_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_10_percent_25()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 4> preserve_frame = {
    side_effect,
  };

  int result = depth_09_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_09_percent_25()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 30> preserve_frame = {
    side_effect,
  };

  int result = depth_08_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_08_percent_25()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 3> preserve_frame = {
    side_effect,
  };

  int result = depth_07_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_07_percent_25()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 7> preserve_frame = {
    side_effect,
  };

  int result = depth_06_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_06_percent_25()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 26> preserve_frame = {
    side_effect,
  };

  int result = depth_05_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_05_percent_25()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 13> preserve_frame = {
    side_effect,
  };

  int result = depth_04_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_04_percent_25()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 17> preserve_frame = {
    side_effect,
  };

  int result = depth_03_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_03_percent_25()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 23> preserve_frame = {
    side_effect,
  };

  int result = depth_02_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_02_percent_25()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 31> preserve_frame = {
    side_effect,
  };

  int result = depth_01_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_01_percent_25()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 11> preserve_frame = {
    side_effect,
  };

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }

  // This is where the exception originates

  if (error_size_select == 64) {
    start();
    throw test_error_64{ .data = { 0xDE, 0xAD, 0xBE, 0xEF } };
  }

  if (error_size_select == 96) {
    start();
    throw test_error_96{ .data = { 0xDE, 0xAD, 0xBE, 0xEF } };
  }

  return side_effect;
}

int depth_70_percent_50();
int depth_69_percent_50();
int depth_68_percent_50();
int depth_67_percent_50();
int depth_66_percent_50();
int depth_65_percent_50();
int depth_64_percent_50();
int depth_63_percent_50();
int depth_62_percent_50();
int depth_61_percent_50();
int depth_60_percent_50();
int depth_59_percent_50();
int depth_58_percent_50();
int depth_57_percent_50();
int depth_56_percent_50();
int depth_55_percent_50();
int depth_54_percent_50();
int depth_53_percent_50();
int depth_52_percent_50();
int depth_51_percent_50();
int depth_50_percent_50();
int depth_49_percent_50();
int depth_48_percent_50();
int depth_47_percent_50();
int depth_46_percent_50();
int depth_45_percent_50();
int depth_44_percent_50();
int depth_43_percent_50();
int depth_42_percent_50();
int depth_41_percent_50();
int depth_40_percent_50();
int depth_39_percent_50();
int depth_38_percent_50();
int depth_37_percent_50();
int depth_36_percent_50();
int depth_35_percent_50();
int depth_34_percent_50();
int depth_33_percent_50();
int depth_32_percent_50();
int depth_31_percent_50();
int depth_30_percent_50();
int depth_29_percent_50();
int depth_28_percent_50();
int depth_27_percent_50();
int depth_26_percent_50();
int depth_25_percent_50();
int depth_24_percent_50();
int depth_23_percent_50();
int depth_22_percent_50();
int depth_21_percent_50();
int depth_20_percent_50();
int depth_19_percent_50();
int depth_18_percent_50();
int depth_17_percent_50();
int depth_16_percent_50();
int depth_15_percent_50();
int depth_14_percent_50();
int depth_13_percent_50();
int depth_12_percent_50();
int depth_11_percent_50();
int depth_10_percent_50();
int depth_09_percent_50();
int depth_08_percent_50();
int depth_07_percent_50();
int depth_06_percent_50();
int depth_05_percent_50();
int depth_04_percent_50();
int depth_03_percent_50();
int depth_02_percent_50();
int depth_01_percent_50();
[[gnu::noinline]]
int depth_70_percent_50()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 14> preserve_frame = {
    side_effect,
  };

  int result = depth_69_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_69_percent_50()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 4> preserve_frame = {
    side_effect,
  };

  int result = depth_68_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_68_percent_50()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 11> preserve_frame = {
    side_effect,
  };

  int result = depth_67_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_67_percent_50()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 11> preserve_frame = {
    side_effect,
  };

  int result = depth_66_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_66_percent_50()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 22> preserve_frame = {
    side_effect,
  };

  int result = depth_65_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_65_percent_50()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 17> preserve_frame = {
    side_effect,
  };

  int result = depth_64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_64_percent_50()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 8> preserve_frame = {
    side_effect,
  };

  int result = depth_63_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_63_percent_50()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 29> preserve_frame = {
    side_effect,
  };

  int result = depth_62_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_62_percent_50()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 12> preserve_frame = {
    side_effect,
  };

  int result = depth_61_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_61_percent_50()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 1> preserve_frame = {
    side_effect,
  };

  int result = depth_60_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_60_percent_50()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 31> preserve_frame = {
    side_effect,
  };

  int result = depth_59_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_59_percent_50()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 27> preserve_frame = {
    side_effect,
  };

  int result = depth_58_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_58_percent_50()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 20> preserve_frame = {
    side_effect,
  };

  int result = depth_57_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_57_percent_50()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 23> preserve_frame = {
    side_effect,
  };

  int result = depth_56_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_56_percent_50()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 25> preserve_frame = {
    side_effect,
  };

  int result = depth_55_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_55_percent_50()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 17> preserve_frame = {
    side_effect,
  };

  int result = depth_54_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_54_percent_50()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 10> preserve_frame = {
    side_effect,
  };

  int result = depth_53_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_53_percent_50()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 1> preserve_frame = {
    side_effect,
  };

  int result = depth_52_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_52_percent_50()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 30> preserve_frame = {
    side_effect,
  };

  int result = depth_51_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_51_percent_50()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 6> preserve_frame = {
    side_effect,
  };

  int result = depth_50_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_50_percent_50()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 22> preserve_frame = {
    side_effect,
  };

  int result = depth_49_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_49_percent_50()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 3> preserve_frame = {
    side_effect,
  };

  int result = depth_48_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_48_percent_50()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 18> preserve_frame = {
    side_effect,
  };

  int result = depth_47_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_47_percent_50()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 9> preserve_frame = {
    side_effect,
  };

  int result = depth_46_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_46_percent_50()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 16> preserve_frame = {
    side_effect,
  };

  int result = depth_45_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_45_percent_50()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 31> preserve_frame = {
    side_effect,
  };

  int result = depth_44_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_44_percent_50()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 23> preserve_frame = {
    side_effect,
  };

  int result = depth_43_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_43_percent_50()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 19> preserve_frame = {
    side_effect,
  };

  int result = depth_42_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_42_percent_50()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 23> preserve_frame = {
    side_effect,
  };

  int result = depth_41_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_41_percent_50()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 9> preserve_frame = {
    side_effect,
  };

  int result = depth_40_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_40_percent_50()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 20> preserve_frame = {
    side_effect,
  };

  int result = depth_39_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_39_percent_50()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 25> preserve_frame = {
    side_effect,
  };

  int result = depth_38_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_38_percent_50()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 27> preserve_frame = {
    side_effect,
  };

  int result = depth_37_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_37_percent_50()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 6> preserve_frame = {
    side_effect,
  };

  int result = depth_36_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_36_percent_50()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 1> preserve_frame = {
    side_effect,
  };

  int result = depth_35_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_35_percent_50()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 13> preserve_frame = {
    side_effect,
  };

  int result = depth_34_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_34_percent_50()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 22> preserve_frame = {
    side_effect,
  };

  int result = depth_33_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_33_percent_50()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 11> preserve_frame = {
    side_effect,
  };

  int result = depth_32_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_32_percent_50()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 16> preserve_frame = {
    side_effect,
  };

  int result = depth_31_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_31_percent_50()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 15> preserve_frame = {
    side_effect,
  };

  int result = depth_30_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_30_percent_50()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 29> preserve_frame = {
    side_effect,
  };

  int result = depth_29_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_29_percent_50()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 25> preserve_frame = {
    side_effect,
  };

  int result = depth_28_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_28_percent_50()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 27> preserve_frame = {
    side_effect,
  };

  int result = depth_27_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_27_percent_50()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 3> preserve_frame = {
    side_effect,
  };

  int result = depth_26_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_26_percent_50()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 26> preserve_frame = {
    side_effect,
  };

  int result = depth_25_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_25_percent_50()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 27> preserve_frame = {
    side_effect,
  };

  int result = depth_24_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_24_percent_50()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 3> preserve_frame = {
    side_effect,
  };

  int result = depth_23_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_23_percent_50()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 11> preserve_frame = {
    side_effect,
  };

  int result = depth_22_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_22_percent_50()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 29> preserve_frame = {
    side_effect,
  };

  int result = depth_21_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_21_percent_50()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 5> preserve_frame = {
    side_effect,
  };

  int result = depth_20_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_20_percent_50()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 17> preserve_frame = {
    side_effect,
  };

  int result = depth_19_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_19_percent_50()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 11> preserve_frame = {
    side_effect,
  };

  int result = depth_18_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_18_percent_50()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 29> preserve_frame = {
    side_effect,
  };

  int result = depth_17_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_17_percent_50()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 32> preserve_frame = {
    side_effect,
  };

  int result = depth_16_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_16_percent_50()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 1> preserve_frame = {
    side_effect,
  };

  int result = depth_15_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_15_percent_50()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 3> preserve_frame = {
    side_effect,
  };

  int result = depth_14_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_14_percent_50()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 32> preserve_frame = {
    side_effect,
  };

  int result = depth_13_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_13_percent_50()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 21> preserve_frame = {
    side_effect,
  };

  int result = depth_12_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_12_percent_50()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 20> preserve_frame = {
    side_effect,
  };

  int result = depth_11_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_11_percent_50()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 30> preserve_frame = {
    side_effect,
  };

  int result = depth_10_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_10_percent_50()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 4> preserve_frame = {
    side_effect,
  };

  int result = depth_09_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_09_percent_50()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 27> preserve_frame = {
    side_effect,
  };

  int result = depth_08_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_08_percent_50()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 13> preserve_frame = {
    side_effect,
  };

  int result = depth_07_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_07_percent_50()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 6> preserve_frame = {
    side_effect,
  };

  int result = depth_06_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_06_percent_50()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 9> preserve_frame = {
    side_effect,
  };

  int result = depth_05_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_05_percent_50()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 1> preserve_frame = {
    side_effect,
  };

  int result = depth_04_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_04_percent_50()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 26> preserve_frame = {
    side_effect,
  };

  int result = depth_03_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_03_percent_50()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 27> preserve_frame = {
    side_effect,
  };

  int result = depth_02_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_02_percent_50()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 21> preserve_frame = {
    side_effect,
  };

  int result = depth_01_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_01_percent_50()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 1> preserve_frame = {
    side_effect,
  };

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }

  // This is where the exception originates

  if (error_size_select == 64) {
    start();
    throw test_error_64{ .data = { 0xDE, 0xAD, 0xBE, 0xEF } };
  }

  if (error_size_select == 96) {
    start();
    throw test_error_96{ .data = { 0xDE, 0xAD, 0xBE, 0xEF } };
  }

  return side_effect;
}

int depth_70_percent_75();
int depth_69_percent_75();
int depth_68_percent_75();
int depth_67_percent_75();
int depth_66_percent_75();
int depth_65_percent_75();
int depth_64_percent_75();
int depth_63_percent_75();
int depth_62_percent_75();
int depth_61_percent_75();
int depth_60_percent_75();
int depth_59_percent_75();
int depth_58_percent_75();
int depth_57_percent_75();
int depth_56_percent_75();
int depth_55_percent_75();
int depth_54_percent_75();
int depth_53_percent_75();
int depth_52_percent_75();
int depth_51_percent_75();
int depth_50_percent_75();
int depth_49_percent_75();
int depth_48_percent_75();
int depth_47_percent_75();
int depth_46_percent_75();
int depth_45_percent_75();
int depth_44_percent_75();
int depth_43_percent_75();
int depth_42_percent_75();
int depth_41_percent_75();
int depth_40_percent_75();
int depth_39_percent_75();
int depth_38_percent_75();
int depth_37_percent_75();
int depth_36_percent_75();
int depth_35_percent_75();
int depth_34_percent_75();
int depth_33_percent_75();
int depth_32_percent_75();
int depth_31_percent_75();
int depth_30_percent_75();
int depth_29_percent_75();
int depth_28_percent_75();
int depth_27_percent_75();
int depth_26_percent_75();
int depth_25_percent_75();
int depth_24_percent_75();
int depth_23_percent_75();
int depth_22_percent_75();
int depth_21_percent_75();
int depth_20_percent_75();
int depth_19_percent_75();
int depth_18_percent_75();
int depth_17_percent_75();
int depth_16_percent_75();
int depth_15_percent_75();
int depth_14_percent_75();
int depth_13_percent_75();
int depth_12_percent_75();
int depth_11_percent_75();
int depth_10_percent_75();
int depth_09_percent_75();
int depth_08_percent_75();
int depth_07_percent_75();
int depth_06_percent_75();
int depth_05_percent_75();
int depth_04_percent_75();
int depth_03_percent_75();
int depth_02_percent_75();
int depth_01_percent_75();
[[gnu::noinline]]
int depth_70_percent_75()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 14> preserve_frame = {
    side_effect,
  };

  int result = depth_69_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_69_percent_75()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 1> preserve_frame = {
    side_effect,
  };

  int result = depth_68_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_68_percent_75()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 1> preserve_frame = {
    side_effect,
  };

  int result = depth_67_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_67_percent_75()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 7> preserve_frame = {
    side_effect,
  };

  int result = depth_66_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_66_percent_75()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 13> preserve_frame = {
    side_effect,
  };

  int result = depth_65_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_65_percent_75()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 8> preserve_frame = {
    side_effect,
  };

  int result = depth_64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_64_percent_75()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 13> preserve_frame = {
    side_effect,
  };

  int result = depth_63_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_63_percent_75()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 20> preserve_frame = {
    side_effect,
  };

  int result = depth_62_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_62_percent_75()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 18> preserve_frame = {
    side_effect,
  };

  int result = depth_61_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_61_percent_75()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 12> preserve_frame = {
    side_effect,
  };

  int result = depth_60_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_60_percent_75()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 7> preserve_frame = {
    side_effect,
  };

  int result = depth_59_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_59_percent_75()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 31> preserve_frame = {
    side_effect,
  };

  int result = depth_58_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_58_percent_75()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 26> preserve_frame = {
    side_effect,
  };

  int result = depth_57_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_57_percent_75()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 6> preserve_frame = {
    side_effect,
  };

  int result = depth_56_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_56_percent_75()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 2> preserve_frame = {
    side_effect,
  };

  int result = depth_55_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_55_percent_75()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 18> preserve_frame = {
    side_effect,
  };

  int result = depth_54_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_54_percent_75()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 29> preserve_frame = {
    side_effect,
  };

  int result = depth_53_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_53_percent_75()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 8> preserve_frame = {
    side_effect,
  };

  int result = depth_52_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_52_percent_75()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 17> preserve_frame = {
    side_effect,
  };

  int result = depth_51_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_51_percent_75()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 9> preserve_frame = {
    side_effect,
  };

  int result = depth_50_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_50_percent_75()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 23> preserve_frame = {
    side_effect,
  };

  int result = depth_49_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_49_percent_75()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 8> preserve_frame = {
    side_effect,
  };

  int result = depth_48_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_48_percent_75()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 10> preserve_frame = {
    side_effect,
  };

  int result = depth_47_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_47_percent_75()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 18> preserve_frame = {
    side_effect,
  };

  int result = depth_46_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_46_percent_75()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 2> preserve_frame = {
    side_effect,
  };

  int result = depth_45_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_45_percent_75()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 3> preserve_frame = {
    side_effect,
  };

  int result = depth_44_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_44_percent_75()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 3> preserve_frame = {
    side_effect,
  };

  int result = depth_43_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_43_percent_75()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 14> preserve_frame = {
    side_effect,
  };

  int result = depth_42_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_42_percent_75()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 17> preserve_frame = {
    side_effect,
  };

  int result = depth_41_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_41_percent_75()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 21> preserve_frame = {
    side_effect,
  };

  int result = depth_40_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_40_percent_75()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 24> preserve_frame = {
    side_effect,
  };

  int result = depth_39_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_39_percent_75()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 3> preserve_frame = {
    side_effect,
  };

  int result = depth_38_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_38_percent_75()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 32> preserve_frame = {
    side_effect,
  };

  int result = depth_37_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_37_percent_75()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 30> preserve_frame = {
    side_effect,
  };

  int result = depth_36_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_36_percent_75()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 28> preserve_frame = {
    side_effect,
  };

  int result = depth_35_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_35_percent_75()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 24> preserve_frame = {
    side_effect,
  };

  int result = depth_34_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_34_percent_75()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 12> preserve_frame = {
    side_effect,
  };

  int result = depth_33_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_33_percent_75()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 14> preserve_frame = {
    side_effect,
  };

  int result = depth_32_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_32_percent_75()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 25> preserve_frame = {
    side_effect,
  };

  int result = depth_31_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_31_percent_75()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 19> preserve_frame = {
    side_effect,
  };

  int result = depth_30_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_30_percent_75()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 1> preserve_frame = {
    side_effect,
  };

  int result = depth_29_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_29_percent_75()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 9> preserve_frame = {
    side_effect,
  };

  int result = depth_28_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_28_percent_75()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 10> preserve_frame = {
    side_effect,
  };

  int result = depth_27_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_27_percent_75()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 18> preserve_frame = {
    side_effect,
  };

  int result = depth_26_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_26_percent_75()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 22> preserve_frame = {
    side_effect,
  };

  int result = depth_25_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_25_percent_75()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 22> preserve_frame = {
    side_effect,
  };

  int result = depth_24_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_24_percent_75()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 24> preserve_frame = {
    side_effect,
  };

  int result = depth_23_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_23_percent_75()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 6> preserve_frame = {
    side_effect,
  };

  int result = depth_22_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_22_percent_75()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 22> preserve_frame = {
    side_effect,
  };

  int result = depth_21_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_21_percent_75()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 3> preserve_frame = {
    side_effect,
  };

  int result = depth_20_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_20_percent_75()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 3> preserve_frame = {
    side_effect,
  };

  int result = depth_19_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_19_percent_75()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 18> preserve_frame = {
    side_effect,
  };

  int result = depth_18_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_18_percent_75()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 11> preserve_frame = {
    side_effect,
  };

  int result = depth_17_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_17_percent_75()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 10> preserve_frame = {
    side_effect,
  };

  int result = depth_16_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_16_percent_75()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 19> preserve_frame = {
    side_effect,
  };

  int result = depth_15_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_15_percent_75()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 24> preserve_frame = {
    side_effect,
  };

  int result = depth_14_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_14_percent_75()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 26> preserve_frame = {
    side_effect,
  };

  int result = depth_13_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_13_percent_75()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 9> preserve_frame = {
    side_effect,
  };

  int result = depth_12_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_12_percent_75()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 19> preserve_frame = {
    side_effect,
  };

  int result = depth_11_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_11_percent_75()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 8> preserve_frame = {
    side_effect,
  };

  int result = depth_10_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_10_percent_75()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 31> preserve_frame = {
    side_effect,
  };

  int result = depth_09_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_09_percent_75()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 16> preserve_frame = {
    side_effect,
  };

  int result = depth_08_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_08_percent_75()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 4> preserve_frame = {
    side_effect,
  };

  int result = depth_07_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_07_percent_75()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 20> preserve_frame = {
    side_effect,
  };

  int result = depth_06_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_06_percent_75()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 12> preserve_frame = {
    side_effect,
  };

  int result = depth_05_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_05_percent_75()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 5> preserve_frame = {
    side_effect,
  };

  int result = depth_04_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_04_percent_75()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 20> preserve_frame = {
    side_effect,
  };

  int result = depth_03_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_03_percent_75()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 26> preserve_frame = {
    side_effect,
  };

  int result = depth_02_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_02_percent_75()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 22> preserve_frame = {
    side_effect,
  };

  int result = depth_01_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_01_percent_75()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 20> preserve_frame = {
    side_effect,
  };

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }

  // This is where the exception originates

  if (error_size_select == 64) {
    start();
    throw test_error_64{ .data = { 0xDE, 0xAD, 0xBE, 0xEF } };
  }

  if (error_size_select == 96) {
    start();
    throw test_error_96{ .data = { 0xDE, 0xAD, 0xBE, 0xEF } };
  }

  return side_effect;
}

int depth_70_percent_100();
int depth_69_percent_100();
int depth_68_percent_100();
int depth_67_percent_100();
int depth_66_percent_100();
int depth_65_percent_100();
int depth_64_percent_100();
int depth_63_percent_100();
int depth_62_percent_100();
int depth_61_percent_100();
int depth_60_percent_100();
int depth_59_percent_100();
int depth_58_percent_100();
int depth_57_percent_100();
int depth_56_percent_100();
int depth_55_percent_100();
int depth_54_percent_100();
int depth_53_percent_100();
int depth_52_percent_100();
int depth_51_percent_100();
int depth_50_percent_100();
int depth_49_percent_100();
int depth_48_percent_100();
int depth_47_percent_100();
int depth_46_percent_100();
int depth_45_percent_100();
int depth_44_percent_100();
int depth_43_percent_100();
int depth_42_percent_100();
int depth_41_percent_100();
int depth_40_percent_100();
int depth_39_percent_100();
int depth_38_percent_100();
int depth_37_percent_100();
int depth_36_percent_100();
int depth_35_percent_100();
int depth_34_percent_100();
int depth_33_percent_100();
int depth_32_percent_100();
int depth_31_percent_100();
int depth_30_percent_100();
int depth_29_percent_100();
int depth_28_percent_100();
int depth_27_percent_100();
int depth_26_percent_100();
int depth_25_percent_100();
int depth_24_percent_100();
int depth_23_percent_100();
int depth_22_percent_100();
int depth_21_percent_100();
int depth_20_percent_100();
int depth_19_percent_100();
int depth_18_percent_100();
int depth_17_percent_100();
int depth_16_percent_100();
int depth_15_percent_100();
int depth_14_percent_100();
int depth_13_percent_100();
int depth_12_percent_100();
int depth_11_percent_100();
int depth_10_percent_100();
int depth_09_percent_100();
int depth_08_percent_100();
int depth_07_percent_100();
int depth_06_percent_100();
int depth_05_percent_100();
int depth_04_percent_100();
int depth_03_percent_100();
int depth_02_percent_100();
int depth_01_percent_100();
[[gnu::noinline]]
int depth_70_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 27> preserve_frame = {
    side_effect,
  };

  int result = depth_69_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_69_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 7> preserve_frame = {
    side_effect,
  };

  int result = depth_68_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_68_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 7> preserve_frame = {
    side_effect,
  };

  int result = depth_67_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_67_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 31> preserve_frame = {
    side_effect,
  };

  int result = depth_66_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_66_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 31> preserve_frame = {
    side_effect,
  };

  int result = depth_65_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 22> preserve_frame = {
    side_effect,
  };

  int result = depth_64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_64_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 22> preserve_frame = {
    side_effect,
  };

  int result = depth_63_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_63_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 8> preserve_frame = {
    side_effect,
  };

  int result = depth_62_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_62_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 31> preserve_frame = {
    side_effect,
  };

  int result = depth_61_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_61_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 8> preserve_frame = {
    side_effect,
  };

  int result = depth_60_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_60_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 32> preserve_frame = {
    side_effect,
  };

  int result = depth_59_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_59_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 28> preserve_frame = {
    side_effect,
  };

  int result = depth_58_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_58_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 3> preserve_frame = {
    side_effect,
  };

  int result = depth_57_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_57_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 20> preserve_frame = {
    side_effect,
  };

  int result = depth_56_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_56_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 22> preserve_frame = {
    side_effect,
  };

  int result = depth_55_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_55_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 10> preserve_frame = {
    side_effect,
  };

  int result = depth_54_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_54_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 11> preserve_frame = {
    side_effect,
  };

  int result = depth_53_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_53_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 25> preserve_frame = {
    side_effect,
  };

  int result = depth_52_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_52_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 6> preserve_frame = {
    side_effect,
  };

  int result = depth_51_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_51_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 5> preserve_frame = {
    side_effect,
  };

  int result = depth_50_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_50_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 6> preserve_frame = {
    side_effect,
  };

  int result = depth_49_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_49_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 13> preserve_frame = {
    side_effect,
  };

  int result = depth_48_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_48_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 15> preserve_frame = {
    side_effect,
  };

  int result = depth_47_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_47_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 4> preserve_frame = {
    side_effect,
  };

  int result = depth_46_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_46_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 25> preserve_frame = {
    side_effect,
  };

  int result = depth_45_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_45_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 1> preserve_frame = {
    side_effect,
  };

  int result = depth_44_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_44_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 7> preserve_frame = {
    side_effect,
  };

  int result = depth_43_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_43_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 26> preserve_frame = {
    side_effect,
  };

  int result = depth_42_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_42_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 19> preserve_frame = {
    side_effect,
  };

  int result = depth_41_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_41_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 29> preserve_frame = {
    side_effect,
  };

  int result = depth_40_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_40_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 32> preserve_frame = {
    side_effect,
  };

  int result = depth_39_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_39_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 14> preserve_frame = {
    side_effect,
  };

  int result = depth_38_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_38_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 28> preserve_frame = {
    side_effect,
  };

  int result = depth_37_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_37_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 6> preserve_frame = {
    side_effect,
  };

  int result = depth_36_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_36_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 24> preserve_frame = {
    side_effect,
  };

  int result = depth_35_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_35_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 15> preserve_frame = {
    side_effect,
  };

  int result = depth_34_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_34_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 17> preserve_frame = {
    side_effect,
  };

  int result = depth_33_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_33_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 11> preserve_frame = {
    side_effect,
  };

  int result = depth_32_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_32_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 28> preserve_frame = {
    side_effect,
  };

  int result = depth_31_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_31_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 13> preserve_frame = {
    side_effect,
  };

  int result = depth_30_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_30_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 23> preserve_frame = {
    side_effect,
  };

  int result = depth_29_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_29_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 8> preserve_frame = {
    side_effect,
  };

  int result = depth_28_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_28_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 5> preserve_frame = {
    side_effect,
  };

  int result = depth_27_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_27_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 2> preserve_frame = {
    side_effect,
  };

  int result = depth_26_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_26_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 29> preserve_frame = {
    side_effect,
  };

  int result = depth_25_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_25_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 13> preserve_frame = {
    side_effect,
  };

  int result = depth_24_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_24_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 8> preserve_frame = {
    side_effect,
  };

  int result = depth_23_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_23_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 32> preserve_frame = {
    side_effect,
  };

  int result = depth_22_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_22_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 26> preserve_frame = {
    side_effect,
  };

  int result = depth_21_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_21_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 17> preserve_frame = {
    side_effect,
  };

  int result = depth_20_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_20_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 14> preserve_frame = {
    side_effect,
  };

  int result = depth_19_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_19_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 3> preserve_frame = {
    side_effect,
  };

  int result = depth_18_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_18_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 14> preserve_frame = {
    side_effect,
  };

  int result = depth_17_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_17_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 10> preserve_frame = {
    side_effect,
  };

  int result = depth_16_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_16_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 7> preserve_frame = {
    side_effect,
  };

  int result = depth_15_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_15_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 13> preserve_frame = {
    side_effect,
  };

  int result = depth_14_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_14_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 30> preserve_frame = {
    side_effect,
  };

  int result = depth_13_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_13_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 25> preserve_frame = {
    side_effect,
  };

  int result = depth_12_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_12_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 24> preserve_frame = {
    side_effect,
  };

  int result = depth_11_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_11_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 10> preserve_frame = {
    side_effect,
  };

  int result = depth_10_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_10_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 7> preserve_frame = {
    side_effect,
  };

  int result = depth_09_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_09_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 32> preserve_frame = {
    side_effect,
  };

  int result = depth_08_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_08_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 10> preserve_frame = {
    side_effect,
  };

  int result = depth_07_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_07_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 26> preserve_frame = {
    side_effect,
  };

  int result = depth_06_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_06_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 28> preserve_frame = {
    side_effect,
  };

  int result = depth_05_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_05_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 32> preserve_frame = {
    side_effect,
  };

  int result = depth_04_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_04_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 21> preserve_frame = {
    side_effect,
  };

  int result = depth_03_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_03_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 32> preserve_frame = {
    side_effect,
  };

  int result = depth_02_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_02_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 32> preserve_frame = {
    side_effect,
  };

  int result = depth_01_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_01_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 13> preserve_frame = {
    side_effect,
  };

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1;  // Never executed but prevents optimization
  }

  // This is where the exception originates

  if (error_size_select == 64) {
    start();
    throw test_error_64{ .data = { 0xDE, 0xAD, 0xBE, 0xEF } };
  }

  if (error_size_select == 96) {
    start();
    throw test_error_96{ .data = { 0xDE, 0xAD, 0xBE, 0xEF } };
  }

  return side_effect;
}

// Test runner
[[gnu::noinline]]
void run_test_depth70_error64_cleanup_0()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 64;

  try {
    depth_70_percent_0();
  } catch (test_error_64 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth50_error64_cleanup_0()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 64;

  try {
    depth_50_percent_0();
  } catch (test_error_64 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth30_error64_cleanup_0()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 64;

  try {
    depth_30_percent_0();
  } catch (test_error_64 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth10_error64_cleanup_0()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 64;

  try {
    depth_10_percent_0();
  } catch (test_error_64 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth01_error64_cleanup_0()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 64;

  try {
    depth_01_percent_0();
  } catch (test_error_64 const& e) {
    end();
  }

  pause();
}

void run_test_error64_cleanup_0()
{
  run_test_depth70_error64_cleanup_0();
  run_test_depth50_error64_cleanup_0();
  run_test_depth30_error64_cleanup_0();
  run_test_depth10_error64_cleanup_0();
  run_test_depth01_error64_cleanup_0();
}
// Test runner
[[gnu::noinline]]
void run_test_depth70_error64_cleanup_25()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 64;

  try {
    depth_70_percent_25();
  } catch (test_error_64 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth50_error64_cleanup_25()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 64;

  try {
    depth_50_percent_25();
  } catch (test_error_64 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth30_error64_cleanup_25()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 64;

  try {
    depth_30_percent_25();
  } catch (test_error_64 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth10_error64_cleanup_25()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 64;

  try {
    depth_10_percent_25();
  } catch (test_error_64 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth01_error64_cleanup_25()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 64;

  try {
    depth_01_percent_25();
  } catch (test_error_64 const& e) {
    end();
  }

  pause();
}

void run_test_error64_cleanup_25()
{
  run_test_depth70_error64_cleanup_25();
  run_test_depth50_error64_cleanup_25();
  run_test_depth30_error64_cleanup_25();
  run_test_depth10_error64_cleanup_25();
  run_test_depth01_error64_cleanup_25();
}
// Test runner
[[gnu::noinline]]
void run_test_depth70_error64_cleanup_50()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 64;

  try {
    depth_70_percent_50();
  } catch (test_error_64 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth50_error64_cleanup_50()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 64;

  try {
    depth_50_percent_50();
  } catch (test_error_64 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth30_error64_cleanup_50()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 64;

  try {
    depth_30_percent_50();
  } catch (test_error_64 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth10_error64_cleanup_50()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 64;

  try {
    depth_10_percent_50();
  } catch (test_error_64 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth01_error64_cleanup_50()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 64;

  try {
    depth_01_percent_50();
  } catch (test_error_64 const& e) {
    end();
  }

  pause();
}

void run_test_error64_cleanup_50()
{
  run_test_depth70_error64_cleanup_50();
  run_test_depth50_error64_cleanup_50();
  run_test_depth30_error64_cleanup_50();
  run_test_depth10_error64_cleanup_50();
  run_test_depth01_error64_cleanup_50();
}
// Test runner
[[gnu::noinline]]
void run_test_depth70_error64_cleanup_75()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 64;

  try {
    depth_70_percent_75();
  } catch (test_error_64 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth50_error64_cleanup_75()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 64;

  try {
    depth_50_percent_75();
  } catch (test_error_64 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth30_error64_cleanup_75()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 64;

  try {
    depth_30_percent_75();
  } catch (test_error_64 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth10_error64_cleanup_75()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 64;

  try {
    depth_10_percent_75();
  } catch (test_error_64 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth01_error64_cleanup_75()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 64;

  try {
    depth_01_percent_75();
  } catch (test_error_64 const& e) {
    end();
  }

  pause();
}

void run_test_error64_cleanup_75()
{
  run_test_depth70_error64_cleanup_75();
  run_test_depth50_error64_cleanup_75();
  run_test_depth30_error64_cleanup_75();
  run_test_depth10_error64_cleanup_75();
  run_test_depth01_error64_cleanup_75();
}
// Test runner
[[gnu::noinline]]
void run_test_depth70_error64_cleanup_100()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 64;

  try {
    depth_70_percent_100();
  } catch (test_error_64 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth50_error64_cleanup_100()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 64;

  try {
    depth_50_percent_100();
  } catch (test_error_64 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth30_error64_cleanup_100()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 64;

  try {
    depth_30_percent_100();
  } catch (test_error_64 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth10_error64_cleanup_100()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 64;

  try {
    depth_10_percent_100();
  } catch (test_error_64 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth01_error64_cleanup_100()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 64;

  try {
    depth_01_percent_100();
  } catch (test_error_64 const& e) {
    end();
  }

  pause();
}

void run_test_error64_cleanup_100()
{
  run_test_depth70_error64_cleanup_100();
  run_test_depth50_error64_cleanup_100();
  run_test_depth30_error64_cleanup_100();
  run_test_depth10_error64_cleanup_100();
  run_test_depth01_error64_cleanup_100();
}
// Test runner
[[gnu::noinline]]
void run_test_depth70_error96_cleanup_0()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 96;

  try {
    depth_70_percent_0();
  } catch (test_error_96 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth50_error96_cleanup_0()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 96;

  try {
    depth_50_percent_0();
  } catch (test_error_96 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth30_error96_cleanup_0()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 96;

  try {
    depth_30_percent_0();
  } catch (test_error_96 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth10_error96_cleanup_0()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 96;

  try {
    depth_10_percent_0();
  } catch (test_error_96 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth01_error96_cleanup_0()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 96;

  try {
    depth_01_percent_0();
  } catch (test_error_96 const& e) {
    end();
  }

  pause();
}

void run_test_error96_cleanup_0()
{
  run_test_depth70_error96_cleanup_0();
  run_test_depth50_error96_cleanup_0();
  run_test_depth30_error96_cleanup_0();
  run_test_depth10_error96_cleanup_0();
  run_test_depth01_error96_cleanup_0();
}
// Test runner
[[gnu::noinline]]
void run_test_depth70_error96_cleanup_25()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 96;

  try {
    depth_70_percent_25();
  } catch (test_error_96 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth50_error96_cleanup_25()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 96;

  try {
    depth_50_percent_25();
  } catch (test_error_96 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth30_error96_cleanup_25()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 96;

  try {
    depth_30_percent_25();
  } catch (test_error_96 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth10_error96_cleanup_25()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 96;

  try {
    depth_10_percent_25();
  } catch (test_error_96 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth01_error96_cleanup_25()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 96;

  try {
    depth_01_percent_25();
  } catch (test_error_96 const& e) {
    end();
  }

  pause();
}

void run_test_error96_cleanup_25()
{
  run_test_depth70_error96_cleanup_25();
  run_test_depth50_error96_cleanup_25();
  run_test_depth30_error96_cleanup_25();
  run_test_depth10_error96_cleanup_25();
  run_test_depth01_error96_cleanup_25();
}
// Test runner
[[gnu::noinline]]
void run_test_depth70_error96_cleanup_50()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 96;

  try {
    depth_70_percent_50();
  } catch (test_error_96 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth50_error96_cleanup_50()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 96;

  try {
    depth_50_percent_50();
  } catch (test_error_96 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth30_error96_cleanup_50()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 96;

  try {
    depth_30_percent_50();
  } catch (test_error_96 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth10_error96_cleanup_50()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 96;

  try {
    depth_10_percent_50();
  } catch (test_error_96 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth01_error96_cleanup_50()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 96;

  try {
    depth_01_percent_50();
  } catch (test_error_96 const& e) {
    end();
  }

  pause();
}

void run_test_error96_cleanup_50()
{
  run_test_depth70_error96_cleanup_50();
  run_test_depth50_error96_cleanup_50();
  run_test_depth30_error96_cleanup_50();
  run_test_depth10_error96_cleanup_50();
  run_test_depth01_error96_cleanup_50();
}
// Test runner
[[gnu::noinline]]
void run_test_depth70_error96_cleanup_75()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 96;

  try {
    depth_70_percent_75();
  } catch (test_error_96 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth50_error96_cleanup_75()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 96;

  try {
    depth_50_percent_75();
  } catch (test_error_96 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth30_error96_cleanup_75()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 96;

  try {
    depth_30_percent_75();
  } catch (test_error_96 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth10_error96_cleanup_75()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 96;

  try {
    depth_10_percent_75();
  } catch (test_error_96 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth01_error96_cleanup_75()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 96;

  try {
    depth_01_percent_75();
  } catch (test_error_96 const& e) {
    end();
  }

  pause();
}

void run_test_error96_cleanup_75()
{
  run_test_depth70_error96_cleanup_75();
  run_test_depth50_error96_cleanup_75();
  run_test_depth30_error96_cleanup_75();
  run_test_depth10_error96_cleanup_75();
  run_test_depth01_error96_cleanup_75();
}
// Test runner
[[gnu::noinline]]
void run_test_depth70_error96_cleanup_100()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 96;

  try {
    depth_70_percent_100();
  } catch (test_error_96 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth50_error96_cleanup_100()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 96;

  try {
    depth_50_percent_100();
  } catch (test_error_96 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth30_error96_cleanup_100()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 96;

  try {
    depth_30_percent_100();
  } catch (test_error_96 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth10_error96_cleanup_100()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 96;

  try {
    depth_10_percent_100();
  } catch (test_error_96 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth01_error96_cleanup_100()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 96;

  try {
    depth_01_percent_100();
  } catch (test_error_96 const& e) {
    end();
  }

  pause();
}

void run_test_error96_cleanup_100()
{
  run_test_depth70_error96_cleanup_100();
  run_test_depth50_error96_cleanup_100();
  run_test_depth30_error96_cleanup_100();
  run_test_depth10_error96_cleanup_100();
  run_test_depth01_error96_cleanup_100();
}
// Test runner
void run_test()
{
  run_test_error64_cleanup_0();
  run_test_error64_cleanup_25();
  run_test_error64_cleanup_50();
  run_test_error64_cleanup_75();
  run_test_error64_cleanup_100();
  run_test_error96_cleanup_0();
  run_test_error96_cleanup_25();
  run_test_error96_cleanup_50();
  run_test_error96_cleanup_75();
  run_test_error96_cleanup_100();
}
