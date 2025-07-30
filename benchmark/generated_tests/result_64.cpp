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
struct test_error_64 {
  std::array<std::uint8_t, 64> data;
};
std::expected<int, test_error_64> depth_70_error64_percent_0();
std::expected<int, test_error_64> depth_69_error64_percent_0();
std::expected<int, test_error_64> depth_68_error64_percent_0();
std::expected<int, test_error_64> depth_67_error64_percent_0();
std::expected<int, test_error_64> depth_66_error64_percent_0();
std::expected<int, test_error_64> depth_65_error64_percent_0();
std::expected<int, test_error_64> depth_64_error64_percent_0();
std::expected<int, test_error_64> depth_63_error64_percent_0();
std::expected<int, test_error_64> depth_62_error64_percent_0();
std::expected<int, test_error_64> depth_61_error64_percent_0();
std::expected<int, test_error_64> depth_60_error64_percent_0();
std::expected<int, test_error_64> depth_59_error64_percent_0();
std::expected<int, test_error_64> depth_58_error64_percent_0();
std::expected<int, test_error_64> depth_57_error64_percent_0();
std::expected<int, test_error_64> depth_56_error64_percent_0();
std::expected<int, test_error_64> depth_55_error64_percent_0();
std::expected<int, test_error_64> depth_54_error64_percent_0();
std::expected<int, test_error_64> depth_53_error64_percent_0();
std::expected<int, test_error_64> depth_52_error64_percent_0();
std::expected<int, test_error_64> depth_51_error64_percent_0();
std::expected<int, test_error_64> depth_50_error64_percent_0();
std::expected<int, test_error_64> depth_49_error64_percent_0();
std::expected<int, test_error_64> depth_48_error64_percent_0();
std::expected<int, test_error_64> depth_47_error64_percent_0();
std::expected<int, test_error_64> depth_46_error64_percent_0();
std::expected<int, test_error_64> depth_45_error64_percent_0();
std::expected<int, test_error_64> depth_44_error64_percent_0();
std::expected<int, test_error_64> depth_43_error64_percent_0();
std::expected<int, test_error_64> depth_42_error64_percent_0();
std::expected<int, test_error_64> depth_41_error64_percent_0();
std::expected<int, test_error_64> depth_40_error64_percent_0();
std::expected<int, test_error_64> depth_39_error64_percent_0();
std::expected<int, test_error_64> depth_38_error64_percent_0();
std::expected<int, test_error_64> depth_37_error64_percent_0();
std::expected<int, test_error_64> depth_36_error64_percent_0();
std::expected<int, test_error_64> depth_35_error64_percent_0();
std::expected<int, test_error_64> depth_34_error64_percent_0();
std::expected<int, test_error_64> depth_33_error64_percent_0();
std::expected<int, test_error_64> depth_32_error64_percent_0();
std::expected<int, test_error_64> depth_31_error64_percent_0();
std::expected<int, test_error_64> depth_30_error64_percent_0();
std::expected<int, test_error_64> depth_29_error64_percent_0();
std::expected<int, test_error_64> depth_28_error64_percent_0();
std::expected<int, test_error_64> depth_27_error64_percent_0();
std::expected<int, test_error_64> depth_26_error64_percent_0();
std::expected<int, test_error_64> depth_25_error64_percent_0();
std::expected<int, test_error_64> depth_24_error64_percent_0();
std::expected<int, test_error_64> depth_23_error64_percent_0();
std::expected<int, test_error_64> depth_22_error64_percent_0();
std::expected<int, test_error_64> depth_21_error64_percent_0();
std::expected<int, test_error_64> depth_20_error64_percent_0();
std::expected<int, test_error_64> depth_19_error64_percent_0();
std::expected<int, test_error_64> depth_18_error64_percent_0();
std::expected<int, test_error_64> depth_17_error64_percent_0();
std::expected<int, test_error_64> depth_16_error64_percent_0();
std::expected<int, test_error_64> depth_15_error64_percent_0();
std::expected<int, test_error_64> depth_14_error64_percent_0();
std::expected<int, test_error_64> depth_13_error64_percent_0();
std::expected<int, test_error_64> depth_12_error64_percent_0();
std::expected<int, test_error_64> depth_11_error64_percent_0();
std::expected<int, test_error_64> depth_10_error64_percent_0();
std::expected<int, test_error_64> depth_09_error64_percent_0();
std::expected<int, test_error_64> depth_08_error64_percent_0();
std::expected<int, test_error_64> depth_07_error64_percent_0();
std::expected<int, test_error_64> depth_06_error64_percent_0();
std::expected<int, test_error_64> depth_05_error64_percent_0();
std::expected<int, test_error_64> depth_04_error64_percent_0();
std::expected<int, test_error_64> depth_03_error64_percent_0();
std::expected<int, test_error_64> depth_02_error64_percent_0();
std::expected<int, test_error_64> depth_01_error64_percent_0();
[[gnu::noinline]]
std::expected<int, test_error_64> depth_70_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 25> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_69_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_69_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 27> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_68_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_68_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 3> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_67_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_67_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 17> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_66_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_66_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 32> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_65_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_65_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 26> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_64_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_64_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 20> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_63_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_63_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 31> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_62_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_62_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 23> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_61_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_61_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 14> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_60_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_60_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 9> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_59_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_59_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 19> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_58_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_58_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 9> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_57_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_57_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 7> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_56_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_56_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 17> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_55_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_55_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 10> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_54_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_54_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 20> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_53_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_53_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 7> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_52_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_52_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 5> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_51_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_51_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 22> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_50_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_50_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 31> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_49_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_49_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 7> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_48_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_48_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 23> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_47_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_47_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 28> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_46_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_46_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 21> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_45_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_45_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 14> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_44_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_44_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 31> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_43_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_43_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 29> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_42_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_42_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 17> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_41_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_41_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 4> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_40_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_40_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 1> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_39_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_39_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 6> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_38_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_38_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 26> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_37_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_37_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 1> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_36_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_36_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 32> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_35_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_35_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 22> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_34_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_34_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 16> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_33_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_33_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 21> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_32_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_32_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 5> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_31_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_31_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 13> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_30_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_30_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 15> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_29_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_29_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 16> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_28_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_28_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 10> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_27_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_27_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 29> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_26_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_26_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 6> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_25_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_25_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 6> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_24_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_24_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 21> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_23_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_23_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 32> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_22_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_22_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 7> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_21_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_21_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 20> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_20_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_20_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 19> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_19_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_19_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 8> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_18_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_18_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 22> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_17_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_17_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 14> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_16_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_16_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 19> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_15_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_15_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 29> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_14_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_14_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 6> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_13_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_13_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 25> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_12_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_12_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 21> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_11_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_11_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 16> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_10_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_10_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 19> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_09_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_09_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 12> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_08_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_08_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 13> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_07_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_07_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 12> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_06_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_06_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 3> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_05_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_05_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 17> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_04_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_04_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 31> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_03_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_03_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 5> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_02_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_02_error64_percent_0() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 6> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_01_error64_percent_0();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_01_error64_percent_0() {
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
  return std::unexpected(test_error_64
                        {
                            .data = { 0xDE, 0xAD, 0xBE, 0xEF }
                        });
}

std::expected<int, test_error_64> depth_70_error64_percent_25();
std::expected<int, test_error_64> depth_69_error64_percent_25();
std::expected<int, test_error_64> depth_68_error64_percent_25();
std::expected<int, test_error_64> depth_67_error64_percent_25();
std::expected<int, test_error_64> depth_66_error64_percent_25();
std::expected<int, test_error_64> depth_65_error64_percent_25();
std::expected<int, test_error_64> depth_64_error64_percent_25();
std::expected<int, test_error_64> depth_63_error64_percent_25();
std::expected<int, test_error_64> depth_62_error64_percent_25();
std::expected<int, test_error_64> depth_61_error64_percent_25();
std::expected<int, test_error_64> depth_60_error64_percent_25();
std::expected<int, test_error_64> depth_59_error64_percent_25();
std::expected<int, test_error_64> depth_58_error64_percent_25();
std::expected<int, test_error_64> depth_57_error64_percent_25();
std::expected<int, test_error_64> depth_56_error64_percent_25();
std::expected<int, test_error_64> depth_55_error64_percent_25();
std::expected<int, test_error_64> depth_54_error64_percent_25();
std::expected<int, test_error_64> depth_53_error64_percent_25();
std::expected<int, test_error_64> depth_52_error64_percent_25();
std::expected<int, test_error_64> depth_51_error64_percent_25();
std::expected<int, test_error_64> depth_50_error64_percent_25();
std::expected<int, test_error_64> depth_49_error64_percent_25();
std::expected<int, test_error_64> depth_48_error64_percent_25();
std::expected<int, test_error_64> depth_47_error64_percent_25();
std::expected<int, test_error_64> depth_46_error64_percent_25();
std::expected<int, test_error_64> depth_45_error64_percent_25();
std::expected<int, test_error_64> depth_44_error64_percent_25();
std::expected<int, test_error_64> depth_43_error64_percent_25();
std::expected<int, test_error_64> depth_42_error64_percent_25();
std::expected<int, test_error_64> depth_41_error64_percent_25();
std::expected<int, test_error_64> depth_40_error64_percent_25();
std::expected<int, test_error_64> depth_39_error64_percent_25();
std::expected<int, test_error_64> depth_38_error64_percent_25();
std::expected<int, test_error_64> depth_37_error64_percent_25();
std::expected<int, test_error_64> depth_36_error64_percent_25();
std::expected<int, test_error_64> depth_35_error64_percent_25();
std::expected<int, test_error_64> depth_34_error64_percent_25();
std::expected<int, test_error_64> depth_33_error64_percent_25();
std::expected<int, test_error_64> depth_32_error64_percent_25();
std::expected<int, test_error_64> depth_31_error64_percent_25();
std::expected<int, test_error_64> depth_30_error64_percent_25();
std::expected<int, test_error_64> depth_29_error64_percent_25();
std::expected<int, test_error_64> depth_28_error64_percent_25();
std::expected<int, test_error_64> depth_27_error64_percent_25();
std::expected<int, test_error_64> depth_26_error64_percent_25();
std::expected<int, test_error_64> depth_25_error64_percent_25();
std::expected<int, test_error_64> depth_24_error64_percent_25();
std::expected<int, test_error_64> depth_23_error64_percent_25();
std::expected<int, test_error_64> depth_22_error64_percent_25();
std::expected<int, test_error_64> depth_21_error64_percent_25();
std::expected<int, test_error_64> depth_20_error64_percent_25();
std::expected<int, test_error_64> depth_19_error64_percent_25();
std::expected<int, test_error_64> depth_18_error64_percent_25();
std::expected<int, test_error_64> depth_17_error64_percent_25();
std::expected<int, test_error_64> depth_16_error64_percent_25();
std::expected<int, test_error_64> depth_15_error64_percent_25();
std::expected<int, test_error_64> depth_14_error64_percent_25();
std::expected<int, test_error_64> depth_13_error64_percent_25();
std::expected<int, test_error_64> depth_12_error64_percent_25();
std::expected<int, test_error_64> depth_11_error64_percent_25();
std::expected<int, test_error_64> depth_10_error64_percent_25();
std::expected<int, test_error_64> depth_09_error64_percent_25();
std::expected<int, test_error_64> depth_08_error64_percent_25();
std::expected<int, test_error_64> depth_07_error64_percent_25();
std::expected<int, test_error_64> depth_06_error64_percent_25();
std::expected<int, test_error_64> depth_05_error64_percent_25();
std::expected<int, test_error_64> depth_04_error64_percent_25();
std::expected<int, test_error_64> depth_03_error64_percent_25();
std::expected<int, test_error_64> depth_02_error64_percent_25();
std::expected<int, test_error_64> depth_01_error64_percent_25();
[[gnu::noinline]]
std::expected<int, test_error_64> depth_70_error64_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 10> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_69_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_69_error64_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 3> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_68_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_68_error64_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 6> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_67_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_67_error64_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 26> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_66_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_66_error64_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 18> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_65_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_65_error64_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 16> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_64_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_64_error64_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 14> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_63_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_63_error64_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 27> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_62_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_62_error64_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 18> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_61_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_61_error64_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 29> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_60_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_60_error64_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 32> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_59_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_59_error64_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 23> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_58_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_58_error64_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 6> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_57_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_57_error64_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 21> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_56_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_56_error64_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 8> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_55_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_55_error64_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 32> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_54_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_54_error64_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 22> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_53_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_53_error64_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 13> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_52_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_52_error64_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 16> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_51_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_51_error64_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 2> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_50_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_50_error64_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 18> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_49_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_49_error64_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 8> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_48_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_48_error64_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 15> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_47_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_47_error64_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 24> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_46_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_46_error64_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 11> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_45_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_45_error64_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 22> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_44_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_44_error64_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 28> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_43_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_43_error64_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 4> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_42_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_42_error64_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 7> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_41_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_41_error64_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 10> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_40_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_40_error64_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 15> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_39_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_39_error64_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 3> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_38_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_38_error64_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 5> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_37_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_37_error64_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 2> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_36_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_36_error64_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 8> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_35_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_35_error64_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 13> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_34_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_34_error64_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 8> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_33_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_33_error64_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 26> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_32_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_32_error64_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 6> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_31_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_31_error64_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 24> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_30_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_30_error64_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 8> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_29_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_29_error64_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 3> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_28_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_28_error64_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 2> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_27_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_27_error64_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 13> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_26_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_26_error64_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 12> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_25_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_25_error64_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 8> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_24_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_24_error64_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 31> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_23_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_23_error64_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 14> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_22_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_22_error64_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 4> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_21_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_21_error64_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 2> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_20_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_20_error64_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 28> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_19_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_19_error64_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 7> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_18_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_18_error64_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 17> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_17_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_17_error64_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 5> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_16_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_16_error64_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 15> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_15_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_15_error64_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 5> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_14_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_14_error64_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 20> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_13_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_13_error64_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 23> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_12_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_12_error64_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 28> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_11_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_11_error64_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 12> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_10_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_10_error64_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 4> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_09_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_09_error64_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 30> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_08_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_08_error64_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 3> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_07_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_07_error64_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 7> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_06_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_06_error64_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 26> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_05_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_05_error64_percent_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 13> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_04_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_04_error64_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 17> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_03_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_03_error64_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 23> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_02_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_02_error64_percent_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 31> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_01_error64_percent_25();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_01_error64_percent_25() {
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
  return std::unexpected(test_error_64
                        {
                            .data = { 0xDE, 0xAD, 0xBE, 0xEF }
                        });
}

std::expected<int, test_error_64> depth_70_error64_percent_50();
std::expected<int, test_error_64> depth_69_error64_percent_50();
std::expected<int, test_error_64> depth_68_error64_percent_50();
std::expected<int, test_error_64> depth_67_error64_percent_50();
std::expected<int, test_error_64> depth_66_error64_percent_50();
std::expected<int, test_error_64> depth_65_error64_percent_50();
std::expected<int, test_error_64> depth_64_error64_percent_50();
std::expected<int, test_error_64> depth_63_error64_percent_50();
std::expected<int, test_error_64> depth_62_error64_percent_50();
std::expected<int, test_error_64> depth_61_error64_percent_50();
std::expected<int, test_error_64> depth_60_error64_percent_50();
std::expected<int, test_error_64> depth_59_error64_percent_50();
std::expected<int, test_error_64> depth_58_error64_percent_50();
std::expected<int, test_error_64> depth_57_error64_percent_50();
std::expected<int, test_error_64> depth_56_error64_percent_50();
std::expected<int, test_error_64> depth_55_error64_percent_50();
std::expected<int, test_error_64> depth_54_error64_percent_50();
std::expected<int, test_error_64> depth_53_error64_percent_50();
std::expected<int, test_error_64> depth_52_error64_percent_50();
std::expected<int, test_error_64> depth_51_error64_percent_50();
std::expected<int, test_error_64> depth_50_error64_percent_50();
std::expected<int, test_error_64> depth_49_error64_percent_50();
std::expected<int, test_error_64> depth_48_error64_percent_50();
std::expected<int, test_error_64> depth_47_error64_percent_50();
std::expected<int, test_error_64> depth_46_error64_percent_50();
std::expected<int, test_error_64> depth_45_error64_percent_50();
std::expected<int, test_error_64> depth_44_error64_percent_50();
std::expected<int, test_error_64> depth_43_error64_percent_50();
std::expected<int, test_error_64> depth_42_error64_percent_50();
std::expected<int, test_error_64> depth_41_error64_percent_50();
std::expected<int, test_error_64> depth_40_error64_percent_50();
std::expected<int, test_error_64> depth_39_error64_percent_50();
std::expected<int, test_error_64> depth_38_error64_percent_50();
std::expected<int, test_error_64> depth_37_error64_percent_50();
std::expected<int, test_error_64> depth_36_error64_percent_50();
std::expected<int, test_error_64> depth_35_error64_percent_50();
std::expected<int, test_error_64> depth_34_error64_percent_50();
std::expected<int, test_error_64> depth_33_error64_percent_50();
std::expected<int, test_error_64> depth_32_error64_percent_50();
std::expected<int, test_error_64> depth_31_error64_percent_50();
std::expected<int, test_error_64> depth_30_error64_percent_50();
std::expected<int, test_error_64> depth_29_error64_percent_50();
std::expected<int, test_error_64> depth_28_error64_percent_50();
std::expected<int, test_error_64> depth_27_error64_percent_50();
std::expected<int, test_error_64> depth_26_error64_percent_50();
std::expected<int, test_error_64> depth_25_error64_percent_50();
std::expected<int, test_error_64> depth_24_error64_percent_50();
std::expected<int, test_error_64> depth_23_error64_percent_50();
std::expected<int, test_error_64> depth_22_error64_percent_50();
std::expected<int, test_error_64> depth_21_error64_percent_50();
std::expected<int, test_error_64> depth_20_error64_percent_50();
std::expected<int, test_error_64> depth_19_error64_percent_50();
std::expected<int, test_error_64> depth_18_error64_percent_50();
std::expected<int, test_error_64> depth_17_error64_percent_50();
std::expected<int, test_error_64> depth_16_error64_percent_50();
std::expected<int, test_error_64> depth_15_error64_percent_50();
std::expected<int, test_error_64> depth_14_error64_percent_50();
std::expected<int, test_error_64> depth_13_error64_percent_50();
std::expected<int, test_error_64> depth_12_error64_percent_50();
std::expected<int, test_error_64> depth_11_error64_percent_50();
std::expected<int, test_error_64> depth_10_error64_percent_50();
std::expected<int, test_error_64> depth_09_error64_percent_50();
std::expected<int, test_error_64> depth_08_error64_percent_50();
std::expected<int, test_error_64> depth_07_error64_percent_50();
std::expected<int, test_error_64> depth_06_error64_percent_50();
std::expected<int, test_error_64> depth_05_error64_percent_50();
std::expected<int, test_error_64> depth_04_error64_percent_50();
std::expected<int, test_error_64> depth_03_error64_percent_50();
std::expected<int, test_error_64> depth_02_error64_percent_50();
std::expected<int, test_error_64> depth_01_error64_percent_50();
[[gnu::noinline]]
std::expected<int, test_error_64> depth_70_error64_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 14> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_69_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_69_error64_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 4> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_68_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_68_error64_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 11> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_67_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_67_error64_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 11> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_66_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_66_error64_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 22> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_65_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_65_error64_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 17> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_64_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_64_error64_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 8> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_63_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_63_error64_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 29> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_62_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_62_error64_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 12> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_61_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_61_error64_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 1> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_60_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_60_error64_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 31> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_59_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_59_error64_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 27> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_58_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_58_error64_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 20> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_57_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_57_error64_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 23> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_56_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_56_error64_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 25> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_55_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_55_error64_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 17> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_54_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_54_error64_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 10> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_53_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_53_error64_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 1> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_52_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_52_error64_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 30> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_51_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_51_error64_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 6> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_50_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_50_error64_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 22> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_49_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_49_error64_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 3> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_48_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_48_error64_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 18> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_47_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_47_error64_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 9> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_46_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_46_error64_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 16> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_45_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_45_error64_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 31> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_44_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_44_error64_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 23> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_43_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_43_error64_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 19> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_42_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_42_error64_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 23> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_41_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_41_error64_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 9> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_40_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_40_error64_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 20> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_39_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_39_error64_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 25> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_38_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_38_error64_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 27> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_37_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_37_error64_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 6> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_36_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_36_error64_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 1> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_35_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_35_error64_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 13> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_34_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_34_error64_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 22> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_33_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_33_error64_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 11> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_32_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_32_error64_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 16> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_31_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_31_error64_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 15> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_30_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_30_error64_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 29> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_29_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_29_error64_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 25> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_28_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_28_error64_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 27> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_27_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_27_error64_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 3> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_26_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_26_error64_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 26> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_25_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_25_error64_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 27> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_24_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_24_error64_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 3> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_23_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_23_error64_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 11> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_22_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_22_error64_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 29> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_21_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_21_error64_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 5> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_20_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_20_error64_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 17> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_19_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_19_error64_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 11> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_18_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_18_error64_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 29> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_17_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_17_error64_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 32> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_16_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_16_error64_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 1> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_15_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_15_error64_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 3> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_14_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_14_error64_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 32> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_13_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_13_error64_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 21> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_12_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_12_error64_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 20> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_11_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_11_error64_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 30> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_10_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_10_error64_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 4> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_09_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_09_error64_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 27> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_08_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_08_error64_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 13> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_07_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_07_error64_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 6> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_06_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_06_error64_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 9> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_05_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_05_error64_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 1> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_04_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_04_error64_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 26> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_03_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_03_error64_percent_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 27> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_02_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_02_error64_percent_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 21> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_01_error64_percent_50();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_01_error64_percent_50() {
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
  return std::unexpected(test_error_64
                        {
                            .data = { 0xDE, 0xAD, 0xBE, 0xEF }
                        });
}

std::expected<int, test_error_64> depth_70_error64_percent_75();
std::expected<int, test_error_64> depth_69_error64_percent_75();
std::expected<int, test_error_64> depth_68_error64_percent_75();
std::expected<int, test_error_64> depth_67_error64_percent_75();
std::expected<int, test_error_64> depth_66_error64_percent_75();
std::expected<int, test_error_64> depth_65_error64_percent_75();
std::expected<int, test_error_64> depth_64_error64_percent_75();
std::expected<int, test_error_64> depth_63_error64_percent_75();
std::expected<int, test_error_64> depth_62_error64_percent_75();
std::expected<int, test_error_64> depth_61_error64_percent_75();
std::expected<int, test_error_64> depth_60_error64_percent_75();
std::expected<int, test_error_64> depth_59_error64_percent_75();
std::expected<int, test_error_64> depth_58_error64_percent_75();
std::expected<int, test_error_64> depth_57_error64_percent_75();
std::expected<int, test_error_64> depth_56_error64_percent_75();
std::expected<int, test_error_64> depth_55_error64_percent_75();
std::expected<int, test_error_64> depth_54_error64_percent_75();
std::expected<int, test_error_64> depth_53_error64_percent_75();
std::expected<int, test_error_64> depth_52_error64_percent_75();
std::expected<int, test_error_64> depth_51_error64_percent_75();
std::expected<int, test_error_64> depth_50_error64_percent_75();
std::expected<int, test_error_64> depth_49_error64_percent_75();
std::expected<int, test_error_64> depth_48_error64_percent_75();
std::expected<int, test_error_64> depth_47_error64_percent_75();
std::expected<int, test_error_64> depth_46_error64_percent_75();
std::expected<int, test_error_64> depth_45_error64_percent_75();
std::expected<int, test_error_64> depth_44_error64_percent_75();
std::expected<int, test_error_64> depth_43_error64_percent_75();
std::expected<int, test_error_64> depth_42_error64_percent_75();
std::expected<int, test_error_64> depth_41_error64_percent_75();
std::expected<int, test_error_64> depth_40_error64_percent_75();
std::expected<int, test_error_64> depth_39_error64_percent_75();
std::expected<int, test_error_64> depth_38_error64_percent_75();
std::expected<int, test_error_64> depth_37_error64_percent_75();
std::expected<int, test_error_64> depth_36_error64_percent_75();
std::expected<int, test_error_64> depth_35_error64_percent_75();
std::expected<int, test_error_64> depth_34_error64_percent_75();
std::expected<int, test_error_64> depth_33_error64_percent_75();
std::expected<int, test_error_64> depth_32_error64_percent_75();
std::expected<int, test_error_64> depth_31_error64_percent_75();
std::expected<int, test_error_64> depth_30_error64_percent_75();
std::expected<int, test_error_64> depth_29_error64_percent_75();
std::expected<int, test_error_64> depth_28_error64_percent_75();
std::expected<int, test_error_64> depth_27_error64_percent_75();
std::expected<int, test_error_64> depth_26_error64_percent_75();
std::expected<int, test_error_64> depth_25_error64_percent_75();
std::expected<int, test_error_64> depth_24_error64_percent_75();
std::expected<int, test_error_64> depth_23_error64_percent_75();
std::expected<int, test_error_64> depth_22_error64_percent_75();
std::expected<int, test_error_64> depth_21_error64_percent_75();
std::expected<int, test_error_64> depth_20_error64_percent_75();
std::expected<int, test_error_64> depth_19_error64_percent_75();
std::expected<int, test_error_64> depth_18_error64_percent_75();
std::expected<int, test_error_64> depth_17_error64_percent_75();
std::expected<int, test_error_64> depth_16_error64_percent_75();
std::expected<int, test_error_64> depth_15_error64_percent_75();
std::expected<int, test_error_64> depth_14_error64_percent_75();
std::expected<int, test_error_64> depth_13_error64_percent_75();
std::expected<int, test_error_64> depth_12_error64_percent_75();
std::expected<int, test_error_64> depth_11_error64_percent_75();
std::expected<int, test_error_64> depth_10_error64_percent_75();
std::expected<int, test_error_64> depth_09_error64_percent_75();
std::expected<int, test_error_64> depth_08_error64_percent_75();
std::expected<int, test_error_64> depth_07_error64_percent_75();
std::expected<int, test_error_64> depth_06_error64_percent_75();
std::expected<int, test_error_64> depth_05_error64_percent_75();
std::expected<int, test_error_64> depth_04_error64_percent_75();
std::expected<int, test_error_64> depth_03_error64_percent_75();
std::expected<int, test_error_64> depth_02_error64_percent_75();
std::expected<int, test_error_64> depth_01_error64_percent_75();
[[gnu::noinline]]
std::expected<int, test_error_64> depth_70_error64_percent_75() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 14> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_69_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_69_error64_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 1> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_68_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_68_error64_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 1> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_67_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_67_error64_percent_75() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 7> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_66_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_66_error64_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 13> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_65_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_65_error64_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 8> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_64_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_64_error64_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 13> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_63_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_63_error64_percent_75() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 20> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_62_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_62_error64_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 18> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_61_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_61_error64_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 12> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_60_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_60_error64_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 7> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_59_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_59_error64_percent_75() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 31> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_58_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_58_error64_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 26> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_57_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_57_error64_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 6> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_56_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_56_error64_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 2> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_55_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_55_error64_percent_75() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 18> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_54_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_54_error64_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 29> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_53_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_53_error64_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 8> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_52_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_52_error64_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 17> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_51_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_51_error64_percent_75() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 9> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_50_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_50_error64_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 23> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_49_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_49_error64_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 8> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_48_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_48_error64_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 10> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_47_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_47_error64_percent_75() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 18> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_46_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_46_error64_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 2> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_45_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_45_error64_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 3> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_44_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_44_error64_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 3> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_43_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_43_error64_percent_75() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 14> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_42_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_42_error64_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 17> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_41_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_41_error64_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 21> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_40_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_40_error64_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 24> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_39_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_39_error64_percent_75() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 3> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_38_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_38_error64_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 32> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_37_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_37_error64_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 30> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_36_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_36_error64_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 28> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_35_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_35_error64_percent_75() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 24> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_34_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_34_error64_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 12> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_33_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_33_error64_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 14> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_32_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_32_error64_percent_75() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 25> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_31_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_31_error64_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 19> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_30_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_30_error64_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 1> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_29_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_29_error64_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 9> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_28_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_28_error64_percent_75() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 10> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_27_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_27_error64_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 18> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_26_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_26_error64_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 22> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_25_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_25_error64_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 22> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_24_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_24_error64_percent_75() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 24> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_23_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_23_error64_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 6> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_22_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_22_error64_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 22> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_21_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_21_error64_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 3> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_20_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_20_error64_percent_75() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 3> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_19_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_19_error64_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 18> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_18_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_18_error64_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 11> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_17_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_17_error64_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 10> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_16_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_16_error64_percent_75() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 19> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_15_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_15_error64_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 24> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_14_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_14_error64_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 26> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_13_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_13_error64_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 9> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_12_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_12_error64_percent_75() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 19> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_11_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_11_error64_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 8> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_10_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_10_error64_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 31> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_09_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_09_error64_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 16> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_08_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_08_error64_percent_75() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 4> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_07_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_07_error64_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 20> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_06_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_06_error64_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 12> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_05_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_05_error64_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 5> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_04_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_04_error64_percent_75() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 20> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_03_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_03_error64_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 26> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_02_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_02_error64_percent_75() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 22> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_01_error64_percent_75();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_01_error64_percent_75() {
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
  return std::unexpected(test_error_64
                        {
                            .data = { 0xDE, 0xAD, 0xBE, 0xEF }
                        });
}

std::expected<int, test_error_64> depth_70_error64_percent_100();
std::expected<int, test_error_64> depth_69_error64_percent_100();
std::expected<int, test_error_64> depth_68_error64_percent_100();
std::expected<int, test_error_64> depth_67_error64_percent_100();
std::expected<int, test_error_64> depth_66_error64_percent_100();
std::expected<int, test_error_64> depth_65_error64_percent_100();
std::expected<int, test_error_64> depth_64_error64_percent_100();
std::expected<int, test_error_64> depth_63_error64_percent_100();
std::expected<int, test_error_64> depth_62_error64_percent_100();
std::expected<int, test_error_64> depth_61_error64_percent_100();
std::expected<int, test_error_64> depth_60_error64_percent_100();
std::expected<int, test_error_64> depth_59_error64_percent_100();
std::expected<int, test_error_64> depth_58_error64_percent_100();
std::expected<int, test_error_64> depth_57_error64_percent_100();
std::expected<int, test_error_64> depth_56_error64_percent_100();
std::expected<int, test_error_64> depth_55_error64_percent_100();
std::expected<int, test_error_64> depth_54_error64_percent_100();
std::expected<int, test_error_64> depth_53_error64_percent_100();
std::expected<int, test_error_64> depth_52_error64_percent_100();
std::expected<int, test_error_64> depth_51_error64_percent_100();
std::expected<int, test_error_64> depth_50_error64_percent_100();
std::expected<int, test_error_64> depth_49_error64_percent_100();
std::expected<int, test_error_64> depth_48_error64_percent_100();
std::expected<int, test_error_64> depth_47_error64_percent_100();
std::expected<int, test_error_64> depth_46_error64_percent_100();
std::expected<int, test_error_64> depth_45_error64_percent_100();
std::expected<int, test_error_64> depth_44_error64_percent_100();
std::expected<int, test_error_64> depth_43_error64_percent_100();
std::expected<int, test_error_64> depth_42_error64_percent_100();
std::expected<int, test_error_64> depth_41_error64_percent_100();
std::expected<int, test_error_64> depth_40_error64_percent_100();
std::expected<int, test_error_64> depth_39_error64_percent_100();
std::expected<int, test_error_64> depth_38_error64_percent_100();
std::expected<int, test_error_64> depth_37_error64_percent_100();
std::expected<int, test_error_64> depth_36_error64_percent_100();
std::expected<int, test_error_64> depth_35_error64_percent_100();
std::expected<int, test_error_64> depth_34_error64_percent_100();
std::expected<int, test_error_64> depth_33_error64_percent_100();
std::expected<int, test_error_64> depth_32_error64_percent_100();
std::expected<int, test_error_64> depth_31_error64_percent_100();
std::expected<int, test_error_64> depth_30_error64_percent_100();
std::expected<int, test_error_64> depth_29_error64_percent_100();
std::expected<int, test_error_64> depth_28_error64_percent_100();
std::expected<int, test_error_64> depth_27_error64_percent_100();
std::expected<int, test_error_64> depth_26_error64_percent_100();
std::expected<int, test_error_64> depth_25_error64_percent_100();
std::expected<int, test_error_64> depth_24_error64_percent_100();
std::expected<int, test_error_64> depth_23_error64_percent_100();
std::expected<int, test_error_64> depth_22_error64_percent_100();
std::expected<int, test_error_64> depth_21_error64_percent_100();
std::expected<int, test_error_64> depth_20_error64_percent_100();
std::expected<int, test_error_64> depth_19_error64_percent_100();
std::expected<int, test_error_64> depth_18_error64_percent_100();
std::expected<int, test_error_64> depth_17_error64_percent_100();
std::expected<int, test_error_64> depth_16_error64_percent_100();
std::expected<int, test_error_64> depth_15_error64_percent_100();
std::expected<int, test_error_64> depth_14_error64_percent_100();
std::expected<int, test_error_64> depth_13_error64_percent_100();
std::expected<int, test_error_64> depth_12_error64_percent_100();
std::expected<int, test_error_64> depth_11_error64_percent_100();
std::expected<int, test_error_64> depth_10_error64_percent_100();
std::expected<int, test_error_64> depth_09_error64_percent_100();
std::expected<int, test_error_64> depth_08_error64_percent_100();
std::expected<int, test_error_64> depth_07_error64_percent_100();
std::expected<int, test_error_64> depth_06_error64_percent_100();
std::expected<int, test_error_64> depth_05_error64_percent_100();
std::expected<int, test_error_64> depth_04_error64_percent_100();
std::expected<int, test_error_64> depth_03_error64_percent_100();
std::expected<int, test_error_64> depth_02_error64_percent_100();
std::expected<int, test_error_64> depth_01_error64_percent_100();
[[gnu::noinline]]
std::expected<int, test_error_64> depth_70_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 27> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_69_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_69_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 7> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_68_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_68_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 7> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_67_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_67_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 31> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_66_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_66_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 31> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_65_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_65_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 22> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_64_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_64_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 22> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_63_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_63_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 8> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_62_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_62_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 31> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_61_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_61_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 8> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_60_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_60_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 32> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_59_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_59_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 28> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_58_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_58_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 3> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_57_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_57_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 20> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_56_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_56_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 22> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_55_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_55_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 10> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_54_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_54_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 11> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_53_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_53_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 25> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_52_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_52_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 6> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_51_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_51_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 5> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_50_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_50_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 6> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_49_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_49_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 13> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_48_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_48_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 15> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_47_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_47_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 4> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_46_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_46_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 25> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_45_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_45_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 1> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_44_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_44_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 7> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_43_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_43_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 26> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_42_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_42_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 19> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_41_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_41_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 29> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_40_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_40_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 32> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_39_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_39_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 14> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_38_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_38_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 28> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_37_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_37_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 6> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_36_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_36_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 24> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_35_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_35_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 15> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_34_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_34_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 17> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_33_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_33_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 11> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_32_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_32_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 28> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_31_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_31_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 13> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_30_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_30_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 23> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_29_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_29_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 8> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_28_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_28_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 5> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_27_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_27_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 2> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_26_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_26_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 29> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_25_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_25_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 13> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_24_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_24_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 8> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_23_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_23_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 32> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_22_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_22_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 26> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_21_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_21_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 17> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_20_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_20_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 14> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_19_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_19_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 3> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_18_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_18_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 14> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_17_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_17_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 10> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_16_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_16_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 7> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_15_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_15_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 13> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_14_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_14_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 30> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_13_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_13_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 25> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_12_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_12_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 24> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_11_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_11_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 10> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_10_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_10_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 7> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_09_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_09_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 32> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_08_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_08_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 10> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_07_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_07_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 26> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_06_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_06_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 28> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_05_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_05_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 32> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_04_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_04_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 21> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_03_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_03_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 32> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_02_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_02_error64_percent_100() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, 32> preserve_frame =
    {
      side_effect,
    };

  auto result = depth_01_error64_percent_100();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }

  if (!result) {
    return std::unexpected(result.error());
  }

  return result.value() + side_effect;
}

[[gnu::noinline]]
std::expected<int, test_error_64> depth_01_error64_percent_100() {
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
  return std::unexpected(test_error_64
                        {
                            .data = { 0xDE, 0xAD, 0xBE, 0xEF }
                        });
}

// Test runner
[[gnu::noinline]]
void run_test_depth70_error64_cleanup_0() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_70_error64_percent_0();
    if (!result) {
        end();
    } else {
        pause(); // Should have gotten an error
    }
}

[[gnu::noinline]]
void run_test_depth50_error64_cleanup_0() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_50_error64_percent_0();
    if (!result) {
        end();
    } else {
        pause();
    }
}

[[gnu::noinline]]
void run_test_depth30_error64_cleanup_0() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_30_error64_percent_0();
    if (!result) {
        end();
    } else {
        pause();
    }
}

[[gnu::noinline]]
void run_test_depth10_error64_cleanup_0() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_10_error64_percent_0();
    if (!result) {
        end();
    } else {
        pause();
    }
}

[[gnu::noinline]]
void run_test_depth01_error64_cleanup_0() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_01_error64_percent_0();
    if (!result) {
        end();
    } else {
        pause();
    }
}

void run_test_error64_cleanup_0() {
    run_test_depth70_error64_cleanup_0();
    run_test_depth50_error64_cleanup_0();
    run_test_depth30_error64_cleanup_0();
    run_test_depth10_error64_cleanup_0();
    run_test_depth01_error64_cleanup_0();
}
// Test runner
[[gnu::noinline]]
void run_test_depth70_error64_cleanup_25() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_70_error64_percent_25();
    if (!result) {
        end();
    } else {
        pause(); // Should have gotten an error
    }
}

[[gnu::noinline]]
void run_test_depth50_error64_cleanup_25() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_50_error64_percent_25();
    if (!result) {
        end();
    } else {
        pause();
    }
}

[[gnu::noinline]]
void run_test_depth30_error64_cleanup_25() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_30_error64_percent_25();
    if (!result) {
        end();
    } else {
        pause();
    }
}

[[gnu::noinline]]
void run_test_depth10_error64_cleanup_25() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_10_error64_percent_25();
    if (!result) {
        end();
    } else {
        pause();
    }
}

[[gnu::noinline]]
void run_test_depth01_error64_cleanup_25() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_01_error64_percent_25();
    if (!result) {
        end();
    } else {
        pause();
    }
}

void run_test_error64_cleanup_25() {
    run_test_depth70_error64_cleanup_25();
    run_test_depth50_error64_cleanup_25();
    run_test_depth30_error64_cleanup_25();
    run_test_depth10_error64_cleanup_25();
    run_test_depth01_error64_cleanup_25();
}
// Test runner
[[gnu::noinline]]
void run_test_depth70_error64_cleanup_50() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_70_error64_percent_50();
    if (!result) {
        end();
    } else {
        pause(); // Should have gotten an error
    }
}

[[gnu::noinline]]
void run_test_depth50_error64_cleanup_50() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_50_error64_percent_50();
    if (!result) {
        end();
    } else {
        pause();
    }
}

[[gnu::noinline]]
void run_test_depth30_error64_cleanup_50() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_30_error64_percent_50();
    if (!result) {
        end();
    } else {
        pause();
    }
}

[[gnu::noinline]]
void run_test_depth10_error64_cleanup_50() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_10_error64_percent_50();
    if (!result) {
        end();
    } else {
        pause();
    }
}

[[gnu::noinline]]
void run_test_depth01_error64_cleanup_50() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_01_error64_percent_50();
    if (!result) {
        end();
    } else {
        pause();
    }
}

void run_test_error64_cleanup_50() {
    run_test_depth70_error64_cleanup_50();
    run_test_depth50_error64_cleanup_50();
    run_test_depth30_error64_cleanup_50();
    run_test_depth10_error64_cleanup_50();
    run_test_depth01_error64_cleanup_50();
}
// Test runner
[[gnu::noinline]]
void run_test_depth70_error64_cleanup_75() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_70_error64_percent_75();
    if (!result) {
        end();
    } else {
        pause(); // Should have gotten an error
    }
}

[[gnu::noinline]]
void run_test_depth50_error64_cleanup_75() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_50_error64_percent_75();
    if (!result) {
        end();
    } else {
        pause();
    }
}

[[gnu::noinline]]
void run_test_depth30_error64_cleanup_75() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_30_error64_percent_75();
    if (!result) {
        end();
    } else {
        pause();
    }
}

[[gnu::noinline]]
void run_test_depth10_error64_cleanup_75() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_10_error64_percent_75();
    if (!result) {
        end();
    } else {
        pause();
    }
}

[[gnu::noinline]]
void run_test_depth01_error64_cleanup_75() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_01_error64_percent_75();
    if (!result) {
        end();
    } else {
        pause();
    }
}

void run_test_error64_cleanup_75() {
    run_test_depth70_error64_cleanup_75();
    run_test_depth50_error64_cleanup_75();
    run_test_depth30_error64_cleanup_75();
    run_test_depth10_error64_cleanup_75();
    run_test_depth01_error64_cleanup_75();
}
// Test runner
[[gnu::noinline]]
void run_test_depth70_error64_cleanup_100() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_70_error64_percent_100();
    if (!result) {
        end();
    } else {
        pause(); // Should have gotten an error
    }
}

[[gnu::noinline]]
void run_test_depth50_error64_cleanup_100() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_50_error64_percent_100();
    if (!result) {
        end();
    } else {
        pause();
    }
}

[[gnu::noinline]]
void run_test_depth30_error64_cleanup_100() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_30_error64_percent_100();
    if (!result) {
        end();
    } else {
        pause();
    }
}

[[gnu::noinline]]
void run_test_depth10_error64_cleanup_100() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_10_error64_percent_100();
    if (!result) {
        end();
    } else {
        pause();
    }
}

[[gnu::noinline]]
void run_test_depth01_error64_cleanup_100() {
    side_effect = 1; // Ensure we will return error

    auto result = depth_01_error64_percent_100();
    if (!result) {
        end();
    } else {
        pause();
    }
}

void run_test_error64_cleanup_100() {
    run_test_depth70_error64_cleanup_100();
    run_test_depth50_error64_cleanup_100();
    run_test_depth30_error64_cleanup_100();
    run_test_depth10_error64_cleanup_100();
    run_test_depth01_error64_cleanup_100();
}
// Test runner
void run_test() {
    run_test_error64_cleanup_0();
    run_test_error64_cleanup_25();
    run_test_error64_cleanup_50();
    run_test_error64_cleanup_75();
    run_test_error64_cleanup_100();

}

