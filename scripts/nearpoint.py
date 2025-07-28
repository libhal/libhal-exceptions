#!/usr/bin/env python3
import subprocess
import re
import argparse
from typing import List
import logging
import struct
from pathlib import Path
from collections import defaultdict
import statistics


class FunctionInfo:
    def __init__(self, name: str, address: int, size: int = 0):
        self.name = name
        self.address = address
        self.size = size
        self.unwind_info = 0xFFFFFFFF

    def __repr__(self):
        return f"FunctionInfo(name='{self.name}', address=0x{self.address:08x}, size={self.size})\n"


class FunctionGroup:
    """
    Class that holds a group of functions with the same unwind info
    """

    def __init__(self, unwind_info: int):
        self.unwind_info = unwind_info
        self.functions: List[FunctionInfo] = []

    def __repr__(self):
        return f'FunctionGroup(info={self.unwind_info:08x}, functions={self.functions}'

    def add(self, function: FunctionInfo):
        self.functions.append(function)

    def size(self):
        sum = 0
        for function in self.functions:
            sum += function.size
        return sum

    def generate_order_list(self):
        order = ""
        for function in self.functions:
            name = function.name
            if name.startswith(".text."):
                order += f"    *({name})\n"
            else:
                order += f"    {name}\n"
        return order


def read_disassembly_get_function(text_section_asm: str) -> List[FunctionInfo]:
    actualized_functions: List[FunctionInfo] = []
    lines = text_section_asm.splitlines()
    for line in lines:
        # format: "08000040 <_exit>:"
        if line.startswith('\t') or line.startswith(' '):
            continue
        if not line.endswith(':'):
            continue

        pattern = r"^([0-9a-fA-F]+) <(.+)>:$"
        matches = re.findall(pattern, line)
        if matches:
            for address_text, function in matches:
                address = int(address_text, 16)
                actualized_functions.append(
                    FunctionInfo(name=function, address=address))
        else:
            logging.error("INVALID function string!!")
            raise ValueError

        # We have reached the end of the function space
        if line.endswith("<__text_end>:"):
            break

    # ==========================================================================
    # Step 3: Calculate function sizes for all functions by using the distance
    # between functions.
    # NOTE: from step 2, we end when we encounter __text_end which isn't a real # function but gives us the address passed the end.
    # ==========================================================================

    for i in range(1, len(actualized_functions)):
        current = actualized_functions[i - 1]
        next = actualized_functions[i]
        current.size = (next.address - current.address)

    # Remove __text_end from the actualized functions and what we have left is
    # a list of ALL functions within the final binary
    FINALIZED_FUNCTIONS = actualized_functions[:-1]

    return FINALIZED_FUNCTIONS


def parse_object_map_line(line):
    # Split by whitespace to get the main components
    parts = line.split()

    # parts[0] = '.text'
    # parts[1] = '0x0800391c'
    # parts[2] = '0x378'
    # parts[3] = '/Users/kammce/.conan2/p/.../libgcc.a(_arm_addsubdf3.o)'

    address = int(parts[1], 16)  # Convert hex to int
    size = int(parts[2], 16)     # Convert hex to int

    # Extract the object file name from the path
    full_path = parts[3]

    # Find the part in parentheses (the object file)
    if '(' in full_path and ')' in full_path:
        start = full_path.rfind('(')  # Find last '('
        end = full_path.rfind(')')    # Find last ')'
        obj_file = full_path[start+1:end]  # Extract '_arm_addsubdf3.o'
    else:
        # If no parentheses, take the last part of the path
        obj_file = full_path.split('/')[-1]

    return address, size, obj_file


def read_map_get_function(map_file_text: str) -> List[FunctionInfo]:
    actualized_functions: List[FunctionInfo] = []
    lines = map_file_text.split('\n')
    text_only_lines: List[str] = []

    for start in range(len(lines)):
        if lines[start].startswith('.text'):
            # Trim all lines before this line
            lines = lines[start:]
            break

    for line in lines:
        text_only_lines.append(line)
        # Trim everything after the text section
        if '__fini_array_end = .' in line:
            break

    for index in range(len(text_only_lines)):
        line = text_only_lines[index]
        # Start of a sectioned function
        if line.startswith(' .text.'):
            sections = line.strip().split(maxsplit=3)
            symbol_name = sections[0]

            if len(sections) == 1:
                address_and_size = text_only_lines[index + 1].strip()
                address_and_size_array = address_and_size.split(maxsplit=2)
                address = int(address_and_size_array[0], 16)
                size = int(address_and_size_array[1], 16)
            elif len(sections) >= 3:
                address = int(sections[1], 16)
                size = int(sections[2], 16)
            else:
                logging.error(f"Invalid map section found: {sections}")
                exit(1)
        # Start of a function group
        elif line.startswith(' .text '):
            # if this is the case there is always another line right below it
            address, size, object_file = parse_object_map_line(line)
            # *_arm_addsubdf3.o(.text*)
            symbol_name = "*" + object_file + "(.text*)"
        else:
            continue

        logging.debug(
            f"symbol_name = {symbol_name}, address={address}, size={size}")
        actualized_functions.append(FunctionInfo(
            name=symbol_name, address=address, size=size))

    return actualized_functions


def get_substring_after(main_string, delimiter):
    index = main_string.rfind(delimiter)
    if index == -1:
        raise ValueError
    else:
        return main_string[index + len(delimiter):]


class Block:
    def __init__(self, start_entry: int, average_size: int):
        self.start = start_entry
        self.average_size = average_size

    def __repr__(self):
        return f"Block(start='{self.start}', avg_size={self.average_size})"

    def as_c_bit_mask(self, block_power: int):
        return f"({self.start} << {block_power}) | {self.average_size}"


def break_into_blocks(exception_index: List[FunctionGroup],
                      block_power: int = 10) -> List[Block]:
    # TODO(kammce): Add support for small table
    if block_power < 3:
        raise Exception("Block size power must be greater than 2")

    logging.info(f"len(exception_index) = {len(exception_index)}")

    index_cursor = 0
    start_index = 0
    group_addresses: List[int] = []
    address_space_sum = 0

    for i, entry in enumerate(exception_index):
        group_addresses.append(address_space_sum)
        address_space_sum += entry.size()

    logging.info(f"Exception index covers {address_space_sum}B of code")

    BLOCK_SIZE = (1 << block_power) - 1
    LAST_FUNCTION = group_addresses[-1]
    FIRST_FUNCTION = group_addresses[0]
    PROGRAM_LENGTH = LAST_FUNCTION - FIRST_FUNCTION
    NUMBER_OF_BLOCKS = (PROGRAM_LENGTH >> block_power) + 1

    block_list = [Block(0, 0)] * NUMBER_OF_BLOCKS
    logging.info(f"Created {len(block_list)} blocks")

    # Lookup Table Region
    while index_cursor < len(group_addresses) - 1:
        addr1 = group_addresses[index_cursor] - FIRST_FUNCTION
        addr2 = group_addresses[index_cursor + 1] - FIRST_FUNCTION
        function_size = addr2 - addr1

        if function_size < BLOCK_SIZE:
            break

        starting_block = addr1 >> block_power
        ending_block = addr2 >> block_power

        for i in range(starting_block, ending_block):
            if i < len(block_list):
                block_list[i] = Block(index_cursor, 0)

        index_cursor += 1

    logging.debug(f"Lookup Region Ends @ {index_cursor}")

    # Grouped Function Region
    start_index = index_cursor
    # Iterate through the address space, setting blocks as necessary. We skip
    # the last block
    while index_cursor < len(group_addresses) - 1:
        index_cursor += 1
        BLOCK_START_ADDRESS = group_addresses[start_index] - \
            FIRST_FUNCTION
        BLOCK_NUMBER_START = (BLOCK_START_ADDRESS >> block_power)
        BLOCK_END_ADDRESS = group_addresses[index_cursor] - FIRST_FUNCTION
        BLOCK_NUMBER_END = (BLOCK_END_ADDRESS >> block_power)
        BLOCK_INDEX_DELTA = (BLOCK_NUMBER_END - BLOCK_NUMBER_START)

        if BLOCK_INDEX_DELTA == 1:
            if BLOCK_NUMBER_START < len(block_list):
                EXCEPTION_SLICE = exception_index[start_index:index_cursor]
                AVERAGE_SIZE = round(statistics.fmean(
                    entry.size() for entry in EXCEPTION_SLICE))
                block_list[BLOCK_NUMBER_START] = Block(
                    start_index, AVERAGE_SIZE)
            start_index = index_cursor
        elif BLOCK_INDEX_DELTA > 1:
            logging.warning("Block delta > 1, adjusting...")

    # Setting final block
    EXCEPTION_SLICE = exception_index[start_index:index_cursor]
    AVERAGE_SIZE = round(statistics.fmean(
        entry.size() for entry in exception_index[start_index:index_cursor]))
    block_list[-1] = Block(start_index, AVERAGE_SIZE)

    return block_list


def generate_cpp_table_file(filename: str,
                            block_power: int,
                            blocks: List[Block],
                            program_start: int):
    # TODO(kammce): Add support for small table
    code = """#include <cstdint>

#include <array>
#include <span>

namespace ke::__except_abi::inline v1 {

namespace {
"""

    code += "std::array<std::uint32_t, 2> const _near_point_descriptor_data = {\n"
    code += f"  0x{block_power:08x},\n"
    code += f"  0x{program_start:08x},\n"
    code += "};\n\n"

    code += f"std::array<std::uint32_t, {len(blocks)}> const _normal_table_data = {{\n"
    for block in blocks:
        code += f"  {block.as_c_bit_mask(block_power)}, // entry={block.start}, avg_size={block.average_size}\n"
    code += "};\n\n"
    code += "}  // namespace\n\n"

    code += "std::span<std::uint32_t const> near_point_descriptor = _near_point_descriptor_data;\n"
    code += "std::span<std::uint32_t const> normal_table = _normal_table_data;\n"
    code += "}  // namespace ke::__except_abi::inline v1\n"

    with open(filename, "w") as f:
        f.write(code)

    logging.info(f"C++ nearpoint tables written to: {filename}")


def main():
    parser = argparse.ArgumentParser(
        description='Generate nearpoint exception tables and linker script from ELF file'
    )
    parser.add_argument('elf_file', help='Path to the ELF binary')
    parser.add_argument('-o', '--output',
                        help='Output name (default: elf_file.nearpoint.cpp)',
                        default=None)
    parser.add_argument('-b', '--block-power', type=int, default=0,
                        help='Normal block size power of 2 (0 = auto-optimize)')
    parser.add_argument('-s', '--small-block-power', type=int, default=0,
                        help='Small block size power of 2 (0 = auto-optimize) (NOT CURRENTLY SUPPORTED!)')
    parser.add_argument('-e', '--error-threshold', type=int, default=8,
                        help='Error threshold for small table generation (default: 8, min: 4) (NOT CURRENTLY SUPPORTED!)')
    parser.add_argument('--auto-optimize', action='store_true',
                        help='Automatically find optimal block sizes (NOT CURRENTLY SUPPORTED!)')
    parser.add_argument('--tool-prefix', type=str, default="",
                        help='Toolchain prefix for objdump/nm (e.g., "arm-none-eabi-" or full path)')
    parser.add_argument('-m', '--map', type=Path, required=True,
                        help='Path to map file for executable')
    parser.add_argument('-r', '--order_file', type=str,
                        default="order.ld",
                        help='Path to where to store the ordering file.')
    parser.add_argument('-n', '--nearpoint_file', type=str,
                        default="nearpoint.cpp",
                        help='Path to where to store the nearpoint table.')
    parser.add_argument('-v', '--verbose', action='store_true',
                        help='Enable verbose logging')
    args = parser.parse_args()

    if args.verbose:
        logging.getLogger().setLevel(logging.DEBUG)
    else:
        logging.getLogger().setLevel(logging.INFO)

    tool_prefix = args.tool_prefix

    objdump_cmd = f"{tool_prefix}/arm-none-eabi-objdump"

    # ==========================================================================
    # Step 0: Disassemble elf file with all sections
    # ==========================================================================
    disassembly_cmd = [objdump_cmd, '-d', '-s', args.elf_file]
    disassembly = subprocess.check_output(
        disassembly_cmd, universal_newlines=True, stderr=subprocess.PIPE)

    # ==========================================================================
    # Step 1: Extract the list of ACTUAL functions from the `.text` section.
    # ==========================================================================

    map_file = Path(args.map).read_text()
    FINALIZED_FUNCTIONS = read_map_get_function(
        map_file)
    logging.debug(f"FINALIZED_FUNCTIONS = \n{FINALIZED_FUNCTIONS}")

    # ==========================================================================
    # Step 2: Parse the exception index
    # ==========================================================================
    # I, for the life of me, cannot understand why they put the index in the
    # ordered area and the table in the ordered area. Might be a typo.
    EXCEPTION_INDEX_SECTION_NAME = ".except_unordered:\n"
    section_content = disassembly.split("Contents of section ")
    exception_index = ""
    for section in section_content:
        if section.startswith(EXCEPTION_INDEX_SECTION_NAME):
            exception_index = section
            break

    exception_index_text = exception_index.removeprefix(
        EXCEPTION_INDEX_SECTION_NAME)
    logging.debug(f"\n{exception_index_text}")

    def parse_prel31(value):
        """Convert PREL31 value to signed 32-bit integer"""
        # Check if MSB (bit 30) is set for sign extension
        if value & (1 << 30):
            value |= 1 << 31
        return struct.unpack('>i', struct.pack('>I', value))[0]

    def parse_exception_index(hex_data: str):
        """Parse exception index from hex dump"""
        # Remove hex dump formatting and convert to bytes
        hex_lines = hex_data.strip().split('\n')
        hex_bytes = []
        first_line = hex_lines[0].split()[0].zfill(8)
        logging.debug(f'first_line = "{first_line}"')
        initial_address_text = bytes.fromhex(first_line)
        initial_address = struct.unpack('>I', initial_address_text)[0]
        logging.debug(f'initial address = {initial_address:08x}')
        # format:  800835c 00000000 e07cff7f 10ffff7f ec7cff7f  .....|.......|..

        # For some reason there is a set of 0s at the start which puts
        # everything off by 1. We need to handle this line outside of the loop
        for line in hex_lines:
            # Extract hex values after the address
            address_and_values = (line.split("  ")[0]).strip()
            logging.debug(f'address_and_values = {address_and_values}')
            parts = address_and_values.split(" ")[1:]
            logging.debug(f'parts = {parts}')
            hex_bytes.extend(parts)

        # Skip the first 0s in the index if it exists
        if hex_bytes[0] == "00000000":
            hex_bytes = hex_bytes[1:]
        results: List[FunctionInfo] = []

        # Process in pairs (skip first two, then take pairs)
        for i in range(0, len(hex_bytes), 2):
            if i + 1 >= len(hex_bytes):
                break

            addr_hex = hex_bytes[i]
            offset_hex = hex_bytes[i + 1]
            logging.debug(f"  addr_hex = {addr_hex}")
            logging.debug(f"offset_hex = {offset_hex}")

            addr_bytes = bytes.fromhex(addr_hex)
            offset_bytes = bytes.fromhex(offset_hex)

            addr_raw = struct.unpack('<I', addr_bytes)[0]
            offset_raw = struct.unpack('<I', offset_bytes)[0]

            # Apply PREL31 conversion
            addr_prel31 = parse_prel31(addr_raw)
            offset_prel31 = offset_raw

            entry_offset = i * 4
            absolute_address = (initial_address + entry_offset) + addr_prel31
            logging.debug(
                f"addr_prel31 = {addr_prel31} -> {absolute_address:08x}\n")

            results.append((absolute_address, offset_prel31))

        return results

    EXCEPTION_ENTRIES = parse_exception_index(exception_index_text)

    hex_values = ' '.join(
        f'(function: {entry[0]:08x}, data: {entry[1]:08x}),\n' for entry in EXCEPTION_ENTRIES)
    logging.debug(hex_values)

    # ==========================================================================
    # Step X: Set the unwind info for each function in the finalized_functions
    # ==========================================================================
    function_index = 0

    for i in range(1, len(EXCEPTION_ENTRIES)):
        entry_function, unwind_info = EXCEPTION_ENTRIES[i - 1]
        next_entry_function, next_unwind_info = EXCEPTION_ENTRIES[i]

        logging.debug(
            f"entry_function: {entry_function:08x}, unwind: {unwind_info}, next_entry_function: {next_entry_function:08x}")

        if FINALIZED_FUNCTIONS[function_index].address != entry_function:
            # TODO(kammce): figure out better exception
            logging.error(
                f"entry_function({i}): {entry_function:08x} != {FINALIZED_FUNCTIONS[function_index].address:08x}:{FINALIZED_FUNCTIONS[function_index].name}")

            # Print the last of functions
            for i in range(function_index, len(FINALIZED_FUNCTIONS)):
                function_symbol = FINALIZED_FUNCTIONS[i]
                logging.error(f"[{i}] = {function_symbol}")

            exit(1)

        FINALIZED_FUNCTIONS[function_index].unwind_info = unwind_info
        function_index = function_index + 1

        while (FINALIZED_FUNCTIONS[function_index].address < next_entry_function):
            if unwind_info & 1 << 31 or unwind_info == 1:
                logging.debug(
                    f"Set [{function_index}] = {FINALIZED_FUNCTIONS[function_index].address:08x}:{FINALIZED_FUNCTIONS[function_index].name} = {unwind_info:08x}")
                FINALIZED_FUNCTIONS[function_index].unwind_info = unwind_info
            else:
                logging.debug(
                    f"Transparent [{function_index}] = 0xFFFFFFFF")
                FINALIZED_FUNCTIONS[function_index].unwind_info = 0xFFFFFFFF

            function_index = function_index + 1

    # Append the last of the functions
    last_unwind_info = EXCEPTION_ENTRIES[-1][1]
    if not (last_unwind_info & 1 << 31):
        last_unwind_info = 0xFFFFFFFF
    for i in range(function_index, len(FINALIZED_FUNCTIONS)):
        FINALIZED_FUNCTIONS[i].unwind_info = last_unwind_info

    # ==========================================================================
    # Step 4: Collect functions into groups with common unwind info
    # ==========================================================================
    unwind_groups_map: defaultdict[int,
                                   FunctionGroup] = {}
    logging.debug("unwind_groups_map")
    for function in FINALIZED_FUNCTIONS:
        if function.unwind_info in unwind_groups_map:
            unwind_groups_map[function.unwind_info].add(function)
        else:
            new_group = FunctionGroup(function.unwind_info)
            new_group.add(function)
            unwind_groups_map[function.unwind_info] = new_group

    for unwind, value in unwind_groups_map.items():
        logging.debug(f"unwind:  {unwind:08x}: >>> {value} <<<\n")

    # ==========================================================================
    # Step 5: Sort Function groups
    # ==========================================================================
    # Make a copy of the leaf functions because we are going to delete them
    # from the unwind groups as they don't have unwind information.
    leaf_functions = unwind_groups_map[0xFFFFFFFF]
    unwind_groups_map.pop(0xFFFFFFFF)
    # Add all of the leaf functions to the NOEXCEPT terminate group
    for funct in leaf_functions.functions:
        unwind_groups_map[1].add(funct)
    sorted_unwind_groups_list = list(unwind_groups_map.values())
    sorted_unwind_groups_list.sort(key=FunctionGroup.size, reverse=True)
    logging.debug(f"Size sorted unwind groups\n")
    for group in sorted_unwind_groups_list:
        logging.debug(
            f"group-[{group.unwind_info:08x}]: >>> {group.functions} <<<\n")

    # ==========================================================================
    # Step 6: Generate text ordering
    # ==========================================================================
    order_string = ""
    order_string += "SECTIONS {\n"
    order_string += "  .text.sorted : {\n"
    order_string += "    /* LEAF & unsortable functions below */\n"
    for group in sorted_unwind_groups_list:
        # SECTIONS {
        #     .text : {
        order_string += f"    /* Unwind info 0x{group.unwind_info:08x} */\n"
        order_string += group.generate_order_list()
        #     }
        # }
        # INSERT BEFORE .text;
    order_string += "  }\n"
    order_string += "}\n"
    order_string += "INSERT BEFORE .text;\n"
    Path(args.order_file).write_text(order_string)
    logging.info(
        f"Function ordering linker script written to {args.order_file}")
    logging.debug(order_string)

    # ==========================================================================
    # Step 7: Generate nearpoint table
    # ==========================================================================
    blocks = break_into_blocks(
        sorted_unwind_groups_list, block_power=args.block_power)
    logging.debug(f"blocks={blocks}")
    generate_cpp_table_file(blocks=blocks,
                            block_power=args.block_power,
                            filename=args.nearpoint_file,
                            program_start=FINALIZED_FUNCTIONS[0].address)

    return 0


if __name__ == '__main__':
    exit(main())
