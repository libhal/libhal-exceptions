#!/usr/bin/env python3

from pathlib import Path


def generate_exception_file(destructor_percent: int, depth: int) -> str:
    """Generate C++ file for exception-based error propagation test."""

    # Calculate how many functions should have destructors
    destructor_count = int((destructor_percent / 100.0) * depth)

    content = f'''#include <array>
#include <cstdint>
#include <string_view>

// External functions
extern void start();
extern void end();
extern void log_start(std::string_view);

// Global side effect to prevent optimization
std::int32_t volatile side_effect = 0;

// Error type for testing
struct test_error {{
  std::array<std::uint8_t, 4> data;
}};

// Simple class without destructor
class simple_object {{
public:
  explicit simple_object(std::int32_t value) : m_value(value) {{
    side_effect = side_effect + 1;
  }}

  void do_work() {{
    side_effect = side_effect + m_value;
  }}

private:
  std::int32_t m_value;
}};

// Class with destructor for testing destructor impact
class destructor_object {{
public:
  explicit destructor_object(std::int32_t value) : m_value(value) {{
    side_effect = side_effect + 1;
  }}

  ~destructor_object() {{
    side_effect = side_effect + 1;
  }}

  void do_work() {{
    side_effect = side_effect + m_value;
  }}

private:
  std::int32_t m_value;
}};

'''

    # Generate forward declarations
    for i in range(depth, 0, -1):
        content += f"int depth_{i:02d}();\n"

    content += "\n"

    # Generate function implementations
    for i in range(depth, 0, -1):
        # Determine if this function should have a destructor
        has_destructor = i <= destructor_count
        obj_type = "destructor_object" if has_destructor else "simple_object"

        content += f'''[[gnu::noinline]]
int depth_{i:02d}() {{
  {obj_type} obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;
'''

        if i == 1:  # Last function - this is where we throw
            content += f'''
  // Use the variable after the call
  if (preserve_frame < 0) {{
    return -1; // Never executed but prevents optimization
  }}

  // This is where the exception originates
  if (side_effect > 0) {{
    start();
    throw test_error{{.data = {{0xDE, 0xAD, 0xBE, 0xEF}}}};
  }}

  return side_effect;
}}

'''
        else:  # Call next function in chain
            content += f'''
            int result = depth_{i-1:02d}();

  // Use the variable after the call
  if (preserve_frame < 0) {{
    return -1; // Never executed but prevents optimization
  }}
  return result + side_effect;
}}

'''

    # Generate test runner
    content += f'''// Test runner
void run_test() {{
  log_start("EXCEPT_{destructor_percent}PCT_DEPTH{depth}");
  side_effect = 1; // Ensure we will throw

  try {{
    depth_{depth:02d}();
  }} catch (const test_error& e) {{
    end();
  }}
}}
'''

    return content


def generate_result_file(destructor_percent: int, depth: int) -> str:
    """Generate C++ file for std::expected-based error propagation test."""

    # Calculate how many functions should have destructors
    destructor_count = int((destructor_percent / 100.0) * depth)

    content = f'''#include <array>
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
struct test_error {{
  std::array<std::uint8_t, 4> data;
}};

using result_type = std::expected<int, test_error>;

// Simple class without destructor
class simple_object {{
public:
  explicit simple_object(std::int32_t value) : m_value(value) {{
    side_effect = side_effect + 1;
  }}

  void do_work() {{
    side_effect = side_effect + m_value;
  }}

private:
  std::int32_t m_value;
}};

// Class with destructor for testing destructor impact
class destructor_object {{
public:
  explicit destructor_object(std::int32_t value) : m_value(value) {{
    side_effect = side_effect + 1;
  }}

  ~destructor_object() {{
    side_effect = side_effect + 1;
  }}

  void do_work() {{
    side_effect = side_effect + m_value;
  }}

private:
  std::int32_t m_value;
}};

'''

    # Generate forward declarations
    for i in range(depth, 0, -1):
        content += f"result_type depth_{i:02d}();\n"

    content += "\n"

    # Generate function implementations
    for i in range(depth, 0, -1):
        # Determine if this function should have a destructor
        has_destructor = i <= destructor_count
        obj_type = "destructor_object" if has_destructor else "simple_object"

        content += f'''[[gnu::noinline]]
result_type depth_{i:02d}() {{
  {obj_type} obj(side_effect >> 8);
  obj.do_work();

  volatile int preserve_frame = side_effect;
'''

        if i == 1:  # Last function - this is where we return error
            content += f'''
  // This is where the error originates
  if (side_effect > 0) {{
    start();
    return std::unexpected(test_error{{.data = {{0xDE, 0xAD, 0xBE, 0xEF}}}});
  }}

  // Use the variable after the call
  if (preserve_frame < 0) {{
    return -1; // Never executed but prevents optimization
  }}

  return side_effect;
}}

'''
        else:  # Call next function in chain and propagate error
            content += f'''  auto result = depth_{i-1:02d}();
  if (!result) {{
    return result; // Propagate error
  }}

  // Use the variable after the call
  if (preserve_frame < 0) {{
    return -1; // Never executed but prevents optimization
  }}

  return result.value();
}}

'''

    # Generate test runner
    content += f'''// Test runner
void run_test() {{
  log_start("RESULT_{destructor_percent}PCT_DEPTH{depth}");
  side_effect = 1; // Ensure we will return error

  auto result = depth_{depth:02d}();
  if (!result) {{
    end();
  }}
}}
'''

    return content


def generate_test_files(destructor_percent: int, depth: int, output_dir: Path):
    """Generate both exception and result test files."""

    # Create output directory if it doesn't exist
    output_dir.mkdir(parents=True, exist_ok=True)

    # Generate exception file
    exception_content = generate_exception_file(destructor_percent, depth)
    exception_filename = f"except_{destructor_percent}percent_depth{depth}.cpp"
    exception_path = output_dir / exception_filename

    with open(exception_path, 'w') as f:
        f.write(exception_content)
    print(f"Generated: {exception_path}")

    # Generate result file
    result_content = generate_result_file(destructor_percent, depth)
    result_filename = f"result_{destructor_percent}percent_depth{depth}.cpp"
    result_path = output_dir / result_filename

    with open(result_path, 'w') as f:
        f.write(result_content)
    print(f"Generated: {result_path}")


def main():
    """Generate test files for all combinations."""

    destructor_percentages = [0, 25, 50, 75, 100]
    depths = [10, 30, 50, 70]
    output_dir = Path("generated_tests")

    for destructor_pct in destructor_percentages:
        for depth in depths:
            generate_test_files(destructor_pct, depth, output_dir)

    print(
        f"\nGenerated {len(destructor_percentages) * len(depths) * 2} test files in {output_dir}/")


if __name__ == "__main__":
    main()
