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
  return depth_29();
}

[[gnu::noinline]]
int depth_29() {
  simple_object obj(side_effect >> 8);
  obj.do_work();
  return depth_28();
}

[[gnu::noinline]]
int depth_28() {
  simple_object obj(side_effect >> 8);
  obj.do_work();
  return depth_27();
}

[[gnu::noinline]]
int depth_27() {
  simple_object obj(side_effect >> 8);
  obj.do_work();
  return depth_26();
}

[[gnu::noinline]]
int depth_26() {
  simple_object obj(side_effect >> 8);
  obj.do_work();
  return depth_25();
}

[[gnu::noinline]]
int depth_25() {
  simple_object obj(side_effect >> 8);
  obj.do_work();
  return depth_24();
}

[[gnu::noinline]]
int depth_24() {
  simple_object obj(side_effect >> 8);
  obj.do_work();
  return depth_23();
}

[[gnu::noinline]]
int depth_23() {
  simple_object obj(side_effect >> 8);
  obj.do_work();
  return depth_22();
}

[[gnu::noinline]]
int depth_22() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_21();
}

[[gnu::noinline]]
int depth_21() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_20();
}

[[gnu::noinline]]
int depth_20() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_19();
}

[[gnu::noinline]]
int depth_19() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_18();
}

[[gnu::noinline]]
int depth_18() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_17();
}

[[gnu::noinline]]
int depth_17() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_16();
}

[[gnu::noinline]]
int depth_16() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_15();
}

[[gnu::noinline]]
int depth_15() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_14();
}

[[gnu::noinline]]
int depth_14() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_13();
}

[[gnu::noinline]]
int depth_13() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_12();
}

[[gnu::noinline]]
int depth_12() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_11();
}

[[gnu::noinline]]
int depth_11() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_10();
}

[[gnu::noinline]]
int depth_10() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_09();
}

[[gnu::noinline]]
int depth_09() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_08();
}

[[gnu::noinline]]
int depth_08() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_07();
}

[[gnu::noinline]]
int depth_07() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_06();
}

[[gnu::noinline]]
int depth_06() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_05();
}

[[gnu::noinline]]
int depth_05() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_04();
}

[[gnu::noinline]]
int depth_04() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_03();
}

[[gnu::noinline]]
int depth_03() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_02();
}

[[gnu::noinline]]
int depth_02() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_01();
}

[[gnu::noinline]]
int depth_01() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  // This is where the exception originates
  if (side_effect > 0) {
    start();
    throw test_error{.data = {0xDE, 0xAD, 0xBE, 0xEF}};
  }

  return side_effect;
}

// Test runner
void run_test() {
  log_start("EXCEPT_75PCT_DEPTH30");
  side_effect = 1; // Ensure we will throw

  try {
    depth_30();
  } catch (const test_error& e) {
    end();
  }
}
