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
struct test_error_65 {
  std::array<std::uint8_t, 65> data;
};
std::expected<int, test_error_65> depth_70_error65_percent_0();
std::expected<int, test_error_65> depth_69_error65_percent_0();
std::expected<int, test_error_65> depth_68_error65_percent_0();
std::expected<int, test_error_65> depth_67_error65_percent_0();
std::expected<int, test_error_65> depth_66_error65_percent_0();
std::expected<int, test_error_65> depth_65_error65_percent_0();
std::expected<int, test_error_65> depth_64_error65_percent_0();
std::expected<int, test_error_65> depth_63_error65_percent_0();
std::expected<int, test_error_65> depth_62_error65_percent_0();
std::expected<int, test_error_65> depth_61_error65_percent_0();
std::expected<int, test_error_65> depth_60_error65_percent_0();
std::expected<int, test_error_65> depth_59_error65_percent_0();
std::expected<int, test_error_65> depth_58_error65_percent_0();
std::expected<int, test_error_65> depth_57_error65_percent_0();
std::expected<int, test_error_65> depth_56_error65_percent_0();
std::expected<int, test_error_65> depth_55_error65_percent_0();
std::expected<int, test_error_65> depth_54_error65_percent_0();
std::expected<int, test_error_65> depth_53_error65_percent_0();
std::expected<int, test_error_65> depth_52_error65_percent_0();
std::expected<int, test_error_65> depth_51_error65_percent_0();
std::expected<int, test_error_65> depth_50_error65_percent_0();
std::expected<int, test_error_65> depth_49_error65_percent_0();
std::expected<int, test_error_65> depth_48_error65_percent_0();
std::expected<int, test_error_65> depth_47_error65_percent_0();
std::expected<int, test_error_65> depth_46_error65_percent_0();
std::expected<int, test_error_65> depth_45_error65_percent_0();
std::expected<int, test_error_65> depth_44_error65_percent_0();
std::expected<int, test_error_65> depth_43_error65_percent_0();
std::expected<int, test_error_65> depth_42_error65_percent_0();
std::expected<int, test_error_65> depth_41_error65_percent_0();
std::expected<int, test_error_65> depth_40_error65_percent_0();
std::expected<int, test_error_65> depth_39_error65_percent_0();
std::expected<int, test_error_65> depth_38_error65_percent_0();
std::expected<int, test_error_65> depth_37_error65_percent_0();
std::expected<int, test_error_65> depth_36_error65_percent_0();
std::expected<int, test_error_65> depth_35_error65_percent_0();
std::expected<int, test_error_65> depth_34_error65_percent_0();
std::expected<int, test_error_65> depth_33_error65_percent_0();
std::expected<int, test_error_65> depth_32_error65_percent_0();
std::expected<int, test_error_65> depth_31_error65_percent_0();
std::expected<int, test_error_65> depth_30_error65_percent_0();
std::expected<int, test_error_65> depth_29_error65_percent_0();
std::expected<int, test_error_65> depth_28_error65_percent_0();
std::expected<int, test_error_65> depth_27_error65_percent_0();
std::expected<int, test_error_65> depth_26_error65_percent_0();
std::expected<int, test_error_65> depth_25_error65_percent_0();
std::expected<int, test_error_65> depth_24_error65_percent_0();
std::expected<int, test_error_65> depth_23_error65_percent_0();
std::expected<int, test_error_65> depth_22_error65_percent_0();
std::expected<int, test_error_65> depth_21_error65_percent_0();
std::expected<int, test_error_65> depth_20_error65_percent_0();
std::expected<int, test_error_65> depth_19_error65_percent_0();
std::expected<int, test_error_65> depth_18_error65_percent_0();
std::expected<int, test_error_65> depth_17_error65_percent_0();
std::expected<int, test_error_65> depth_16_error65_percent_0();
std::expected<int, test_error_65> depth_15_error65_percent_0();
std::expected<int, test_error_65> depth_14_error65_percent_0();
std::expected<int, test_error_65> depth_13_error65_percent_0();
std::expected<int, test_error_65> depth_12_error65_percent_0();
std::expected<int, test_error_65> depth_11_error65_percent_0();
std::expected<int, test_error_65> depth_10_error65_percent_0();
std::expected<int, test_error_65> depth_09_error65_percent_0();
std::expected<int, test_error_65> depth_08_error65_percent_0();
std::expected<int, test_error_65> depth_07_error65_percent_0();
std::expected<int, test_error_65> depth_06_error65_percent_0();
std::expected<int, test_error_65> depth_05_error65_percent_0();
std::expected<int, test_error_65> depth_04_error65_percent_0();
std::expected<int, test_error_65> depth_03_error65_percent_0();
std::expected<int, test_error_65> depth_02_error65_percent_0();
std::expected<int, test_error_65> depth_01_error65_percent_0();
[[gnu::noinline]]
std::expected<int, test_error_65> depth_70_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_69_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_69_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_68_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_68_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_67_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_67_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_66_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_66_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_65_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_65_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_64_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_64_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_63_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_63_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_62_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_62_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_61_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_61_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_60_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_60_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_59_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_59_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_58_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_58_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_57_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_57_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_56_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_56_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_55_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_55_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_54_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_54_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_53_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_53_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_52_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_52_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_51_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_51_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_50_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_50_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_49_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_49_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_48_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_48_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_47_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_47_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_46_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_46_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_45_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_45_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_44_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_44_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_43_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_43_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_42_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_42_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_41_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_41_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_40_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_40_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_39_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_39_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_38_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_38_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_37_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_37_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_36_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_36_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_35_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_35_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_34_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_34_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_33_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_33_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_32_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_32_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_31_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_31_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_30_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_30_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_29_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_29_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_28_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_28_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_27_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_27_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_26_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_26_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_25_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_25_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_24_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_24_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_23_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_23_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_22_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_22_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_21_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_21_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_20_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_20_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_19_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_19_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_18_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_18_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_17_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_17_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_16_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_16_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_15_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_15_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_14_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_14_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_13_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_13_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_12_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_12_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_11_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_11_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_10_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_10_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_09_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_09_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_08_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_08_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_07_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_07_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_06_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_06_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_05_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_05_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_04_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_04_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_03_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_03_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_02_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_02_error65_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_01_error65_percent_0();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_01_error65_percent_0() {
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
  return std::unexpected(test_error_65
                        {
                            .data = { 0xDE, 0xAD, 0xBE, 0xEF }
                        });
}

std::expected<int, test_error_65> depth_70_error65_percent_25();
std::expected<int, test_error_65> depth_69_error65_percent_25();
std::expected<int, test_error_65> depth_68_error65_percent_25();
std::expected<int, test_error_65> depth_67_error65_percent_25();
std::expected<int, test_error_65> depth_66_error65_percent_25();
std::expected<int, test_error_65> depth_65_error65_percent_25();
std::expected<int, test_error_65> depth_64_error65_percent_25();
std::expected<int, test_error_65> depth_63_error65_percent_25();
std::expected<int, test_error_65> depth_62_error65_percent_25();
std::expected<int, test_error_65> depth_61_error65_percent_25();
std::expected<int, test_error_65> depth_60_error65_percent_25();
std::expected<int, test_error_65> depth_59_error65_percent_25();
std::expected<int, test_error_65> depth_58_error65_percent_25();
std::expected<int, test_error_65> depth_57_error65_percent_25();
std::expected<int, test_error_65> depth_56_error65_percent_25();
std::expected<int, test_error_65> depth_55_error65_percent_25();
std::expected<int, test_error_65> depth_54_error65_percent_25();
std::expected<int, test_error_65> depth_53_error65_percent_25();
std::expected<int, test_error_65> depth_52_error65_percent_25();
std::expected<int, test_error_65> depth_51_error65_percent_25();
std::expected<int, test_error_65> depth_50_error65_percent_25();
std::expected<int, test_error_65> depth_49_error65_percent_25();
std::expected<int, test_error_65> depth_48_error65_percent_25();
std::expected<int, test_error_65> depth_47_error65_percent_25();
std::expected<int, test_error_65> depth_46_error65_percent_25();
std::expected<int, test_error_65> depth_45_error65_percent_25();
std::expected<int, test_error_65> depth_44_error65_percent_25();
std::expected<int, test_error_65> depth_43_error65_percent_25();
std::expected<int, test_error_65> depth_42_error65_percent_25();
std::expected<int, test_error_65> depth_41_error65_percent_25();
std::expected<int, test_error_65> depth_40_error65_percent_25();
std::expected<int, test_error_65> depth_39_error65_percent_25();
std::expected<int, test_error_65> depth_38_error65_percent_25();
std::expected<int, test_error_65> depth_37_error65_percent_25();
std::expected<int, test_error_65> depth_36_error65_percent_25();
std::expected<int, test_error_65> depth_35_error65_percent_25();
std::expected<int, test_error_65> depth_34_error65_percent_25();
std::expected<int, test_error_65> depth_33_error65_percent_25();
std::expected<int, test_error_65> depth_32_error65_percent_25();
std::expected<int, test_error_65> depth_31_error65_percent_25();
std::expected<int, test_error_65> depth_30_error65_percent_25();
std::expected<int, test_error_65> depth_29_error65_percent_25();
std::expected<int, test_error_65> depth_28_error65_percent_25();
std::expected<int, test_error_65> depth_27_error65_percent_25();
std::expected<int, test_error_65> depth_26_error65_percent_25();
std::expected<int, test_error_65> depth_25_error65_percent_25();
std::expected<int, test_error_65> depth_24_error65_percent_25();
std::expected<int, test_error_65> depth_23_error65_percent_25();
std::expected<int, test_error_65> depth_22_error65_percent_25();
std::expected<int, test_error_65> depth_21_error65_percent_25();
std::expected<int, test_error_65> depth_20_error65_percent_25();
std::expected<int, test_error_65> depth_19_error65_percent_25();
std::expected<int, test_error_65> depth_18_error65_percent_25();
std::expected<int, test_error_65> depth_17_error65_percent_25();
std::expected<int, test_error_65> depth_16_error65_percent_25();
std::expected<int, test_error_65> depth_15_error65_percent_25();
std::expected<int, test_error_65> depth_14_error65_percent_25();
std::expected<int, test_error_65> depth_13_error65_percent_25();
std::expected<int, test_error_65> depth_12_error65_percent_25();
std::expected<int, test_error_65> depth_11_error65_percent_25();
std::expected<int, test_error_65> depth_10_error65_percent_25();
std::expected<int, test_error_65> depth_09_error65_percent_25();
std::expected<int, test_error_65> depth_08_error65_percent_25();
std::expected<int, test_error_65> depth_07_error65_percent_25();
std::expected<int, test_error_65> depth_06_error65_percent_25();
std::expected<int, test_error_65> depth_05_error65_percent_25();
std::expected<int, test_error_65> depth_04_error65_percent_25();
std::expected<int, test_error_65> depth_03_error65_percent_25();
std::expected<int, test_error_65> depth_02_error65_percent_25();
std::expected<int, test_error_65> depth_01_error65_percent_25();
[[gnu::noinline]]
std::expected<int, test_error_65> depth_70_error65_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_69_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_69_error65_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_68_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_68_error65_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_67_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_67_error65_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_66_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_66_error65_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_65_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_65_error65_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_64_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_64_error65_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_63_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_63_error65_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_62_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_62_error65_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_61_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_61_error65_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_60_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_60_error65_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_59_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_59_error65_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_58_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_58_error65_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_57_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_57_error65_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_56_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_56_error65_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_55_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_55_error65_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_54_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_54_error65_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_53_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_53_error65_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_52_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_52_error65_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_51_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_51_error65_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_50_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_50_error65_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_49_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_49_error65_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_48_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_48_error65_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_47_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_47_error65_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_46_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_46_error65_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_45_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_45_error65_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_44_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_44_error65_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_43_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_43_error65_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_42_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_42_error65_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_41_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_41_error65_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_40_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_40_error65_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_39_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_39_error65_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_38_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_38_error65_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_37_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_37_error65_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_36_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_36_error65_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_35_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_35_error65_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_34_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_34_error65_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_33_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_33_error65_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_32_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_32_error65_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_31_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_31_error65_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_30_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_30_error65_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_29_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_29_error65_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_28_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_28_error65_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_27_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_27_error65_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_26_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_26_error65_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_25_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_25_error65_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_24_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_24_error65_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_23_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_23_error65_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_22_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_22_error65_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_21_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_21_error65_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_20_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_20_error65_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_19_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_19_error65_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_18_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_18_error65_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_17_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_17_error65_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_16_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_16_error65_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_15_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_15_error65_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_14_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_14_error65_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_13_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_13_error65_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_12_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_12_error65_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_11_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_11_error65_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_10_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_10_error65_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_09_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_09_error65_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_08_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_08_error65_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_07_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_07_error65_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_06_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_06_error65_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_05_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_05_error65_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_04_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_04_error65_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_03_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_03_error65_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_02_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_02_error65_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_01_error65_percent_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_01_error65_percent_25() {
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
  return std::unexpected(test_error_65
                        {
                            .data = { 0xDE, 0xAD, 0xBE, 0xEF }
                        });
}

std::expected<int, test_error_65> depth_70_error65_percent_50();
std::expected<int, test_error_65> depth_69_error65_percent_50();
std::expected<int, test_error_65> depth_68_error65_percent_50();
std::expected<int, test_error_65> depth_67_error65_percent_50();
std::expected<int, test_error_65> depth_66_error65_percent_50();
std::expected<int, test_error_65> depth_65_error65_percent_50();
std::expected<int, test_error_65> depth_64_error65_percent_50();
std::expected<int, test_error_65> depth_63_error65_percent_50();
std::expected<int, test_error_65> depth_62_error65_percent_50();
std::expected<int, test_error_65> depth_61_error65_percent_50();
std::expected<int, test_error_65> depth_60_error65_percent_50();
std::expected<int, test_error_65> depth_59_error65_percent_50();
std::expected<int, test_error_65> depth_58_error65_percent_50();
std::expected<int, test_error_65> depth_57_error65_percent_50();
std::expected<int, test_error_65> depth_56_error65_percent_50();
std::expected<int, test_error_65> depth_55_error65_percent_50();
std::expected<int, test_error_65> depth_54_error65_percent_50();
std::expected<int, test_error_65> depth_53_error65_percent_50();
std::expected<int, test_error_65> depth_52_error65_percent_50();
std::expected<int, test_error_65> depth_51_error65_percent_50();
std::expected<int, test_error_65> depth_50_error65_percent_50();
std::expected<int, test_error_65> depth_49_error65_percent_50();
std::expected<int, test_error_65> depth_48_error65_percent_50();
std::expected<int, test_error_65> depth_47_error65_percent_50();
std::expected<int, test_error_65> depth_46_error65_percent_50();
std::expected<int, test_error_65> depth_45_error65_percent_50();
std::expected<int, test_error_65> depth_44_error65_percent_50();
std::expected<int, test_error_65> depth_43_error65_percent_50();
std::expected<int, test_error_65> depth_42_error65_percent_50();
std::expected<int, test_error_65> depth_41_error65_percent_50();
std::expected<int, test_error_65> depth_40_error65_percent_50();
std::expected<int, test_error_65> depth_39_error65_percent_50();
std::expected<int, test_error_65> depth_38_error65_percent_50();
std::expected<int, test_error_65> depth_37_error65_percent_50();
std::expected<int, test_error_65> depth_36_error65_percent_50();
std::expected<int, test_error_65> depth_35_error65_percent_50();
std::expected<int, test_error_65> depth_34_error65_percent_50();
std::expected<int, test_error_65> depth_33_error65_percent_50();
std::expected<int, test_error_65> depth_32_error65_percent_50();
std::expected<int, test_error_65> depth_31_error65_percent_50();
std::expected<int, test_error_65> depth_30_error65_percent_50();
std::expected<int, test_error_65> depth_29_error65_percent_50();
std::expected<int, test_error_65> depth_28_error65_percent_50();
std::expected<int, test_error_65> depth_27_error65_percent_50();
std::expected<int, test_error_65> depth_26_error65_percent_50();
std::expected<int, test_error_65> depth_25_error65_percent_50();
std::expected<int, test_error_65> depth_24_error65_percent_50();
std::expected<int, test_error_65> depth_23_error65_percent_50();
std::expected<int, test_error_65> depth_22_error65_percent_50();
std::expected<int, test_error_65> depth_21_error65_percent_50();
std::expected<int, test_error_65> depth_20_error65_percent_50();
std::expected<int, test_error_65> depth_19_error65_percent_50();
std::expected<int, test_error_65> depth_18_error65_percent_50();
std::expected<int, test_error_65> depth_17_error65_percent_50();
std::expected<int, test_error_65> depth_16_error65_percent_50();
std::expected<int, test_error_65> depth_15_error65_percent_50();
std::expected<int, test_error_65> depth_14_error65_percent_50();
std::expected<int, test_error_65> depth_13_error65_percent_50();
std::expected<int, test_error_65> depth_12_error65_percent_50();
std::expected<int, test_error_65> depth_11_error65_percent_50();
std::expected<int, test_error_65> depth_10_error65_percent_50();
std::expected<int, test_error_65> depth_09_error65_percent_50();
std::expected<int, test_error_65> depth_08_error65_percent_50();
std::expected<int, test_error_65> depth_07_error65_percent_50();
std::expected<int, test_error_65> depth_06_error65_percent_50();
std::expected<int, test_error_65> depth_05_error65_percent_50();
std::expected<int, test_error_65> depth_04_error65_percent_50();
std::expected<int, test_error_65> depth_03_error65_percent_50();
std::expected<int, test_error_65> depth_02_error65_percent_50();
std::expected<int, test_error_65> depth_01_error65_percent_50();
[[gnu::noinline]]
std::expected<int, test_error_65> depth_70_error65_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_69_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_69_error65_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_68_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_68_error65_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_67_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_67_error65_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_66_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_66_error65_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_65_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_65_error65_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_64_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_64_error65_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_63_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_63_error65_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_62_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_62_error65_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_61_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_61_error65_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_60_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_60_error65_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_59_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_59_error65_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_58_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_58_error65_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_57_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_57_error65_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_56_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_56_error65_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_55_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_55_error65_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_54_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_54_error65_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_53_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_53_error65_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_52_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_52_error65_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_51_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_51_error65_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_50_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_50_error65_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_49_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_49_error65_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_48_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_48_error65_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_47_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_47_error65_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_46_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_46_error65_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_45_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_45_error65_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_44_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_44_error65_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_43_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_43_error65_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_42_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_42_error65_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_41_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_41_error65_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_40_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_40_error65_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_39_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_39_error65_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_38_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_38_error65_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_37_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_37_error65_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_36_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_36_error65_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_35_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_35_error65_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_34_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_34_error65_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_33_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_33_error65_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_32_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_32_error65_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_31_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_31_error65_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_30_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_30_error65_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_29_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_29_error65_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_28_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_28_error65_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_27_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_27_error65_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_26_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_26_error65_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_25_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_25_error65_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_24_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_24_error65_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_23_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_23_error65_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_22_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_22_error65_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_21_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_21_error65_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_20_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_20_error65_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_19_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_19_error65_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_18_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_18_error65_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_17_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_17_error65_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_16_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_16_error65_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_15_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_15_error65_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_14_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_14_error65_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_13_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_13_error65_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_12_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_12_error65_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_11_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_11_error65_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_10_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_10_error65_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_09_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_09_error65_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_08_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_08_error65_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_07_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_07_error65_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_06_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_06_error65_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_05_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_05_error65_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_04_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_04_error65_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_03_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_03_error65_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_02_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_02_error65_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_01_error65_percent_50();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_01_error65_percent_50() {
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
  return std::unexpected(test_error_65
                        {
                            .data = { 0xDE, 0xAD, 0xBE, 0xEF }
                        });
}

std::expected<int, test_error_65> depth_70_error65_percent_100();
std::expected<int, test_error_65> depth_69_error65_percent_100();
std::expected<int, test_error_65> depth_68_error65_percent_100();
std::expected<int, test_error_65> depth_67_error65_percent_100();
std::expected<int, test_error_65> depth_66_error65_percent_100();
std::expected<int, test_error_65> depth_65_error65_percent_100();
std::expected<int, test_error_65> depth_64_error65_percent_100();
std::expected<int, test_error_65> depth_63_error65_percent_100();
std::expected<int, test_error_65> depth_62_error65_percent_100();
std::expected<int, test_error_65> depth_61_error65_percent_100();
std::expected<int, test_error_65> depth_60_error65_percent_100();
std::expected<int, test_error_65> depth_59_error65_percent_100();
std::expected<int, test_error_65> depth_58_error65_percent_100();
std::expected<int, test_error_65> depth_57_error65_percent_100();
std::expected<int, test_error_65> depth_56_error65_percent_100();
std::expected<int, test_error_65> depth_55_error65_percent_100();
std::expected<int, test_error_65> depth_54_error65_percent_100();
std::expected<int, test_error_65> depth_53_error65_percent_100();
std::expected<int, test_error_65> depth_52_error65_percent_100();
std::expected<int, test_error_65> depth_51_error65_percent_100();
std::expected<int, test_error_65> depth_50_error65_percent_100();
std::expected<int, test_error_65> depth_49_error65_percent_100();
std::expected<int, test_error_65> depth_48_error65_percent_100();
std::expected<int, test_error_65> depth_47_error65_percent_100();
std::expected<int, test_error_65> depth_46_error65_percent_100();
std::expected<int, test_error_65> depth_45_error65_percent_100();
std::expected<int, test_error_65> depth_44_error65_percent_100();
std::expected<int, test_error_65> depth_43_error65_percent_100();
std::expected<int, test_error_65> depth_42_error65_percent_100();
std::expected<int, test_error_65> depth_41_error65_percent_100();
std::expected<int, test_error_65> depth_40_error65_percent_100();
std::expected<int, test_error_65> depth_39_error65_percent_100();
std::expected<int, test_error_65> depth_38_error65_percent_100();
std::expected<int, test_error_65> depth_37_error65_percent_100();
std::expected<int, test_error_65> depth_36_error65_percent_100();
std::expected<int, test_error_65> depth_35_error65_percent_100();
std::expected<int, test_error_65> depth_34_error65_percent_100();
std::expected<int, test_error_65> depth_33_error65_percent_100();
std::expected<int, test_error_65> depth_32_error65_percent_100();
std::expected<int, test_error_65> depth_31_error65_percent_100();
std::expected<int, test_error_65> depth_30_error65_percent_100();
std::expected<int, test_error_65> depth_29_error65_percent_100();
std::expected<int, test_error_65> depth_28_error65_percent_100();
std::expected<int, test_error_65> depth_27_error65_percent_100();
std::expected<int, test_error_65> depth_26_error65_percent_100();
std::expected<int, test_error_65> depth_25_error65_percent_100();
std::expected<int, test_error_65> depth_24_error65_percent_100();
std::expected<int, test_error_65> depth_23_error65_percent_100();
std::expected<int, test_error_65> depth_22_error65_percent_100();
std::expected<int, test_error_65> depth_21_error65_percent_100();
std::expected<int, test_error_65> depth_20_error65_percent_100();
std::expected<int, test_error_65> depth_19_error65_percent_100();
std::expected<int, test_error_65> depth_18_error65_percent_100();
std::expected<int, test_error_65> depth_17_error65_percent_100();
std::expected<int, test_error_65> depth_16_error65_percent_100();
std::expected<int, test_error_65> depth_15_error65_percent_100();
std::expected<int, test_error_65> depth_14_error65_percent_100();
std::expected<int, test_error_65> depth_13_error65_percent_100();
std::expected<int, test_error_65> depth_12_error65_percent_100();
std::expected<int, test_error_65> depth_11_error65_percent_100();
std::expected<int, test_error_65> depth_10_error65_percent_100();
std::expected<int, test_error_65> depth_09_error65_percent_100();
std::expected<int, test_error_65> depth_08_error65_percent_100();
std::expected<int, test_error_65> depth_07_error65_percent_100();
std::expected<int, test_error_65> depth_06_error65_percent_100();
std::expected<int, test_error_65> depth_05_error65_percent_100();
std::expected<int, test_error_65> depth_04_error65_percent_100();
std::expected<int, test_error_65> depth_03_error65_percent_100();
std::expected<int, test_error_65> depth_02_error65_percent_100();
std::expected<int, test_error_65> depth_01_error65_percent_100();
[[gnu::noinline]]
std::expected<int, test_error_65> depth_70_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_69_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_69_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_68_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_68_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_67_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_67_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_66_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_66_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_65_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_65_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_64_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_64_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_63_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_63_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_62_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_62_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_61_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_61_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_60_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_60_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_59_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_59_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_58_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_58_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_57_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_57_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_56_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_56_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_55_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_55_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_54_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_54_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_53_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_53_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_52_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_52_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_51_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_51_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_50_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_50_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_49_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_49_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_48_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_48_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_47_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_47_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_46_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_46_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_45_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_45_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_44_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_44_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_43_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_43_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_42_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_42_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_41_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_41_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_40_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_40_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_39_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_39_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_38_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_38_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_37_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_37_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_36_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_36_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_35_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_35_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_34_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_34_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_33_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_33_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_32_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_32_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_31_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_31_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_30_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_30_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_29_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_29_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_28_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_28_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_27_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_27_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_26_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_26_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_25_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_25_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_24_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_24_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_23_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_23_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_22_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_22_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_21_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_21_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_20_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_20_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_19_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_19_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_18_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_18_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_17_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_17_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_16_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_16_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_15_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_15_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_14_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_14_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_13_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_13_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_12_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_12_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_11_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_11_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_10_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_10_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_09_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_09_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_08_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_08_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_07_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_07_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_06_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_06_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_05_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_05_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_04_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_04_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_03_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_03_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_02_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_02_error65_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return -1;
  }

  auto result = depth_01_error65_percent_100();

  // Use the variable after the call
  if (preserve_frame < 0) {
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_65> depth_01_error65_percent_100() {
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
  return std::unexpected(test_error_65
                        {
                            .data = { 0xDE, 0xAD, 0xBE, 0xEF }
                        });
}

// Test runner
[[gnu::noinline]]
void run_test_depth60_error65_cleanup_0() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_60_error65_percent_0();
    if (!result) {
        end();
    } else {
        pause(); // Should have gotten an error
    }
}

[[gnu::noinline]]
void run_test_depth40_error65_cleanup_0() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_40_error65_percent_0();
    if (!result) {
        end();
    } else {
        pause();
    }
}

[[gnu::noinline]]
void run_test_depth20_error65_cleanup_0() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_20_error65_percent_0();
    if (!result) {
        end();
    } else {
        pause();
    }
}

[[gnu::noinline]]
void run_test_depth10_error65_cleanup_0() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_10_error65_percent_0();
    if (!result) {
        end();
    } else {
        pause();
    }
}

[[gnu::noinline]]
void run_test_depth01_error65_cleanup_0() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_01_error65_percent_0();
    if (!result) {
        end();
    } else {
        pause();
    }
}

void run_test_error65_cleanup_0() {
    run_test_depth60_error65_cleanup_0();
    run_test_depth40_error65_cleanup_0();
    run_test_depth20_error65_cleanup_0();
    run_test_depth10_error65_cleanup_0();
    run_test_depth01_error65_cleanup_0();
}
// Test runner
[[gnu::noinline]]
void run_test_depth60_error65_cleanup_25() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_60_error65_percent_25();
    if (!result) {
        end();
    } else {
        pause(); // Should have gotten an error
    }
}

[[gnu::noinline]]
void run_test_depth40_error65_cleanup_25() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_40_error65_percent_25();
    if (!result) {
        end();
    } else {
        pause();
    }
}

[[gnu::noinline]]
void run_test_depth20_error65_cleanup_25() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_20_error65_percent_25();
    if (!result) {
        end();
    } else {
        pause();
    }
}

[[gnu::noinline]]
void run_test_depth10_error65_cleanup_25() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_10_error65_percent_25();
    if (!result) {
        end();
    } else {
        pause();
    }
}

[[gnu::noinline]]
void run_test_depth01_error65_cleanup_25() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_01_error65_percent_25();
    if (!result) {
        end();
    } else {
        pause();
    }
}

void run_test_error65_cleanup_25() {
    run_test_depth60_error65_cleanup_25();
    run_test_depth40_error65_cleanup_25();
    run_test_depth20_error65_cleanup_25();
    run_test_depth10_error65_cleanup_25();
    run_test_depth01_error65_cleanup_25();
}
// Test runner
[[gnu::noinline]]
void run_test_depth60_error65_cleanup_50() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_60_error65_percent_50();
    if (!result) {
        end();
    } else {
        pause(); // Should have gotten an error
    }
}

[[gnu::noinline]]
void run_test_depth40_error65_cleanup_50() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_40_error65_percent_50();
    if (!result) {
        end();
    } else {
        pause();
    }
}

[[gnu::noinline]]
void run_test_depth20_error65_cleanup_50() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_20_error65_percent_50();
    if (!result) {
        end();
    } else {
        pause();
    }
}

[[gnu::noinline]]
void run_test_depth10_error65_cleanup_50() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_10_error65_percent_50();
    if (!result) {
        end();
    } else {
        pause();
    }
}

[[gnu::noinline]]
void run_test_depth01_error65_cleanup_50() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_01_error65_percent_50();
    if (!result) {
        end();
    } else {
        pause();
    }
}

void run_test_error65_cleanup_50() {
    run_test_depth60_error65_cleanup_50();
    run_test_depth40_error65_cleanup_50();
    run_test_depth20_error65_cleanup_50();
    run_test_depth10_error65_cleanup_50();
    run_test_depth01_error65_cleanup_50();
}
// Test runner
[[gnu::noinline]]
void run_test_depth60_error65_cleanup_100() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_60_error65_percent_100();
    if (!result) {
        end();
    } else {
        pause(); // Should have gotten an error
    }
}

[[gnu::noinline]]
void run_test_depth40_error65_cleanup_100() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_40_error65_percent_100();
    if (!result) {
        end();
    } else {
        pause();
    }
}

[[gnu::noinline]]
void run_test_depth20_error65_cleanup_100() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_20_error65_percent_100();
    if (!result) {
        end();
    } else {
        pause();
    }
}

[[gnu::noinline]]
void run_test_depth10_error65_cleanup_100() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_10_error65_percent_100();
    if (!result) {
        end();
    } else {
        pause();
    }
}

[[gnu::noinline]]
void run_test_depth01_error65_cleanup_100() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_01_error65_percent_100();
    if (!result) {
        end();
    } else {
        pause();
    }
}

void run_test_error65_cleanup_100() {
    run_test_depth60_error65_cleanup_100();
    run_test_depth40_error65_cleanup_100();
    run_test_depth20_error65_cleanup_100();
    run_test_depth10_error65_cleanup_100();
    run_test_depth01_error65_cleanup_100();
}
// Test runner
void run_test() {
    run_test_error65_cleanup_0();
    run_test_error65_cleanup_25();
    run_test_error65_cleanup_50();
    run_test_error65_cleanup_100();

}

