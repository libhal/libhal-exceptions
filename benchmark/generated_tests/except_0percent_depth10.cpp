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
  log_start("EXCEPT_0PCT_DEPTH10");
  side_effect = 1; // Ensure we will throw

  try {
    depth_10();
  } catch (const test_error& e) {
    end();
  }
}
