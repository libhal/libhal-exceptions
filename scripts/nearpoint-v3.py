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
import struct
from pathlib import Path
from collections import defaultdict


class FunctionInfo:
    def __init__(self, name: str, address: int):
        self.name = name
        self.address = address
        self.size = 0
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


def main():
    logging.getLogger().setLevel(logging.DEBUG)
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

    def get_substring_after(main_string, delimiter):
        index = main_string.rfind(delimiter)
        if index == -1:
            raise ValueError
        else:
            return main_string[index + len(delimiter):]

    def get_substring_after(main_string, delimiter):
        index = main_string.rfind(delimiter)
        if index == -1:
            raise ValueError
        else:
            return main_string[index + len(delimiter):]

    text_section_asm = get_substring_after(
        disassembly, 'Disassembly of section .text:\n\n')

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

    # TODO(kammce): Consider what happens if __text_end is not in the linker
    """
    # Handle last function by using the address in the address in the final line
    # format:  "8006f8c:	5119 0800                                   .Q.."
    final_line = lines[-1]
    logging.debug(f'final_line = "{final_line}"')
    last_instruction_address = r"^ ([0-9a-fA-F]+):"
    last_address = int(re.findall(last_instruction_address, final_line)[0], 16)
    actualized_functions[-1].size = last_address - \
        actualized_functions[-1].address + 4
    """

    logging.debug(FINALIZED_FUNCTIONS)

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
    logging.info(exception_index_text)

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
        for line in hex_lines:
            # Extract hex values after the address
            parts = line.split()[1:]  # Skip address
            for part in parts:
                if len(part) == 8:  # 4-byte hex values
                    hex_bytes.append(part)

        results: List[FunctionInfo] = []

        # Process in pairs (skip first two, then take pairs)
        for i in range(0, len(hex_bytes), 2):
            if i + 1 >= len(hex_bytes):
                break

            offset_hex = hex_bytes[i]
            addr_hex = hex_bytes[i + 1]

            addr_bytes = bytes.fromhex(addr_hex)
            offset_bytes = bytes.fromhex(offset_hex)

            addr_raw = struct.unpack('<I', addr_bytes)[0]
            offset_raw = struct.unpack('<I', offset_bytes)[0]

            # Apply PREL31 conversion
            addr_prel31 = parse_prel31(addr_raw)
            logging.debug(f"addr_prel31 = {addr_prel31}")
            offset_prel31 = offset_raw

            # TODO(kammce): THIS IS WRONG!!!
            entry_offset = (i + 1) * 4
            absolute_address = (0x800835c + entry_offset) + addr_prel31

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
        next_entry_function, _ = EXCEPTION_ENTRIES[i]

        logging.debug(
            f"entry_function: {entry_function:08x}, next_entry_function: {next_entry_function:08x}")

        if FINALIZED_FUNCTIONS[function_index].address != entry_function:
            # TODO(kammce): figure out better exception
            logging.error(
                f"entry_function({i}): {entry_function:08x} != addr: {FINALIZED_FUNCTIONS[function_index].address:08x}")
            raise ValueError

        FINALIZED_FUNCTIONS[function_index].unwind_info = unwind_info
        function_index = function_index + 1

        while (FINALIZED_FUNCTIONS[function_index].address < next_entry_function):
            if unwind_info & 1 << 31:
                logging.debug(f"Set [{function_index}] = {unwind_info}")
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
        FINALIZED_FUNCTIONS[function_index].unwind_info = last_unwind_info

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
    sorted_unwind_groups_list = list(unwind_groups_map.values())
    sorted_unwind_groups_list.sort(key=FunctionGroup.size, reverse=True)
    logging.debug(f"Size sorted unwind groups\n")
    for group in sorted_unwind_groups_list:
        logging.debug(
            f"group-[{group.unwind_info:08x}]: >>> {group.functions} <<<\n")

    # ==========================================================================
    # Step 6: Generate text ordering
    # ==========================================================================

    """
    function_map = defaultdict(list)

    for function_info in FINALIZED_FUNCTIONS:
        function_map[function_info.address] = function_info
    logging.debug(f"function_map={function_map}")

    logging.debug("\nLogging exception groups:\n")
    exception_groups: List[FunctionGroup] = []
    for unwind_info, function_list in unwind_groups_map.items():
        group = FunctionGroup(unwind_info=unwind_info)
        for function_address in function_list:
            function_info = function_map[function_address]
            logging.debug(f"Found {function_address:08x} == {function_info}")
            group.add(function_map[function_address])
        exception_groups.append(group)

    logging.debug("\nLogging exception groups:\n")
    for group in exception_groups:
        logging.debug(group)
    """
    return 0


if __name__ == '__main__':
    exit(main())
