#include <array>
#include <cstdint>
#include <expected>
#include <string_view>

// External functions
extern void start();
extern void end();
extern void log_start(std::string_view);

// Global side effect to prevent optimization
std::int32_t volatile side_effect = 0;

// Error type for testing
struct test_error {
  std::array<std::uint8_t, 4> data;
};

using result_type = std::expected<int, test_error>;

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

result_type depth_30();
result_type depth_29();
result_type depth_28();
result_type depth_27();
result_type depth_26();
result_type depth_25();
result_type depth_24();
result_type depth_23();
result_type depth_22();
result_type depth_21();
result_type depth_20();
result_type depth_19();
result_type depth_18();
result_type depth_17();
result_type depth_16();
result_type depth_15();
result_type depth_14();
result_type depth_13();
result_type depth_12();
result_type depth_11();
result_type depth_10();
result_type depth_09();
result_type depth_08();
result_type depth_07();
result_type depth_06();
result_type depth_05();
result_type depth_04();
result_type depth_03();
result_type depth_02();
result_type depth_01();

[[gnu::noinline]]
result_type depth_30() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;
  auto result = depth_29();
  if (!result) {
    return result; // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_29() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;
  auto result = depth_28();
  if (!result) {
    return result; // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_28() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;
  auto result = depth_27();
  if (!result) {
    return result; // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_27() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;
  auto result = depth_26();
  if (!result) {
    return result; // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_26() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;
  auto result = depth_25();
  if (!result) {
    return result; // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;
  auto result = depth_24();
  if (!result) {
    return result; // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_24() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;
  auto result = depth_23();
  if (!result) {
    return result; // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_23() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;
  auto result = depth_22();
  if (!result) {
    return result; // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_22() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;
  auto result = depth_21();
  if (!result) {
    return result; // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_21() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;
  auto result = depth_20();
  if (!result) {
    return result; // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_20() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;
  auto result = depth_19();
  if (!result) {
    return result; // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_19() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;
  auto result = depth_18();
  if (!result) {
    return result; // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_18() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;
  auto result = depth_17();
  if (!result) {
    return result; // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_17() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;
  auto result = depth_16();
  if (!result) {
    return result; // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_16() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;
  auto result = depth_15();
  if (!result) {
    return result; // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_15() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;
  auto result = depth_14();
  if (!result) {
    return result; // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_14() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;
  auto result = depth_13();
  if (!result) {
    return result; // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_13() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;
  auto result = depth_12();
  if (!result) {
    return result; // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_12() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;
  auto result = depth_11();
  if (!result) {
    return result; // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_11() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;
  auto result = depth_10();
  if (!result) {
    return result; // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_10() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;
  auto result = depth_09();
  if (!result) {
    return result; // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_09() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;
  auto result = depth_08();
  if (!result) {
    return result; // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_08() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;
  auto result = depth_07();
  if (!result) {
    return result; // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_07() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;
  auto result = depth_06();
  if (!result) {
    return result; // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_06() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;
  auto result = depth_05();
  if (!result) {
    return result; // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_05() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;
  auto result = depth_04();
  if (!result) {
    return result; // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_04() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;
  auto result = depth_03();
  if (!result) {
    return result; // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_03() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;
  auto result = depth_02();
  if (!result) {
    return result; // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_02() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;
  auto result = depth_01();
  if (!result) {
    return result; // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_01() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;

  // This is where the error originates
  if (side_effect > 0) {
    start();
    return std::unexpected(test_error{.data = {0xDE, 0xAD, 0xBE, 0xEF}});
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }

  return side_effect;
}

// Test runner
void run_test() {
  log_start("RESULT_100PCT_DEPTH30");
  side_effect = 1; // Ensure we will return error

  auto result = depth_30();
  if (!result) {
    end();
  }
}
