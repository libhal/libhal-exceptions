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

int depth_70();
int depth_69();
int depth_68();
int depth_67();
int depth_66();
int depth_65();
int depth_64();
int depth_63();
int depth_62();
int depth_61();
int depth_60();
int depth_59();
int depth_58();
int depth_57();
int depth_56();
int depth_55();
int depth_54();
int depth_53();
int depth_52();
int depth_51();
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
int depth_70() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_69();
}

[[gnu::noinline]]
int depth_69() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_68();
}

[[gnu::noinline]]
int depth_68() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_67();
}

[[gnu::noinline]]
int depth_67() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_66();
}

[[gnu::noinline]]
int depth_66() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_65();
}

[[gnu::noinline]]
int depth_65() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_64();
}

[[gnu::noinline]]
int depth_64() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_63();
}

[[gnu::noinline]]
int depth_63() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_62();
}

[[gnu::noinline]]
int depth_62() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_61();
}

[[gnu::noinline]]
int depth_61() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_60();
}

[[gnu::noinline]]
int depth_60() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_59();
}

[[gnu::noinline]]
int depth_59() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_58();
}

[[gnu::noinline]]
int depth_58() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_57();
}

[[gnu::noinline]]
int depth_57() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_56();
}

[[gnu::noinline]]
int depth_56() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_55();
}

[[gnu::noinline]]
int depth_55() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_54();
}

[[gnu::noinline]]
int depth_54() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_53();
}

[[gnu::noinline]]
int depth_53() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_52();
}

[[gnu::noinline]]
int depth_52() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_51();
}

[[gnu::noinline]]
int depth_51() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_50();
}

[[gnu::noinline]]
int depth_50() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_49();
}

[[gnu::noinline]]
int depth_49() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_48();
}

[[gnu::noinline]]
int depth_48() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_47();
}

[[gnu::noinline]]
int depth_47() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_46();
}

[[gnu::noinline]]
int depth_46() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_45();
}

[[gnu::noinline]]
int depth_45() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_44();
}

[[gnu::noinline]]
int depth_44() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_43();
}

[[gnu::noinline]]
int depth_43() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_42();
}

[[gnu::noinline]]
int depth_42() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_41();
}

[[gnu::noinline]]
int depth_41() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_40();
}

[[gnu::noinline]]
int depth_40() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_39();
}

[[gnu::noinline]]
int depth_39() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_38();
}

[[gnu::noinline]]
int depth_38() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_37();
}

[[gnu::noinline]]
int depth_37() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_36();
}

[[gnu::noinline]]
int depth_36() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_35();
}

[[gnu::noinline]]
int depth_35() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_34();
}

[[gnu::noinline]]
int depth_34() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_33();
}

[[gnu::noinline]]
int depth_33() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_32();
}

[[gnu::noinline]]
int depth_32() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_31();
}

[[gnu::noinline]]
int depth_31() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_30();
}

[[gnu::noinline]]
int depth_30() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_29();
}

[[gnu::noinline]]
int depth_29() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_28();
}

[[gnu::noinline]]
int depth_28() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_27();
}

[[gnu::noinline]]
int depth_27() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_26();
}

[[gnu::noinline]]
int depth_26() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_25();
}

[[gnu::noinline]]
int depth_25() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_24();
}

[[gnu::noinline]]
int depth_24() {
  destructor_object obj(side_effect >> 8);
  obj.do_work();
  return depth_23();
}

[[gnu::noinline]]
int depth_23() {
  destructor_object obj(side_effect >> 8);
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
  log_start("EXCEPT_100PCT_DEPTH70");
  side_effect = 1; // Ensure we will throw

  try {
    depth_70();
  } catch (const test_error& e) {
    end();
  }
}
