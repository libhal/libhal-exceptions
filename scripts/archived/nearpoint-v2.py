#!/usr/bin/env python3
import subprocess
import re
import argparse
import csv
from typing import NamedTuple, List, Tuple, Optional
import pandas as pd
from sklearn.linear_model import LinearRegression
import numpy as np
import math
import logging
from pathlib import Path

# Configure logging
logging.basicConfig(level=logging.INFO, format='%(levelname)s: %(message)s')


class Function(NamedTuple):
    name: str
    size: int
    orig_addr: int
    new_addr: int
    index: int


class Block:
    def __init__(self, start_entry: int, end_entry: int):
        self.start = start_entry
        self.end = end_entry

    def __repr__(self):
        return f"Block(start='{self.start}', end={self.end})"


class Equation:
    def __init__(self, start_entry: int, average_function_size: int):
        self.entry = start_entry
        self.size = average_function_size

    def __repr__(self):
        return f"Equation(entry='{self.entry}', function_size={self.size})"

    def to_u32(self, block_power: int) -> int:
        LSB_TRIM = 2
        SIZE_BIT_LIMIT = 9
        SIZE_BIT_REDUCTION = LSB_TRIM + 3  # ERROR_ALLOWANCE_POWER
        MAX_ALLOWED_BLOCK_SIZE = SIZE_BIT_LIMIT + SIZE_BIT_REDUCTION
        BLOCK_SIZE = 1 << block_power
        ERROR_ALLOWANCE = 1 << 3

        if block_power > MAX_ALLOWED_BLOCK_SIZE:
            raise Exception("Block power is too high! Must be below 14")

        u32 = 0
        if self.size < (BLOCK_SIZE / ERROR_ALLOWANCE):
            u32 = self.size >> LSB_TRIM
        u32 = u32 | (self.entry << SIZE_BIT_LIMIT)
        return u32

    def to_verbose_code(self, block_power: int) -> str:
        LSB_TRIM = 2
        SIZE_BIT_LIMIT = 9
        SIZE_BIT_REDUCTION = LSB_TRIM + 3
        MAX_ALLOWED_BLOCK_SIZE = SIZE_BIT_LIMIT + SIZE_BIT_REDUCTION
        BLOCK_SIZE = 1 << block_power
        ERROR_ALLOWANCE = 1 << 3

        if block_power > MAX_ALLOWED_BLOCK_SIZE:
            raise Exception("Block power is too high! Must be below 14")

        final_size = 0
        if self.size < (BLOCK_SIZE / ERROR_ALLOWANCE):
            final_size = self.size >> LSB_TRIM

        return f"({self.entry} << {SIZE_BIT_LIMIT}) | {final_size}"


def get_sorted_functions(binary_path: str, tool_prefix: str = "") -> List[Function]:
    """Extract functions that actually exist in final binary using objdump disassembly."""
    objdump_cmd = f"{tool_prefix}objdump" if tool_prefix else "objdump"
    nm_cmd = f"{tool_prefix}nm" if tool_prefix else "nm"

    try:
        # Step 1: Get real function addresses and names from disassembly (eliminates aliases)
        cmd = [objdump_cmd, '-d', binary_path]
        objdump_output = subprocess.check_output(
            cmd, universal_newlines=True, stderr=subprocess.PIPE)

        real_functions = {}
        # Pattern matches: "00000840 <function_name>:"
        for line in objdump_output.splitlines():
            match = re.match(r'^([0-9a-f]{8}) <(.+?)>:$', line)
            if match:
                addr = int(match.group(1), 16)
                name = match.group(2)
                real_functions[addr] = name

        if not real_functions:
            logging.error("No functions found in disassembly")
            return []

        # Step 2: Get sizes using nm for functions that actually exist
        cmd = [nm_cmd, '-S', '--size-sort', '--defined-only', binary_path]
        nm_output = subprocess.check_output(
            cmd, universal_newlines=True, stderr=subprocess.PIPE)

        size_lookup = {}
        for line in nm_output.splitlines():
            if ' t ' in line or ' T ' in line:
                parts = line.strip().split()
                if len(parts) >= 4:
                    addr = int(parts[0], 16)
                    size = int(parts[1], 16)
                    name = parts[3]
                    # Only store sizes for functions that actually exist in disassembly
                    if addr in real_functions and size > 0:
                        size_lookup[addr] = size

        # Step 3: Build final function list
        functions = []
        sorted_addrs = sorted(real_functions.keys())
        lowest_addr = sorted_addrs[0] if sorted_addrs else 0
        current_addr = lowest_addr

        for idx, addr in enumerate(sorted_addrs):
            name = real_functions[addr]
            size = size_lookup.get(addr, 0)

            # Calculate size from next function if not available from nm
            if size == 0 and idx < len(sorted_addrs) - 1:
                size = sorted_addrs[idx + 1] - addr
            elif size == 0:
                size = 4  # Default minimum size for last function

            functions.append(Function(name, size, addr, current_addr, idx))
            current_addr = (current_addr + size + 3) & ~3  # 4-byte align

        # Sort by size descending and recalculate indices
        functions.sort(key=lambda x: x.size, reverse=True)
        current_addr = lowest_addr
        for idx, func in enumerate(functions):
            functions[idx] = Function(
                func.name, func.size, func.orig_addr, current_addr, idx)
            current_addr = (current_addr + func.size + 3) & ~3

        return functions

    except subprocess.CalledProcessError as e:
        logging.error(f"Error running {objdump_cmd}/{nm_cmd}: {e}")
        return []


def break_into_blocks(exception_index: list, block_power: int = 8):
    if block_power < 3:
        raise Exception("Block size power must be greater than 2")

    BLOCK_SIZE = (1 << block_power) - 1
    LAST_FUNCTION = exception_index[-1]
    FIRST_FUNCTION = exception_index[0]
    PROGRAM_LENGTH = LAST_FUNCTION - FIRST_FUNCTION
    NUMBER_OF_BLOCKS = (PROGRAM_LENGTH >> block_power) + 1

    block_list = [Block(0, 0)] * NUMBER_OF_BLOCKS
    logging.debug(f"Created {len(block_list)} blocks")

    index = 0
    block_start_index = 0

    # Lookup Table Region
    while index < len(exception_index) - 1:
        addr1 = exception_index[index] - FIRST_FUNCTION
        addr2 = exception_index[index + 1] - FIRST_FUNCTION
        function_size = addr2 - addr1

        if function_size < BLOCK_SIZE:
            break

        starting_block = addr1 >> block_power
        ending_block = addr2 >> block_power

        for i in range(starting_block, ending_block):
            if i < len(block_list):
                block_list[i] = Block(index, index)

        index += 1

    logging.debug(f"Lookup Region Ends @ {index}")

    # Grouped Function Region
    block_start_index = index
    while index < len(exception_index) - 1:
        index += 1
        BLOCK_START_ADDRESS = exception_index[block_start_index] - \
            FIRST_FUNCTION
        BLOCK_NUMBER_START = (BLOCK_START_ADDRESS >> block_power)

        BLOCK_END_ADDRESS = exception_index[index] - FIRST_FUNCTION
        BLOCK_NUMBER_END = (BLOCK_END_ADDRESS >> block_power)

        BLOCK_INDEX_DELTA = (BLOCK_NUMBER_END - BLOCK_NUMBER_START)

        if BLOCK_INDEX_DELTA == 1:
            if BLOCK_NUMBER_START < len(block_list):
                block_list[BLOCK_NUMBER_START] = Block(
                    block_start_index, index)
            block_start_index = index
        elif BLOCK_INDEX_DELTA > 1:
            logging.warning("Block delta > 1, adjusting...")

    # Set the last block
    if block_list:
        block_list[-1] = Block(block_start_index, index)

    return block_list


def convert_blocks_to_linear_equations(blocks: list, exception_index: list, block_power: int = 8):
    BLOCK_SIZE = 1 << block_power
    equations = [Equation(0, 0)] * len(blocks)

    for iter, block in enumerate(blocks):
        start = block.start
        end = block.end

        if start == end:
            equations[iter] = Equation(start, 0)
            continue

        index_slice = exception_index[start:end + 1]

        # Perform linear fit
        X = np.array(index_slice).reshape(-1, 1)
        y = [*range(start, end + 1, 1)]

        model = LinearRegression()
        model.fit(X, y)

        SLOPE = model.coef_[0]
        if math.isclose(SLOPE, 0):
            AVERAGE_SIZE = 0
        else:
            AVERAGE_SIZE = math.floor(1.0 / SLOPE)

        if AVERAGE_SIZE <= BLOCK_SIZE:
            equations[iter] = Equation(start, AVERAGE_SIZE)
        else:
            equations[iter] = Equation(start, 0)

    return equations


def predict_location(address: int, equations: list, block_power: int = 8):
    INTER_BLOCK_MASK = (1 << block_power) - 1
    INTER_BLOCK_LOCATION = address & INTER_BLOCK_MASK
    EQUATION_INDEX = address >> block_power

    if EQUATION_INDEX >= len(equations):
        return len(equations) - 1

    EQUATION = equations[EQUATION_INDEX]
    START = EQUATION.entry

    AVERAGE_FUNCTION_SIZE = EQUATION.size
    if AVERAGE_FUNCTION_SIZE == 0:
        return START

    GUESS_OFFSET = math.ceil(INTER_BLOCK_LOCATION / AVERAGE_FUNCTION_SIZE)
    LOCATION = START + GUESS_OFFSET

    return LOCATION


def function_entry_matches_address(address: int, exception_index: list, index: int):
    if index >= len(exception_index) - 1:
        return address >= exception_index[index]
    else:
        return (exception_index[index] <= address and
                address < exception_index[index + 1])


def prediction_error(address: int, exception_index: list, index: int):
    if not (0 <= index <= len(exception_index) - 1):
        index = min(max(index, 0), len(exception_index) - 1)

    if function_entry_matches_address(address, exception_index, index):
        return 0

    if address < exception_index[index]:
        for i in range(index, -1, -1):
            if function_entry_matches_address(address, exception_index, i):
                return i - index
    if address >= exception_index[index]:
        for i in range(index, len(exception_index)):
            if function_entry_matches_address(address, exception_index, i):
                return i - index

    return len(exception_index) - index


def calculate_error_stats(entries: list, equations: list, block_power: int,
                          address_offset: int = 0, max_error_threshold: int = 8) -> Tuple[int, int, int]:
    """Calculate error statistics and return (over_threshold_count, small_block_start, max_error)"""
    over_threshold_count = 0
    small_block_start = len(entries) - 1  # Default to end if no errors found
    max_error = 0
    first_error_found = False

    for actual_entry_number, address in enumerate(entries):
        NEW_ADDRESS = address - address_offset
        estimated_entry_number = predict_location(
            address=NEW_ADDRESS,
            equations=equations,
            block_power=block_power)

        error = abs(estimated_entry_number - actual_entry_number)
        if error > max_error:
            max_error = error

        if error > max_error_threshold:
            over_threshold_count += 1
            if not first_error_found:  # First error found
                small_block_start = actual_entry_number
                # Changed to INFO
                logging.info(
                    f"First error > {max_error_threshold} found at entry {small_block_start} with value {error}.")
                first_error_found = True

    return over_threshold_count, small_block_start, max_error


def optimize_block_size(entries: list, start_power: int = 10, max_error_threshold: int = 8) -> Tuple[int, int]:
    """Find optimal block sizes for normal and small tables"""
    logging.info("Optimizing block sizes...")

    best_normal_power = start_power
    best_small_power = 7
    best_score = float('inf')

    # Test normal block powers
    for normal_power in range(8, 15):
        try:
            blocks = break_into_blocks(entries, block_power=normal_power)
            equations = convert_blocks_to_linear_equations(
                blocks, entries, normal_power)
            over_count, small_start, max_err = calculate_error_stats(
                entries, equations, normal_power, 0, max_error_threshold)

            # Score based on memory usage and error count
            memory_usage = len(equations) * 4  # 4 bytes per equation
            # Heavy penalty for errors
            score = memory_usage + (over_count * 1000)

            logging.debug(
                f"Normal power {normal_power}: {len(equations)} blocks, {over_count} errors, score {score}")

            if score < best_score:
                best_score = score
                best_normal_power = normal_power

        except Exception as e:
            logging.debug(f"Normal power {normal_power} failed: {e}")
            continue

    # Test small block powers (should be smaller than normal)
    for small_power in range(5, min(best_normal_power, 12)):
        try:
            # Test with a small subset to see if it would work
            test_entries = entries[-1000:] if len(entries) > 1000 else entries
            blocks = break_into_blocks(test_entries, block_power=small_power)
            equations = convert_blocks_to_linear_equations(
                blocks, test_entries, small_power)
            over_count, _, max_err = calculate_error_stats(
                test_entries, equations, small_power, 0, max_error_threshold)

            if over_count == 0:  # Found a good small block size
                best_small_power = small_power
                break

        except Exception as e:
            logging.debug(f"Small power {small_power} failed: {e}")
            continue

    logging.info(f"Optimal block sizes: normal={best_normal_power} (2^{best_normal_power}={1<<best_normal_power}), "
                 f"small={best_small_power} (2^{best_small_power}={1<<best_small_power})")

    return best_normal_power, best_small_power


def make_smaller_block_table(small_block_start: int, entries: list, block_power: int):
    """Create small table starting from where normal table errors exceed threshold"""
    SMALL_TABLE_ADDRESS = entries[small_block_start]
    SMALL_ENTRIES_SLICE = entries[small_block_start:]

    logging.info(f"Small table covers entries {small_block_start} to {len(entries)-1} "
                 f"(addresses 0x{SMALL_TABLE_ADDRESS:x} to 0x{entries[-1]:x})")

    blocks = break_into_blocks(
        exception_index=SMALL_ENTRIES_SLICE,
        block_power=block_power)

    equations = convert_blocks_to_linear_equations(
        blocks=blocks,
        exception_index=SMALL_ENTRIES_SLICE,
        block_power=block_power)

    return (equations, SMALL_TABLE_ADDRESS)


def generate_linker_section(functions: List[Function], output_file: str):
    """Generate linker script section with sorted functions."""
    script_lines = []

    # Add functions in size order
    for func in functions:
        script_lines.append(f"    KEEP(*(.text.{func.name}))")

    # Write to file
    with open(output_file, 'w') as f:
        f.write('\n'.join(script_lines))
        f.write('\n')

    logging.info(f"Linker section written to: {output_file}")


def generate_cpp_table_file(filename: str,
                            equations: list,
                            block_power: int,
                            small_equations: list,
                            small_block_start: int,
                            small_table_address_start: int,
                            small_block_power: int):
    code = """#include <cstdint>
#include <span>

namespace hal::__except_abi {

using u32 = std::uint32_t;
using u32_span = std::span<std::uint32_t>;

namespace {
"""

    code += "u32 _near_point_descriptor_data[] = {\n"
    code += f"  0x{block_power:08x},\n"
    code += f"  0x{small_block_power:08x},\n"
    code += f"  0x{small_block_start:08x},\n"
    code += f"  0x{small_table_address_start:08x},\n"
    code += "};\n\n"

    code += "u32 _normal_table_data[] = {\n"
    for equation in equations:
        code += f"  {equation.to_verbose_code(block_power)}, // entry={equation.entry}, size={equation.size}\n"
    code += "};\n\n"

    code += "u32 _small_table_data[] = {\n"
    if len(small_equations) == 0:
        code += "  0,\n"
    else:
        for equation in small_equations:
            code += f"  {equation.to_verbose_code(small_block_power)}, // entry={equation.entry}, size={equation.size}\n"
    code += "};\n"
    code += "}  // namespace\n\n"

    code += "u32_span near_point_descriptor = _near_point_descriptor_data;\n"
    code += "u32_span normal_table = _normal_table_data;\n"
    code += "u32_span small_table = _small_table_data;\n\n"

    code += "}  // namespace hal::__except_abi\n"

    with open(filename, "w") as f:
        f.write(code)

    logging.info(f"C++ nearpoint tables written to: {filename}")


def interactive_test(entries: list, equations: list, block_power: int,
                     small_equations: list = None, small_block_start: int = 0,
                     small_table_address_start: int = 0, small_block_power: int = 7):
    """Interactive testing mode"""
    logging.info(
        "Entering interactive mode. Enter addresses to test, or non-integer to exit.")

    guess_count = 0
    while True:
        try:
            logging.info(f"guess #{guess_count}")
            guess_count += 1
            address = int(input("Provide a memory address: "))

            if small_equations and address >= small_table_address_start:
                logging.info("Using small table")
                NEW_ADDRESS = address - small_table_address_start
                guess_location = predict_location(
                    address=NEW_ADDRESS,
                    equations=small_equations,
                    block_power=small_block_power)
                guess_location += small_block_start
                guess_location = max(0, min(guess_location, len(entries) - 1))
                error = prediction_error(address=address,
                                         exception_index=entries,
                                         index=guess_location)
            else:
                guess_location = predict_location(address=address,
                                                  equations=equations,
                                                  block_power=block_power)
                guess_location = max(0, min(guess_location, len(entries) - 1))
                error = prediction_error(address=address,
                                         exception_index=entries,
                                         index=guess_location)

            logging.info(f"guess_location = {guess_location}")
            logging.info(f"ERROR = {error}")
            if abs(error) > 8:
                logging.warning(
                    "Error distance is greater than a single cache line")

        except ValueError:
            break


def main():
    parser = argparse.ArgumentParser(
        description='Generate nearpoint exception tables and linker script from ELF file'
    )
    parser.add_argument('elf_file', help='Path to the ELF binary')
    parser.add_argument('-o', '--output', help='Output base name (default: elf filename)',
                        default=None)
    parser.add_argument('-b', '--block-power', type=int, default=0,
                        help='Normal block size power of 2 (0 = auto-optimize)')
    parser.add_argument('-s', '--small-block-power', type=int, default=0,
                        help='Small block size power of 2 (0 = auto-optimize)')
    parser.add_argument('-e', '--error-threshold', type=int, default=8,
                        help='Error threshold for small table generation (default: 8, min: 4)')
    parser.add_argument('-i', '--interactive', action='store_true',
                        help='Enter interactive testing mode after generation')
    parser.add_argument('--auto-optimize', action='store_true',
                        help='Automatically find optimal block sizes')
    parser.add_argument('--tool-prefix', type=str, default="",
                        help='Toolchain prefix for objdump/nm (e.g., "arm-none-eabi-" or full path)')
    parser.add_argument('-v', '--verbose', action='store_true',
                        help='Enable verbose logging')

    args = parser.parse_args()

    if args.verbose:
        logging.getLogger().setLevel(logging.DEBUG)

    if args.error_threshold < 4:
        logging.error("Error threshold must be at least 4")
        return 1

    # Get base output name
    if args.output:
        base_name = args.output
    else:
        base_name = Path(args.elf_file).stem

    # Extract functions from ELF using objdump (avoids aliases!)
    logging.info(
        f"Extracting real functions from {args.elf_file} (no aliases)")
    if args.tool_prefix:
        logging.info(f"Using toolchain prefix: {args.tool_prefix}")

    functions = get_sorted_functions(args.elf_file, args.tool_prefix)

    if not functions:
        logging.error("No functions found in ELF file")
        return 1

    logging.info(f"Found {len(functions)} real functions")

    # Create entries list (addresses in size-sorted order)
    entries = [func.new_addr for func in functions]
    entries.append(entries[-1] + functions[-1].size)  # Add end address

    # Determine block sizes
    if args.auto_optimize or (args.block_power == 0):
        normal_power, small_power = optimize_block_size(
            entries, 10, args.error_threshold)
    else:
        normal_power = args.block_power if args.block_power > 0 else 10
        small_power = args.small_block_power if args.small_block_power > 0 else 7

    if normal_power <= small_power:
        logging.error(
            f"Normal block power ({normal_power}) must be greater than small block power ({small_power})")
        return 1

    logging.info(
        f"Using block sizes: normal=2^{normal_power}={1<<normal_power}, small=2^{small_power}={1<<small_power}")

    # Generate normal table
    logging.info("Generating normal nearpoint table...")
    blocks = break_into_blocks(entries, block_power=normal_power)
    equations = convert_blocks_to_linear_equations(
        blocks, entries, normal_power)

    # Check if small table is needed
    over_count, small_block_start, max_error = calculate_error_stats(
        entries, equations, normal_power, 0, args.error_threshold)

    logging.info(
        f"Normal table: {len(equations)} blocks, {over_count} errors > {args.error_threshold}, max error: {max_error}")

    small_equations = []
    small_table_address_start = entries[-1]

    if over_count > 0:
        logging.info(
            f"Generating small table starting at entry {small_block_start}")
        small_equations, small_table_address_start = make_smaller_block_table(
            small_block_start, entries, small_power)

        # Verify small table performance
        small_over_count, _, small_max_error = calculate_error_stats(
            entries[small_block_start:], small_equations, small_power,
            small_table_address_start, args.error_threshold)

        logging.info(
            f"Small table: {len(small_equations)} blocks, {small_over_count} errors > {args.error_threshold}, max error: {small_max_error}")

    # Generate outputs
    cpp_file = f"{base_name}.nearpoint.cpp"
    linker_file = f"{base_name}.linker_section.ld"

    generate_cpp_table_file(
        cpp_file, equations, normal_power,
        small_equations, small_block_start, small_table_address_start, small_power)

    generate_linker_section(functions, linker_file)

    # Summary
    total_memory = len(equations) * 4 + len(small_equations) * \
        4 + 16  # 16 bytes for descriptor
    text_size = entries[-1] - entries[0]
    overhead_percent = (total_memory / text_size) * 100

    logging.info(f"\nSummary:")
    logging.info(f"  Functions: {len(functions)}")
    logging.info(
        f"  Normal table: {len(equations)} entries ({len(equations) * 4} bytes)")
    logging.info(
        f"  Small table: {len(small_equations)} entries ({len(small_equations) * 4} bytes)")
    logging.info(
        f"  Total memory: {total_memory} bytes ({overhead_percent:.3f}% of .text size)")
    logging.info(f"  Generated: {cpp_file}, {linker_file}")

    # Interactive mode
    if args.interactive:
        interactive_test(entries, equations, normal_power,
                         small_equations, small_block_start, small_table_address_start, small_power)

    return 0


if __name__ == '__main__':
    exit(main())
