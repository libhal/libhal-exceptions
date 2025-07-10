#include <array>
#include <cstdint>
#include <expected>
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

struct test_error_65
{
  std::array<std::uint8_t, 65> data;
};
std::expected<int, test_error_65> depth_70_error_65_percent_000();
std::expected<int, test_error_65> depth_69_error_65_percent_000();
std::expected<int, test_error_65> depth_68_error_65_percent_000();
std::expected<int, test_error_65> depth_67_error_65_percent_000();
std::expected<int, test_error_65> depth_66_error_65_percent_000();
std::expected<int, test_error_65> depth_65_error_65_percent_000();
std::expected<int, test_error_65> depth_64_error_65_percent_000();
std::expected<int, test_error_65> depth_63_error_65_percent_000();
std::expected<int, test_error_65> depth_62_error_65_percent_000();
std::expected<int, test_error_65> depth_61_error_65_percent_000();
std::expected<int, test_error_65> depth_60_error_65_percent_000();
std::expected<int, test_error_65> depth_59_error_65_percent_000();
std::expected<int, test_error_65> depth_58_error_65_percent_000();
std::expected<int, test_error_65> depth_57_error_65_percent_000();
std::expected<int, test_error_65> depth_56_error_65_percent_000();
std::expected<int, test_error_65> depth_55_error_65_percent_000();
std::expected<int, test_error_65> depth_54_error_65_percent_000();
std::expected<int, test_error_65> depth_53_error_65_percent_000();
std::expected<int, test_error_65> depth_52_error_65_percent_000();
std::expected<int, test_error_65> depth_51_error_65_percent_000();
std::expected<int, test_error_65> depth_50_error_65_percent_000();
std::expected<int, test_error_65> depth_49_error_65_percent_000();
std::expected<int, test_error_65> depth_48_error_65_percent_000();
std::expected<int, test_error_65> depth_47_error_65_percent_000();
std::expected<int, test_error_65> depth_46_error_65_percent_000();
std::expected<int, test_error_65> depth_45_error_65_percent_000();
std::expected<int, test_error_65> depth_44_error_65_percent_000();
std::expected<int, test_error_65> depth_43_error_65_percent_000();
std::expected<int, test_error_65> depth_42_error_65_percent_000();
std::expected<int, test_error_65> depth_41_error_65_percent_000();
std::expected<int, test_error_65> depth_40_error_65_percent_000();
std::expected<int, test_error_65> depth_39_error_65_percent_000();
std::expected<int, test_error_65> depth_38_error_65_percent_000();
std::expected<int, test_error_65> depth_37_error_65_percent_000();
std::expected<int, test_error_65> depth_36_error_65_percent_000();
std::expected<int, test_error_65> depth_35_error_65_percent_000();
std::expected<int, test_error_65> depth_34_error_65_percent_000();
std::expected<int, test_error_65> depth_33_error_65_percent_000();
std::expected<int, test_error_65> depth_32_error_65_percent_000();
std::expected<int, test_error_65> depth_31_error_65_percent_000();
std::expected<int, test_error_65> depth_30_error_65_percent_000();
std::expected<int, test_error_65> depth_29_error_65_percent_000();
std::expected<int, test_error_65> depth_28_error_65_percent_000();
std::expected<int, test_error_65> depth_27_error_65_percent_000();
std::expected<int, test_error_65> depth_26_error_65_percent_000();
std::expected<int, test_error_65> depth_25_error_65_percent_000();
std::expected<int, test_error_65> depth_24_error_65_percent_000();
std::expected<int, test_error_65> depth_23_error_65_percent_000();
std::expected<int, test_error_65> depth_22_error_65_percent_000();
std::expected<int, test_error_65> depth_21_error_65_percent_000();
std::expected<int, test_error_65> depth_20_error_65_percent_000();
std::expected<int, test_error_65> depth_19_error_65_percent_000();
std::expected<int, test_error_65> depth_18_error_65_percent_000();
std::expected<int, test_error_65> depth_17_error_65_percent_000();
std::expected<int, test_error_65> depth_16_error_65_percent_000();
std::expected<int, test_error_65> depth_15_error_65_percent_000();
std::expected<int, test_error_65> depth_14_error_65_percent_000();
std::expected<int, test_error_65> depth_13_error_65_percent_000();
std::expected<int, test_error_65> depth_12_error_65_percent_000();
std::expected<int, test_error_65> depth_11_error_65_percent_000();
std::expected<int, test_error_65> depth_10_error_65_percent_000();
std::expected<int, test_error_65> depth_09_error_65_percent_000();
std::expected<int, test_error_65> depth_08_error_65_percent_000();
std::expected<int, test_error_65> depth_07_error_65_percent_000();
std::expected<int, test_error_65> depth_06_error_65_percent_000();
std::expected<int, test_error_65> depth_05_error_65_percent_000();
std::expected<int, test_error_65> depth_04_error_65_percent_000();
std::expected<int, test_error_65> depth_03_error_65_percent_000();
std::expected<int, test_error_65> depth_02_error_65_percent_000();
std::expected<int, test_error_65> depth_01_error_65_percent_000();
[[gnu::noinline]]
std::expected<int, test_error_65> depth_70_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 5> preserve_frame = { 8 };

  auto const result = depth_69_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_69_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 5> preserve_frame = { 8 };

  auto const result = depth_68_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_68_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  auto const result = depth_67_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_67_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  auto const result = depth_66_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_66_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 16> preserve_frame = { 8 };

  auto const result = depth_65_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_65_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 9> preserve_frame = { 8 };

  auto const result = depth_64_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_64_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 2> preserve_frame = { 8 };

  auto const result = depth_63_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_63_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 6> preserve_frame = { 8 };

  auto const result = depth_62_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_62_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 7> preserve_frame = { 8 };

  auto const result = depth_61_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_61_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 6> preserve_frame = { 8 };

  auto const result = depth_60_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_60_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 10> preserve_frame = { 8 };

  auto const result = depth_59_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_59_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 8> preserve_frame = { 8 };

  auto const result = depth_58_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_58_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 11> preserve_frame = { 8 };

  auto const result = depth_57_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_57_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 13> preserve_frame = { 8 };

  auto const result = depth_56_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_56_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  auto const result = depth_55_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_55_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 15> preserve_frame = { 8 };

  auto const result = depth_54_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_54_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 10> preserve_frame = { 8 };

  auto const result = depth_53_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_53_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 7> preserve_frame = { 8 };

  auto const result = depth_52_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_52_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 11> preserve_frame = { 8 };

  auto const result = depth_51_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_51_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 4> preserve_frame = { 8 };

  auto const result = depth_50_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_50_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 10> preserve_frame = { 8 };

  auto const result = depth_49_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_49_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 10> preserve_frame = { 8 };

  auto const result = depth_48_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_48_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 4> preserve_frame = { 8 };

  auto const result = depth_47_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_47_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 16> preserve_frame = { 8 };

  auto const result = depth_46_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_46_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 11> preserve_frame = { 8 };

  auto const result = depth_45_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_45_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  auto const result = depth_44_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_44_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  auto const result = depth_43_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_43_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 15> preserve_frame = { 8 };

  auto const result = depth_42_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_42_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 5> preserve_frame = { 8 };

  auto const result = depth_41_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_41_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 8> preserve_frame = { 8 };

  auto const result = depth_40_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_40_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 8> preserve_frame = { 8 };

  auto const result = depth_39_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_39_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 7> preserve_frame = { 8 };

  auto const result = depth_38_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_38_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  auto const result = depth_37_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_37_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 11> preserve_frame = { 8 };

  auto const result = depth_36_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_36_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 8> preserve_frame = { 8 };

  auto const result = depth_35_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_35_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 11> preserve_frame = { 8 };

  auto const result = depth_34_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_34_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 16> preserve_frame = { 8 };

  auto const result = depth_33_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_33_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 1> preserve_frame = { 8 };

  auto const result = depth_32_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_32_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 13> preserve_frame = { 8 };

  auto const result = depth_31_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_31_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  auto const result = depth_30_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_30_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 1> preserve_frame = { 8 };

  auto const result = depth_29_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_29_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 2> preserve_frame = { 8 };

  auto const result = depth_28_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_28_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 9> preserve_frame = { 8 };

  auto const result = depth_27_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_27_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 15> preserve_frame = { 8 };

  auto const result = depth_26_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_26_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 16> preserve_frame = { 8 };

  auto const result = depth_25_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_25_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 7> preserve_frame = { 8 };

  auto const result = depth_24_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_24_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 11> preserve_frame = { 8 };

  auto const result = depth_23_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_23_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 14> preserve_frame = { 8 };

  auto const result = depth_22_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_22_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 12> preserve_frame = { 8 };

  auto const result = depth_21_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_21_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 4> preserve_frame = { 8 };

  auto const result = depth_20_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_20_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 16> preserve_frame = { 8 };

  auto const result = depth_19_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_19_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 11> preserve_frame = { 8 };

  auto const result = depth_18_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_18_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  auto const result = depth_17_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_17_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 4> preserve_frame = { 8 };

  auto const result = depth_16_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_16_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 10> preserve_frame = { 8 };

  auto const result = depth_15_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_15_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 5> preserve_frame = { 8 };

  auto const result = depth_14_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_14_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 9> preserve_frame = { 8 };

  auto const result = depth_13_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_13_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 4> preserve_frame = { 8 };

  auto const result = depth_12_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_12_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 5> preserve_frame = { 8 };

  auto const result = depth_11_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_11_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 10> preserve_frame = { 8 };

  auto const result = depth_10_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_10_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 5> preserve_frame = { 8 };

  auto const result = depth_09_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_09_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 7> preserve_frame = { 8 };

  auto const result = depth_08_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_08_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 12> preserve_frame = { 8 };

  auto const result = depth_07_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_07_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 16> preserve_frame = { 8 };

  auto const result = depth_06_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_06_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 10> preserve_frame = { 8 };

  auto const result = depth_05_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_05_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 13> preserve_frame = { 8 };

  auto const result = depth_04_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_04_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 16> preserve_frame = { 8 };

  auto const result = depth_03_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_03_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 9> preserve_frame = { 8 };

  auto const result = depth_02_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_02_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 2> preserve_frame = { 8 };

  auto const result = depth_01_error_65_percent_000();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_01_error_65_percent_000()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 14> preserve_frame = { 8 };

  // This is where the error originates
  if (side_effect > 0) {
    start();
    return std::unexpected(test_error_65{ .data = { 0xDE, 0xAD, 0xBE, 0xEF } });
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  return side_effect + 1;
}

std::expected<int, test_error_65> depth_70_error_65_percent_025();
std::expected<int, test_error_65> depth_69_error_65_percent_025();
std::expected<int, test_error_65> depth_68_error_65_percent_025();
std::expected<int, test_error_65> depth_67_error_65_percent_025();
std::expected<int, test_error_65> depth_66_error_65_percent_025();
std::expected<int, test_error_65> depth_65_error_65_percent_025();
std::expected<int, test_error_65> depth_64_error_65_percent_025();
std::expected<int, test_error_65> depth_63_error_65_percent_025();
std::expected<int, test_error_65> depth_62_error_65_percent_025();
std::expected<int, test_error_65> depth_61_error_65_percent_025();
std::expected<int, test_error_65> depth_60_error_65_percent_025();
std::expected<int, test_error_65> depth_59_error_65_percent_025();
std::expected<int, test_error_65> depth_58_error_65_percent_025();
std::expected<int, test_error_65> depth_57_error_65_percent_025();
std::expected<int, test_error_65> depth_56_error_65_percent_025();
std::expected<int, test_error_65> depth_55_error_65_percent_025();
std::expected<int, test_error_65> depth_54_error_65_percent_025();
std::expected<int, test_error_65> depth_53_error_65_percent_025();
std::expected<int, test_error_65> depth_52_error_65_percent_025();
std::expected<int, test_error_65> depth_51_error_65_percent_025();
std::expected<int, test_error_65> depth_50_error_65_percent_025();
std::expected<int, test_error_65> depth_49_error_65_percent_025();
std::expected<int, test_error_65> depth_48_error_65_percent_025();
std::expected<int, test_error_65> depth_47_error_65_percent_025();
std::expected<int, test_error_65> depth_46_error_65_percent_025();
std::expected<int, test_error_65> depth_45_error_65_percent_025();
std::expected<int, test_error_65> depth_44_error_65_percent_025();
std::expected<int, test_error_65> depth_43_error_65_percent_025();
std::expected<int, test_error_65> depth_42_error_65_percent_025();
std::expected<int, test_error_65> depth_41_error_65_percent_025();
std::expected<int, test_error_65> depth_40_error_65_percent_025();
std::expected<int, test_error_65> depth_39_error_65_percent_025();
std::expected<int, test_error_65> depth_38_error_65_percent_025();
std::expected<int, test_error_65> depth_37_error_65_percent_025();
std::expected<int, test_error_65> depth_36_error_65_percent_025();
std::expected<int, test_error_65> depth_35_error_65_percent_025();
std::expected<int, test_error_65> depth_34_error_65_percent_025();
std::expected<int, test_error_65> depth_33_error_65_percent_025();
std::expected<int, test_error_65> depth_32_error_65_percent_025();
std::expected<int, test_error_65> depth_31_error_65_percent_025();
std::expected<int, test_error_65> depth_30_error_65_percent_025();
std::expected<int, test_error_65> depth_29_error_65_percent_025();
std::expected<int, test_error_65> depth_28_error_65_percent_025();
std::expected<int, test_error_65> depth_27_error_65_percent_025();
std::expected<int, test_error_65> depth_26_error_65_percent_025();
std::expected<int, test_error_65> depth_25_error_65_percent_025();
std::expected<int, test_error_65> depth_24_error_65_percent_025();
std::expected<int, test_error_65> depth_23_error_65_percent_025();
std::expected<int, test_error_65> depth_22_error_65_percent_025();
std::expected<int, test_error_65> depth_21_error_65_percent_025();
std::expected<int, test_error_65> depth_20_error_65_percent_025();
std::expected<int, test_error_65> depth_19_error_65_percent_025();
std::expected<int, test_error_65> depth_18_error_65_percent_025();
std::expected<int, test_error_65> depth_17_error_65_percent_025();
std::expected<int, test_error_65> depth_16_error_65_percent_025();
std::expected<int, test_error_65> depth_15_error_65_percent_025();
std::expected<int, test_error_65> depth_14_error_65_percent_025();
std::expected<int, test_error_65> depth_13_error_65_percent_025();
std::expected<int, test_error_65> depth_12_error_65_percent_025();
std::expected<int, test_error_65> depth_11_error_65_percent_025();
std::expected<int, test_error_65> depth_10_error_65_percent_025();
std::expected<int, test_error_65> depth_09_error_65_percent_025();
std::expected<int, test_error_65> depth_08_error_65_percent_025();
std::expected<int, test_error_65> depth_07_error_65_percent_025();
std::expected<int, test_error_65> depth_06_error_65_percent_025();
std::expected<int, test_error_65> depth_05_error_65_percent_025();
std::expected<int, test_error_65> depth_04_error_65_percent_025();
std::expected<int, test_error_65> depth_03_error_65_percent_025();
std::expected<int, test_error_65> depth_02_error_65_percent_025();
std::expected<int, test_error_65> depth_01_error_65_percent_025();
[[gnu::noinline]]
std::expected<int, test_error_65> depth_70_error_65_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 5> preserve_frame = { 8 };

  auto const result = depth_69_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_69_error_65_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 5> preserve_frame = { 8 };

  auto const result = depth_68_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_68_error_65_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  auto const result = depth_67_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_67_error_65_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  auto const result = depth_66_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_66_error_65_percent_025()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 16> preserve_frame = { 8 };

  auto const result = depth_65_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_65_error_65_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 9> preserve_frame = { 8 };

  auto const result = depth_64_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_64_error_65_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 2> preserve_frame = { 8 };

  auto const result = depth_63_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_63_error_65_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 6> preserve_frame = { 8 };

  auto const result = depth_62_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_62_error_65_percent_025()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 7> preserve_frame = { 8 };

  auto const result = depth_61_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_61_error_65_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 6> preserve_frame = { 8 };

  auto const result = depth_60_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_60_error_65_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 10> preserve_frame = { 8 };

  auto const result = depth_59_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_59_error_65_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 8> preserve_frame = { 8 };

  auto const result = depth_58_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_58_error_65_percent_025()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 11> preserve_frame = { 8 };

  auto const result = depth_57_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_57_error_65_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 13> preserve_frame = { 8 };

  auto const result = depth_56_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_56_error_65_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  auto const result = depth_55_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_55_error_65_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 15> preserve_frame = { 8 };

  auto const result = depth_54_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_54_error_65_percent_025()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 10> preserve_frame = { 8 };

  auto const result = depth_53_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_53_error_65_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 7> preserve_frame = { 8 };

  auto const result = depth_52_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_52_error_65_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 11> preserve_frame = { 8 };

  auto const result = depth_51_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_51_error_65_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 4> preserve_frame = { 8 };

  auto const result = depth_50_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_50_error_65_percent_025()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 10> preserve_frame = { 8 };

  auto const result = depth_49_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_49_error_65_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 10> preserve_frame = { 8 };

  auto const result = depth_48_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_48_error_65_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 4> preserve_frame = { 8 };

  auto const result = depth_47_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_47_error_65_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 16> preserve_frame = { 8 };

  auto const result = depth_46_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_46_error_65_percent_025()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 11> preserve_frame = { 8 };

  auto const result = depth_45_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_45_error_65_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  auto const result = depth_44_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_44_error_65_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  auto const result = depth_43_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_43_error_65_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 15> preserve_frame = { 8 };

  auto const result = depth_42_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_42_error_65_percent_025()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 5> preserve_frame = { 8 };

  auto const result = depth_41_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_41_error_65_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 8> preserve_frame = { 8 };

  auto const result = depth_40_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_40_error_65_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 8> preserve_frame = { 8 };

  auto const result = depth_39_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_39_error_65_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 7> preserve_frame = { 8 };

  auto const result = depth_38_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_38_error_65_percent_025()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  auto const result = depth_37_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_37_error_65_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 11> preserve_frame = { 8 };

  auto const result = depth_36_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_36_error_65_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 8> preserve_frame = { 8 };

  auto const result = depth_35_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_35_error_65_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 11> preserve_frame = { 8 };

  auto const result = depth_34_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_34_error_65_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 16> preserve_frame = { 8 };

  auto const result = depth_33_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_33_error_65_percent_025()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 1> preserve_frame = { 8 };

  auto const result = depth_32_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_32_error_65_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 13> preserve_frame = { 8 };

  auto const result = depth_31_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_31_error_65_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  auto const result = depth_30_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_30_error_65_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 1> preserve_frame = { 8 };

  auto const result = depth_29_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_29_error_65_percent_025()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 2> preserve_frame = { 8 };

  auto const result = depth_28_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_28_error_65_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 9> preserve_frame = { 8 };

  auto const result = depth_27_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_27_error_65_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 15> preserve_frame = { 8 };

  auto const result = depth_26_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_26_error_65_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 16> preserve_frame = { 8 };

  auto const result = depth_25_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_25_error_65_percent_025()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 7> preserve_frame = { 8 };

  auto const result = depth_24_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_24_error_65_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 11> preserve_frame = { 8 };

  auto const result = depth_23_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_23_error_65_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 14> preserve_frame = { 8 };

  auto const result = depth_22_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_22_error_65_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 12> preserve_frame = { 8 };

  auto const result = depth_21_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_21_error_65_percent_025()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 4> preserve_frame = { 8 };

  auto const result = depth_20_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_20_error_65_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 16> preserve_frame = { 8 };

  auto const result = depth_19_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_19_error_65_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 11> preserve_frame = { 8 };

  auto const result = depth_18_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_18_error_65_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  auto const result = depth_17_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_17_error_65_percent_025()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 4> preserve_frame = { 8 };

  auto const result = depth_16_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_16_error_65_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 10> preserve_frame = { 8 };

  auto const result = depth_15_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_15_error_65_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 5> preserve_frame = { 8 };

  auto const result = depth_14_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_14_error_65_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 9> preserve_frame = { 8 };

  auto const result = depth_13_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_13_error_65_percent_025()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 4> preserve_frame = { 8 };

  auto const result = depth_12_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_12_error_65_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 5> preserve_frame = { 8 };

  auto const result = depth_11_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_11_error_65_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 10> preserve_frame = { 8 };

  auto const result = depth_10_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_10_error_65_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 5> preserve_frame = { 8 };

  auto const result = depth_09_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_09_error_65_percent_025()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 7> preserve_frame = { 8 };

  auto const result = depth_08_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_08_error_65_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 12> preserve_frame = { 8 };

  auto const result = depth_07_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_07_error_65_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 16> preserve_frame = { 8 };

  auto const result = depth_06_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_06_error_65_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 10> preserve_frame = { 8 };

  auto const result = depth_05_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_05_error_65_percent_025()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 13> preserve_frame = { 8 };

  auto const result = depth_04_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_04_error_65_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 16> preserve_frame = { 8 };

  auto const result = depth_03_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_03_error_65_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 9> preserve_frame = { 8 };

  auto const result = depth_02_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_02_error_65_percent_025()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 2> preserve_frame = { 8 };

  auto const result = depth_01_error_65_percent_025();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_01_error_65_percent_025()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 14> preserve_frame = { 8 };

  // This is where the error originates
  if (side_effect > 0) {
    start();
    return std::unexpected(test_error_65{ .data = { 0xDE, 0xAD, 0xBE, 0xEF } });
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  return side_effect + 1;
}

std::expected<int, test_error_65> depth_70_error_65_percent_050();
std::expected<int, test_error_65> depth_69_error_65_percent_050();
std::expected<int, test_error_65> depth_68_error_65_percent_050();
std::expected<int, test_error_65> depth_67_error_65_percent_050();
std::expected<int, test_error_65> depth_66_error_65_percent_050();
std::expected<int, test_error_65> depth_65_error_65_percent_050();
std::expected<int, test_error_65> depth_64_error_65_percent_050();
std::expected<int, test_error_65> depth_63_error_65_percent_050();
std::expected<int, test_error_65> depth_62_error_65_percent_050();
std::expected<int, test_error_65> depth_61_error_65_percent_050();
std::expected<int, test_error_65> depth_60_error_65_percent_050();
std::expected<int, test_error_65> depth_59_error_65_percent_050();
std::expected<int, test_error_65> depth_58_error_65_percent_050();
std::expected<int, test_error_65> depth_57_error_65_percent_050();
std::expected<int, test_error_65> depth_56_error_65_percent_050();
std::expected<int, test_error_65> depth_55_error_65_percent_050();
std::expected<int, test_error_65> depth_54_error_65_percent_050();
std::expected<int, test_error_65> depth_53_error_65_percent_050();
std::expected<int, test_error_65> depth_52_error_65_percent_050();
std::expected<int, test_error_65> depth_51_error_65_percent_050();
std::expected<int, test_error_65> depth_50_error_65_percent_050();
std::expected<int, test_error_65> depth_49_error_65_percent_050();
std::expected<int, test_error_65> depth_48_error_65_percent_050();
std::expected<int, test_error_65> depth_47_error_65_percent_050();
std::expected<int, test_error_65> depth_46_error_65_percent_050();
std::expected<int, test_error_65> depth_45_error_65_percent_050();
std::expected<int, test_error_65> depth_44_error_65_percent_050();
std::expected<int, test_error_65> depth_43_error_65_percent_050();
std::expected<int, test_error_65> depth_42_error_65_percent_050();
std::expected<int, test_error_65> depth_41_error_65_percent_050();
std::expected<int, test_error_65> depth_40_error_65_percent_050();
std::expected<int, test_error_65> depth_39_error_65_percent_050();
std::expected<int, test_error_65> depth_38_error_65_percent_050();
std::expected<int, test_error_65> depth_37_error_65_percent_050();
std::expected<int, test_error_65> depth_36_error_65_percent_050();
std::expected<int, test_error_65> depth_35_error_65_percent_050();
std::expected<int, test_error_65> depth_34_error_65_percent_050();
std::expected<int, test_error_65> depth_33_error_65_percent_050();
std::expected<int, test_error_65> depth_32_error_65_percent_050();
std::expected<int, test_error_65> depth_31_error_65_percent_050();
std::expected<int, test_error_65> depth_30_error_65_percent_050();
std::expected<int, test_error_65> depth_29_error_65_percent_050();
std::expected<int, test_error_65> depth_28_error_65_percent_050();
std::expected<int, test_error_65> depth_27_error_65_percent_050();
std::expected<int, test_error_65> depth_26_error_65_percent_050();
std::expected<int, test_error_65> depth_25_error_65_percent_050();
std::expected<int, test_error_65> depth_24_error_65_percent_050();
std::expected<int, test_error_65> depth_23_error_65_percent_050();
std::expected<int, test_error_65> depth_22_error_65_percent_050();
std::expected<int, test_error_65> depth_21_error_65_percent_050();
std::expected<int, test_error_65> depth_20_error_65_percent_050();
std::expected<int, test_error_65> depth_19_error_65_percent_050();
std::expected<int, test_error_65> depth_18_error_65_percent_050();
std::expected<int, test_error_65> depth_17_error_65_percent_050();
std::expected<int, test_error_65> depth_16_error_65_percent_050();
std::expected<int, test_error_65> depth_15_error_65_percent_050();
std::expected<int, test_error_65> depth_14_error_65_percent_050();
std::expected<int, test_error_65> depth_13_error_65_percent_050();
std::expected<int, test_error_65> depth_12_error_65_percent_050();
std::expected<int, test_error_65> depth_11_error_65_percent_050();
std::expected<int, test_error_65> depth_10_error_65_percent_050();
std::expected<int, test_error_65> depth_09_error_65_percent_050();
std::expected<int, test_error_65> depth_08_error_65_percent_050();
std::expected<int, test_error_65> depth_07_error_65_percent_050();
std::expected<int, test_error_65> depth_06_error_65_percent_050();
std::expected<int, test_error_65> depth_05_error_65_percent_050();
std::expected<int, test_error_65> depth_04_error_65_percent_050();
std::expected<int, test_error_65> depth_03_error_65_percent_050();
std::expected<int, test_error_65> depth_02_error_65_percent_050();
std::expected<int, test_error_65> depth_01_error_65_percent_050();
[[gnu::noinline]]
std::expected<int, test_error_65> depth_70_error_65_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 5> preserve_frame = { 8 };

  auto const result = depth_69_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_69_error_65_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 5> preserve_frame = { 8 };

  auto const result = depth_68_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_68_error_65_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  auto const result = depth_67_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_67_error_65_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  auto const result = depth_66_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_66_error_65_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 16> preserve_frame = { 8 };

  auto const result = depth_65_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_65_error_65_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 9> preserve_frame = { 8 };

  auto const result = depth_64_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_64_error_65_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 2> preserve_frame = { 8 };

  auto const result = depth_63_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_63_error_65_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 6> preserve_frame = { 8 };

  auto const result = depth_62_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_62_error_65_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 7> preserve_frame = { 8 };

  auto const result = depth_61_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_61_error_65_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 6> preserve_frame = { 8 };

  auto const result = depth_60_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_60_error_65_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 10> preserve_frame = { 8 };

  auto const result = depth_59_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_59_error_65_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 8> preserve_frame = { 8 };

  auto const result = depth_58_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_58_error_65_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 11> preserve_frame = { 8 };

  auto const result = depth_57_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_57_error_65_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 13> preserve_frame = { 8 };

  auto const result = depth_56_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_56_error_65_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  auto const result = depth_55_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_55_error_65_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 15> preserve_frame = { 8 };

  auto const result = depth_54_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_54_error_65_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 10> preserve_frame = { 8 };

  auto const result = depth_53_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_53_error_65_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 7> preserve_frame = { 8 };

  auto const result = depth_52_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_52_error_65_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 11> preserve_frame = { 8 };

  auto const result = depth_51_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_51_error_65_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 4> preserve_frame = { 8 };

  auto const result = depth_50_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_50_error_65_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 10> preserve_frame = { 8 };

  auto const result = depth_49_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_49_error_65_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 10> preserve_frame = { 8 };

  auto const result = depth_48_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_48_error_65_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 4> preserve_frame = { 8 };

  auto const result = depth_47_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_47_error_65_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 16> preserve_frame = { 8 };

  auto const result = depth_46_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_46_error_65_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 11> preserve_frame = { 8 };

  auto const result = depth_45_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_45_error_65_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  auto const result = depth_44_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_44_error_65_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  auto const result = depth_43_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_43_error_65_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 15> preserve_frame = { 8 };

  auto const result = depth_42_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_42_error_65_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 5> preserve_frame = { 8 };

  auto const result = depth_41_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_41_error_65_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 8> preserve_frame = { 8 };

  auto const result = depth_40_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_40_error_65_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 8> preserve_frame = { 8 };

  auto const result = depth_39_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_39_error_65_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 7> preserve_frame = { 8 };

  auto const result = depth_38_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_38_error_65_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  auto const result = depth_37_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_37_error_65_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 11> preserve_frame = { 8 };

  auto const result = depth_36_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_36_error_65_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 8> preserve_frame = { 8 };

  auto const result = depth_35_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_35_error_65_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 11> preserve_frame = { 8 };

  auto const result = depth_34_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_34_error_65_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 16> preserve_frame = { 8 };

  auto const result = depth_33_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_33_error_65_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 1> preserve_frame = { 8 };

  auto const result = depth_32_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_32_error_65_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 13> preserve_frame = { 8 };

  auto const result = depth_31_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_31_error_65_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  auto const result = depth_30_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_30_error_65_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 1> preserve_frame = { 8 };

  auto const result = depth_29_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_29_error_65_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 2> preserve_frame = { 8 };

  auto const result = depth_28_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_28_error_65_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 9> preserve_frame = { 8 };

  auto const result = depth_27_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_27_error_65_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 15> preserve_frame = { 8 };

  auto const result = depth_26_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_26_error_65_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 16> preserve_frame = { 8 };

  auto const result = depth_25_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_25_error_65_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 7> preserve_frame = { 8 };

  auto const result = depth_24_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_24_error_65_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 11> preserve_frame = { 8 };

  auto const result = depth_23_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_23_error_65_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 14> preserve_frame = { 8 };

  auto const result = depth_22_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_22_error_65_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 12> preserve_frame = { 8 };

  auto const result = depth_21_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_21_error_65_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 4> preserve_frame = { 8 };

  auto const result = depth_20_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_20_error_65_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 16> preserve_frame = { 8 };

  auto const result = depth_19_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_19_error_65_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 11> preserve_frame = { 8 };

  auto const result = depth_18_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_18_error_65_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  auto const result = depth_17_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_17_error_65_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 4> preserve_frame = { 8 };

  auto const result = depth_16_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_16_error_65_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 10> preserve_frame = { 8 };

  auto const result = depth_15_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_15_error_65_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 5> preserve_frame = { 8 };

  auto const result = depth_14_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_14_error_65_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 9> preserve_frame = { 8 };

  auto const result = depth_13_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_13_error_65_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 4> preserve_frame = { 8 };

  auto const result = depth_12_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_12_error_65_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 5> preserve_frame = { 8 };

  auto const result = depth_11_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_11_error_65_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 10> preserve_frame = { 8 };

  auto const result = depth_10_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_10_error_65_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 5> preserve_frame = { 8 };

  auto const result = depth_09_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_09_error_65_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 7> preserve_frame = { 8 };

  auto const result = depth_08_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_08_error_65_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 12> preserve_frame = { 8 };

  auto const result = depth_07_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_07_error_65_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 16> preserve_frame = { 8 };

  auto const result = depth_06_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_06_error_65_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 10> preserve_frame = { 8 };

  auto const result = depth_05_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_05_error_65_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 13> preserve_frame = { 8 };

  auto const result = depth_04_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_04_error_65_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 16> preserve_frame = { 8 };

  auto const result = depth_03_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_03_error_65_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 9> preserve_frame = { 8 };

  auto const result = depth_02_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_02_error_65_percent_050()
{
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 2> preserve_frame = { 8 };

  auto const result = depth_01_error_65_percent_050();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_01_error_65_percent_050()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 14> preserve_frame = { 8 };

  // This is where the error originates
  if (side_effect > 0) {
    start();
    return std::unexpected(test_error_65{ .data = { 0xDE, 0xAD, 0xBE, 0xEF } });
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  return side_effect + 1;
}

std::expected<int, test_error_65> depth_70_error_65_percent_100();
std::expected<int, test_error_65> depth_69_error_65_percent_100();
std::expected<int, test_error_65> depth_68_error_65_percent_100();
std::expected<int, test_error_65> depth_67_error_65_percent_100();
std::expected<int, test_error_65> depth_66_error_65_percent_100();
std::expected<int, test_error_65> depth_65_error_65_percent_100();
std::expected<int, test_error_65> depth_64_error_65_percent_100();
std::expected<int, test_error_65> depth_63_error_65_percent_100();
std::expected<int, test_error_65> depth_62_error_65_percent_100();
std::expected<int, test_error_65> depth_61_error_65_percent_100();
std::expected<int, test_error_65> depth_60_error_65_percent_100();
std::expected<int, test_error_65> depth_59_error_65_percent_100();
std::expected<int, test_error_65> depth_58_error_65_percent_100();
std::expected<int, test_error_65> depth_57_error_65_percent_100();
std::expected<int, test_error_65> depth_56_error_65_percent_100();
std::expected<int, test_error_65> depth_55_error_65_percent_100();
std::expected<int, test_error_65> depth_54_error_65_percent_100();
std::expected<int, test_error_65> depth_53_error_65_percent_100();
std::expected<int, test_error_65> depth_52_error_65_percent_100();
std::expected<int, test_error_65> depth_51_error_65_percent_100();
std::expected<int, test_error_65> depth_50_error_65_percent_100();
std::expected<int, test_error_65> depth_49_error_65_percent_100();
std::expected<int, test_error_65> depth_48_error_65_percent_100();
std::expected<int, test_error_65> depth_47_error_65_percent_100();
std::expected<int, test_error_65> depth_46_error_65_percent_100();
std::expected<int, test_error_65> depth_45_error_65_percent_100();
std::expected<int, test_error_65> depth_44_error_65_percent_100();
std::expected<int, test_error_65> depth_43_error_65_percent_100();
std::expected<int, test_error_65> depth_42_error_65_percent_100();
std::expected<int, test_error_65> depth_41_error_65_percent_100();
std::expected<int, test_error_65> depth_40_error_65_percent_100();
std::expected<int, test_error_65> depth_39_error_65_percent_100();
std::expected<int, test_error_65> depth_38_error_65_percent_100();
std::expected<int, test_error_65> depth_37_error_65_percent_100();
std::expected<int, test_error_65> depth_36_error_65_percent_100();
std::expected<int, test_error_65> depth_35_error_65_percent_100();
std::expected<int, test_error_65> depth_34_error_65_percent_100();
std::expected<int, test_error_65> depth_33_error_65_percent_100();
std::expected<int, test_error_65> depth_32_error_65_percent_100();
std::expected<int, test_error_65> depth_31_error_65_percent_100();
std::expected<int, test_error_65> depth_30_error_65_percent_100();
std::expected<int, test_error_65> depth_29_error_65_percent_100();
std::expected<int, test_error_65> depth_28_error_65_percent_100();
std::expected<int, test_error_65> depth_27_error_65_percent_100();
std::expected<int, test_error_65> depth_26_error_65_percent_100();
std::expected<int, test_error_65> depth_25_error_65_percent_100();
std::expected<int, test_error_65> depth_24_error_65_percent_100();
std::expected<int, test_error_65> depth_23_error_65_percent_100();
std::expected<int, test_error_65> depth_22_error_65_percent_100();
std::expected<int, test_error_65> depth_21_error_65_percent_100();
std::expected<int, test_error_65> depth_20_error_65_percent_100();
std::expected<int, test_error_65> depth_19_error_65_percent_100();
std::expected<int, test_error_65> depth_18_error_65_percent_100();
std::expected<int, test_error_65> depth_17_error_65_percent_100();
std::expected<int, test_error_65> depth_16_error_65_percent_100();
std::expected<int, test_error_65> depth_15_error_65_percent_100();
std::expected<int, test_error_65> depth_14_error_65_percent_100();
std::expected<int, test_error_65> depth_13_error_65_percent_100();
std::expected<int, test_error_65> depth_12_error_65_percent_100();
std::expected<int, test_error_65> depth_11_error_65_percent_100();
std::expected<int, test_error_65> depth_10_error_65_percent_100();
std::expected<int, test_error_65> depth_09_error_65_percent_100();
std::expected<int, test_error_65> depth_08_error_65_percent_100();
std::expected<int, test_error_65> depth_07_error_65_percent_100();
std::expected<int, test_error_65> depth_06_error_65_percent_100();
std::expected<int, test_error_65> depth_05_error_65_percent_100();
std::expected<int, test_error_65> depth_04_error_65_percent_100();
std::expected<int, test_error_65> depth_03_error_65_percent_100();
std::expected<int, test_error_65> depth_02_error_65_percent_100();
std::expected<int, test_error_65> depth_01_error_65_percent_100();
[[gnu::noinline]]
std::expected<int, test_error_65> depth_70_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 5> preserve_frame = { 8 };

  auto const result = depth_69_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_69_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 5> preserve_frame = { 8 };

  auto const result = depth_68_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_68_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  auto const result = depth_67_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_67_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  auto const result = depth_66_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_66_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 16> preserve_frame = { 8 };

  auto const result = depth_65_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_65_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 9> preserve_frame = { 8 };

  auto const result = depth_64_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_64_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 2> preserve_frame = { 8 };

  auto const result = depth_63_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_63_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 6> preserve_frame = { 8 };

  auto const result = depth_62_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_62_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 7> preserve_frame = { 8 };

  auto const result = depth_61_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_61_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 6> preserve_frame = { 8 };

  auto const result = depth_60_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_60_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 10> preserve_frame = { 8 };

  auto const result = depth_59_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_59_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 8> preserve_frame = { 8 };

  auto const result = depth_58_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_58_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 11> preserve_frame = { 8 };

  auto const result = depth_57_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_57_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 13> preserve_frame = { 8 };

  auto const result = depth_56_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_56_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  auto const result = depth_55_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_55_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 15> preserve_frame = { 8 };

  auto const result = depth_54_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_54_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 10> preserve_frame = { 8 };

  auto const result = depth_53_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_53_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 7> preserve_frame = { 8 };

  auto const result = depth_52_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_52_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 11> preserve_frame = { 8 };

  auto const result = depth_51_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_51_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 4> preserve_frame = { 8 };

  auto const result = depth_50_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_50_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 10> preserve_frame = { 8 };

  auto const result = depth_49_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_49_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 10> preserve_frame = { 8 };

  auto const result = depth_48_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_48_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 4> preserve_frame = { 8 };

  auto const result = depth_47_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_47_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 16> preserve_frame = { 8 };

  auto const result = depth_46_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_46_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 11> preserve_frame = { 8 };

  auto const result = depth_45_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_45_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  auto const result = depth_44_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_44_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  auto const result = depth_43_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_43_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 15> preserve_frame = { 8 };

  auto const result = depth_42_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_42_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 5> preserve_frame = { 8 };

  auto const result = depth_41_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_41_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 8> preserve_frame = { 8 };

  auto const result = depth_40_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_40_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 8> preserve_frame = { 8 };

  auto const result = depth_39_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_39_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 7> preserve_frame = { 8 };

  auto const result = depth_38_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_38_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  auto const result = depth_37_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_37_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 11> preserve_frame = { 8 };

  auto const result = depth_36_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_36_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 8> preserve_frame = { 8 };

  auto const result = depth_35_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_35_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 11> preserve_frame = { 8 };

  auto const result = depth_34_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_34_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 16> preserve_frame = { 8 };

  auto const result = depth_33_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_33_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 1> preserve_frame = { 8 };

  auto const result = depth_32_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_32_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 13> preserve_frame = { 8 };

  auto const result = depth_31_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_31_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  auto const result = depth_30_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_30_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 1> preserve_frame = { 8 };

  auto const result = depth_29_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_29_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 2> preserve_frame = { 8 };

  auto const result = depth_28_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_28_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 9> preserve_frame = { 8 };

  auto const result = depth_27_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_27_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 15> preserve_frame = { 8 };

  auto const result = depth_26_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_26_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 16> preserve_frame = { 8 };

  auto const result = depth_25_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_25_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 7> preserve_frame = { 8 };

  auto const result = depth_24_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_24_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 11> preserve_frame = { 8 };

  auto const result = depth_23_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_23_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 14> preserve_frame = { 8 };

  auto const result = depth_22_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_22_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 12> preserve_frame = { 8 };

  auto const result = depth_21_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_21_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 4> preserve_frame = { 8 };

  auto const result = depth_20_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_20_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 16> preserve_frame = { 8 };

  auto const result = depth_19_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_19_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 11> preserve_frame = { 8 };

  auto const result = depth_18_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_18_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 3> preserve_frame = { 8 };

  auto const result = depth_17_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_17_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 4> preserve_frame = { 8 };

  auto const result = depth_16_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_16_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 10> preserve_frame = { 8 };

  auto const result = depth_15_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_15_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 5> preserve_frame = { 8 };

  auto const result = depth_14_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_14_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 9> preserve_frame = { 8 };

  auto const result = depth_13_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_13_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 4> preserve_frame = { 8 };

  auto const result = depth_12_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_12_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 5> preserve_frame = { 8 };

  auto const result = depth_11_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_11_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 10> preserve_frame = { 8 };

  auto const result = depth_10_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_10_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 5> preserve_frame = { 8 };

  auto const result = depth_09_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_09_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 7> preserve_frame = { 8 };

  auto const result = depth_08_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_08_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 12> preserve_frame = { 8 };

  auto const result = depth_07_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_07_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 16> preserve_frame = { 8 };

  auto const result = depth_06_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_06_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 10> preserve_frame = { 8 };

  auto const result = depth_05_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_05_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 13> preserve_frame = { 8 };

  auto const result = depth_04_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_04_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 16> preserve_frame = { 8 };

  auto const result = depth_03_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_03_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 9> preserve_frame = { 8 };

  auto const result = depth_02_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_02_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 2> preserve_frame = { 8 };

  auto const result = depth_01_error_65_percent_100();

  if (!result) {
    return std::unexpected(result.error());
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_01_error_65_percent_100()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, 14> preserve_frame = { 8 };

  // This is where the error originates
  if (side_effect > 0) {
    start();
    return std::unexpected(test_error_65{ .data = { 0xDE, 0xAD, 0xBE, 0xEF } });
  }

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  return side_effect + 1;
}

// Test runner
[[gnu::noinline]]
void run_test_depth_50_error_65_cleanup_000()
{
  side_effect = 1;  // Ensure we will return error

  auto const result = depth_50_error_65_percent_000();
  if (!result) {
    end();
  }
  pause();  // Should have gotten an error
}

[[gnu::noinline]]
void run_test_depth_35_error_65_cleanup_000()
{
  side_effect = 1;  // Ensure we will return error

  auto const result = depth_35_error_65_percent_000();
  if (!result) {
    end();
  }
  pause();
}

[[gnu::noinline]]
void run_test_depth_15_error_65_cleanup_000()
{
  side_effect = 1;  // Ensure we will return error

  auto const result = depth_15_error_65_percent_000();
  if (!result) {
    end();
  }
  pause();
}

[[gnu::noinline]]
void run_test_depth_05_error_65_cleanup_000()
{
  side_effect = 1;  // Ensure we will return error

  auto const result = depth_05_error_65_percent_000();
  if (!result) {
    end();
  }
  pause();
}

[[gnu::noinline]]
void run_test_depth_01_error_65_cleanup_000()
{
  side_effect = 1;  // Ensure we will return error

  auto const result = depth_01_error_65_percent_000();
  if (!result) {
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
  side_effect = 1;  // Ensure we will return error

  auto const result = depth_50_error_65_percent_025();
  if (!result) {
    end();
  }
  pause();  // Should have gotten an error
}

[[gnu::noinline]]
void run_test_depth_35_error_65_cleanup_025()
{
  side_effect = 1;  // Ensure we will return error

  auto const result = depth_35_error_65_percent_025();
  if (!result) {
    end();
  }
  pause();
}

[[gnu::noinline]]
void run_test_depth_15_error_65_cleanup_025()
{
  side_effect = 1;  // Ensure we will return error

  auto const result = depth_15_error_65_percent_025();
  if (!result) {
    end();
  }
  pause();
}

[[gnu::noinline]]
void run_test_depth_05_error_65_cleanup_025()
{
  side_effect = 1;  // Ensure we will return error

  auto const result = depth_05_error_65_percent_025();
  if (!result) {
    end();
  }
  pause();
}

[[gnu::noinline]]
void run_test_depth_01_error_65_cleanup_025()
{
  side_effect = 1;  // Ensure we will return error

  auto const result = depth_01_error_65_percent_025();
  if (!result) {
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
  side_effect = 1;  // Ensure we will return error

  auto const result = depth_50_error_65_percent_050();
  if (!result) {
    end();
  }
  pause();  // Should have gotten an error
}

[[gnu::noinline]]
void run_test_depth_35_error_65_cleanup_050()
{
  side_effect = 1;  // Ensure we will return error

  auto const result = depth_35_error_65_percent_050();
  if (!result) {
    end();
  }
  pause();
}

[[gnu::noinline]]
void run_test_depth_15_error_65_cleanup_050()
{
  side_effect = 1;  // Ensure we will return error

  auto const result = depth_15_error_65_percent_050();
  if (!result) {
    end();
  }
  pause();
}

[[gnu::noinline]]
void run_test_depth_05_error_65_cleanup_050()
{
  side_effect = 1;  // Ensure we will return error

  auto const result = depth_05_error_65_percent_050();
  if (!result) {
    end();
  }
  pause();
}

[[gnu::noinline]]
void run_test_depth_01_error_65_cleanup_050()
{
  side_effect = 1;  // Ensure we will return error

  auto const result = depth_01_error_65_percent_050();
  if (!result) {
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
  side_effect = 1;  // Ensure we will return error

  auto const result = depth_50_error_65_percent_100();
  if (!result) {
    end();
  }
  pause();  // Should have gotten an error
}

[[gnu::noinline]]
void run_test_depth_35_error_65_cleanup_100()
{
  side_effect = 1;  // Ensure we will return error

  auto const result = depth_35_error_65_percent_100();
  if (!result) {
    end();
  }
  pause();
}

[[gnu::noinline]]
void run_test_depth_15_error_65_cleanup_100()
{
  side_effect = 1;  // Ensure we will return error

  auto const result = depth_15_error_65_percent_100();
  if (!result) {
    end();
  }
  pause();
}

[[gnu::noinline]]
void run_test_depth_05_error_65_cleanup_100()
{
  side_effect = 1;  // Ensure we will return error

  auto const result = depth_05_error_65_percent_100();
  if (!result) {
    end();
  }
  pause();
}

[[gnu::noinline]]
void run_test_depth_01_error_65_cleanup_100()
{
  side_effect = 1;  // Ensure we will return error

  auto const result = depth_01_error_65_percent_100();
  if (!result) {
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
  run_test_error_65_cleanup_000();
  run_test_error_65_cleanup_025();
  run_test_error_65_cleanup_050();
  run_test_error_65_cleanup_100();
}
