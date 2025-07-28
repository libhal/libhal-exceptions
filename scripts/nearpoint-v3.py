#!/usr/bin/env python3
import subprocess
import re
import argparse
from typing import NamedTuple, List, Tuple, Optional
import logging
import struct
from pathlib import Path
from collections import defaultdict


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
            order += f"    *({name})\n"
            """
            # Handle C++ constructor/destructor variants
            if re.search(r'[CD][012]Ev$', name):
                # Replace D1Ev with D* or C1Ev with C*
                base_name = re.sub(r'[CD][012]Ev$', '', name)
                order += f"    *(.text.*{base_name}*)\n"
            else:
                order += f"    *(.text.*{name})\n"
            """

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
            symbol_name = text_only_lines[index + 1].split(maxsplit=2)[1]
            glob_start = line.strip().split(maxsplit=3)
            address = int(glob_start[1], 16)
            size = int(glob_start[2], 16)
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
    parser.add_argument('-m', '--map', type=Path, required=True,
                        help='Path to map file for executable')
    parser.add_argument('-r', '--order_file', type=str,
                        default="order.ld",
                        help='Path to where to store the ordering file.')
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

    # actualized_functions: List[FunctionInfo] = read_disassembly_get_function(
    #     get_substring_after(disassembly, 'Disassembly of section .text:\n\n'))

    map_file = Path(args.map).read_text()
    FINALIZED_FUNCTIONS = read_map_get_function(
        map_file)

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
    logging.info(f"\n{exception_index_text}")

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
    order_string += leaf_functions.generate_order_list()
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
    logging.info(f"ordering = \n{order_string}")
    return 0


if __name__ == '__main__':
    exit(main())
