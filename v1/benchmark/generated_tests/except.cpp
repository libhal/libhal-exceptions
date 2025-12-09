#include <cstdint>

#include <array>
#include <string>

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

struct test_error_04
{
  std::array<std::uint8_t, 04> data;
};
struct test_error_16
{
  std::array<std::uint8_t, 16> data;
};
struct test_error_65
{
  std::array<std::uint8_t, 65> data;
};
int depth_70_percent_000();
int depth_69_percent_000();
int depth_68_percent_000();
int depth_67_percent_000();
int depth_66_percent_000();
int depth_65_percent_000();
int depth_64_percent_000();
int depth_63_percent_000();
int depth_62_percent_000();
int depth_61_percent_000();
int depth_60_percent_000();
int depth_59_percent_000();
int depth_58_percent_000();
int depth_57_percent_000();
int depth_56_percent_000();
int depth_55_percent_000();
int depth_54_percent_000();
int depth_53_percent_000();
int depth_52_percent_000();
int depth_51_percent_000();
int depth_50_percent_000();
int depth_49_percent_000();
int depth_48_percent_000();
int depth_47_percent_000();
int depth_46_percent_000();
int depth_45_percent_000();
int depth_44_percent_000();
int depth_43_percent_000();
int depth_42_percent_000();
int depth_41_percent_000();
int depth_40_percent_000();
int depth_39_percent_000();
int depth_38_percent_000();
int depth_37_percent_000();
int depth_36_percent_000();
int depth_35_percent_000();
int depth_34_percent_000();
int depth_33_percent_000();
int depth_32_percent_000();
int depth_31_percent_000();
int depth_30_percent_000();
int depth_29_percent_000();
int depth_28_percent_000();
int depth_27_percent_000();
int depth_26_percent_000();
int depth_25_percent_000();
int depth_24_percent_000();
int depth_23_percent_000();
int depth_22_percent_000();
int depth_21_percent_000();
int depth_20_percent_000();
int depth_19_percent_000();
int depth_18_percent_000();
int depth_17_percent_000();
int depth_16_percent_000();
int depth_15_percent_000();
int depth_14_percent_000();
int depth_13_percent_000();
int depth_12_percent_000();
int depth_11_percent_000();
int depth_10_percent_000();
int depth_09_percent_000();
int depth_08_percent_000();
int depth_07_percent_000();
int depth_06_percent_000();
int depth_05_percent_000();
int depth_04_percent_000();
int depth_03_percent_000();
int depth_02_percent_000();
int depth_01_percent_000();
[[gnu::noinline]]
int depth_70_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 5> preserve_frame = { 8 };

  int const result = depth_69_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_69_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 5> preserve_frame = { 8 };

  int const result = depth_68_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_68_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  int const result = depth_67_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_67_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  int const result = depth_66_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_66_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 16> preserve_frame = { 8 };

  int const result = depth_65_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 9> preserve_frame = { 8 };

  int const result = depth_64_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_64_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 2> preserve_frame = { 8 };

  int const result = depth_63_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_63_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 6> preserve_frame = { 8 };

  int const result = depth_62_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_62_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 7> preserve_frame = { 8 };

  int const result = depth_61_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_61_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 6> preserve_frame = { 8 };

  int const result = depth_60_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_60_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 10> preserve_frame = { 8 };

  int const result = depth_59_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_59_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 8> preserve_frame = { 8 };

  int const result = depth_58_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_58_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 11> preserve_frame = { 8 };

  int const result = depth_57_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_57_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 13> preserve_frame = { 8 };

  int const result = depth_56_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_56_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  int const result = depth_55_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_55_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 15> preserve_frame = { 8 };

  int const result = depth_54_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_54_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 10> preserve_frame = { 8 };

  int const result = depth_53_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_53_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 7> preserve_frame = { 8 };

  int const result = depth_52_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_52_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 11> preserve_frame = { 8 };

  int const result = depth_51_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_51_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 4> preserve_frame = { 8 };

  int const result = depth_50_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_50_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 10> preserve_frame = { 8 };

  int const result = depth_49_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_49_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 10> preserve_frame = { 8 };

  int const result = depth_48_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_48_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 4> preserve_frame = { 8 };

  int const result = depth_47_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_47_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 16> preserve_frame = { 8 };

  int const result = depth_46_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_46_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 11> preserve_frame = { 8 };

  int const result = depth_45_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_45_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  int const result = depth_44_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_44_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  int const result = depth_43_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_43_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 15> preserve_frame = { 8 };

  int const result = depth_42_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_42_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 5> preserve_frame = { 8 };

  int const result = depth_41_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_41_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 8> preserve_frame = { 8 };

  int const result = depth_40_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_40_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 8> preserve_frame = { 8 };

  int const result = depth_39_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_39_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 7> preserve_frame = { 8 };

  int const result = depth_38_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_38_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  int const result = depth_37_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_37_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 11> preserve_frame = { 8 };

  int const result = depth_36_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_36_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 8> preserve_frame = { 8 };

  int const result = depth_35_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_35_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 11> preserve_frame = { 8 };

  int const result = depth_34_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_34_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 16> preserve_frame = { 8 };

  int const result = depth_33_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_33_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 1> preserve_frame = { 8 };

  int const result = depth_32_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_32_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 13> preserve_frame = { 8 };

  int const result = depth_31_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_31_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  int const result = depth_30_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_30_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 1> preserve_frame = { 8 };

  int const result = depth_29_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_29_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 2> preserve_frame = { 8 };

  int const result = depth_28_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_28_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 9> preserve_frame = { 8 };

  int const result = depth_27_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_27_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 15> preserve_frame = { 8 };

  int const result = depth_26_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_26_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 16> preserve_frame = { 8 };

  int const result = depth_25_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_25_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 7> preserve_frame = { 8 };

  int const result = depth_24_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_24_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 11> preserve_frame = { 8 };

  int const result = depth_23_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_23_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 14> preserve_frame = { 8 };

  int const result = depth_22_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_22_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 12> preserve_frame = { 8 };

  int const result = depth_21_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_21_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 4> preserve_frame = { 8 };

  int const result = depth_20_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_20_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 16> preserve_frame = { 8 };

  int const result = depth_19_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_19_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 11> preserve_frame = { 8 };

  int const result = depth_18_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_18_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  int const result = depth_17_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_17_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 4> preserve_frame = { 8 };

  int const result = depth_16_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_16_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 10> preserve_frame = { 8 };

  int const result = depth_15_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_15_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 5> preserve_frame = { 8 };

  int const result = depth_14_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_14_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 9> preserve_frame = { 8 };

  int const result = depth_13_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_13_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 4> preserve_frame = { 8 };

  int const result = depth_12_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_12_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 5> preserve_frame = { 8 };

  int const result = depth_11_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_11_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 10> preserve_frame = { 8 };

  int const result = depth_10_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_10_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 5> preserve_frame = { 8 };

  int const result = depth_09_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_09_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 7> preserve_frame = { 8 };

  int const result = depth_08_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_08_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 12> preserve_frame = { 8 };

  int const result = depth_07_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_07_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 16> preserve_frame = { 8 };

  int const result = depth_06_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_06_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 10> preserve_frame = { 8 };

  int const result = depth_05_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_05_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 13> preserve_frame = { 8 };

  int const result = depth_04_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_04_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 16> preserve_frame = { 8 };

  int const result = depth_03_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_03_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 9> preserve_frame = { 8 };

  int const result = depth_02_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_02_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 2> preserve_frame = { 8 };

  int const result = depth_01_percent_000();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_01_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 14> preserve_frame = { 8 };

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  // This is where the exception originates

  if (error_size_select == 4) {
    start();
    throw test_error_04{ .data = { 0xDE, 0xAD, 0xBE, 0xEF } };
  }

  if (error_size_select == 16) {
    start();
    throw test_error_16{ .data = { 0xDE, 0xAD, 0xBE, 0xEF } };
  }

  if (error_size_select == 65) {
    start();
    throw test_error_65{ .data = { 0xDE, 0xAD, 0xBE, 0xEF } };
  }

  return side_effect;
}

int depth_70_percent_025();
int depth_69_percent_025();
int depth_68_percent_025();
int depth_67_percent_025();
int depth_66_percent_025();
int depth_65_percent_025();
int depth_64_percent_025();
int depth_63_percent_025();
int depth_62_percent_025();
int depth_61_percent_025();
int depth_60_percent_025();
int depth_59_percent_025();
int depth_58_percent_025();
int depth_57_percent_025();
int depth_56_percent_025();
int depth_55_percent_025();
int depth_54_percent_025();
int depth_53_percent_025();
int depth_52_percent_025();
int depth_51_percent_025();
int depth_50_percent_025();
int depth_49_percent_025();
int depth_48_percent_025();
int depth_47_percent_025();
int depth_46_percent_025();
int depth_45_percent_025();
int depth_44_percent_025();
int depth_43_percent_025();
int depth_42_percent_025();
int depth_41_percent_025();
int depth_40_percent_025();
int depth_39_percent_025();
int depth_38_percent_025();
int depth_37_percent_025();
int depth_36_percent_025();
int depth_35_percent_025();
int depth_34_percent_025();
int depth_33_percent_025();
int depth_32_percent_025();
int depth_31_percent_025();
int depth_30_percent_025();
int depth_29_percent_025();
int depth_28_percent_025();
int depth_27_percent_025();
int depth_26_percent_025();
int depth_25_percent_025();
int depth_24_percent_025();
int depth_23_percent_025();
int depth_22_percent_025();
int depth_21_percent_025();
int depth_20_percent_025();
int depth_19_percent_025();
int depth_18_percent_025();
int depth_17_percent_025();
int depth_16_percent_025();
int depth_15_percent_025();
int depth_14_percent_025();
int depth_13_percent_025();
int depth_12_percent_025();
int depth_11_percent_025();
int depth_10_percent_025();
int depth_09_percent_025();
int depth_08_percent_025();
int depth_07_percent_025();
int depth_06_percent_025();
int depth_05_percent_025();
int depth_04_percent_025();
int depth_03_percent_025();
int depth_02_percent_025();
int depth_01_percent_025();
[[gnu::noinline]]
int depth_70_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 5> preserve_frame = { 8 };

  int const result = depth_69_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_69_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 5> preserve_frame = { 8 };

  int const result = depth_68_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_68_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  int const result = depth_67_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_67_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  int const result = depth_66_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_66_percent_025()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 16> preserve_frame = { 8 };

  int const result = depth_65_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_65_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 9> preserve_frame = { 8 };

  int const result = depth_64_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_64_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 2> preserve_frame = { 8 };

  int const result = depth_63_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_63_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 6> preserve_frame = { 8 };

  int const result = depth_62_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_62_percent_025()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 7> preserve_frame = { 8 };

  int const result = depth_61_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_61_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 6> preserve_frame = { 8 };

  int const result = depth_60_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_60_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 10> preserve_frame = { 8 };

  int const result = depth_59_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_59_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 8> preserve_frame = { 8 };

  int const result = depth_58_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_58_percent_025()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 11> preserve_frame = { 8 };

  int const result = depth_57_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_57_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 13> preserve_frame = { 8 };

  int const result = depth_56_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_56_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  int const result = depth_55_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_55_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 15> preserve_frame = { 8 };

  int const result = depth_54_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_54_percent_025()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 10> preserve_frame = { 8 };

  int const result = depth_53_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_53_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 7> preserve_frame = { 8 };

  int const result = depth_52_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_52_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 11> preserve_frame = { 8 };

  int const result = depth_51_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_51_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 4> preserve_frame = { 8 };

  int const result = depth_50_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_50_percent_025()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 10> preserve_frame = { 8 };

  int const result = depth_49_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_49_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 10> preserve_frame = { 8 };

  int const result = depth_48_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_48_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 4> preserve_frame = { 8 };

  int const result = depth_47_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_47_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 16> preserve_frame = { 8 };

  int const result = depth_46_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_46_percent_025()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 11> preserve_frame = { 8 };

  int const result = depth_45_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_45_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  int const result = depth_44_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_44_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  int const result = depth_43_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_43_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 15> preserve_frame = { 8 };

  int const result = depth_42_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_42_percent_025()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 5> preserve_frame = { 8 };

  int const result = depth_41_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_41_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 8> preserve_frame = { 8 };

  int const result = depth_40_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_40_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 8> preserve_frame = { 8 };

  int const result = depth_39_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_39_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 7> preserve_frame = { 8 };

  int const result = depth_38_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_38_percent_025()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  int const result = depth_37_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_37_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 11> preserve_frame = { 8 };

  int const result = depth_36_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_36_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 8> preserve_frame = { 8 };

  int const result = depth_35_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_35_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 11> preserve_frame = { 8 };

  int const result = depth_34_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_34_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 16> preserve_frame = { 8 };

  int const result = depth_33_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_33_percent_025()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 1> preserve_frame = { 8 };

  int const result = depth_32_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_32_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 13> preserve_frame = { 8 };

  int const result = depth_31_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_31_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  int const result = depth_30_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_30_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 1> preserve_frame = { 8 };

  int const result = depth_29_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_29_percent_025()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 2> preserve_frame = { 8 };

  int const result = depth_28_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_28_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 9> preserve_frame = { 8 };

  int const result = depth_27_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_27_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 15> preserve_frame = { 8 };

  int const result = depth_26_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_26_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 16> preserve_frame = { 8 };

  int const result = depth_25_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_25_percent_025()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 7> preserve_frame = { 8 };

  int const result = depth_24_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_24_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 11> preserve_frame = { 8 };

  int const result = depth_23_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_23_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 14> preserve_frame = { 8 };

  int const result = depth_22_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_22_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 12> preserve_frame = { 8 };

  int const result = depth_21_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_21_percent_025()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 4> preserve_frame = { 8 };

  int const result = depth_20_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_20_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 16> preserve_frame = { 8 };

  int const result = depth_19_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_19_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 11> preserve_frame = { 8 };

  int const result = depth_18_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_18_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  int const result = depth_17_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_17_percent_025()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 4> preserve_frame = { 8 };

  int const result = depth_16_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_16_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 10> preserve_frame = { 8 };

  int const result = depth_15_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_15_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 5> preserve_frame = { 8 };

  int const result = depth_14_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_14_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 9> preserve_frame = { 8 };

  int const result = depth_13_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_13_percent_025()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 4> preserve_frame = { 8 };

  int const result = depth_12_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_12_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 5> preserve_frame = { 8 };

  int const result = depth_11_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_11_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 10> preserve_frame = { 8 };

  int const result = depth_10_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_10_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 5> preserve_frame = { 8 };

  int const result = depth_09_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_09_percent_025()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 7> preserve_frame = { 8 };

  int const result = depth_08_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_08_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 12> preserve_frame = { 8 };

  int const result = depth_07_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_07_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 16> preserve_frame = { 8 };

  int const result = depth_06_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_06_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 10> preserve_frame = { 8 };

  int const result = depth_05_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_05_percent_025()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 13> preserve_frame = { 8 };

  int const result = depth_04_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_04_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 16> preserve_frame = { 8 };

  int const result = depth_03_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_03_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 9> preserve_frame = { 8 };

  int const result = depth_02_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_02_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 2> preserve_frame = { 8 };

  int const result = depth_01_percent_025();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_01_percent_025()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 14> preserve_frame = { 8 };

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  // This is where the exception originates

  if (error_size_select == 4) {
    start();
    throw test_error_04{ .data = { 0xDE, 0xAD, 0xBE, 0xEF } };
  }

  if (error_size_select == 16) {
    start();
    throw test_error_16{ .data = { 0xDE, 0xAD, 0xBE, 0xEF } };
  }

  if (error_size_select == 65) {
    start();
    throw test_error_65{ .data = { 0xDE, 0xAD, 0xBE, 0xEF } };
  }

  return side_effect;
}

int depth_70_percent_050();
int depth_69_percent_050();
int depth_68_percent_050();
int depth_67_percent_050();
int depth_66_percent_050();
int depth_65_percent_050();
int depth_64_percent_050();
int depth_63_percent_050();
int depth_62_percent_050();
int depth_61_percent_050();
int depth_60_percent_050();
int depth_59_percent_050();
int depth_58_percent_050();
int depth_57_percent_050();
int depth_56_percent_050();
int depth_55_percent_050();
int depth_54_percent_050();
int depth_53_percent_050();
int depth_52_percent_050();
int depth_51_percent_050();
int depth_50_percent_050();
int depth_49_percent_050();
int depth_48_percent_050();
int depth_47_percent_050();
int depth_46_percent_050();
int depth_45_percent_050();
int depth_44_percent_050();
int depth_43_percent_050();
int depth_42_percent_050();
int depth_41_percent_050();
int depth_40_percent_050();
int depth_39_percent_050();
int depth_38_percent_050();
int depth_37_percent_050();
int depth_36_percent_050();
int depth_35_percent_050();
int depth_34_percent_050();
int depth_33_percent_050();
int depth_32_percent_050();
int depth_31_percent_050();
int depth_30_percent_050();
int depth_29_percent_050();
int depth_28_percent_050();
int depth_27_percent_050();
int depth_26_percent_050();
int depth_25_percent_050();
int depth_24_percent_050();
int depth_23_percent_050();
int depth_22_percent_050();
int depth_21_percent_050();
int depth_20_percent_050();
int depth_19_percent_050();
int depth_18_percent_050();
int depth_17_percent_050();
int depth_16_percent_050();
int depth_15_percent_050();
int depth_14_percent_050();
int depth_13_percent_050();
int depth_12_percent_050();
int depth_11_percent_050();
int depth_10_percent_050();
int depth_09_percent_050();
int depth_08_percent_050();
int depth_07_percent_050();
int depth_06_percent_050();
int depth_05_percent_050();
int depth_04_percent_050();
int depth_03_percent_050();
int depth_02_percent_050();
int depth_01_percent_050();
[[gnu::noinline]]
int depth_70_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 5> preserve_frame = { 8 };

  int const result = depth_69_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_69_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 5> preserve_frame = { 8 };

  int const result = depth_68_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_68_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  int const result = depth_67_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_67_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  int const result = depth_66_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_66_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 16> preserve_frame = { 8 };

  int const result = depth_65_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_65_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 9> preserve_frame = { 8 };

  int const result = depth_64_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_64_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 2> preserve_frame = { 8 };

  int const result = depth_63_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_63_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 6> preserve_frame = { 8 };

  int const result = depth_62_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_62_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 7> preserve_frame = { 8 };

  int const result = depth_61_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_61_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 6> preserve_frame = { 8 };

  int const result = depth_60_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_60_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 10> preserve_frame = { 8 };

  int const result = depth_59_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_59_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 8> preserve_frame = { 8 };

  int const result = depth_58_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_58_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 11> preserve_frame = { 8 };

  int const result = depth_57_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_57_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 13> preserve_frame = { 8 };

  int const result = depth_56_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_56_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  int const result = depth_55_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_55_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 15> preserve_frame = { 8 };

  int const result = depth_54_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_54_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 10> preserve_frame = { 8 };

  int const result = depth_53_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_53_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 7> preserve_frame = { 8 };

  int const result = depth_52_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_52_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 11> preserve_frame = { 8 };

  int const result = depth_51_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_51_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 4> preserve_frame = { 8 };

  int const result = depth_50_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_50_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 10> preserve_frame = { 8 };

  int const result = depth_49_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_49_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 10> preserve_frame = { 8 };

  int const result = depth_48_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_48_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 4> preserve_frame = { 8 };

  int const result = depth_47_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_47_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 16> preserve_frame = { 8 };

  int const result = depth_46_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_46_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 11> preserve_frame = { 8 };

  int const result = depth_45_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_45_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  int const result = depth_44_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_44_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  int const result = depth_43_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_43_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 15> preserve_frame = { 8 };

  int const result = depth_42_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_42_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 5> preserve_frame = { 8 };

  int const result = depth_41_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_41_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 8> preserve_frame = { 8 };

  int const result = depth_40_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_40_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 8> preserve_frame = { 8 };

  int const result = depth_39_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_39_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 7> preserve_frame = { 8 };

  int const result = depth_38_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_38_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  int const result = depth_37_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_37_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 11> preserve_frame = { 8 };

  int const result = depth_36_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_36_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 8> preserve_frame = { 8 };

  int const result = depth_35_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_35_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 11> preserve_frame = { 8 };

  int const result = depth_34_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_34_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 16> preserve_frame = { 8 };

  int const result = depth_33_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_33_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 1> preserve_frame = { 8 };

  int const result = depth_32_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_32_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 13> preserve_frame = { 8 };

  int const result = depth_31_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_31_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  int const result = depth_30_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_30_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 1> preserve_frame = { 8 };

  int const result = depth_29_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_29_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 2> preserve_frame = { 8 };

  int const result = depth_28_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_28_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 9> preserve_frame = { 8 };

  int const result = depth_27_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_27_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 15> preserve_frame = { 8 };

  int const result = depth_26_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_26_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 16> preserve_frame = { 8 };

  int const result = depth_25_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_25_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 7> preserve_frame = { 8 };

  int const result = depth_24_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_24_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 11> preserve_frame = { 8 };

  int const result = depth_23_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_23_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 14> preserve_frame = { 8 };

  int const result = depth_22_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_22_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 12> preserve_frame = { 8 };

  int const result = depth_21_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_21_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 4> preserve_frame = { 8 };

  int const result = depth_20_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_20_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 16> preserve_frame = { 8 };

  int const result = depth_19_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_19_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 11> preserve_frame = { 8 };

  int const result = depth_18_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_18_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  int const result = depth_17_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_17_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 4> preserve_frame = { 8 };

  int const result = depth_16_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_16_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 10> preserve_frame = { 8 };

  int const result = depth_15_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_15_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 5> preserve_frame = { 8 };

  int const result = depth_14_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_14_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 9> preserve_frame = { 8 };

  int const result = depth_13_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_13_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 4> preserve_frame = { 8 };

  int const result = depth_12_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_12_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 5> preserve_frame = { 8 };

  int const result = depth_11_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_11_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 10> preserve_frame = { 8 };

  int const result = depth_10_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_10_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 5> preserve_frame = { 8 };

  int const result = depth_09_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_09_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 7> preserve_frame = { 8 };

  int const result = depth_08_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_08_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 12> preserve_frame = { 8 };

  int const result = depth_07_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_07_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 16> preserve_frame = { 8 };

  int const result = depth_06_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_06_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 10> preserve_frame = { 8 };

  int const result = depth_05_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_05_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 13> preserve_frame = { 8 };

  int const result = depth_04_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_04_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 16> preserve_frame = { 8 };

  int const result = depth_03_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_03_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 9> preserve_frame = { 8 };

  int const result = depth_02_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_02_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 2> preserve_frame = { 8 };

  int const result = depth_01_percent_050();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_01_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 14> preserve_frame = { 8 };

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  // This is where the exception originates

  if (error_size_select == 4) {
    start();
    throw test_error_04{ .data = { 0xDE, 0xAD, 0xBE, 0xEF } };
  }

  if (error_size_select == 16) {
    start();
    throw test_error_16{ .data = { 0xDE, 0xAD, 0xBE, 0xEF } };
  }

  if (error_size_select == 65) {
    start();
    throw test_error_65{ .data = { 0xDE, 0xAD, 0xBE, 0xEF } };
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

  std::array<std::int8_t volatile, 5> preserve_frame = { 8 };

  int const result = depth_69_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_69_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 5> preserve_frame = { 8 };

  int const result = depth_68_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_68_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  int const result = depth_67_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_67_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  int const result = depth_66_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_66_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 16> preserve_frame = { 8 };

  int const result = depth_65_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 9> preserve_frame = { 8 };

  int const result = depth_64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_64_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 2> preserve_frame = { 8 };

  int const result = depth_63_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_63_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 6> preserve_frame = { 8 };

  int const result = depth_62_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_62_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 7> preserve_frame = { 8 };

  int const result = depth_61_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_61_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 6> preserve_frame = { 8 };

  int const result = depth_60_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_60_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 10> preserve_frame = { 8 };

  int const result = depth_59_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_59_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 8> preserve_frame = { 8 };

  int const result = depth_58_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_58_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 11> preserve_frame = { 8 };

  int const result = depth_57_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_57_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 13> preserve_frame = { 8 };

  int const result = depth_56_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_56_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  int const result = depth_55_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_55_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 15> preserve_frame = { 8 };

  int const result = depth_54_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_54_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 10> preserve_frame = { 8 };

  int const result = depth_53_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_53_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 7> preserve_frame = { 8 };

  int const result = depth_52_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_52_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 11> preserve_frame = { 8 };

  int const result = depth_51_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_51_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 4> preserve_frame = { 8 };

  int const result = depth_50_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_50_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 10> preserve_frame = { 8 };

  int const result = depth_49_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_49_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 10> preserve_frame = { 8 };

  int const result = depth_48_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_48_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 4> preserve_frame = { 8 };

  int const result = depth_47_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_47_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 16> preserve_frame = { 8 };

  int const result = depth_46_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_46_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 11> preserve_frame = { 8 };

  int const result = depth_45_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_45_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  int const result = depth_44_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_44_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  int const result = depth_43_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_43_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 15> preserve_frame = { 8 };

  int const result = depth_42_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_42_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 5> preserve_frame = { 8 };

  int const result = depth_41_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_41_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 8> preserve_frame = { 8 };

  int const result = depth_40_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_40_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 8> preserve_frame = { 8 };

  int const result = depth_39_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_39_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 7> preserve_frame = { 8 };

  int const result = depth_38_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_38_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  int const result = depth_37_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_37_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 11> preserve_frame = { 8 };

  int const result = depth_36_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_36_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 8> preserve_frame = { 8 };

  int const result = depth_35_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_35_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 11> preserve_frame = { 8 };

  int const result = depth_34_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_34_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 16> preserve_frame = { 8 };

  int const result = depth_33_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_33_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 1> preserve_frame = { 8 };

  int const result = depth_32_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_32_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 13> preserve_frame = { 8 };

  int const result = depth_31_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_31_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  int const result = depth_30_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_30_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 1> preserve_frame = { 8 };

  int const result = depth_29_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_29_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 2> preserve_frame = { 8 };

  int const result = depth_28_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_28_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 9> preserve_frame = { 8 };

  int const result = depth_27_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_27_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 15> preserve_frame = { 8 };

  int const result = depth_26_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_26_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 16> preserve_frame = { 8 };

  int const result = depth_25_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_25_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 7> preserve_frame = { 8 };

  int const result = depth_24_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_24_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 11> preserve_frame = { 8 };

  int const result = depth_23_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_23_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 14> preserve_frame = { 8 };

  int const result = depth_22_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_22_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 12> preserve_frame = { 8 };

  int const result = depth_21_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_21_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 4> preserve_frame = { 8 };

  int const result = depth_20_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_20_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 16> preserve_frame = { 8 };

  int const result = depth_19_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_19_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 11> preserve_frame = { 8 };

  int const result = depth_18_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_18_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  int const result = depth_17_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_17_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 4> preserve_frame = { 8 };

  int const result = depth_16_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_16_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 10> preserve_frame = { 8 };

  int const result = depth_15_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_15_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 5> preserve_frame = { 8 };

  int const result = depth_14_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_14_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 9> preserve_frame = { 8 };

  int const result = depth_13_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_13_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 4> preserve_frame = { 8 };

  int const result = depth_12_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_12_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 5> preserve_frame = { 8 };

  int const result = depth_11_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_11_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 10> preserve_frame = { 8 };

  int const result = depth_10_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_10_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 5> preserve_frame = { 8 };

  int const result = depth_09_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_09_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 7> preserve_frame = { 8 };

  int const result = depth_08_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_08_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 12> preserve_frame = { 8 };

  int const result = depth_07_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_07_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 16> preserve_frame = { 8 };

  int const result = depth_06_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_06_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 10> preserve_frame = { 8 };

  int const result = depth_05_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_05_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 13> preserve_frame = { 8 };

  int const result = depth_04_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_04_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 16> preserve_frame = { 8 };

  int const result = depth_03_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_03_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 9> preserve_frame = { 8 };

  int const result = depth_02_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_02_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 2> preserve_frame = { 8 };

  int const result = depth_01_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_01_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 14> preserve_frame = { 8 };

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  // This is where the exception originates

  if (error_size_select == 4) {
    start();
    throw test_error_04{ .data = { 0xDE, 0xAD, 0xBE, 0xEF } };
  }

  if (error_size_select == 16) {
    start();
    throw test_error_16{ .data = { 0xDE, 0xAD, 0xBE, 0xEF } };
  }

  if (error_size_select == 65) {
    start();
    throw test_error_65{ .data = { 0xDE, 0xAD, 0xBE, 0xEF } };
  }

  return side_effect;
}

// Test runner
[[gnu::noinline]]
void run_test_depth_50_error_04_cleanup_000()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 4;

  try {
    depth_50_percent_000();
  } catch (test_error_04 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth_35_error_04_cleanup_000()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 4;

  try {
    depth_35_percent_000();
  } catch (test_error_04 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth_15_error_04_cleanup_000()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 4;

  try {
    depth_15_percent_000();
  } catch (test_error_04 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth_05_error_04_cleanup_000()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 4;

  try {
    depth_05_percent_000();
  } catch (test_error_04 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth_01_error_04_cleanup_000()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 4;

  try {
    depth_01_percent_000();
  } catch (test_error_04 const& e) {
    end();
  }

  pause();
}

void run_test_error_04_cleanup_000()
{
  run_test_depth_50_error_04_cleanup_000();
  run_test_depth_35_error_04_cleanup_000();
  run_test_depth_15_error_04_cleanup_000();
  run_test_depth_05_error_04_cleanup_000();
  run_test_depth_01_error_04_cleanup_000();
}
// Test runner
[[gnu::noinline]]
void run_test_depth_50_error_04_cleanup_025()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 4;

  try {
    depth_50_percent_025();
  } catch (test_error_04 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth_35_error_04_cleanup_025()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 4;

  try {
    depth_35_percent_025();
  } catch (test_error_04 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth_15_error_04_cleanup_025()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 4;

  try {
    depth_15_percent_025();
  } catch (test_error_04 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth_05_error_04_cleanup_025()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 4;

  try {
    depth_05_percent_025();
  } catch (test_error_04 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth_01_error_04_cleanup_025()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 4;

  try {
    depth_01_percent_025();
  } catch (test_error_04 const& e) {
    end();
  }

  pause();
}

void run_test_error_04_cleanup_025()
{
  run_test_depth_50_error_04_cleanup_025();
  run_test_depth_35_error_04_cleanup_025();
  run_test_depth_15_error_04_cleanup_025();
  run_test_depth_05_error_04_cleanup_025();
  run_test_depth_01_error_04_cleanup_025();
}
// Test runner
[[gnu::noinline]]
void run_test_depth_50_error_04_cleanup_050()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 4;

  try {
    depth_50_percent_050();
  } catch (test_error_04 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth_35_error_04_cleanup_050()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 4;

  try {
    depth_35_percent_050();
  } catch (test_error_04 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth_15_error_04_cleanup_050()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 4;

  try {
    depth_15_percent_050();
  } catch (test_error_04 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth_05_error_04_cleanup_050()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 4;

  try {
    depth_05_percent_050();
  } catch (test_error_04 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth_01_error_04_cleanup_050()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 4;

  try {
    depth_01_percent_050();
  } catch (test_error_04 const& e) {
    end();
  }

  pause();
}

void run_test_error_04_cleanup_050()
{
  run_test_depth_50_error_04_cleanup_050();
  run_test_depth_35_error_04_cleanup_050();
  run_test_depth_15_error_04_cleanup_050();
  run_test_depth_05_error_04_cleanup_050();
  run_test_depth_01_error_04_cleanup_050();
}
// Test runner
[[gnu::noinline]]
void run_test_depth_50_error_04_cleanup_100()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 4;

  try {
    depth_50_percent_100();
  } catch (test_error_04 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth_35_error_04_cleanup_100()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 4;

  try {
    depth_35_percent_100();
  } catch (test_error_04 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth_15_error_04_cleanup_100()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 4;

  try {
    depth_15_percent_100();
  } catch (test_error_04 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth_05_error_04_cleanup_100()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 4;

  try {
    depth_05_percent_100();
  } catch (test_error_04 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth_01_error_04_cleanup_100()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 4;

  try {
    depth_01_percent_100();
  } catch (test_error_04 const& e) {
    end();
  }

  pause();
}

void run_test_error_04_cleanup_100()
{
  run_test_depth_50_error_04_cleanup_100();
  run_test_depth_35_error_04_cleanup_100();
  run_test_depth_15_error_04_cleanup_100();
  run_test_depth_05_error_04_cleanup_100();
  run_test_depth_01_error_04_cleanup_100();
}
// Test runner
[[gnu::noinline]]
void run_test_depth_50_error_16_cleanup_000()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 16;

  try {
    depth_50_percent_000();
  } catch (test_error_16 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth_35_error_16_cleanup_000()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 16;

  try {
    depth_35_percent_000();
  } catch (test_error_16 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth_15_error_16_cleanup_000()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 16;

  try {
    depth_15_percent_000();
  } catch (test_error_16 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth_05_error_16_cleanup_000()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 16;

  try {
    depth_05_percent_000();
  } catch (test_error_16 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth_01_error_16_cleanup_000()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 16;

  try {
    depth_01_percent_000();
  } catch (test_error_16 const& e) {
    end();
  }

  pause();
}

void run_test_error_16_cleanup_000()
{
  run_test_depth_50_error_16_cleanup_000();
  run_test_depth_35_error_16_cleanup_000();
  run_test_depth_15_error_16_cleanup_000();
  run_test_depth_05_error_16_cleanup_000();
  run_test_depth_01_error_16_cleanup_000();
}
// Test runner
[[gnu::noinline]]
void run_test_depth_50_error_16_cleanup_025()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 16;

  try {
    depth_50_percent_025();
  } catch (test_error_16 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth_35_error_16_cleanup_025()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 16;

  try {
    depth_35_percent_025();
  } catch (test_error_16 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth_15_error_16_cleanup_025()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 16;

  try {
    depth_15_percent_025();
  } catch (test_error_16 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth_05_error_16_cleanup_025()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 16;

  try {
    depth_05_percent_025();
  } catch (test_error_16 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth_01_error_16_cleanup_025()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 16;

  try {
    depth_01_percent_025();
  } catch (test_error_16 const& e) {
    end();
  }

  pause();
}

void run_test_error_16_cleanup_025()
{
  run_test_depth_50_error_16_cleanup_025();
  run_test_depth_35_error_16_cleanup_025();
  run_test_depth_15_error_16_cleanup_025();
  run_test_depth_05_error_16_cleanup_025();
  run_test_depth_01_error_16_cleanup_025();
}
// Test runner
[[gnu::noinline]]
void run_test_depth_50_error_16_cleanup_050()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 16;

  try {
    depth_50_percent_050();
  } catch (test_error_16 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth_35_error_16_cleanup_050()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 16;

  try {
    depth_35_percent_050();
  } catch (test_error_16 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth_15_error_16_cleanup_050()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 16;

  try {
    depth_15_percent_050();
  } catch (test_error_16 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth_05_error_16_cleanup_050()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 16;

  try {
    depth_05_percent_050();
  } catch (test_error_16 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth_01_error_16_cleanup_050()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 16;

  try {
    depth_01_percent_050();
  } catch (test_error_16 const& e) {
    end();
  }

  pause();
}

void run_test_error_16_cleanup_050()
{
  run_test_depth_50_error_16_cleanup_050();
  run_test_depth_35_error_16_cleanup_050();
  run_test_depth_15_error_16_cleanup_050();
  run_test_depth_05_error_16_cleanup_050();
  run_test_depth_01_error_16_cleanup_050();
}
// Test runner
[[gnu::noinline]]
void run_test_depth_50_error_16_cleanup_100()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 16;

  try {
    depth_50_percent_100();
  } catch (test_error_16 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth_35_error_16_cleanup_100()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 16;

  try {
    depth_35_percent_100();
  } catch (test_error_16 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth_15_error_16_cleanup_100()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 16;

  try {
    depth_15_percent_100();
  } catch (test_error_16 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth_05_error_16_cleanup_100()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 16;

  try {
    depth_05_percent_100();
  } catch (test_error_16 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth_01_error_16_cleanup_100()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 16;

  try {
    depth_01_percent_100();
  } catch (test_error_16 const& e) {
    end();
  }

  pause();
}

void run_test_error_16_cleanup_100()
{
  run_test_depth_50_error_16_cleanup_100();
  run_test_depth_35_error_16_cleanup_100();
  run_test_depth_15_error_16_cleanup_100();
  run_test_depth_05_error_16_cleanup_100();
  run_test_depth_01_error_16_cleanup_100();
}
// Test runner
[[gnu::noinline]]
void run_test_depth_50_error_65_cleanup_000()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 65;

  try {
    depth_50_percent_000();
  } catch (test_error_65 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth_35_error_65_cleanup_000()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 65;

  try {
    depth_35_percent_000();
  } catch (test_error_65 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth_15_error_65_cleanup_000()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 65;

  try {
    depth_15_percent_000();
  } catch (test_error_65 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth_05_error_65_cleanup_000()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 65;

  try {
    depth_05_percent_000();
  } catch (test_error_65 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth_01_error_65_cleanup_000()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 65;

  try {
    depth_01_percent_000();
  } catch (test_error_65 const& e) {
    end();
  }

  pause();
}

void run_test_error_65_cleanup_000()
{
  run_test_depth_50_error_65_cleanup_000();
  run_test_depth_35_error_65_cleanup_000();
  run_test_depth_15_error_65_cleanup_000();
  run_test_depth_05_error_65_cleanup_000();
  run_test_depth_01_error_65_cleanup_000();
}
// Test runner
[[gnu::noinline]]
void run_test_depth_50_error_65_cleanup_025()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 65;

  try {
    depth_50_percent_025();
  } catch (test_error_65 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth_35_error_65_cleanup_025()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 65;

  try {
    depth_35_percent_025();
  } catch (test_error_65 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth_15_error_65_cleanup_025()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 65;

  try {
    depth_15_percent_025();
  } catch (test_error_65 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth_05_error_65_cleanup_025()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 65;

  try {
    depth_05_percent_025();
  } catch (test_error_65 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth_01_error_65_cleanup_025()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 65;

  try {
    depth_01_percent_025();
  } catch (test_error_65 const& e) {
    end();
  }

  pause();
}

void run_test_error_65_cleanup_025()
{
  run_test_depth_50_error_65_cleanup_025();
  run_test_depth_35_error_65_cleanup_025();
  run_test_depth_15_error_65_cleanup_025();
  run_test_depth_05_error_65_cleanup_025();
  run_test_depth_01_error_65_cleanup_025();
}
// Test runner
[[gnu::noinline]]
void run_test_depth_50_error_65_cleanup_050()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 65;

  try {
    depth_50_percent_050();
  } catch (test_error_65 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth_35_error_65_cleanup_050()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 65;

  try {
    depth_35_percent_050();
  } catch (test_error_65 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth_15_error_65_cleanup_050()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 65;

  try {
    depth_15_percent_050();
  } catch (test_error_65 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth_05_error_65_cleanup_050()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 65;

  try {
    depth_05_percent_050();
  } catch (test_error_65 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth_01_error_65_cleanup_050()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 65;

  try {
    depth_01_percent_050();
  } catch (test_error_65 const& e) {
    end();
  }

  pause();
}

void run_test_error_65_cleanup_050()
{
  run_test_depth_50_error_65_cleanup_050();
  run_test_depth_35_error_65_cleanup_050();
  run_test_depth_15_error_65_cleanup_050();
  run_test_depth_05_error_65_cleanup_050();
  run_test_depth_01_error_65_cleanup_050();
}
// Test runner
[[gnu::noinline]]
void run_test_depth_50_error_65_cleanup_100()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 65;

  try {
    depth_50_percent_100();
  } catch (test_error_65 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth_35_error_65_cleanup_100()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 65;

  try {
    depth_35_percent_100();
  } catch (test_error_65 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth_15_error_65_cleanup_100()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 65;

  try {
    depth_15_percent_100();
  } catch (test_error_65 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth_05_error_65_cleanup_100()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 65;

  try {
    depth_05_percent_100();
  } catch (test_error_65 const& e) {
    end();
  }

  pause();
}

[[gnu::noinline]]
void run_test_depth_01_error_65_cleanup_100()
{
  side_effect = 1;  // Ensure we will throw
  error_size_select = 65;

  try {
    depth_01_percent_100();
  } catch (test_error_65 const& e) {
    end();
  }

  pause();
}

void run_test_error_65_cleanup_100()
{
  run_test_depth_50_error_65_cleanup_100();
  run_test_depth_35_error_65_cleanup_100();
  run_test_depth_15_error_65_cleanup_100();
  run_test_depth_05_error_65_cleanup_100();
  run_test_depth_01_error_65_cleanup_100();
}

// Test runner
void run_test()
{
  run_test_error_04_cleanup_000();
  run_test_error_04_cleanup_025();
  run_test_error_04_cleanup_050();
  run_test_error_04_cleanup_100();
  run_test_error_16_cleanup_000();
  run_test_error_16_cleanup_025();
  run_test_error_16_cleanup_050();
  run_test_error_16_cleanup_100();
  run_test_error_65_cleanup_000();
  run_test_error_65_cleanup_025();
  run_test_error_65_cleanup_050();
  run_test_error_65_cleanup_100();
}
