#include <array>
#include <cstdint>
#include <expected>
#include <string_view>

#include <platform.hpp>

// Global side effect to prevent optimization
std::int32_t volatile side_effect = 0;

// Error type for testing
struct test_error
{
  std::array<std::uint8_t, 4> data;
};

using result_type = std::expected<int, test_error>;

// Simple class without destructor
class simple_object
{
public:
  explicit simple_object(std::int32_t value)
    : m_value(value)
  {
    side_effect = side_effect + 1;
  }

  void do_work()
  {
    side_effect = side_effect + m_value;
  }

private:
  std::int32_t m_value;
};

// Class with destructor for testing destructor impact
class destructor_object
{
public:
  explicit destructor_object(std::int32_t value)
    : m_value(value)
  {
    side_effect = side_effect + 1;
  }

  ~destructor_object()
  {
    side_effect = side_effect + 1;
  }

  void do_work()
  {
    side_effect = side_effect + m_value;
  }

private:
  std::int32_t m_value;
};

result_type depth_70();
result_type depth_69();
result_type depth_68();
result_type depth_67();
result_type depth_66();
result_type depth_65();
result_type depth_64();
result_type depth_63();
result_type depth_62();
result_type depth_61();
result_type depth_60();
result_type depth_59();
result_type depth_58();
result_type depth_57();
result_type depth_56();
result_type depth_55();
result_type depth_54();
result_type depth_53();
result_type depth_52();
result_type depth_51();
result_type depth_50();
result_type depth_49();
result_type depth_48();
result_type depth_47();
result_type depth_46();
result_type depth_45();
result_type depth_44();
result_type depth_43();
result_type depth_42();
result_type depth_41();
result_type depth_40();
result_type depth_39();
result_type depth_38();
result_type depth_37();
result_type depth_36();
result_type depth_35();
result_type depth_34();
result_type depth_33();
result_type depth_32();
result_type depth_31();
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
result_type depth_70()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_69();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_69()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_68();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_68()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_67();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_67()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_66();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_66()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_65();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_65()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_64();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_64()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_63();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_63()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_62();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_62()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_61();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_61()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_60();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_60()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_59();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_59()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_58();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_58()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_57();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_57()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_56();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_56()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_55();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_55()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_54();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_54()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_53();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_53()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_52();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_52()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_51();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_51()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_50();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_50()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_49();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_49()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_48();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_48()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_47();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_47()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_46();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_46()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_45();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_45()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_44();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_44()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_43();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_43()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_42();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_42()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_41();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_41()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_40();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_40()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_39();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_39()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_38();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_38()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_37();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_37()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_36();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_36()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_35();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_35()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_34();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_34()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_33();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_33()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_32();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_32()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_31();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_31()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_30();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_30()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_29();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_29()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_28();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_28()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_27();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_27()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_26();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_26()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_25();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_25()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_24();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_24()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_23();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_23()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_22();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_22()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_21();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_21()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_20();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_20()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_19();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_19()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_18();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_18()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_17();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_17()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_16();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_16()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_15();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_15()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_14();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_14()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_13();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_13()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_12();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_12()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_11();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_11()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_10();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_10()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_09();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_09()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_08();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_08()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_07();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_07()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_06();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_06()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_05();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_05()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_04();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_04()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_03();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_03()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_02();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_02()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;
  auto result = depth_01();
  if (!result) {
    return result;  // Propagate error
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return result.value();
}

[[gnu::noinline]]
result_type depth_01()
{
  destructor_object obj(side_effect >> 8);
  obj.do_work();

  int volatile preserve_frame = side_effect;

  // This is where the error originates
  if (side_effect > 0) {
    start();
    return std::unexpected(test_error{ .data = { 0xDE, 0xAD, 0xBE, 0xEF } });
  }

  // Use the variable after the call
  if (preserve_frame < 0) {
    return -1;  // Never executed but prevents optimization
  }

  return side_effect;
}

// Test runner
void run_test()
{
  log_start("RESULT-100%-DEPTH70");
  side_effect = 1;  // Ensure we will return error

  auto result_70 = depth_70();
  if (!result_70) {
    end();
  }
  auto result_50 = depth_50();
  if (!result_50) {
    end();
  }
  auto result_30 = depth_30();
  if (!result_30) {
    end();
  }
  auto result_10 = depth_10();
  if (!result_10) {
    end();
  }
}
