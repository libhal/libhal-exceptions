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
struct test_error_4 {
  std::array<std::uint8_t, 4> data;
};
std::expected<int, test_error_4> depth_70_error4_percent_0();
std::expected<int, test_error_4> depth_69_error4_percent_0();
std::expected<int, test_error_4> depth_68_error4_percent_0();
std::expected<int, test_error_4> depth_67_error4_percent_0();
std::expected<int, test_error_4> depth_66_error4_percent_0();
std::expected<int, test_error_4> depth_65_error4_percent_0();
std::expected<int, test_error_4> depth_64_error4_percent_0();
std::expected<int, test_error_4> depth_63_error4_percent_0();
std::expected<int, test_error_4> depth_62_error4_percent_0();
std::expected<int, test_error_4> depth_61_error4_percent_0();
std::expected<int, test_error_4> depth_60_error4_percent_0();
std::expected<int, test_error_4> depth_59_error4_percent_0();
std::expected<int, test_error_4> depth_58_error4_percent_0();
std::expected<int, test_error_4> depth_57_error4_percent_0();
std::expected<int, test_error_4> depth_56_error4_percent_0();
std::expected<int, test_error_4> depth_55_error4_percent_0();
std::expected<int, test_error_4> depth_54_error4_percent_0();
std::expected<int, test_error_4> depth_53_error4_percent_0();
std::expected<int, test_error_4> depth_52_error4_percent_0();
std::expected<int, test_error_4> depth_51_error4_percent_0();
std::expected<int, test_error_4> depth_50_error4_percent_0();
std::expected<int, test_error_4> depth_49_error4_percent_0();
std::expected<int, test_error_4> depth_48_error4_percent_0();
std::expected<int, test_error_4> depth_47_error4_percent_0();
std::expected<int, test_error_4> depth_46_error4_percent_0();
std::expected<int, test_error_4> depth_45_error4_percent_0();
std::expected<int, test_error_4> depth_44_error4_percent_0();
std::expected<int, test_error_4> depth_43_error4_percent_0();
std::expected<int, test_error_4> depth_42_error4_percent_0();
std::expected<int, test_error_4> depth_41_error4_percent_0();
std::expected<int, test_error_4> depth_40_error4_percent_0();
std::expected<int, test_error_4> depth_39_error4_percent_0();
std::expected<int, test_error_4> depth_38_error4_percent_0();
std::expected<int, test_error_4> depth_37_error4_percent_0();
std::expected<int, test_error_4> depth_36_error4_percent_0();
std::expected<int, test_error_4> depth_35_error4_percent_0();
std::expected<int, test_error_4> depth_34_error4_percent_0();
std::expected<int, test_error_4> depth_33_error4_percent_0();
std::expected<int, test_error_4> depth_32_error4_percent_0();
std::expected<int, test_error_4> depth_31_error4_percent_0();
std::expected<int, test_error_4> depth_30_error4_percent_0();
std::expected<int, test_error_4> depth_29_error4_percent_0();
std::expected<int, test_error_4> depth_28_error4_percent_0();
std::expected<int, test_error_4> depth_27_error4_percent_0();
std::expected<int, test_error_4> depth_26_error4_percent_0();
std::expected<int, test_error_4> depth_25_error4_percent_0();
std::expected<int, test_error_4> depth_24_error4_percent_0();
std::expected<int, test_error_4> depth_23_error4_percent_0();
std::expected<int, test_error_4> depth_22_error4_percent_0();
std::expected<int, test_error_4> depth_21_error4_percent_0();
std::expected<int, test_error_4> depth_20_error4_percent_0();
std::expected<int, test_error_4> depth_19_error4_percent_0();
std::expected<int, test_error_4> depth_18_error4_percent_0();
std::expected<int, test_error_4> depth_17_error4_percent_0();
std::expected<int, test_error_4> depth_16_error4_percent_0();
std::expected<int, test_error_4> depth_15_error4_percent_0();
std::expected<int, test_error_4> depth_14_error4_percent_0();
std::expected<int, test_error_4> depth_13_error4_percent_0();
std::expected<int, test_error_4> depth_12_error4_percent_0();
std::expected<int, test_error_4> depth_11_error4_percent_0();
std::expected<int, test_error_4> depth_10_error4_percent_0();
std::expected<int, test_error_4> depth_09_error4_percent_0();
std::expected<int, test_error_4> depth_08_error4_percent_0();
std::expected<int, test_error_4> depth_07_error4_percent_0();
std::expected<int, test_error_4> depth_06_error4_percent_0();
std::expected<int, test_error_4> depth_05_error4_percent_0();
std::expected<int, test_error_4> depth_04_error4_percent_0();
std::expected<int, test_error_4> depth_03_error4_percent_0();
std::expected<int, test_error_4> depth_02_error4_percent_0();
std::expected<int, test_error_4> depth_01_error4_percent_0();
[[gnu::noinline]]
std::expected<int, test_error_4> depth_70_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 25> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_69_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_69_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 27> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_68_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_68_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 3> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_67_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_67_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 17> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_66_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_66_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 32> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_65_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_65_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 26> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_64_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_64_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 20> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_63_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_63_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 31> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_62_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_62_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 23> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_61_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_61_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 14> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_60_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_60_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 9> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_59_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_59_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 19> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_58_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_58_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 9> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_57_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_57_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 7> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_56_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_56_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 17> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_55_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_55_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 10> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_54_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_54_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 20> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_53_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_53_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 7> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_52_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_52_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 5> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_51_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_51_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 22> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_50_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_50_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 31> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_49_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_49_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 7> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_48_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_48_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 23> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_47_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_47_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 28> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_46_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_46_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 21> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_45_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_45_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 14> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_44_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_44_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 31> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_43_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_43_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 29> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_42_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_42_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 17> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_41_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_41_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 4> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_40_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_40_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 1> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_39_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_39_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 6> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_38_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_38_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 26> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_37_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_37_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 1> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_36_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_36_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 32> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_35_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_35_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 22> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_34_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_34_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 16> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_33_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_33_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 21> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_32_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_32_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 5> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_31_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_31_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 13> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_30_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_30_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 15> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_29_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_29_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 16> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_28_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_28_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 10> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_27_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_27_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 29> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_26_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_26_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 6> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_25_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_25_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 6> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_24_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_24_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 21> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_23_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_23_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 32> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_22_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_22_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 7> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_21_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_21_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 20> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_20_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_20_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 19> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_19_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_19_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 8> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_18_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_18_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 22> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_17_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_17_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 14> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_16_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_16_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 19> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_15_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_15_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 29> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_14_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_14_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 6> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_13_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_13_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 25> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_12_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_12_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 21> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_11_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_11_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 16> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_10_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_10_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 19> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_09_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_09_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 12> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_08_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_08_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 13> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_07_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_07_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 12> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_06_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_06_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 3> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_05_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_05_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 17> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_04_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_04_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 31> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_03_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_03_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 5> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_02_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_02_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 6> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_01_error4_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_01_error4_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 9> preserve_frame =
    {
      side_effect,
    };

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1; // Never executed but prevents optimization
  }

  // This is where the error originates
  start();
  return std::unexpected(test_error_4
                        {
                            .data = { 0xDE, 0xAD, 0xBE, 0xEF }
                        });
}

std::expected<int, test_error_4> depth_70_error4_percent_25();
std::expected<int, test_error_4> depth_69_error4_percent_25();
std::expected<int, test_error_4> depth_68_error4_percent_25();
std::expected<int, test_error_4> depth_67_error4_percent_25();
std::expected<int, test_error_4> depth_66_error4_percent_25();
std::expected<int, test_error_4> depth_65_error4_percent_25();
std::expected<int, test_error_4> depth_64_error4_percent_25();
std::expected<int, test_error_4> depth_63_error4_percent_25();
std::expected<int, test_error_4> depth_62_error4_percent_25();
std::expected<int, test_error_4> depth_61_error4_percent_25();
std::expected<int, test_error_4> depth_60_error4_percent_25();
std::expected<int, test_error_4> depth_59_error4_percent_25();
std::expected<int, test_error_4> depth_58_error4_percent_25();
std::expected<int, test_error_4> depth_57_error4_percent_25();
std::expected<int, test_error_4> depth_56_error4_percent_25();
std::expected<int, test_error_4> depth_55_error4_percent_25();
std::expected<int, test_error_4> depth_54_error4_percent_25();
std::expected<int, test_error_4> depth_53_error4_percent_25();
std::expected<int, test_error_4> depth_52_error4_percent_25();
std::expected<int, test_error_4> depth_51_error4_percent_25();
std::expected<int, test_error_4> depth_50_error4_percent_25();
std::expected<int, test_error_4> depth_49_error4_percent_25();
std::expected<int, test_error_4> depth_48_error4_percent_25();
std::expected<int, test_error_4> depth_47_error4_percent_25();
std::expected<int, test_error_4> depth_46_error4_percent_25();
std::expected<int, test_error_4> depth_45_error4_percent_25();
std::expected<int, test_error_4> depth_44_error4_percent_25();
std::expected<int, test_error_4> depth_43_error4_percent_25();
std::expected<int, test_error_4> depth_42_error4_percent_25();
std::expected<int, test_error_4> depth_41_error4_percent_25();
std::expected<int, test_error_4> depth_40_error4_percent_25();
std::expected<int, test_error_4> depth_39_error4_percent_25();
std::expected<int, test_error_4> depth_38_error4_percent_25();
std::expected<int, test_error_4> depth_37_error4_percent_25();
std::expected<int, test_error_4> depth_36_error4_percent_25();
std::expected<int, test_error_4> depth_35_error4_percent_25();
std::expected<int, test_error_4> depth_34_error4_percent_25();
std::expected<int, test_error_4> depth_33_error4_percent_25();
std::expected<int, test_error_4> depth_32_error4_percent_25();
std::expected<int, test_error_4> depth_31_error4_percent_25();
std::expected<int, test_error_4> depth_30_error4_percent_25();
std::expected<int, test_error_4> depth_29_error4_percent_25();
std::expected<int, test_error_4> depth_28_error4_percent_25();
std::expected<int, test_error_4> depth_27_error4_percent_25();
std::expected<int, test_error_4> depth_26_error4_percent_25();
std::expected<int, test_error_4> depth_25_error4_percent_25();
std::expected<int, test_error_4> depth_24_error4_percent_25();
std::expected<int, test_error_4> depth_23_error4_percent_25();
std::expected<int, test_error_4> depth_22_error4_percent_25();
std::expected<int, test_error_4> depth_21_error4_percent_25();
std::expected<int, test_error_4> depth_20_error4_percent_25();
std::expected<int, test_error_4> depth_19_error4_percent_25();
std::expected<int, test_error_4> depth_18_error4_percent_25();
std::expected<int, test_error_4> depth_17_error4_percent_25();
std::expected<int, test_error_4> depth_16_error4_percent_25();
std::expected<int, test_error_4> depth_15_error4_percent_25();
std::expected<int, test_error_4> depth_14_error4_percent_25();
std::expected<int, test_error_4> depth_13_error4_percent_25();
std::expected<int, test_error_4> depth_12_error4_percent_25();
std::expected<int, test_error_4> depth_11_error4_percent_25();
std::expected<int, test_error_4> depth_10_error4_percent_25();
std::expected<int, test_error_4> depth_09_error4_percent_25();
std::expected<int, test_error_4> depth_08_error4_percent_25();
std::expected<int, test_error_4> depth_07_error4_percent_25();
std::expected<int, test_error_4> depth_06_error4_percent_25();
std::expected<int, test_error_4> depth_05_error4_percent_25();
std::expected<int, test_error_4> depth_04_error4_percent_25();
std::expected<int, test_error_4> depth_03_error4_percent_25();
std::expected<int, test_error_4> depth_02_error4_percent_25();
std::expected<int, test_error_4> depth_01_error4_percent_25();
[[gnu::noinline]]
std::expected<int, test_error_4> depth_70_error4_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 10> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_69_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_69_error4_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 3> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_68_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_68_error4_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 6> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_67_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_67_error4_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 26> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_66_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_66_error4_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 18> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_65_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_65_error4_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 16> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_64_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_64_error4_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 14> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_63_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_63_error4_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 27> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_62_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_62_error4_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 18> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_61_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_61_error4_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 29> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_60_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_60_error4_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 32> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_59_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_59_error4_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 23> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_58_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_58_error4_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 6> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_57_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_57_error4_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 21> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_56_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_56_error4_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 8> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_55_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_55_error4_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 32> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_54_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_54_error4_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 22> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_53_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_53_error4_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 13> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_52_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_52_error4_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 16> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_51_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_51_error4_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 2> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_50_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_50_error4_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 18> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_49_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_49_error4_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 8> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_48_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_48_error4_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 15> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_47_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_47_error4_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 24> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_46_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_46_error4_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 11> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_45_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_45_error4_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 22> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_44_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_44_error4_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 28> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_43_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_43_error4_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 4> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_42_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_42_error4_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 7> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_41_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_41_error4_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 10> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_40_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_40_error4_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 15> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_39_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_39_error4_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 3> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_38_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_38_error4_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 5> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_37_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_37_error4_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 2> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_36_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_36_error4_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 8> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_35_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_35_error4_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 13> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_34_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_34_error4_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 8> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_33_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_33_error4_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 26> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_32_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_32_error4_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 6> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_31_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_31_error4_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 24> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_30_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_30_error4_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 8> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_29_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_29_error4_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 3> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_28_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_28_error4_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 2> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_27_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_27_error4_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 13> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_26_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_26_error4_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 12> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_25_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_25_error4_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 8> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_24_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_24_error4_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 31> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_23_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_23_error4_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 14> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_22_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_22_error4_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 4> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_21_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_21_error4_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 2> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_20_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_20_error4_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 28> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_19_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_19_error4_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 7> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_18_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_18_error4_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 17> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_17_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_17_error4_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 5> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_16_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_16_error4_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 15> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_15_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_15_error4_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 5> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_14_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_14_error4_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 20> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_13_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_13_error4_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 23> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_12_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_12_error4_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 28> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_11_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_11_error4_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 12> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_10_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_10_error4_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 4> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_09_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_09_error4_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 30> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_08_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_08_error4_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 3> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_07_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_07_error4_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 7> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_06_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_06_error4_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 26> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_05_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_05_error4_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 13> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_04_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_04_error4_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 17> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_03_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_03_error4_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 23> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_02_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_02_error4_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 31> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_01_error4_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_01_error4_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 11> preserve_frame =
    {
      side_effect,
    };

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1; // Never executed but prevents optimization
  }

  // This is where the error originates
  start();
  return std::unexpected(test_error_4
                        {
                            .data = { 0xDE, 0xAD, 0xBE, 0xEF }
                        });
}

std::expected<int, test_error_4> depth_70_error4_percent_50();
std::expected<int, test_error_4> depth_69_error4_percent_50();
std::expected<int, test_error_4> depth_68_error4_percent_50();
std::expected<int, test_error_4> depth_67_error4_percent_50();
std::expected<int, test_error_4> depth_66_error4_percent_50();
std::expected<int, test_error_4> depth_65_error4_percent_50();
std::expected<int, test_error_4> depth_64_error4_percent_50();
std::expected<int, test_error_4> depth_63_error4_percent_50();
std::expected<int, test_error_4> depth_62_error4_percent_50();
std::expected<int, test_error_4> depth_61_error4_percent_50();
std::expected<int, test_error_4> depth_60_error4_percent_50();
std::expected<int, test_error_4> depth_59_error4_percent_50();
std::expected<int, test_error_4> depth_58_error4_percent_50();
std::expected<int, test_error_4> depth_57_error4_percent_50();
std::expected<int, test_error_4> depth_56_error4_percent_50();
std::expected<int, test_error_4> depth_55_error4_percent_50();
std::expected<int, test_error_4> depth_54_error4_percent_50();
std::expected<int, test_error_4> depth_53_error4_percent_50();
std::expected<int, test_error_4> depth_52_error4_percent_50();
std::expected<int, test_error_4> depth_51_error4_percent_50();
std::expected<int, test_error_4> depth_50_error4_percent_50();
std::expected<int, test_error_4> depth_49_error4_percent_50();
std::expected<int, test_error_4> depth_48_error4_percent_50();
std::expected<int, test_error_4> depth_47_error4_percent_50();
std::expected<int, test_error_4> depth_46_error4_percent_50();
std::expected<int, test_error_4> depth_45_error4_percent_50();
std::expected<int, test_error_4> depth_44_error4_percent_50();
std::expected<int, test_error_4> depth_43_error4_percent_50();
std::expected<int, test_error_4> depth_42_error4_percent_50();
std::expected<int, test_error_4> depth_41_error4_percent_50();
std::expected<int, test_error_4> depth_40_error4_percent_50();
std::expected<int, test_error_4> depth_39_error4_percent_50();
std::expected<int, test_error_4> depth_38_error4_percent_50();
std::expected<int, test_error_4> depth_37_error4_percent_50();
std::expected<int, test_error_4> depth_36_error4_percent_50();
std::expected<int, test_error_4> depth_35_error4_percent_50();
std::expected<int, test_error_4> depth_34_error4_percent_50();
std::expected<int, test_error_4> depth_33_error4_percent_50();
std::expected<int, test_error_4> depth_32_error4_percent_50();
std::expected<int, test_error_4> depth_31_error4_percent_50();
std::expected<int, test_error_4> depth_30_error4_percent_50();
std::expected<int, test_error_4> depth_29_error4_percent_50();
std::expected<int, test_error_4> depth_28_error4_percent_50();
std::expected<int, test_error_4> depth_27_error4_percent_50();
std::expected<int, test_error_4> depth_26_error4_percent_50();
std::expected<int, test_error_4> depth_25_error4_percent_50();
std::expected<int, test_error_4> depth_24_error4_percent_50();
std::expected<int, test_error_4> depth_23_error4_percent_50();
std::expected<int, test_error_4> depth_22_error4_percent_50();
std::expected<int, test_error_4> depth_21_error4_percent_50();
std::expected<int, test_error_4> depth_20_error4_percent_50();
std::expected<int, test_error_4> depth_19_error4_percent_50();
std::expected<int, test_error_4> depth_18_error4_percent_50();
std::expected<int, test_error_4> depth_17_error4_percent_50();
std::expected<int, test_error_4> depth_16_error4_percent_50();
std::expected<int, test_error_4> depth_15_error4_percent_50();
std::expected<int, test_error_4> depth_14_error4_percent_50();
std::expected<int, test_error_4> depth_13_error4_percent_50();
std::expected<int, test_error_4> depth_12_error4_percent_50();
std::expected<int, test_error_4> depth_11_error4_percent_50();
std::expected<int, test_error_4> depth_10_error4_percent_50();
std::expected<int, test_error_4> depth_09_error4_percent_50();
std::expected<int, test_error_4> depth_08_error4_percent_50();
std::expected<int, test_error_4> depth_07_error4_percent_50();
std::expected<int, test_error_4> depth_06_error4_percent_50();
std::expected<int, test_error_4> depth_05_error4_percent_50();
std::expected<int, test_error_4> depth_04_error4_percent_50();
std::expected<int, test_error_4> depth_03_error4_percent_50();
std::expected<int, test_error_4> depth_02_error4_percent_50();
std::expected<int, test_error_4> depth_01_error4_percent_50();
[[gnu::noinline]]
std::expected<int, test_error_4> depth_70_error4_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 14> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_69_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_69_error4_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 4> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_68_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_68_error4_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 11> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_67_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_67_error4_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 11> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_66_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_66_error4_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 22> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_65_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_65_error4_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 17> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_64_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_64_error4_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 8> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_63_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_63_error4_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 29> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_62_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_62_error4_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 12> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_61_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_61_error4_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 1> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_60_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_60_error4_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 31> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_59_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_59_error4_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 27> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_58_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_58_error4_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 20> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_57_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_57_error4_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 23> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_56_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_56_error4_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 25> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_55_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_55_error4_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 17> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_54_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_54_error4_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 10> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_53_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_53_error4_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 1> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_52_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_52_error4_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 30> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_51_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_51_error4_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 6> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_50_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_50_error4_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 22> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_49_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_49_error4_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 3> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_48_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_48_error4_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 18> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_47_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_47_error4_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 9> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_46_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_46_error4_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 16> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_45_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_45_error4_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 31> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_44_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_44_error4_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 23> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_43_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_43_error4_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 19> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_42_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_42_error4_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 23> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_41_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_41_error4_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 9> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_40_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_40_error4_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 20> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_39_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_39_error4_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 25> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_38_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_38_error4_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 27> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_37_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_37_error4_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 6> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_36_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_36_error4_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 1> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_35_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_35_error4_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 13> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_34_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_34_error4_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 22> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_33_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_33_error4_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 11> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_32_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_32_error4_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 16> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_31_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_31_error4_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 15> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_30_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_30_error4_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 29> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_29_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_29_error4_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 25> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_28_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_28_error4_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 27> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_27_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_27_error4_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 3> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_26_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_26_error4_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 26> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_25_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_25_error4_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 27> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_24_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_24_error4_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 3> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_23_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_23_error4_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 11> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_22_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_22_error4_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 29> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_21_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_21_error4_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 5> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_20_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_20_error4_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 17> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_19_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_19_error4_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 11> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_18_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_18_error4_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 29> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_17_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_17_error4_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 32> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_16_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_16_error4_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 1> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_15_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_15_error4_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 3> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_14_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_14_error4_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 32> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_13_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_13_error4_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 21> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_12_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_12_error4_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 20> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_11_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_11_error4_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 30> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_10_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_10_error4_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 4> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_09_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_09_error4_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 27> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_08_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_08_error4_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 13> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_07_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_07_error4_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 6> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_06_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_06_error4_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 9> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_05_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_05_error4_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 1> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_04_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_04_error4_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 26> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_03_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_03_error4_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 27> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_02_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_02_error4_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 21> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_01_error4_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_01_error4_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 1> preserve_frame =
    {
      side_effect,
    };

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1; // Never executed but prevents optimization
  }

  // This is where the error originates
  start();
  return std::unexpected(test_error_4
                        {
                            .data = { 0xDE, 0xAD, 0xBE, 0xEF }
                        });
}

std::expected<int, test_error_4> depth_70_error4_percent_75();
std::expected<int, test_error_4> depth_69_error4_percent_75();
std::expected<int, test_error_4> depth_68_error4_percent_75();
std::expected<int, test_error_4> depth_67_error4_percent_75();
std::expected<int, test_error_4> depth_66_error4_percent_75();
std::expected<int, test_error_4> depth_65_error4_percent_75();
std::expected<int, test_error_4> depth_64_error4_percent_75();
std::expected<int, test_error_4> depth_63_error4_percent_75();
std::expected<int, test_error_4> depth_62_error4_percent_75();
std::expected<int, test_error_4> depth_61_error4_percent_75();
std::expected<int, test_error_4> depth_60_error4_percent_75();
std::expected<int, test_error_4> depth_59_error4_percent_75();
std::expected<int, test_error_4> depth_58_error4_percent_75();
std::expected<int, test_error_4> depth_57_error4_percent_75();
std::expected<int, test_error_4> depth_56_error4_percent_75();
std::expected<int, test_error_4> depth_55_error4_percent_75();
std::expected<int, test_error_4> depth_54_error4_percent_75();
std::expected<int, test_error_4> depth_53_error4_percent_75();
std::expected<int, test_error_4> depth_52_error4_percent_75();
std::expected<int, test_error_4> depth_51_error4_percent_75();
std::expected<int, test_error_4> depth_50_error4_percent_75();
std::expected<int, test_error_4> depth_49_error4_percent_75();
std::expected<int, test_error_4> depth_48_error4_percent_75();
std::expected<int, test_error_4> depth_47_error4_percent_75();
std::expected<int, test_error_4> depth_46_error4_percent_75();
std::expected<int, test_error_4> depth_45_error4_percent_75();
std::expected<int, test_error_4> depth_44_error4_percent_75();
std::expected<int, test_error_4> depth_43_error4_percent_75();
std::expected<int, test_error_4> depth_42_error4_percent_75();
std::expected<int, test_error_4> depth_41_error4_percent_75();
std::expected<int, test_error_4> depth_40_error4_percent_75();
std::expected<int, test_error_4> depth_39_error4_percent_75();
std::expected<int, test_error_4> depth_38_error4_percent_75();
std::expected<int, test_error_4> depth_37_error4_percent_75();
std::expected<int, test_error_4> depth_36_error4_percent_75();
std::expected<int, test_error_4> depth_35_error4_percent_75();
std::expected<int, test_error_4> depth_34_error4_percent_75();
std::expected<int, test_error_4> depth_33_error4_percent_75();
std::expected<int, test_error_4> depth_32_error4_percent_75();
std::expected<int, test_error_4> depth_31_error4_percent_75();
std::expected<int, test_error_4> depth_30_error4_percent_75();
std::expected<int, test_error_4> depth_29_error4_percent_75();
std::expected<int, test_error_4> depth_28_error4_percent_75();
std::expected<int, test_error_4> depth_27_error4_percent_75();
std::expected<int, test_error_4> depth_26_error4_percent_75();
std::expected<int, test_error_4> depth_25_error4_percent_75();
std::expected<int, test_error_4> depth_24_error4_percent_75();
std::expected<int, test_error_4> depth_23_error4_percent_75();
std::expected<int, test_error_4> depth_22_error4_percent_75();
std::expected<int, test_error_4> depth_21_error4_percent_75();
std::expected<int, test_error_4> depth_20_error4_percent_75();
std::expected<int, test_error_4> depth_19_error4_percent_75();
std::expected<int, test_error_4> depth_18_error4_percent_75();
std::expected<int, test_error_4> depth_17_error4_percent_75();
std::expected<int, test_error_4> depth_16_error4_percent_75();
std::expected<int, test_error_4> depth_15_error4_percent_75();
std::expected<int, test_error_4> depth_14_error4_percent_75();
std::expected<int, test_error_4> depth_13_error4_percent_75();
std::expected<int, test_error_4> depth_12_error4_percent_75();
std::expected<int, test_error_4> depth_11_error4_percent_75();
std::expected<int, test_error_4> depth_10_error4_percent_75();
std::expected<int, test_error_4> depth_09_error4_percent_75();
std::expected<int, test_error_4> depth_08_error4_percent_75();
std::expected<int, test_error_4> depth_07_error4_percent_75();
std::expected<int, test_error_4> depth_06_error4_percent_75();
std::expected<int, test_error_4> depth_05_error4_percent_75();
std::expected<int, test_error_4> depth_04_error4_percent_75();
std::expected<int, test_error_4> depth_03_error4_percent_75();
std::expected<int, test_error_4> depth_02_error4_percent_75();
std::expected<int, test_error_4> depth_01_error4_percent_75();
[[gnu::noinline]]
std::expected<int, test_error_4> depth_70_error4_percent_75() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 14> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_69_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_69_error4_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 1> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_68_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_68_error4_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 1> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_67_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_67_error4_percent_75() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 7> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_66_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_66_error4_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 13> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_65_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_65_error4_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 8> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_64_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_64_error4_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 13> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_63_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_63_error4_percent_75() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 20> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_62_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_62_error4_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 18> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_61_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_61_error4_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 12> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_60_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_60_error4_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 7> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_59_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_59_error4_percent_75() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 31> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_58_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_58_error4_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 26> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_57_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_57_error4_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 6> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_56_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_56_error4_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 2> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_55_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_55_error4_percent_75() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 18> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_54_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_54_error4_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 29> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_53_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_53_error4_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 8> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_52_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_52_error4_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 17> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_51_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_51_error4_percent_75() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 9> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_50_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_50_error4_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 23> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_49_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_49_error4_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 8> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_48_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_48_error4_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 10> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_47_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_47_error4_percent_75() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 18> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_46_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_46_error4_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 2> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_45_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_45_error4_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 3> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_44_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_44_error4_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 3> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_43_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_43_error4_percent_75() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 14> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_42_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_42_error4_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 17> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_41_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_41_error4_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 21> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_40_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_40_error4_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 24> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_39_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_39_error4_percent_75() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 3> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_38_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_38_error4_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 32> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_37_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_37_error4_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 30> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_36_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_36_error4_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 28> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_35_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_35_error4_percent_75() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 24> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_34_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_34_error4_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 12> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_33_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_33_error4_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 14> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_32_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_32_error4_percent_75() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 25> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_31_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_31_error4_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 19> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_30_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_30_error4_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 1> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_29_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_29_error4_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 9> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_28_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_28_error4_percent_75() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 10> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_27_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_27_error4_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 18> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_26_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_26_error4_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 22> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_25_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_25_error4_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 22> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_24_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_24_error4_percent_75() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 24> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_23_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_23_error4_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 6> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_22_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_22_error4_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 22> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_21_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_21_error4_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 3> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_20_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_20_error4_percent_75() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 3> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_19_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_19_error4_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 18> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_18_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_18_error4_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 11> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_17_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_17_error4_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 10> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_16_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_16_error4_percent_75() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 19> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_15_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_15_error4_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 24> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_14_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_14_error4_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 26> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_13_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_13_error4_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 9> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_12_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_12_error4_percent_75() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 19> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_11_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_11_error4_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 8> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_10_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_10_error4_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 31> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_09_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_09_error4_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 16> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_08_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_08_error4_percent_75() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 4> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_07_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_07_error4_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 20> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_06_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_06_error4_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 12> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_05_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_05_error4_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 5> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_04_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_04_error4_percent_75() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 20> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_03_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_03_error4_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 26> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_02_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_02_error4_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 22> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_01_error4_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_01_error4_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 20> preserve_frame =
    {
      side_effect,
    };

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1; // Never executed but prevents optimization
  }

  // This is where the error originates
  start();
  return std::unexpected(test_error_4
                        {
                            .data = { 0xDE, 0xAD, 0xBE, 0xEF }
                        });
}

std::expected<int, test_error_4> depth_70_error4_percent_100();
std::expected<int, test_error_4> depth_69_error4_percent_100();
std::expected<int, test_error_4> depth_68_error4_percent_100();
std::expected<int, test_error_4> depth_67_error4_percent_100();
std::expected<int, test_error_4> depth_66_error4_percent_100();
std::expected<int, test_error_4> depth_65_error4_percent_100();
std::expected<int, test_error_4> depth_64_error4_percent_100();
std::expected<int, test_error_4> depth_63_error4_percent_100();
std::expected<int, test_error_4> depth_62_error4_percent_100();
std::expected<int, test_error_4> depth_61_error4_percent_100();
std::expected<int, test_error_4> depth_60_error4_percent_100();
std::expected<int, test_error_4> depth_59_error4_percent_100();
std::expected<int, test_error_4> depth_58_error4_percent_100();
std::expected<int, test_error_4> depth_57_error4_percent_100();
std::expected<int, test_error_4> depth_56_error4_percent_100();
std::expected<int, test_error_4> depth_55_error4_percent_100();
std::expected<int, test_error_4> depth_54_error4_percent_100();
std::expected<int, test_error_4> depth_53_error4_percent_100();
std::expected<int, test_error_4> depth_52_error4_percent_100();
std::expected<int, test_error_4> depth_51_error4_percent_100();
std::expected<int, test_error_4> depth_50_error4_percent_100();
std::expected<int, test_error_4> depth_49_error4_percent_100();
std::expected<int, test_error_4> depth_48_error4_percent_100();
std::expected<int, test_error_4> depth_47_error4_percent_100();
std::expected<int, test_error_4> depth_46_error4_percent_100();
std::expected<int, test_error_4> depth_45_error4_percent_100();
std::expected<int, test_error_4> depth_44_error4_percent_100();
std::expected<int, test_error_4> depth_43_error4_percent_100();
std::expected<int, test_error_4> depth_42_error4_percent_100();
std::expected<int, test_error_4> depth_41_error4_percent_100();
std::expected<int, test_error_4> depth_40_error4_percent_100();
std::expected<int, test_error_4> depth_39_error4_percent_100();
std::expected<int, test_error_4> depth_38_error4_percent_100();
std::expected<int, test_error_4> depth_37_error4_percent_100();
std::expected<int, test_error_4> depth_36_error4_percent_100();
std::expected<int, test_error_4> depth_35_error4_percent_100();
std::expected<int, test_error_4> depth_34_error4_percent_100();
std::expected<int, test_error_4> depth_33_error4_percent_100();
std::expected<int, test_error_4> depth_32_error4_percent_100();
std::expected<int, test_error_4> depth_31_error4_percent_100();
std::expected<int, test_error_4> depth_30_error4_percent_100();
std::expected<int, test_error_4> depth_29_error4_percent_100();
std::expected<int, test_error_4> depth_28_error4_percent_100();
std::expected<int, test_error_4> depth_27_error4_percent_100();
std::expected<int, test_error_4> depth_26_error4_percent_100();
std::expected<int, test_error_4> depth_25_error4_percent_100();
std::expected<int, test_error_4> depth_24_error4_percent_100();
std::expected<int, test_error_4> depth_23_error4_percent_100();
std::expected<int, test_error_4> depth_22_error4_percent_100();
std::expected<int, test_error_4> depth_21_error4_percent_100();
std::expected<int, test_error_4> depth_20_error4_percent_100();
std::expected<int, test_error_4> depth_19_error4_percent_100();
std::expected<int, test_error_4> depth_18_error4_percent_100();
std::expected<int, test_error_4> depth_17_error4_percent_100();
std::expected<int, test_error_4> depth_16_error4_percent_100();
std::expected<int, test_error_4> depth_15_error4_percent_100();
std::expected<int, test_error_4> depth_14_error4_percent_100();
std::expected<int, test_error_4> depth_13_error4_percent_100();
std::expected<int, test_error_4> depth_12_error4_percent_100();
std::expected<int, test_error_4> depth_11_error4_percent_100();
std::expected<int, test_error_4> depth_10_error4_percent_100();
std::expected<int, test_error_4> depth_09_error4_percent_100();
std::expected<int, test_error_4> depth_08_error4_percent_100();
std::expected<int, test_error_4> depth_07_error4_percent_100();
std::expected<int, test_error_4> depth_06_error4_percent_100();
std::expected<int, test_error_4> depth_05_error4_percent_100();
std::expected<int, test_error_4> depth_04_error4_percent_100();
std::expected<int, test_error_4> depth_03_error4_percent_100();
std::expected<int, test_error_4> depth_02_error4_percent_100();
std::expected<int, test_error_4> depth_01_error4_percent_100();
[[gnu::noinline]]
std::expected<int, test_error_4> depth_70_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 27> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_69_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_69_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 7> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_68_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_68_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 7> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_67_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_67_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 31> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_66_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_66_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 31> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_65_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_65_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 22> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_64_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_64_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 22> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_63_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_63_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 8> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_62_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_62_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 31> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_61_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_61_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 8> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_60_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_60_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 32> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_59_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_59_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 28> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_58_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_58_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 3> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_57_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_57_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 20> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_56_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_56_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 22> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_55_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_55_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 10> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_54_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_54_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 11> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_53_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_53_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 25> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_52_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_52_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 6> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_51_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_51_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 5> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_50_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_50_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 6> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_49_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_49_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 13> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_48_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_48_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 15> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_47_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_47_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 4> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_46_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_46_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 25> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_45_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_45_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 1> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_44_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_44_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 7> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_43_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_43_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 26> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_42_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_42_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 19> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_41_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_41_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 29> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_40_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_40_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 32> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_39_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_39_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 14> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_38_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_38_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 28> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_37_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_37_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 6> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_36_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_36_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 24> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_35_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_35_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 15> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_34_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_34_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 17> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_33_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_33_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 11> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_32_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_32_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 28> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_31_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_31_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 13> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_30_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_30_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 23> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_29_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_29_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 8> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_28_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_28_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 5> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_27_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_27_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 2> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_26_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_26_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 29> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_25_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_25_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 13> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_24_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_24_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 8> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_23_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_23_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 32> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_22_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_22_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 26> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_21_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_21_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 17> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_20_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_20_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 14> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_19_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_19_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 3> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_18_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_18_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 14> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_17_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_17_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 10> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_16_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_16_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 7> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_15_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_15_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 13> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_14_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_14_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 30> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_13_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_13_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 25> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_12_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_12_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 24> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_11_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_11_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 10> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_10_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_10_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 7> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_09_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_09_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 32> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_08_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_08_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 10> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_07_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_07_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 26> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_06_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_06_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 28> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_05_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_05_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 32> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_04_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_04_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 21> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_03_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_03_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 32> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_02_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_02_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 32> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_01_error4_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_4> depth_01_error4_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 13> preserve_frame =
    {
      side_effect,
    };

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    return -1; // Never executed but prevents optimization
  }

  // This is where the error originates
  start();
  return std::unexpected(test_error_4
                        {
                            .data = { 0xDE, 0xAD, 0xBE, 0xEF }
                        });
}

// Test runner
[[gnu::noinline]]
void run_test_depth70_error4_cleanup_0() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_70_error4_percent_0();
    if (!result) {
        end();
    } else {
        pause(); // Should have gotten an error
    }
}

[[gnu::noinline]]
void run_test_depth50_error4_cleanup_0() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_50_error4_percent_0();
    if (!result) {
        end();
    } else {
        pause();
    }
}

[[gnu::noinline]]
void run_test_depth30_error4_cleanup_0() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_30_error4_percent_0();
    if (!result) {
        end();
    } else {
        pause();
    }
}

[[gnu::noinline]]
void run_test_depth10_error4_cleanup_0() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_10_error4_percent_0();
    if (!result) {
        end();
    } else {
        pause();
    }
}

[[gnu::noinline]]
void run_test_depth01_error4_cleanup_0() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_01_error4_percent_0();
    if (!result) {
        end();
    } else {
        pause();
    }
}

void run_test_error4_cleanup_0() {
    run_test_depth70_error4_cleanup_0();
    run_test_depth50_error4_cleanup_0();
    run_test_depth30_error4_cleanup_0();
    run_test_depth10_error4_cleanup_0();
    run_test_depth01_error4_cleanup_0();
}
// Test runner
[[gnu::noinline]]
void run_test_depth70_error4_cleanup_25() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_70_error4_percent_25();
    if (!result) {
        end();
    } else {
        pause(); // Should have gotten an error
    }
}

[[gnu::noinline]]
void run_test_depth50_error4_cleanup_25() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_50_error4_percent_25();
    if (!result) {
        end();
    } else {
        pause();
    }
}

[[gnu::noinline]]
void run_test_depth30_error4_cleanup_25() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_30_error4_percent_25();
    if (!result) {
        end();
    } else {
        pause();
    }
}

[[gnu::noinline]]
void run_test_depth10_error4_cleanup_25() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_10_error4_percent_25();
    if (!result) {
        end();
    } else {
        pause();
    }
}

[[gnu::noinline]]
void run_test_depth01_error4_cleanup_25() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_01_error4_percent_25();
    if (!result) {
        end();
    } else {
        pause();
    }
}

void run_test_error4_cleanup_25() {
    run_test_depth70_error4_cleanup_25();
    run_test_depth50_error4_cleanup_25();
    run_test_depth30_error4_cleanup_25();
    run_test_depth10_error4_cleanup_25();
    run_test_depth01_error4_cleanup_25();
}
// Test runner
[[gnu::noinline]]
void run_test_depth70_error4_cleanup_50() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_70_error4_percent_50();
    if (!result) {
        end();
    } else {
        pause(); // Should have gotten an error
    }
}

[[gnu::noinline]]
void run_test_depth50_error4_cleanup_50() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_50_error4_percent_50();
    if (!result) {
        end();
    } else {
        pause();
    }
}

[[gnu::noinline]]
void run_test_depth30_error4_cleanup_50() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_30_error4_percent_50();
    if (!result) {
        end();
    } else {
        pause();
    }
}

[[gnu::noinline]]
void run_test_depth10_error4_cleanup_50() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_10_error4_percent_50();
    if (!result) {
        end();
    } else {
        pause();
    }
}

[[gnu::noinline]]
void run_test_depth01_error4_cleanup_50() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_01_error4_percent_50();
    if (!result) {
        end();
    } else {
        pause();
    }
}

void run_test_error4_cleanup_50() {
    run_test_depth70_error4_cleanup_50();
    run_test_depth50_error4_cleanup_50();
    run_test_depth30_error4_cleanup_50();
    run_test_depth10_error4_cleanup_50();
    run_test_depth01_error4_cleanup_50();
}
// Test runner
[[gnu::noinline]]
void run_test_depth70_error4_cleanup_75() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_70_error4_percent_75();
    if (!result) {
        end();
    } else {
        pause(); // Should have gotten an error
    }
}

[[gnu::noinline]]
void run_test_depth50_error4_cleanup_75() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_50_error4_percent_75();
    if (!result) {
        end();
    } else {
        pause();
    }
}

[[gnu::noinline]]
void run_test_depth30_error4_cleanup_75() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_30_error4_percent_75();
    if (!result) {
        end();
    } else {
        pause();
    }
}

[[gnu::noinline]]
void run_test_depth10_error4_cleanup_75() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_10_error4_percent_75();
    if (!result) {
        end();
    } else {
        pause();
    }
}

[[gnu::noinline]]
void run_test_depth01_error4_cleanup_75() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_01_error4_percent_75();
    if (!result) {
        end();
    } else {
        pause();
    }
}

void run_test_error4_cleanup_75() {
    run_test_depth70_error4_cleanup_75();
    run_test_depth50_error4_cleanup_75();
    run_test_depth30_error4_cleanup_75();
    run_test_depth10_error4_cleanup_75();
    run_test_depth01_error4_cleanup_75();
}
// Test runner
[[gnu::noinline]]
void run_test_depth70_error4_cleanup_100() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_70_error4_percent_100();
    if (!result) {
        end();
    } else {
        pause(); // Should have gotten an error
    }
}

[[gnu::noinline]]
void run_test_depth50_error4_cleanup_100() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_50_error4_percent_100();
    if (!result) {
        end();
    } else {
        pause();
    }
}

[[gnu::noinline]]
void run_test_depth30_error4_cleanup_100() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_30_error4_percent_100();
    if (!result) {
        end();
    } else {
        pause();
    }
}

[[gnu::noinline]]
void run_test_depth10_error4_cleanup_100() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_10_error4_percent_100();
    if (!result) {
        end();
    } else {
        pause();
    }
}

[[gnu::noinline]]
void run_test_depth01_error4_cleanup_100() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_01_error4_percent_100();
    if (!result) {
        end();
    } else {
        pause();
    }
}

void run_test_error4_cleanup_100() {
    run_test_depth70_error4_cleanup_100();
    run_test_depth50_error4_cleanup_100();
    run_test_depth30_error4_cleanup_100();
    run_test_depth10_error4_cleanup_100();
    run_test_depth01_error4_cleanup_100();
}
// Test runner
void run_test() {
    run_test_error4_cleanup_0();
    run_test_error4_cleanup_25();
    run_test_error4_cleanup_50();
    run_test_error4_cleanup_75();
    run_test_error4_cleanup_100();

}

