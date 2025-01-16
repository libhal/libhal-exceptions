#!/usr/bin/env python3
import subprocess
import sys
import os
import struct
from typing import Tuple, List, Dict
import ctypes


class SectionInfo:
    def __init__(self, section_name: str, address: int):
        self.name = section_name
        self.address = address

    def __repr__(self):
        return f"SectionInfo(name = {self.name}, address = {self.address})"


class EntryInfo:
    def __init__(self,
                 absolute_address: int,
                 offset: int,
                 handler_bytes: bytes):
        self.address = absolute_address
        self.offset = offset
        self.handler_bytes = handler_bytes

    def __repr__(self):
        return f"EntryInfo(address = 0x{self.address:08x}, offset = {self.offset}, handler_bytes = 0x{self.handler_bytes[::-1].hex()})\n"


class FunctionInfo:
    def __init__(self, addr: int, size: int, type: str, name: str):
        self.address = addr
        self.size = size
        self.type = type
        self.name = name

    def __repr__(self):
        return f"FunctionInfo(address = 0x{self.address:08x}, size = {self.size}, type = {self.type}, name = '{self.name}')\n"


def find_exidx_section(elf_file: str) -> SectionInfo:
    """Find the section name and offset of the ARM_EXIDX section."""
    cmd = ['arm-none-eabi-readelf', '-S', elf_file]
    result = subprocess.run(cmd, capture_output=True, text=True)

    if result.returncode != 0:
        raise RuntimeError(f"readelf failed: {result.stderr}")

    # Parse the output line by line
    for line in result.stdout.splitlines():
        if 'ARM_EXIDX' in line:
            # Split the line into fields
            fields = [f for f in line.split() if f]
            section_name = fields[2]
            return SectionInfo(section_name, int(fields[4], 16))


def extract_section(elf_file: str,
                    section_info: SectionInfo,
                    output_file: str) -> None:
    """Extract the specified section to a binary file."""
    cmd = ['arm-none-eabi-objcopy', '-O', 'binary',
           f'--only-section={section_info.name}',
           elf_file, output_file]
    result = subprocess.run(cmd, capture_output=True, text=True)

    if result.returncode != 0:
        raise RuntimeError(f"objcopy failed: {result.stderr}")


def parse_prel31(data: bytes, entry_index: int) -> int:
    """Parse a PREL31 value from 4 bytes."""

    # entry size is 8 bytes
    ENTRY_SIZE = 8

    # Extract the 32-bit value
    value = struct.unpack('<I', data)[0]

    # Extract the 31-bit signed offset (bit 31 is always 0)
    offset = (value & 0x7fffffff)
    # Sign extend if bit 30 is set
    if offset & 0x40000000:
        offset |= 0x80000000

    # Add the base address if provided
    return ctypes.c_int32(offset).value


def parse_exidx_data(binary_file: str,
                     info: SectionInfo) -> List[EntryInfo]:
    """Parse the extracted .ARM.exidx section data."""
    with open(binary_file, 'rb') as f:
        data = f.read()

    entries = []
    for i in range(0, len(data), 8):
        if i + 8 > len(data):
            break

        prel31_bytes = data[i:i+4]
        handler_bytes = data[i+4:i+8]

        offset = parse_prel31(prel31_bytes, i)
        # PREL31 means relative to the location of the memory itself. To locate
        # the memory we need the starting position of the index as well as the
        # offset from the start into the index.
        absolute_address = (info.address + i) + offset
        entries.append(EntryInfo(absolute_address, offset, handler_bytes))

    return entries


def get_functions(elf_file: str) -> Dict[int, FunctionInfo]:
    """Get all functions with their addresses and sizes using nm."""
    cmd = ['arm-none-eabi-nm', '--print-size', '--size-sort', elf_file]
    result = subprocess.run(cmd, capture_output=True, text=True)

    if result.returncode != 0:
        raise RuntimeError(f"nm failed: {result.stderr}")

    functions: Dict[int, FunctionInfo] = {}
    for line in result.stdout.splitlines():
        parts = line.strip().split()
        if len(parts) == 4 and parts[2].lower() in ['t', 'w', 'T', 'W']:
            addr = int(parts[0], 16)
            size = int(parts[1], 16)
            type = parts[2]
            name = parts[3]
            functions[addr] = (FunctionInfo(addr, size, type, name))

    return functions


def print_entries(entries: List[EntryInfo]):
    for i, entry in enumerate(entries):
        hex_offset = ctypes.c_uint32(entry.offset).value
        print(f"Entry {i} (0x{entry.address:08x}):")
        print(f"   PREL31 offset: {entry.offset} (0x{hex_offset:08x})")
        print(f"    Handler data: {entry.handler_bytes[::-1].hex()}")


def find_and_sort_exceptional_functions(entries: List[EntryInfo],
                                        functions: Dict[int, FunctionInfo]):
    exceptional_functions: List[FunctionInfo] = []

    for entry in entries:
        if entry.address in functions:
            exceptional_functions.append(functions[entry.address])

    sorted_functions = sorted(exceptional_functions,
                              key=lambda function: function.size,
                              reverse=True)

    return sorted_functions


def generate_linker_script_list(linker_partition_file: str,
                                functions: List[FunctionInfo]):
    with open(linker_partition_file, 'w') as f:
        for funct in functions:
            f.write(f"KEEP(*(.text.{funct.name}))\n")


def main():
    if len(sys.argv) != 2:
        print(f"Usage: {sys.argv[0]} <elf_file>")
        sys.exit(1)

    elf_file = sys.argv[1]
    temp_bin = "exidx_temp.bin"

    try:
        section_info = find_exidx_section(elf_file)
        if not section_info:
            print("No ARM_EXIDX section found in the ELF file")
            sys.exit(1)

        function_set = get_functions(elf_file=elf_file)

        extract_section(elf_file, section_info, temp_bin)

        entries = parse_exidx_data(temp_bin, section_info)

        exceptional_functions = find_and_sort_exceptional_functions(
            entries=entries, functions=function_set)

        # Print the results
        print(f"\nFound {len(entries)} exception index entries:")
        print_entries(entries)
        print(exceptional_functions)

        generate_linker_script_list(
            linker_partition_file=f"{elf_file}.part.ld", functions=exceptional_functions)

    finally:
        # Clean up temporary file
        if os.path.exists(temp_bin):
            os.remove(temp_bin)


if __name__ == "__main__":
    main()
