# Copyright 2024 - 2025 Khalil Estell and the libhal contributors
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

#!/usr/bin/env python3

from pathlib import Path

MAX_DEPTH = 70


def generate_exception_file(destructor_percent: int,
                            error_object_size: int = 4) -> str:
    """Generate C++ file for exception-based error propagation test."""

    # Calculate how many functions should have destructors
    destructor_count = int((destructor_percent / 100.0) * MAX_DEPTH)

    content = f'''#include <array>
#include <cstdint>
#include <string_view>

#include <platform.hpp>

// Global side effect to prevent optimization
std::int32_t volatile side_effect = 0;

// Error type for testing
struct test_error {{
  std::array<std::uint8_t, {error_object_size}> data;
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
    for i in range(MAX_DEPTH, 0, -1):
        content += f"int depth_{i:02d}();\n"

    content += "\n"

    # Generate function implementations
    for i in range(MAX_DEPTH, 0, -1):
        # Calculate which functions should have destructors - evenly distributed
        function_index = MAX_DEPTH - i  # 0-based index for this function

        # Calculate total destructor count and distribute evenly
        destructor_count = int((destructor_percent / 100.0) * MAX_DEPTH)

        if destructor_count == 0:
            has_destructor = False
        elif destructor_count >= MAX_DEPTH:
            has_destructor = True
        else:
            # Even distribution using integer arithmetic
            current_position = function_index * destructor_count // MAX_DEPTH
            next_position = (function_index + 1) * \
                destructor_count // MAX_DEPTH
            has_destructor = next_position > current_position

        obj_type = "destructor_object" if has_destructor else "simple_object"
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
  log_start("EXCEPT_{destructor_percent}PCT_DEPTH");
  side_effect = 1; // Ensure we will throw

  try {{
    depth_70();
  }} catch (test_error const& e) {{
    end();
  }}

  pause();

  try {{
    depth_50();
  }} catch (test_error const& e) {{
    end();
  }}

  pause();

  try {{
    depth_30();
  }} catch (test_error const& e) {{
    end();
  }}

  pause();

  try {{
    depth_10();
  }} catch (test_error const& e) {{
    end();
  }}

  pause();

  try {{
    depth_01();
  }} catch (test_error const& e) {{
    end();
  }}

  pause();
}}

'''

    return content


def generate_result_file(destructor_percent: int,
                         error_object_size: int = 4) -> str:
    """Generate C++ file for std::expected-based error propagation test."""

    # Calculate how many functions should have destructors
    destructor_count = int((destructor_percent / 100.0) * MAX_DEPTH)

    content = f'''#include <array>
#include <cstdint>
#include <expected>
#include <string_view>

#include <platform.hpp>

// Global side effect to prevent optimization
std::int32_t volatile side_effect = 0;

// Error type for testing
struct test_error {{
  std::array<std::uint8_t, {error_object_size}> data;
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
    for i in range(MAX_DEPTH, 0, -1):
        content += f"result_type depth_{i:02d}();\n"

    content += "\n"

    # Generate function implementations
    for i in range(MAX_DEPTH, 0, -1):
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
  log_start("RESULT-{destructor_percent}%-DEPTH{MAX_DEPTH}");
  side_effect = 1; // Ensure we will return error

  auto result_70 = depth_70();
  if (!result_70) {{
    end();
  }}

  pause();

  auto result_50 = depth_50();
  if (!result_50) {{
    end();
  }}

  pause();

  auto result_30 = depth_30();
  if (!result_30) {{
    end();
  }}

  pause();

  auto result_10 = depth_10();
  if (!result_10) {{
    end();
  }}

  pause();

  auto result_01 = depth_01();
  if (!result_01) {{
    end();
  }}
}}
'''

    return content


def generate_test_files(destructor_percent: int,
                        output_dir: Path,
                        error_object_size: int = 4):
    """Generate both exception and result test files."""

    # Create output directory if it doesn't exist
    output_dir.mkdir(parents=True, exist_ok=True)

    # Generate exception file
    exception_content = generate_exception_file(
        destructor_percent, error_object_size)
    exception_filename = f"except_{destructor_percent}_cleanup_{error_object_size}_error.cpp"
    exception_path = output_dir / exception_filename

    with open(exception_path, 'w') as f:
        f.write(exception_content)
    print(f"Generated: {exception_path}")

    # Generate result file
    result_content = generate_result_file(
        destructor_percent, error_object_size)
    result_filename = f"result_{destructor_percent}_cleanup_{error_object_size}-error.cpp"
    result_path = output_dir / result_filename

    with open(result_path, 'w') as f:
        f.write(result_content)
    print(f"Generated: {result_path}")


def main():
    """Generate test files for all combinations."""

    destructor_percentages = [0, 25, 50, 75, 100]
    error_sizes = [0, 16, 32, 64, 96]
    output_dir = Path("generated_tests")

    for destructor_pct in destructor_percentages:
        for error_size in error_sizes:
            generate_test_files(destructor_pct, MAX_DEPTH,
                                output_dir, error_size)

    print(
        f"\nGenerated {len(error_sizes) * len(destructor_percentages) * 2} test files in {output_dir}/")


if __name__ == "__main__":
    main()
