
std::array<int volatile, 4> side_effect_array{};

[[gnu::noinline]]
void run_test_again_but_different()
{
  // Now the compiler cannot guess as to which try catch it will be caught by.
  if (additional_side_effect > 0) {
    try {
      depth_01();
    } catch (test_error2 const& e) {
      end();
      additional_side_effect = additional_side_effect + 1;
    }
  }
}

[[gnu::noinline]]
void run70()
{
  try {
    depth_70();
  } catch (test_error const& e) {
    end();
    side_effect_array[0] = 1;
  }
}

[[gnu::noinline]]
void run50()
{
  try {
    depth_50();
  } catch (test_error2 const& e) {
    end();
    side_effect_array[1] = 2;
  } catch (test_error const& e) {
    end();
    side_effect_array[0] = 1;
  }
}

[[gnu::noinline]]
void run30()
{
  try {
    depth_30();
  } catch (test_error2 const& e) {
    end();
    side_effect_array[1] = 2;
  } catch (test_error const& e) {
    end();
    side_effect_array[2] = 3;
  }
}

[[gnu::noinline]]
void run10()
{
  try {
    depth_10();
  } catch (test_error const& e) {
    end();
    side_effect_array[3] = 4;
  } catch (test_error2 const& e) {
    end();
    side_effect_array[1] = 2;
  }
}

// Test runner
[[gnu::noinline]]
void run_test()
{
  log_start("EXCEPT_0PCT_DEPTH70");
  additional_side_effect = 1;
  // Ensure we will throw
  side_effect = 1;

  run70();
  pause();
  run50();
  pause();
  run30();
  pause();
  run10();
  pause();

  run_test_again_but_different();
}
