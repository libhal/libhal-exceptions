#include <array>
#include <cstdint>
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

int depth_30();
int depth_29();
int depth_28();
int depth_27();
int depth_26();
int depth_25();
int depth_24();
int depth_23();
int depth_22();
int depth_21();
int depth_20();
int depth_19();
int depth_18();
int depth_17();
int depth_16();
int depth_15();
int depth_14();
int depth_13();
int depth_12();
int depth_11();
int depth_10();
int depth_09();
int depth_08();
int depth_07();
int depth_06();
int depth_05();
int depth_04();
int depth_03();
int depth_02();
int depth_01();

[[gnu::noinline]]
int depth_30() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;

            int result = depth_29();

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_29() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;

            int result = depth_28();

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_28() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;

            int result = depth_27();

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_27() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;

            int result = depth_26();

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_26() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;

            int result = depth_25();

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;

            int result = depth_24();

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_24() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;

            int result = depth_23();

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_23() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;

            int result = depth_22();

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_22() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;

            int result = depth_21();

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_21() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;

            int result = depth_20();

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_20() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;

            int result = depth_19();

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_19() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;

            int result = depth_18();

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_18() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;

            int result = depth_17();

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_17() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;

            int result = depth_16();

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_16() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;

            int result = depth_15();

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_15() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;

            int result = depth_14();

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_14() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;

            int result = depth_13();

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_13() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;

            int result = depth_12();

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_12() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;

            int result = depth_11();

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_11() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;

            int result = depth_10();

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_10() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;

            int result = depth_09();

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_09() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;

            int result = depth_08();

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_08() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;

            int result = depth_07();

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_07() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;

            int result = depth_06();

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_06() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;

            int result = depth_05();

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_05() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;

            int result = depth_04();

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_04() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;

            int result = depth_03();

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_03() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;

            int result = depth_02();

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_02() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;

            int result = depth_01();

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_01() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }

  // This is where the exception originates
  if (side_effect > 0) {
    start();
    throw test_error{.data = {0xDE, 0xAD, 0xBE, 0xEF}};
  }

  return side_effect;
}

// Test runner
void run_test() {
  log_start("EXCEPT_0PCT_DEPTH30");
  side_effect = 1; // Ensure we will throw

  try {
    depth_30();
  } catch (const test_error& e) {
    end();
  }
}
