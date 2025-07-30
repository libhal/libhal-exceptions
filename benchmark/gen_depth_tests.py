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
from typing import List
import random

MAX_DEPTH = 70


def generate_result_function_sequence(destructor_percent: int,
                                      random_generator: random.Random,
                                      error_size: int):
    content = ""

    # Generate forward declarations
    for i in range(MAX_DEPTH, 0, -1):
        content += f"std::expected<int, test_error_{error_size}> depth_{i:02d}_error{error_size}_percent_{destructor_percent}();\n"

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
        content += f'''[[gnu::noinline]]
std::expected<int, test_error_{error_size}> depth_{i:02d}_error{error_size}_percent_{destructor_percent}() {{
  {obj_type} obj(side_effect >> 8);
  obj.do_work();

  std::array<int volatile, {random_generator.randint(1, 32)}> preserve_frame =
    {{
      side_effect,
    }};
'''

        if i == 1:  # Last function - this is where we return the error
            content += f'''
  // Use the variable after the call
  if (preserve_frame[0] < 0) {{
    return -1; // Never executed but prevents optimization
  }}

  // This is where the error originates
  start();
  return std::unexpected(test_error_{error_size}
                        {{
                            .data = {{ 0xDE, 0xAD, 0xBE, 0xEF }}
                        }});
}}

'''
        else:  # Call next function in chain
            content += f'''
  auto result = depth_{i-1:02d}_error{error_size}_percent_{destructor_percent}();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {{
    // Never executed but prevents optimization
    return std::unexpected(result.error());
  }}

  if (!result) {{
    return std::unexpected(result.error());
  }}

  return result.value() + side_effect;
}}

'''
    return content


def generate_multi_result_file(destructor_percentages: List[int],
                               error_object_sizes: List[int]) -> str:
    """Generate C++ file for expected-based error propagation test."""

    content = f'''#include <cstdint>
#include <array>
#include <expected>
#include <platform.hpp>

// Global side effect to prevent optimization
std::int32_t volatile side_effect = 0;

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

    for error_size in error_object_sizes:
        content += f'''
// Error type for testing
struct test_error_{error_size} {{
  std::array<std::uint8_t, {error_size}> data;
}};'''

    content += "\n"

    # Create a custom random generator object
    custom_random = random.Random()
    custom_random.seed(0)

    # Generate function sequences for each error size and destructor percentage
    for error_size in error_object_sizes:
        for percent in destructor_percentages:
            content += generate_result_function_sequence(
                destructor_percent=percent,
                random_generator=custom_random,
                error_size=error_size)

    tests_function: List[str] = []

    for error_size in error_object_sizes:
        for percent in destructor_percentages:
            tests_function.append(
                f'run_test_error{error_size}_cleanup_{percent}();\n')
            # Generate test runner function
            content += f'''// Test runner
[[gnu::noinline]]
void run_test_depth70_error{error_size}_cleanup_{percent}() {{
    side_effect = 1; // Ensure we will return error

    auto result = depth_70_error{error_size}_percent_{percent}();
    if (!result) {{
        end();
    }} else {{
        pause(); // Should have gotten an error
    }}
}}

[[gnu::noinline]]
void run_test_depth50_error{error_size}_cleanup_{percent}() {{
    side_effect = 1; // Ensure we will return error

    auto result = depth_50_error{error_size}_percent_{percent}();
    if (!result) {{
        end();
    }} else {{
        pause();
    }}
}}

[[gnu::noinline]]
void run_test_depth30_error{error_size}_cleanup_{percent}() {{
    side_effect = 1; // Ensure we will return error

    auto result = depth_30_error{error_size}_percent_{percent}();
    if (!result) {{
        end();
    }} else {{
        pause();
    }}
}}

[[gnu::noinline]]
void run_test_depth10_error{error_size}_cleanup_{percent}() {{
    side_effect = 1; // Ensure we will return error

    auto result = depth_10_error{error_size}_percent_{percent}();
    if (!result) {{
        end();
    }} else {{
        pause();
    }}
}}

[[gnu::noinline]]
void run_test_depth01_error{error_size}_cleanup_{percent}() {{
    side_effect = 1; // Ensure we will return error

    auto result = depth_01_error{error_size}_percent_{percent}();
    if (!result) {{
        end();
    }} else {{
        pause();
    }}
}}

void run_test_error{error_size}_cleanup_{percent}() {{
    run_test_depth70_error{error_size}_cleanup_{percent}();
    run_test_depth50_error{error_size}_cleanup_{percent}();
    run_test_depth30_error{error_size}_cleanup_{percent}();
    run_test_depth10_error{error_size}_cleanup_{percent}();
    run_test_depth01_error{error_size}_cleanup_{percent}();
}}
'''

    content += f'''// Test runner
void run_test() {{
    {"    ".join(tests_function)}
}}

'''

    return content


def generate_except_function_sequence(destructor_percent: int,
                                      random_generator: random.Random,
                                      error_object_sizes: List[int]):
    content = ""

    # Generate forward declarations
    for i in range(MAX_DEPTH, 0, -1):
        content += f"int depth_{i:02d}_percent_{destructor_percent}();\n"

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
        content += f'''[[gnu::noinline]]
int depth_{i:02d}_percent_{destructor_percent}() {{
  {obj_type} obj(side_effect >> 8);
  obj.do_work();

std::array<int volatile, {random_generator.randint(1, 32)}> preserve_frame =
  {{
  side_effect,
  }};
'''

        if i == 1:  # Last function - this is where we throw
            content += f'''
  // Use the variable after the call
  if (preserve_frame[0] < 0) {{
    return -1; // Never executed but prevents optimization
  }}

  // This is where the exception originates
  '''

            for size in error_object_sizes:
                content += f'''
  if (error_size_select == {size}) {{
    start();
    throw test_error_{size}{{.data = {{0xDE, 0xAD, 0xBE, 0xEF}}}};
  }}
'''
            content += f'''
  return side_effect;
}}

'''
        else:  # Call next function in chain
            content += f'''
      int result = depth_{i-1:02d}_percent_{destructor_percent}();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {{
  return -1; // Never executed but prevents optimization
  }}
  return result + side_effect;
}}

'''
    return content


def generate_multi_exception_file(destructor_percentages: List[int],
                                  error_object_sizes: List[int]) -> str:
    """Generate C++ file for exception-based error propagation test."""

    content = f'''#include <cstdint>

#include <array>

#include <platform.hpp>

// Global side effect to prevent optimization
std::int32_t volatile side_effect = 0;

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

volatile auto error_size_select = 0U;
'''

    for error_size in error_object_sizes:
        content += f'''
// Error type for testing
struct test_error_{error_size} {{
  std::array<std::uint8_t, {error_size}> data;
}};'''

    content += "\n"

    # Create a custom random generator object
    custom_random = random.Random()
    custom_random.seed(0)

    for percent in destructor_percentages:
        content += generate_except_function_sequence(
            destructor_percent=percent,
            random_generator=custom_random,
            error_object_sizes=error_object_sizes)

    tests_function: List[str] = []

    for error_size in error_object_sizes:
        for percent in destructor_percentages:
            tests_function.append(
                f'run_test_error{error_size}_cleanup_{percent}();\n')
            # Generate test runner function
            content += f'''// Test runner
[[gnu::noinline]]
void run_test_depth70_error{error_size}_cleanup_{percent}() {{
    side_effect = 1; // Ensure we will throw
    error_size_select = {error_size};

    try {{
        depth_70_percent_{percent}();
    }} catch (test_error_{error_size} const& e) {{
        end();
    }}

    pause();
}}

[[gnu::noinline]]
void run_test_depth50_error{error_size}_cleanup_{percent}() {{
    side_effect = 1; // Ensure we will throw
    error_size_select = {error_size};

    try {{
        depth_50_percent_{percent}();
    }} catch (test_error_{error_size} const& e) {{
        end();
    }}

    pause();
}}

[[gnu::noinline]]
void run_test_depth30_error{error_size}_cleanup_{percent}() {{
    side_effect = 1; // Ensure we will throw
    error_size_select = {error_size};

    try {{
        depth_30_percent_{percent}();
    }} catch (test_error_{error_size} const& e) {{
        end();
    }}

    pause();
}}

[[gnu::noinline]]
void run_test_depth10_error{error_size}_cleanup_{percent}() {{
    side_effect = 1; // Ensure we will throw
    error_size_select = {error_size};

    try {{
        depth_10_percent_{percent}();
    }} catch (test_error_{error_size} const& e) {{
        end();
    }}

    pause();
}}

[[gnu::noinline]]
void run_test_depth01_error{error_size}_cleanup_{percent}() {{
    side_effect = 1; // Ensure we will throw
    error_size_select = {error_size};

    try {{
        depth_01_percent_{percent}();
    }} catch (test_error_{error_size} const& e) {{
        end();
    }}

    pause();
}}

void run_test_error{error_size}_cleanup_{percent}() {{
    run_test_depth70_error{error_size}_cleanup_{percent}();
    run_test_depth50_error{error_size}_cleanup_{percent}();
    run_test_depth30_error{error_size}_cleanup_{percent}();
    run_test_depth10_error{error_size}_cleanup_{percent}();
    run_test_depth01_error{error_size}_cleanup_{percent}();
}}
'''

    content += f'''// Test runner
void run_test() {{
    {"    ".join(tests_function)}
}}

'''

    return content


def chunks(xs, n):
    n = max(1, n)
    return (xs[i:i+n] for i in range(0, len(xs), n))


def generate_full_test_files(destructor_percentages: List[int],
                             error_object_sizes: List[int],
                             output_dir: Path):
    """Generate both exception and result test files."""

    # Create output directory if it doesn't exist
    output_dir.mkdir(parents=True, exist_ok=True)
    for error_size in chunks(error_object_sizes, 2):
        # Generate exception file
        exception_content = generate_multi_exception_file(
            destructor_percentages, error_size)
        error_set_txt = ""
        for size in error_size:
            error_set_txt += f'_{size}'
        exception_filename = f"except{error_set_txt}.cpp"
        exception_path = output_dir / exception_filename

        with open(exception_path, 'w') as f:
            f.write(exception_content)
        print(f"Generated: {exception_path}")

    # Generate result file
    for error_size in error_object_sizes:
        result_content = generate_multi_result_file(
            destructor_percentages, [error_size])
        result_filename = f"result_{error_size}.cpp"
        result_path = output_dir / result_filename

        with open(result_path, 'w') as f:
            f.write(result_content)
        print(f"Generated: {result_path}")


def main():
    """Generate test files for all combinations."""

    destructor_percentages = [0, 25, 50, 75, 100]
    error_sizes = [4, 32, 64, 96]
    output_dir = Path("generated_tests")

    generate_full_test_files(
        destructor_percentages=destructor_percentages,
        output_dir=output_dir,
        error_object_sizes=error_sizes)


if __name__ == "__main__":
    main()
