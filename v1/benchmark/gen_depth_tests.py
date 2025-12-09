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
from typing import List, Tuple
from random import Random

MAX_DEPTH = 70
PRESERVE_ARRAY_MAX_SIZE = 16
DEEPEST_DEPTH = 50
LOW_DEPTH = 35
MID_DEPTH = 15
SHALLOW_DEPTH = 5
IMMEDIATE_DEPTH = 1


class TestInfo:
    def __init__(self, depth: int, error_size: int, destructor_percentage):
        self.depth = depth
        self.error_size = error_size
        self.destructor_percentage = destructor_percentage

    def __str__(self):
        return f"{self.depth},{self.error_size},{self.destructor_percentage}"

    def header() -> str:
        return "depth,error_size,destructor_percentage\n"

    def to_csv(pulse_order: List['TestInfo']):
        csv = TestInfo.header()
        csv += "\n".join([str(pulse) for pulse in pulse_order])
        return csv


def generate_result_function_sequence(destructor_percent: int,
                                      error_size: int,
                                      stack_frame_sizes: List[int]):
    content = ""

    # Generate forward declarations
    for depth in range(MAX_DEPTH, 0, -1):
        content += f"std::expected<int, test_error_{error_size:02d}> depth_{depth:02d}_error_{error_size:02d}_percent_{destructor_percent:03d}();\n"

    # Generate function implementations
    for depth in range(MAX_DEPTH, 0, -1):
        # Calculate which functions should have destructors - evenly distributed
        function_index = MAX_DEPTH - depth  # 0-based index for this function

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
std::expected<int, test_error_{error_size:02d}> depth_{depth:02d}_error_{error_size:02d}_percent_{destructor_percent:03d}() {{
  {obj_type} obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, {
      stack_frame_sizes[depth]
      }> preserve_frame = {{ 8 }};
'''

        if depth == 1:  # Last function - this is where we return the error
            content += f'''
  // This is where the error originates
  if (side_effect > 0) {{
    start();
    return std::unexpected(test_error_{error_size:02d}
                           {{ .data = {{ 0xDE, 0xAD, 0xBE, 0xEF }} }});
  }}

  // Use the variable after the call
  if (preserve_frame[0] < 0) {{
    // Never executed but prevents tail-call optimization
    return -1;
  }}

  return side_effect + 1;
}}

'''
        else:  # Call next function in chain
            content += f'''
  auto const result
    = depth_{depth-1:02d}_error_{error_size:02d}_percent_{destructor_percent:03d}();

  if (!result) {{
    return std::unexpected(result.error());
  }}

  // Use the variable after the call
  if (preserve_frame[0] < 0) {{
    // Never executed but prevents tail-call optimization
    return std::unexpected(result.error());
  }}

  return result.value() + side_effect;
}}

'''
    return content


def generate_multi_result_file(
        destructor_percentages: List[int],
        error_object_sizes: List[int],
        stack_frame_sizes: List[int]) -> Tuple[str, List[TestInfo]]:
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
struct test_error_{error_size:02d} {{
  std::array<std::uint8_t, {error_size:02d}> data;
}};'''

    content += "\n"

    # Generate function sequences for each error size and destructor percentage
    for error_size in error_object_sizes:
        for percent in destructor_percentages:
            content += generate_result_function_sequence(
                destructor_percent=percent,
                stack_frame_sizes=stack_frame_sizes,
                error_size=error_size)

    pulse_order: List[TestInfo] = []
    tests_function: List[str] = []

    for error_size in error_object_sizes:
        for percent in destructor_percentages:
            pulse_order.extend([
                TestInfo(
                    depth=DEEPEST_DEPTH, error_size=error_size, destructor_percentage=percent),
                TestInfo(
                    depth=LOW_DEPTH, error_size=error_size, destructor_percentage=percent),
                TestInfo(
                    depth=MID_DEPTH, error_size=error_size, destructor_percentage=percent),
                TestInfo(
                    depth=SHALLOW_DEPTH, error_size=error_size, destructor_percentage=percent),
                TestInfo(
                    depth=IMMEDIATE_DEPTH, error_size=error_size, destructor_percentage=percent),
            ])
            tests_function.append(
                f'run_test_error_{error_size:02d}_cleanup_{percent:03d}();\n')
            # Generate test runner function
            content += f'''// Test runner
[[gnu::noinline]]
void run_test_depth_{DEEPEST_DEPTH:02d}_error_{error_size:02d}_cleanup_{percent:03d}() {{
    side_effect = 1; // Ensure we will return error

    auto const result
        = depth_{DEEPEST_DEPTH:02d}_error_{error_size:02d}_percent_{percent:03d}();
    if (!result) {{
        end();
    }}
    pause(); // Should have gotten an error
}}

[[gnu::noinline]]
void run_test_depth_{LOW_DEPTH:02d}_error_{error_size:02d}_cleanup_{percent:03d}() {{
    side_effect = 1; // Ensure we will return error

    auto const result
        = depth_{LOW_DEPTH:02d}_error_{error_size:02d}_percent_{percent:03d}();
    if (!result) {{
        end();
    }}
    pause();
}}

[[gnu::noinline]]
void run_test_depth_{MID_DEPTH:02d}_error_{error_size:02d}_cleanup_{percent:03d}() {{
    side_effect = 1; // Ensure we will return error

    auto const result
        = depth_{MID_DEPTH:02d}_error_{error_size:02d}_percent_{percent:03d}();
    if (!result) {{
        end();
    }}
    pause();
}}

[[gnu::noinline]]
void run_test_depth_{SHALLOW_DEPTH:02d}_error_{error_size:02d}_cleanup_{percent:03d}() {{
    side_effect = 1; // Ensure we will return error

    auto const result
        = depth_{SHALLOW_DEPTH:02d}_error_{error_size:02d}_percent_{percent:03d}();
    if (!result) {{
        end();
    }}
    pause();
}}

[[gnu::noinline]]
void run_test_depth_{IMMEDIATE_DEPTH:02d}_error_{error_size:02d}_cleanup_{percent:03d}() {{
    side_effect = 1; // Ensure we will return error

    auto const result
        = depth_{IMMEDIATE_DEPTH:02d}_error_{error_size:02d}_percent_{percent:03d}();
    if (!result) {{
        end();
    }}
    pause();
}}

void run_test_error_{error_size:02d}_cleanup_{percent:03d}() {{
    run_test_depth_{DEEPEST_DEPTH:02d}_error_{error_size:02d}_cleanup_{percent:03d}();
    run_test_depth_{LOW_DEPTH:02d}_error_{error_size:02d}_cleanup_{percent:03d}();
    run_test_depth_{MID_DEPTH:02d}_error_{error_size:02d}_cleanup_{percent:03d}();
    run_test_depth_{SHALLOW_DEPTH:02d}_error_{error_size:02d}_cleanup_{percent:03d}();
    run_test_depth_{IMMEDIATE_DEPTH:02d}_error_{error_size:02d}_cleanup_{percent:03d}();
}}
'''

    content += f'''// Test runner
void run_test() {{
    {"    ".join(tests_function)}
}}

'''

    return (content, pulse_order)


def generate_except_function_sequence(
        destructor_percent: int,
        stack_frame_sizes: List[int],
        error_object_sizes: List[int]) -> str:
    content = ""

    # Generate forward declarations
    for depth in range(MAX_DEPTH, 0, -1):
        content += f"int depth_{depth:02d}_percent_{destructor_percent:03d}();\n"

    # Generate function implementations
    for depth in range(MAX_DEPTH, 0, -1):
        # Calculate which functions should have destructors - evenly distributed
        function_index = MAX_DEPTH - depth  # 0-based index for this function

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
int depth_{depth:02d}_percent_{destructor_percent:03d}() {{
  {obj_type} obj(side_effect >> 8);
  obj.do_work();

  std::array<std::int8_t volatile, {
    stack_frame_sizes[depth]
  }> preserve_frame = {{ 8 }};
'''

        if depth == 1:  # Last function - this is where we throw
            content += f'''
  // Use the variable after the call
  if (preserve_frame[0] < 0) {{
    // Never executed but prevents tail-call optimization
    return -1;
  }}

  // This is where the exception originates
  '''

            for error_size in error_object_sizes:
                content += f'''
  if (error_size_select == {error_size}) {{
    start();
    throw test_error_{error_size:02d}{{.data = {{0xDE, 0xAD, 0xBE, 0xEF}}}};
  }}
'''
            content += f'''
  return side_effect;
}}

'''
        else:  # Call next function in chain
            content += f'''
  int const result = depth_{depth-1:02d}_percent_{destructor_percent:03d}();

  // Use the variable after the call
  if (preserve_frame[0] < 0) {{
    // Never executed but prevents tail-call optimization
    return -1;
  }}
  return result + side_effect;
}}

'''
    return content


def generate_multi_exception_file(
        destructor_percentages: List[int],
        error_object_sizes: List[int],
        stack_frame_sizes: List[int]) -> Tuple[str, List[TestInfo]]:
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
struct test_error_{error_size:02d} {{
  std::array<std::uint8_t, {error_size:02d}> data;
}};'''

    content += "\n"

    pulse_order: List[TestInfo] = []

    for percent in destructor_percentages:
        content += generate_except_function_sequence(
            destructor_percent=percent,
            stack_frame_sizes=stack_frame_sizes,
            error_object_sizes=error_object_sizes)

    tests_function: List[str] = []

    for error_size in error_object_sizes:
        for percent in destructor_percentages:
            pulse_order.extend([
                TestInfo(
                    depth=DEEPEST_DEPTH, error_size=error_size, destructor_percentage=percent),
                TestInfo(
                    depth=LOW_DEPTH, error_size=error_size, destructor_percentage=percent),
                TestInfo(
                    depth=MID_DEPTH, error_size=error_size, destructor_percentage=percent),
                TestInfo(
                    depth=SHALLOW_DEPTH, error_size=error_size, destructor_percentage=percent),
                TestInfo(
                    depth=IMMEDIATE_DEPTH, error_size=error_size, destructor_percentage=percent),
            ])
            tests_function.append(
                f'run_test_error_{error_size:02d}_cleanup_{percent:03d}();\n')
            # Generate test runner function
            content += f'''// Test runner
[[gnu::noinline]]
void run_test_depth_{DEEPEST_DEPTH:02d}_error_{error_size:02d}_cleanup_{percent:03d}() {{
    side_effect = 1; // Ensure we will throw
    error_size_select = {error_size};

    try {{
        depth_{DEEPEST_DEPTH:02d}_percent_{percent:03d}();
    }} catch (test_error_{error_size:02d} const& e) {{
        end();
    }}

    pause();
}}

[[gnu::noinline]]
void run_test_depth_{LOW_DEPTH:02d}_error_{error_size:02d}_cleanup_{percent:03d}() {{
    side_effect = 1; // Ensure we will throw
    error_size_select = {error_size};

    try {{
        depth_{LOW_DEPTH:02d}_percent_{percent:03d}();
    }} catch (test_error_{error_size:02d} const& e) {{
        end();
    }}

    pause();
}}

[[gnu::noinline]]
void run_test_depth_{MID_DEPTH:02d}_error_{error_size:02d}_cleanup_{percent:03d}() {{
    side_effect = 1; // Ensure we will throw
    error_size_select = {error_size};

    try {{
        depth_{MID_DEPTH:02d}_percent_{percent:03d}();
    }} catch (test_error_{error_size:02d} const& e) {{
        end();
    }}

    pause();
}}

[[gnu::noinline]]
void run_test_depth_{SHALLOW_DEPTH:02d}_error_{error_size:02d}_cleanup_{percent:03d}() {{
    side_effect = 1; // Ensure we will throw
    error_size_select = {error_size};

    try {{
        depth_{SHALLOW_DEPTH:02d}_percent_{percent:03d}();
    }} catch (test_error_{error_size:02d} const& e) {{
        end();
    }}

    pause();
}}

[[gnu::noinline]]
void run_test_depth_{IMMEDIATE_DEPTH:02d}_error_{error_size:02d}_cleanup_{percent:03d}() {{
    side_effect = 1; // Ensure we will throw
    error_size_select = {error_size};

    try {{
        depth_{IMMEDIATE_DEPTH:02d}_percent_{percent:03d}();
    }} catch (test_error_{error_size:02d} const& e) {{
        end();
    }}

    pause();
}}

void run_test_error_{error_size:02d}_cleanup_{percent:03d}() {{
    run_test_depth_{DEEPEST_DEPTH:02d}_error_{error_size:02d}_cleanup_{percent:03d}();
    run_test_depth_{LOW_DEPTH:02d}_error_{error_size:02d}_cleanup_{percent:03d}();
    run_test_depth_{MID_DEPTH:02d}_error_{error_size:02d}_cleanup_{percent:03d}();
    run_test_depth_{SHALLOW_DEPTH:02d}_error_{error_size:02d}_cleanup_{percent:03d}();
    run_test_depth_{IMMEDIATE_DEPTH:02d}_error_{error_size:02d}_cleanup_{percent:03d}();
}}
'''

    content += f'''// Test runner
void run_test() {{
    {"    ".join(tests_function)}
}}

'''

    return (content, pulse_order)


def test_info_to_csv(pulse_order: List[TestInfo]):
    csv = TestInfo.header()
    csv += "\n".join([str(pulse) for pulse in pulse_order])
    return csv


def generate_full_test_files(destructor_percentages: List[int],
                             error_object_sizes: List[int],
                             output_dir: Path,
                             stack_sizes: List[int]):
    """Generate both exception and result test files."""

    # Create output directory if it doesn't exist
    output_dir.mkdir(parents=True, exist_ok=True)

    # Generate exception file
    exception_content, pulse_order = generate_multi_exception_file(
        destructor_percentages=destructor_percentages,
        error_object_sizes=error_object_sizes,
        stack_frame_sizes=stack_sizes)
    exception_filename = "except.cpp"
    except_pulse_order = f"{exception_filename}.csv"
    nearpoint_pulse_order = "nearpoint.cpp.csv"
    estell_except_filename = "estell_except.cpp.csv"
    exception_path = output_dir / exception_filename
    except_pulse_order_path = output_dir / except_pulse_order
    nearpoint_pulse_order_path = output_dir / nearpoint_pulse_order
    estell_except_filename_path = output_dir / estell_except_filename

    Path(exception_path).write_text(exception_content)
    Path(except_pulse_order_path).write_text(
        TestInfo.to_csv(pulse_order=pulse_order))
    Path(nearpoint_pulse_order_path).write_text(
        TestInfo.to_csv(pulse_order=pulse_order))
    Path(estell_except_filename_path).write_text(
        TestInfo.to_csv(pulse_order=pulse_order))
    print(f"Generated: {exception_path}")

    # Generate result file
    for error_size in error_object_sizes:
        result_content, pulse_order = generate_multi_result_file(
            destructor_percentages=destructor_percentages,
            error_object_sizes=[error_size],
            stack_frame_sizes=stack_sizes)
        result_filename = f"result_error{error_size:02d}.cpp"
        result_pulse_order = f"{result_filename}.csv"
        result_path = output_dir / result_filename
        result_pulse_order_path = output_dir / result_pulse_order
        Path(result_path).write_text(result_content)
        Path(result_pulse_order_path).write_text(
            TestInfo.to_csv(pulse_order=pulse_order))
        print(f"Generated: {result_path}")


def main():
    """Generate test files for all combinations."""

    destructor_percentages = [0, 25, 50, 100]
    error_sizes = [4, 16, 65]
    output_dir = Path("generated_tests")

    # Create a custom random generator object
    custom_random = Random()
    custom_random.seed(0)
    stack_sizes: List[int] = []
    for _ in range(MAX_DEPTH):
        stack_sizes.append(custom_random.randint(1, PRESERVE_ARRAY_MAX_SIZE))
    stack_sizes.append(custom_random.randint(1, PRESERVE_ARRAY_MAX_SIZE))

    generate_full_test_files(
        destructor_percentages=destructor_percentages,
        output_dir=output_dir,
        error_object_sizes=error_sizes,
        stack_sizes=stack_sizes)


if __name__ == "__main__":
    main()
