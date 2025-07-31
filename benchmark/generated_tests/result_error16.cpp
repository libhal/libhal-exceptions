#include <cstdint>
#include <array>
#include <expected>
#include <platform.hpp>

// Global side effect to prevent optimization
std::int32_t volatile side_effect = 0;

// Simple class without destructor
class simple_object {
public:
  explicit simple_object(std::int32_t value) : m_value(value) {
    side_effect = side_effect + 1;
  }

  void do_work() {
    side_effect = side_effect + m_value;
  }

private:
  std::int32_t m_value;
};

// Class with destructor for testing destructor impact
class destructor_object {
public:
  explicit destructor_object(std::int32_t value) : m_value(value) {
    side_effect = side_effect + 1;
  }

  ~destructor_object() {
    side_effect = side_effect + 1;
  }

  void do_work() {
    side_effect = side_effect + m_value;
  }

private:
  std::int32_t m_value;
};

// Error type for testing
struct test_error_16 {
  std::array<std::uint8_t, 16> data;
};
std::expected<int, test_error_16> depth_70_error16_percent_0();
std::expected<int, test_error_16> depth_69_error16_percent_0();
std::expected<int, test_error_16> depth_68_error16_percent_0();
std::expected<int, test_error_16> depth_67_error16_percent_0();
std::expected<int, test_error_16> depth_66_error16_percent_0();
std::expected<int, test_error_16> depth_65_error16_percent_0();
std::expected<int, test_error_16> depth_64_error16_percent_0();
std::expected<int, test_error_16> depth_63_error16_percent_0();
std::expected<int, test_error_16> depth_62_error16_percent_0();
std::expected<int, test_error_16> depth_61_error16_percent_0();
std::expected<int, test_error_16> depth_60_error16_percent_0();
std::expected<int, test_error_16> depth_59_error16_percent_0();
std::expected<int, test_error_16> depth_58_error16_percent_0();
std::expected<int, test_error_16> depth_57_error16_percent_0();
std::expected<int, test_error_16> depth_56_error16_percent_0();
std::expected<int, test_error_16> depth_55_error16_percent_0();
std::expected<int, test_error_16> depth_54_error16_percent_0();
std::expected<int, test_error_16> depth_53_error16_percent_0();
std::expected<int, test_error_16> depth_52_error16_percent_0();
std::expected<int, test_error_16> depth_51_error16_percent_0();
std::expected<int, test_error_16> depth_50_error16_percent_0();
std::expected<int, test_error_16> depth_49_error16_percent_0();
std::expected<int, test_error_16> depth_48_error16_percent_0();
std::expected<int, test_error_16> depth_47_error16_percent_0();
std::expected<int, test_error_16> depth_46_error16_percent_0();
std::expected<int, test_error_16> depth_45_error16_percent_0();
std::expected<int, test_error_16> depth_44_error16_percent_0();
std::expected<int, test_error_16> depth_43_error16_percent_0();
std::expected<int, test_error_16> depth_42_error16_percent_0();
std::expected<int, test_error_16> depth_41_error16_percent_0();
std::expected<int, test_error_16> depth_40_error16_percent_0();
std::expected<int, test_error_16> depth_39_error16_percent_0();
std::expected<int, test_error_16> depth_38_error16_percent_0();
std::expected<int, test_error_16> depth_37_error16_percent_0();
std::expected<int, test_error_16> depth_36_error16_percent_0();
std::expected<int, test_error_16> depth_35_error16_percent_0();
std::expected<int, test_error_16> depth_34_error16_percent_0();
std::expected<int, test_error_16> depth_33_error16_percent_0();
std::expected<int, test_error_16> depth_32_error16_percent_0();
std::expected<int, test_error_16> depth_31_error16_percent_0();
std::expected<int, test_error_16> depth_30_error16_percent_0();
std::expected<int, test_error_16> depth_29_error16_percent_0();
std::expected<int, test_error_16> depth_28_error16_percent_0();
std::expected<int, test_error_16> depth_27_error16_percent_0();
std::expected<int, test_error_16> depth_26_error16_percent_0();
std::expected<int, test_error_16> depth_25_error16_percent_0();
std::expected<int, test_error_16> depth_24_error16_percent_0();
std::expected<int, test_error_16> depth_23_error16_percent_0();
std::expected<int, test_error_16> depth_22_error16_percent_0();
std::expected<int, test_error_16> depth_21_error16_percent_0();
std::expected<int, test_error_16> depth_20_error16_percent_0();
std::expected<int, test_error_16> depth_19_error16_percent_0();
std::expected<int, test_error_16> depth_18_error16_percent_0();
std::expected<int, test_error_16> depth_17_error16_percent_0();
std::expected<int, test_error_16> depth_16_error16_percent_0();
std::expected<int, test_error_16> depth_15_error16_percent_0();
std::expected<int, test_error_16> depth_14_error16_percent_0();
std::expected<int, test_error_16> depth_13_error16_percent_0();
std::expected<int, test_error_16> depth_12_error16_percent_0();
std::expected<int, test_error_16> depth_11_error16_percent_0();
std::expected<int, test_error_16> depth_10_error16_percent_0();
std::expected<int, test_error_16> depth_09_error16_percent_0();
std::expected<int, test_error_16> depth_08_error16_percent_0();
std::expected<int, test_error_16> depth_07_error16_percent_0();
std::expected<int, test_error_16> depth_06_error16_percent_0();
std::expected<int, test_error_16> depth_05_error16_percent_0();
std::expected<int, test_error_16> depth_04_error16_percent_0();
std::expected<int, test_error_16> depth_03_error16_percent_0();
std::expected<int, test_error_16> depth_02_error16_percent_0();
std::expected<int, test_error_16> depth_01_error16_percent_0();
[[gnu::noinline]]
std::expected<int, test_error_16> depth_70_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_69_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_69_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_68_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_68_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_67_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_67_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_66_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_66_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_65_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_65_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_64_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_64_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_63_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_63_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_62_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_62_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_61_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_61_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_60_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_60_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_59_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_59_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_58_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_58_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_57_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_57_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_56_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_56_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_55_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_55_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_54_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_54_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_53_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_53_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_52_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_52_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_51_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_51_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_50_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_50_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_49_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_49_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_48_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_48_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_47_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_47_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_46_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_46_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_45_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_45_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_44_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_44_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_43_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_43_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_42_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_42_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_41_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_41_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_40_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_40_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_39_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_39_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_38_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_38_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_37_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_37_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_36_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_36_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_35_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_35_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_34_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_34_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_33_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_33_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_32_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_32_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_31_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_31_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_30_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_30_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_29_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_29_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_28_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_28_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_27_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_27_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_26_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_26_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_25_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_25_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_24_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_24_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_23_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_23_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_22_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_22_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_21_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_21_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_20_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_20_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_19_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_19_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_18_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_18_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_17_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_17_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_16_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_16_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_15_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_15_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_14_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_14_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_13_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_13_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_12_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_12_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_11_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_11_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_10_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_10_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_09_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_09_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_08_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_08_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_07_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_07_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_06_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_06_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_05_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_05_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_04_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_04_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_03_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_03_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_02_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_02_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_01_error16_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_01_error16_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  // This is where the error originates
  start();
  return std::unexpected(test_error_16
                        {
                            .data = { 0xDE, 0xAD, 0xBE, 0xEF }
                        });
}

std::expected<int, test_error_16> depth_70_error16_percent_25();
std::expected<int, test_error_16> depth_69_error16_percent_25();
std::expected<int, test_error_16> depth_68_error16_percent_25();
std::expected<int, test_error_16> depth_67_error16_percent_25();
std::expected<int, test_error_16> depth_66_error16_percent_25();
std::expected<int, test_error_16> depth_65_error16_percent_25();
std::expected<int, test_error_16> depth_64_error16_percent_25();
std::expected<int, test_error_16> depth_63_error16_percent_25();
std::expected<int, test_error_16> depth_62_error16_percent_25();
std::expected<int, test_error_16> depth_61_error16_percent_25();
std::expected<int, test_error_16> depth_60_error16_percent_25();
std::expected<int, test_error_16> depth_59_error16_percent_25();
std::expected<int, test_error_16> depth_58_error16_percent_25();
std::expected<int, test_error_16> depth_57_error16_percent_25();
std::expected<int, test_error_16> depth_56_error16_percent_25();
std::expected<int, test_error_16> depth_55_error16_percent_25();
std::expected<int, test_error_16> depth_54_error16_percent_25();
std::expected<int, test_error_16> depth_53_error16_percent_25();
std::expected<int, test_error_16> depth_52_error16_percent_25();
std::expected<int, test_error_16> depth_51_error16_percent_25();
std::expected<int, test_error_16> depth_50_error16_percent_25();
std::expected<int, test_error_16> depth_49_error16_percent_25();
std::expected<int, test_error_16> depth_48_error16_percent_25();
std::expected<int, test_error_16> depth_47_error16_percent_25();
std::expected<int, test_error_16> depth_46_error16_percent_25();
std::expected<int, test_error_16> depth_45_error16_percent_25();
std::expected<int, test_error_16> depth_44_error16_percent_25();
std::expected<int, test_error_16> depth_43_error16_percent_25();
std::expected<int, test_error_16> depth_42_error16_percent_25();
std::expected<int, test_error_16> depth_41_error16_percent_25();
std::expected<int, test_error_16> depth_40_error16_percent_25();
std::expected<int, test_error_16> depth_39_error16_percent_25();
std::expected<int, test_error_16> depth_38_error16_percent_25();
std::expected<int, test_error_16> depth_37_error16_percent_25();
std::expected<int, test_error_16> depth_36_error16_percent_25();
std::expected<int, test_error_16> depth_35_error16_percent_25();
std::expected<int, test_error_16> depth_34_error16_percent_25();
std::expected<int, test_error_16> depth_33_error16_percent_25();
std::expected<int, test_error_16> depth_32_error16_percent_25();
std::expected<int, test_error_16> depth_31_error16_percent_25();
std::expected<int, test_error_16> depth_30_error16_percent_25();
std::expected<int, test_error_16> depth_29_error16_percent_25();
std::expected<int, test_error_16> depth_28_error16_percent_25();
std::expected<int, test_error_16> depth_27_error16_percent_25();
std::expected<int, test_error_16> depth_26_error16_percent_25();
std::expected<int, test_error_16> depth_25_error16_percent_25();
std::expected<int, test_error_16> depth_24_error16_percent_25();
std::expected<int, test_error_16> depth_23_error16_percent_25();
std::expected<int, test_error_16> depth_22_error16_percent_25();
std::expected<int, test_error_16> depth_21_error16_percent_25();
std::expected<int, test_error_16> depth_20_error16_percent_25();
std::expected<int, test_error_16> depth_19_error16_percent_25();
std::expected<int, test_error_16> depth_18_error16_percent_25();
std::expected<int, test_error_16> depth_17_error16_percent_25();
std::expected<int, test_error_16> depth_16_error16_percent_25();
std::expected<int, test_error_16> depth_15_error16_percent_25();
std::expected<int, test_error_16> depth_14_error16_percent_25();
std::expected<int, test_error_16> depth_13_error16_percent_25();
std::expected<int, test_error_16> depth_12_error16_percent_25();
std::expected<int, test_error_16> depth_11_error16_percent_25();
std::expected<int, test_error_16> depth_10_error16_percent_25();
std::expected<int, test_error_16> depth_09_error16_percent_25();
std::expected<int, test_error_16> depth_08_error16_percent_25();
std::expected<int, test_error_16> depth_07_error16_percent_25();
std::expected<int, test_error_16> depth_06_error16_percent_25();
std::expected<int, test_error_16> depth_05_error16_percent_25();
std::expected<int, test_error_16> depth_04_error16_percent_25();
std::expected<int, test_error_16> depth_03_error16_percent_25();
std::expected<int, test_error_16> depth_02_error16_percent_25();
std::expected<int, test_error_16> depth_01_error16_percent_25();
[[gnu::noinline]]
std::expected<int, test_error_16> depth_70_error16_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_69_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_69_error16_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_68_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_68_error16_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_67_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_67_error16_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_66_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_66_error16_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_65_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_65_error16_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_64_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_64_error16_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_63_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_63_error16_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_62_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_62_error16_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_61_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_61_error16_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_60_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_60_error16_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_59_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_59_error16_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_58_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_58_error16_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_57_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_57_error16_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_56_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_56_error16_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_55_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_55_error16_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_54_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_54_error16_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_53_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_53_error16_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_52_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_52_error16_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_51_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_51_error16_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_50_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_50_error16_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_49_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_49_error16_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_48_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_48_error16_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_47_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_47_error16_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_46_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_46_error16_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_45_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_45_error16_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_44_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_44_error16_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_43_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_43_error16_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_42_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_42_error16_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_41_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_41_error16_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_40_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_40_error16_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_39_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_39_error16_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_38_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_38_error16_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_37_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_37_error16_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_36_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_36_error16_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_35_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_35_error16_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_34_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_34_error16_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_33_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_33_error16_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_32_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_32_error16_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_31_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_31_error16_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_30_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_30_error16_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_29_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_29_error16_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_28_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_28_error16_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_27_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_27_error16_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_26_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_26_error16_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_25_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_25_error16_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_24_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_24_error16_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_23_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_23_error16_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_22_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_22_error16_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_21_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_21_error16_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_20_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_20_error16_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_19_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_19_error16_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_18_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_18_error16_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_17_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_17_error16_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_16_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_16_error16_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_15_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_15_error16_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_14_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_14_error16_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_13_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_13_error16_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_12_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_12_error16_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_11_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_11_error16_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_10_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_10_error16_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_09_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_09_error16_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_08_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_08_error16_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_07_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_07_error16_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_06_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_06_error16_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_05_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_05_error16_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_04_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_04_error16_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_03_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_03_error16_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_02_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_02_error16_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_01_error16_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_01_error16_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  // This is where the error originates
  start();
  return std::unexpected(test_error_16
                        {
                            .data = { 0xDE, 0xAD, 0xBE, 0xEF }
                        });
}

std::expected<int, test_error_16> depth_70_error16_percent_50();
std::expected<int, test_error_16> depth_69_error16_percent_50();
std::expected<int, test_error_16> depth_68_error16_percent_50();
std::expected<int, test_error_16> depth_67_error16_percent_50();
std::expected<int, test_error_16> depth_66_error16_percent_50();
std::expected<int, test_error_16> depth_65_error16_percent_50();
std::expected<int, test_error_16> depth_64_error16_percent_50();
std::expected<int, test_error_16> depth_63_error16_percent_50();
std::expected<int, test_error_16> depth_62_error16_percent_50();
std::expected<int, test_error_16> depth_61_error16_percent_50();
std::expected<int, test_error_16> depth_60_error16_percent_50();
std::expected<int, test_error_16> depth_59_error16_percent_50();
std::expected<int, test_error_16> depth_58_error16_percent_50();
std::expected<int, test_error_16> depth_57_error16_percent_50();
std::expected<int, test_error_16> depth_56_error16_percent_50();
std::expected<int, test_error_16> depth_55_error16_percent_50();
std::expected<int, test_error_16> depth_54_error16_percent_50();
std::expected<int, test_error_16> depth_53_error16_percent_50();
std::expected<int, test_error_16> depth_52_error16_percent_50();
std::expected<int, test_error_16> depth_51_error16_percent_50();
std::expected<int, test_error_16> depth_50_error16_percent_50();
std::expected<int, test_error_16> depth_49_error16_percent_50();
std::expected<int, test_error_16> depth_48_error16_percent_50();
std::expected<int, test_error_16> depth_47_error16_percent_50();
std::expected<int, test_error_16> depth_46_error16_percent_50();
std::expected<int, test_error_16> depth_45_error16_percent_50();
std::expected<int, test_error_16> depth_44_error16_percent_50();
std::expected<int, test_error_16> depth_43_error16_percent_50();
std::expected<int, test_error_16> depth_42_error16_percent_50();
std::expected<int, test_error_16> depth_41_error16_percent_50();
std::expected<int, test_error_16> depth_40_error16_percent_50();
std::expected<int, test_error_16> depth_39_error16_percent_50();
std::expected<int, test_error_16> depth_38_error16_percent_50();
std::expected<int, test_error_16> depth_37_error16_percent_50();
std::expected<int, test_error_16> depth_36_error16_percent_50();
std::expected<int, test_error_16> depth_35_error16_percent_50();
std::expected<int, test_error_16> depth_34_error16_percent_50();
std::expected<int, test_error_16> depth_33_error16_percent_50();
std::expected<int, test_error_16> depth_32_error16_percent_50();
std::expected<int, test_error_16> depth_31_error16_percent_50();
std::expected<int, test_error_16> depth_30_error16_percent_50();
std::expected<int, test_error_16> depth_29_error16_percent_50();
std::expected<int, test_error_16> depth_28_error16_percent_50();
std::expected<int, test_error_16> depth_27_error16_percent_50();
std::expected<int, test_error_16> depth_26_error16_percent_50();
std::expected<int, test_error_16> depth_25_error16_percent_50();
std::expected<int, test_error_16> depth_24_error16_percent_50();
std::expected<int, test_error_16> depth_23_error16_percent_50();
std::expected<int, test_error_16> depth_22_error16_percent_50();
std::expected<int, test_error_16> depth_21_error16_percent_50();
std::expected<int, test_error_16> depth_20_error16_percent_50();
std::expected<int, test_error_16> depth_19_error16_percent_50();
std::expected<int, test_error_16> depth_18_error16_percent_50();
std::expected<int, test_error_16> depth_17_error16_percent_50();
std::expected<int, test_error_16> depth_16_error16_percent_50();
std::expected<int, test_error_16> depth_15_error16_percent_50();
std::expected<int, test_error_16> depth_14_error16_percent_50();
std::expected<int, test_error_16> depth_13_error16_percent_50();
std::expected<int, test_error_16> depth_12_error16_percent_50();
std::expected<int, test_error_16> depth_11_error16_percent_50();
std::expected<int, test_error_16> depth_10_error16_percent_50();
std::expected<int, test_error_16> depth_09_error16_percent_50();
std::expected<int, test_error_16> depth_08_error16_percent_50();
std::expected<int, test_error_16> depth_07_error16_percent_50();
std::expected<int, test_error_16> depth_06_error16_percent_50();
std::expected<int, test_error_16> depth_05_error16_percent_50();
std::expected<int, test_error_16> depth_04_error16_percent_50();
std::expected<int, test_error_16> depth_03_error16_percent_50();
std::expected<int, test_error_16> depth_02_error16_percent_50();
std::expected<int, test_error_16> depth_01_error16_percent_50();
[[gnu::noinline]]
std::expected<int, test_error_16> depth_70_error16_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_69_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_69_error16_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_68_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_68_error16_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_67_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_67_error16_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_66_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_66_error16_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_65_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_65_error16_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_64_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_64_error16_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_63_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_63_error16_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_62_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_62_error16_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_61_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_61_error16_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_60_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_60_error16_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_59_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_59_error16_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_58_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_58_error16_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_57_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_57_error16_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_56_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_56_error16_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_55_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_55_error16_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_54_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_54_error16_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_53_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_53_error16_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_52_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_52_error16_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_51_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_51_error16_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_50_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_50_error16_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_49_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_49_error16_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_48_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_48_error16_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_47_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_47_error16_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_46_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_46_error16_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_45_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_45_error16_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_44_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_44_error16_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_43_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_43_error16_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_42_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_42_error16_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_41_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_41_error16_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_40_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_40_error16_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_39_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_39_error16_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_38_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_38_error16_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_37_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_37_error16_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_36_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_36_error16_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_35_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_35_error16_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_34_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_34_error16_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_33_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_33_error16_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_32_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_32_error16_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_31_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_31_error16_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_30_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_30_error16_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_29_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_29_error16_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_28_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_28_error16_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_27_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_27_error16_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_26_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_26_error16_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_25_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_25_error16_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_24_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_24_error16_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_23_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_23_error16_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_22_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_22_error16_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_21_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_21_error16_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_20_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_20_error16_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_19_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_19_error16_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_18_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_18_error16_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_17_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_17_error16_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_16_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_16_error16_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_15_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_15_error16_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_14_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_14_error16_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_13_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_13_error16_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_12_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_12_error16_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_11_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_11_error16_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_10_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_10_error16_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_09_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_09_error16_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_08_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_08_error16_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_07_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_07_error16_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_06_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_06_error16_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_05_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_05_error16_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_04_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_04_error16_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_03_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_03_error16_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_02_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_02_error16_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_01_error16_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_01_error16_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  // This is where the error originates
  start();
  return std::unexpected(test_error_16
                        {
                            .data = { 0xDE, 0xAD, 0xBE, 0xEF }
                        });
}

std::expected<int, test_error_16> depth_70_error16_percent_100();
std::expected<int, test_error_16> depth_69_error16_percent_100();
std::expected<int, test_error_16> depth_68_error16_percent_100();
std::expected<int, test_error_16> depth_67_error16_percent_100();
std::expected<int, test_error_16> depth_66_error16_percent_100();
std::expected<int, test_error_16> depth_65_error16_percent_100();
std::expected<int, test_error_16> depth_64_error16_percent_100();
std::expected<int, test_error_16> depth_63_error16_percent_100();
std::expected<int, test_error_16> depth_62_error16_percent_100();
std::expected<int, test_error_16> depth_61_error16_percent_100();
std::expected<int, test_error_16> depth_60_error16_percent_100();
std::expected<int, test_error_16> depth_59_error16_percent_100();
std::expected<int, test_error_16> depth_58_error16_percent_100();
std::expected<int, test_error_16> depth_57_error16_percent_100();
std::expected<int, test_error_16> depth_56_error16_percent_100();
std::expected<int, test_error_16> depth_55_error16_percent_100();
std::expected<int, test_error_16> depth_54_error16_percent_100();
std::expected<int, test_error_16> depth_53_error16_percent_100();
std::expected<int, test_error_16> depth_52_error16_percent_100();
std::expected<int, test_error_16> depth_51_error16_percent_100();
std::expected<int, test_error_16> depth_50_error16_percent_100();
std::expected<int, test_error_16> depth_49_error16_percent_100();
std::expected<int, test_error_16> depth_48_error16_percent_100();
std::expected<int, test_error_16> depth_47_error16_percent_100();
std::expected<int, test_error_16> depth_46_error16_percent_100();
std::expected<int, test_error_16> depth_45_error16_percent_100();
std::expected<int, test_error_16> depth_44_error16_percent_100();
std::expected<int, test_error_16> depth_43_error16_percent_100();
std::expected<int, test_error_16> depth_42_error16_percent_100();
std::expected<int, test_error_16> depth_41_error16_percent_100();
std::expected<int, test_error_16> depth_40_error16_percent_100();
std::expected<int, test_error_16> depth_39_error16_percent_100();
std::expected<int, test_error_16> depth_38_error16_percent_100();
std::expected<int, test_error_16> depth_37_error16_percent_100();
std::expected<int, test_error_16> depth_36_error16_percent_100();
std::expected<int, test_error_16> depth_35_error16_percent_100();
std::expected<int, test_error_16> depth_34_error16_percent_100();
std::expected<int, test_error_16> depth_33_error16_percent_100();
std::expected<int, test_error_16> depth_32_error16_percent_100();
std::expected<int, test_error_16> depth_31_error16_percent_100();
std::expected<int, test_error_16> depth_30_error16_percent_100();
std::expected<int, test_error_16> depth_29_error16_percent_100();
std::expected<int, test_error_16> depth_28_error16_percent_100();
std::expected<int, test_error_16> depth_27_error16_percent_100();
std::expected<int, test_error_16> depth_26_error16_percent_100();
std::expected<int, test_error_16> depth_25_error16_percent_100();
std::expected<int, test_error_16> depth_24_error16_percent_100();
std::expected<int, test_error_16> depth_23_error16_percent_100();
std::expected<int, test_error_16> depth_22_error16_percent_100();
std::expected<int, test_error_16> depth_21_error16_percent_100();
std::expected<int, test_error_16> depth_20_error16_percent_100();
std::expected<int, test_error_16> depth_19_error16_percent_100();
std::expected<int, test_error_16> depth_18_error16_percent_100();
std::expected<int, test_error_16> depth_17_error16_percent_100();
std::expected<int, test_error_16> depth_16_error16_percent_100();
std::expected<int, test_error_16> depth_15_error16_percent_100();
std::expected<int, test_error_16> depth_14_error16_percent_100();
std::expected<int, test_error_16> depth_13_error16_percent_100();
std::expected<int, test_error_16> depth_12_error16_percent_100();
std::expected<int, test_error_16> depth_11_error16_percent_100();
std::expected<int, test_error_16> depth_10_error16_percent_100();
std::expected<int, test_error_16> depth_09_error16_percent_100();
std::expected<int, test_error_16> depth_08_error16_percent_100();
std::expected<int, test_error_16> depth_07_error16_percent_100();
std::expected<int, test_error_16> depth_06_error16_percent_100();
std::expected<int, test_error_16> depth_05_error16_percent_100();
std::expected<int, test_error_16> depth_04_error16_percent_100();
std::expected<int, test_error_16> depth_03_error16_percent_100();
std::expected<int, test_error_16> depth_02_error16_percent_100();
std::expected<int, test_error_16> depth_01_error16_percent_100();
[[gnu::noinline]]
std::expected<int, test_error_16> depth_70_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_69_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_69_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_68_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_68_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_67_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_67_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_66_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_66_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_65_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_65_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_64_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_64_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_63_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_63_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_62_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_62_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_61_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_61_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_60_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_60_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_59_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_59_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_58_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_58_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_57_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_57_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_56_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_56_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_55_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_55_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_54_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_54_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_53_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_53_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_52_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_52_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_51_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_51_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_50_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_50_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_49_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_49_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_48_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_48_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_47_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_47_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_46_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_46_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_45_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_45_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_44_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_44_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_43_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_43_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_42_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_42_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_41_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_41_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_40_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_40_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_39_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_39_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_38_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_38_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_37_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_37_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_36_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_36_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_35_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_35_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_34_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_34_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_33_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_33_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_32_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_32_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_31_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_31_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_30_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_30_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_29_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_29_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_28_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_28_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_27_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_27_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_26_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_26_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_25_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_25_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_24_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_24_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_23_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_23_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_22_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_22_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_21_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_21_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_20_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_20_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_19_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_19_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_18_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_18_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_17_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_17_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_16_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_16_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_15_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_15_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_14_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_14_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_13_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_13_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_12_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_12_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_11_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_11_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_10_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_10_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_09_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_09_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_08_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_08_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_07_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_07_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_06_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_06_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_05_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_05_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_04_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_04_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_03_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_03_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_02_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_02_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_01_error16_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_16> depth_01_error16_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  // This is where the error originates
  start();
  return std::unexpected(test_error_16
                        {
                            .data = { 0xDE, 0xAD, 0xBE, 0xEF }
                        });
}

// Test runner
[[gnu::noinline]]
void run_test_depth60_error16_cleanup_0() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_60_error16_percent_0();
    if (!result) {
        end();
    } else {
        pause(); // Should have gotten an error
    }
}

[[gnu::noinline]]
void run_test_depth40_error16_cleanup_0() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_40_error16_percent_0();
    if (!result) {
        end();
    } else {
        pause();
    }
}

[[gnu::noinline]]
void run_test_depth20_error16_cleanup_0() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_20_error16_percent_0();
    if (!result) {
        end();
    } else {
        pause();
    }
}

[[gnu::noinline]]
void run_test_depth10_error16_cleanup_0() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_10_error16_percent_0();
    if (!result) {
        end();
    } else {
        pause();
    }
}

[[gnu::noinline]]
void run_test_depth01_error16_cleanup_0() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_01_error16_percent_0();
    if (!result) {
        end();
    } else {
        pause();
    }
}

void run_test_error16_cleanup_0() {
    run_test_depth60_error16_cleanup_0();
    run_test_depth40_error16_cleanup_0();
    run_test_depth20_error16_cleanup_0();
    run_test_depth10_error16_cleanup_0();
    run_test_depth01_error16_cleanup_0();
}
// Test runner
[[gnu::noinline]]
void run_test_depth60_error16_cleanup_25() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_60_error16_percent_25();
    if (!result) {
        end();
    } else {
        pause(); // Should have gotten an error
    }
}

[[gnu::noinline]]
void run_test_depth40_error16_cleanup_25() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_40_error16_percent_25();
    if (!result) {
        end();
    } else {
        pause();
    }
}

[[gnu::noinline]]
void run_test_depth20_error16_cleanup_25() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_20_error16_percent_25();
    if (!result) {
        end();
    } else {
        pause();
    }
}

[[gnu::noinline]]
void run_test_depth10_error16_cleanup_25() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_10_error16_percent_25();
    if (!result) {
        end();
    } else {
        pause();
    }
}

[[gnu::noinline]]
void run_test_depth01_error16_cleanup_25() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_01_error16_percent_25();
    if (!result) {
        end();
    } else {
        pause();
    }
}

void run_test_error16_cleanup_25() {
    run_test_depth60_error16_cleanup_25();
    run_test_depth40_error16_cleanup_25();
    run_test_depth20_error16_cleanup_25();
    run_test_depth10_error16_cleanup_25();
    run_test_depth01_error16_cleanup_25();
}
// Test runner
[[gnu::noinline]]
void run_test_depth60_error16_cleanup_50() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_60_error16_percent_50();
    if (!result) {
        end();
    } else {
        pause(); // Should have gotten an error
    }
}

[[gnu::noinline]]
void run_test_depth40_error16_cleanup_50() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_40_error16_percent_50();
    if (!result) {
        end();
    } else {
        pause();
    }
}

[[gnu::noinline]]
void run_test_depth20_error16_cleanup_50() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_20_error16_percent_50();
    if (!result) {
        end();
    } else {
        pause();
    }
}

[[gnu::noinline]]
void run_test_depth10_error16_cleanup_50() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_10_error16_percent_50();
    if (!result) {
        end();
    } else {
        pause();
    }
}

[[gnu::noinline]]
void run_test_depth01_error16_cleanup_50() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_01_error16_percent_50();
    if (!result) {
        end();
    } else {
        pause();
    }
}

void run_test_error16_cleanup_50() {
    run_test_depth60_error16_cleanup_50();
    run_test_depth40_error16_cleanup_50();
    run_test_depth20_error16_cleanup_50();
    run_test_depth10_error16_cleanup_50();
    run_test_depth01_error16_cleanup_50();
}
// Test runner
[[gnu::noinline]]
void run_test_depth60_error16_cleanup_100() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_60_error16_percent_100();
    if (!result) {
        end();
    } else {
        pause(); // Should have gotten an error
    }
}

[[gnu::noinline]]
void run_test_depth40_error16_cleanup_100() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_40_error16_percent_100();
    if (!result) {
        end();
    } else {
        pause();
    }
}

[[gnu::noinline]]
void run_test_depth20_error16_cleanup_100() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_20_error16_percent_100();
    if (!result) {
        end();
    } else {
        pause();
    }
}

[[gnu::noinline]]
void run_test_depth10_error16_cleanup_100() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_10_error16_percent_100();
    if (!result) {
        end();
    } else {
        pause();
    }
}

[[gnu::noinline]]
void run_test_depth01_error16_cleanup_100() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_01_error16_percent_100();
    if (!result) {
        end();
    } else {
        pause();
    }
}

void run_test_error16_cleanup_100() {
    run_test_depth60_error16_cleanup_100();
    run_test_depth40_error16_cleanup_100();
    run_test_depth20_error16_cleanup_100();
    run_test_depth10_error16_cleanup_100();
    run_test_depth01_error16_cleanup_100();
}
// Test runner
void run_test() {
    run_test_error16_cleanup_0();
    run_test_error16_cleanup_25();
    run_test_error16_cleanup_50();
    run_test_error16_cleanup_100();

}

