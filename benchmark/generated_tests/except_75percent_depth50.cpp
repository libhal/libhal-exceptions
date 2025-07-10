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

int depth_50();
int depth_49();
int depth_48();
int depth_47();
int depth_46();
int depth_45();
int depth_44();
int depth_43();
int depth_42();
int depth_41();
int depth_40();
int depth_39();
int depth_38();
int depth_37();
int depth_36();
int depth_35();
int depth_34();
int depth_33();
int depth_32();
int depth_31();
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
int depth_50() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;

            int result = depth_49();

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_49() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;

            int result = depth_48();

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_48() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;

            int result = depth_47();

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_47() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;

            int result = depth_46();

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_46() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;

            int result = depth_45();

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_45() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;

            int result = depth_44();

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_44() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;

            int result = depth_43();

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_43() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;

            int result = depth_42();

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_42() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;

            int result = depth_41();

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_41() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;

            int result = depth_40();

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_40() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;

            int result = depth_39();

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_39() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;

            int result = depth_38();

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_38() {
  simple_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;

            int result = depth_37();

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_37() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;

            int result = depth_36();

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_36() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;

            int result = depth_35();

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_35() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;

            int result = depth_34();

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_34() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;

            int result = depth_33();

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_33() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;

            int result = depth_32();

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_32() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;

            int result = depth_31();

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_31() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;

            int result = depth_30();

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1; // Never executed but prevents optimization
  }
  return result + side_effect;
}

[[gnu::noinline]]
int depth_30() {
  destructor_object obj(side_effect >> 8);
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
  destructor_object obj(side_effect >> 8);
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
  destructor_object obj(side_effect >> 8);
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
  destructor_object obj(side_effect >> 8);
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
  destructor_object obj(side_effect >> 8);
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
  destructor_object obj(side_effect >> 8);
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
  destructor_object obj(side_effect >> 8);
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
  destructor_object obj(side_effect >> 8);
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
  destructor_object obj(side_effect >> 8);
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
  destructor_object obj(side_effect >> 8);
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
  destructor_object obj(side_effect >> 8);
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
  destructor_object obj(side_effect >> 8);
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
  destructor_object obj(side_effect >> 8);
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
  destructor_object obj(side_effect >> 8);
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
  destructor_object obj(side_effect >> 8);
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
  destructor_object obj(side_effect >> 8);
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
  destructor_object obj(side_effect >> 8);
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
  destructor_object obj(side_effect >> 8);
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
  destructor_object obj(side_effect >> 8);
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
  destructor_object obj(side_effect >> 8);
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
  destructor_object obj(side_effect >> 8);
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
  destructor_object obj(side_effect >> 8);
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
  destructor_object obj(side_effect >> 8);
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
  destructor_object obj(side_effect >> 8);
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
  destructor_object obj(side_effect >> 8);
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
  destructor_object obj(side_effect >> 8);
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
  destructor_object obj(side_effect >> 8);
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
  destructor_object obj(side_effect >> 8);
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
  destructor_object obj(side_effect >> 8);
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
  destructor_object obj(side_effect >> 8);
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
  log_start("EXCEPT_75PCT_DEPTH50");
  side_effect = 1; // Ensure we will throw

  try {
    depth_50();
  } catch (const test_error& e) {
    end();
  }
}
