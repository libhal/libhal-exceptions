#!/usr/bin/env python3
"""
Parse ARM exception index from objdump output and extract function addresses and unwind data.
Each exception index entry is 8 bytes: function_address (prel31) + exception_data (prel31 or inline)
"""

import argparse
import re
import sys
from typing import List, Tuple, NamedTuple


class ExceptionEntry(NamedTuple):
    entry_addr: int
    function_addr: int
    unwind_data: int
    is_inline: bool
    unwind_addr: int = None


def parse_prel31(value: int, base_addr: int) -> int:
    """
    Parse a prel31 (position-relative 31-bit) value.
    Bit 31 is reserved, bit 30 is the sign bit.
    """
    # Sign extend bit 30 to bit 31
    if value & 0x40000000:  # If bit 30 is set
        value |= 0x80000000  # Set bit 31 (sign extend)
    else:
        value &= 0x7FFFFFFF  # Clear bit 31

    # Convert to signed 32-bit
    if value & 0x80000000:
        value = value - 0x100000000

    return base_addr + value


def decode_inline_unwind(data: int) -> str:
    """
    Decode inline ARM unwind instructions.
    """
    instructions = []

    # Extract personality index (bits 27-24)
    personality = (data >> 24) & 0x0F
    instructions.append(f"personality_{personality}")

    # Extract unwind opcodes (bits 23-0, but usually only 16-0 are used)
    opcodes = data & 0x00FFFFFF

    # Parse common ARM unwind opcodes
    opcode_bytes = []
    for i in range(3):  # Process 3 bytes of opcodes
        byte_val = (opcodes >> (16 - i * 8)) & 0xFF
        if byte_val == 0xB0:
            opcode_bytes.append("finish")
        elif byte_val == 0x00:
            opcode_bytes.append("spare")
        elif (byte_val & 0xC0) == 0x00:  # 00xxxxxx
            vsp_inc = ((byte_val & 0x3F) << 2) + 4
            opcode_bytes.append(f"vsp+={vsp_inc}")
        elif (byte_val & 0xC0) == 0x40:  # 01xxxxxx
            vsp_dec = ((byte_val & 0x3F) << 2) + 4
            opcode_bytes.append(f"vsp-={vsp_dec}")
        elif (byte_val & 0xF8) == 0x80:  # 10000nnn
            reg_count = (byte_val & 0x07) + 1
            opcode_bytes.append(f"pop_r4-r{3+reg_count}")
        elif (byte_val & 0xF8) == 0x88:  # 10001nnn
            reg_count = (byte_val & 0x07) + 1
            opcode_bytes.append(f"pop_r4-r{3+reg_count},lr")
        elif byte_val == 0x9D:  # 10011101
            opcode_bytes.append("reserved")
        elif (byte_val & 0xF0) == 0x90:  # 1001nnnn
            reg_num = byte_val & 0x0F
            if reg_num == 13 or reg_num == 15:
                opcode_bytes.append("reserved")
            else:
                opcode_bytes.append(f"vsp=r{reg_num}")
        elif (byte_val & 0xF8) == 0xA0:  # 10100nnn
            reg_count = (byte_val & 0x07) + 1
            opcode_bytes.append(f"pop_r4-r{3+reg_count}")
        elif (byte_val & 0xF8) == 0xA8:  # 10101nnn
            reg_count = (byte_val & 0x07) + 1
            opcode_bytes.append(f"pop_r4-r{3+reg_count},lr")
        else:
            opcode_bytes.append(f"0x{byte_val:02x}")

    return f"[{', '.join(opcode_bytes)}]"


def parse_hex_dump(lines: List[str]) -> List[ExceptionEntry]:
    """
    Parse objdump hex output and return list of ExceptionEntry objects.
    """
    entries = []

    for line in lines:
        # Match lines like: " 800b238 084eff7f 01000000 8882ff7f b0a80380"
        match = re.match(
            r'^\s+([0-9a-f]{7})\s+([0-9a-f]{8}(?:\s+[0-9a-f]{8})*)', line)
        if not match:
            continue

        base_addr = int(match.group(1), 16)
        hex_data = match.group(2).replace(' ', '')

        # Process 8-byte pairs (function_addr + exception_data)
        for i in range(0, len(hex_data), 16):  # 16 hex chars = 8 bytes
            if i + 15 >= len(hex_data):
                break

            # Calculate entry address
            entry_addr = base_addr + (i // 2)

            # Extract function address (first 4 bytes, little-endian)
            func_bytes = hex_data[i:i+8]
            func_addr_le = int(func_bytes, 16)
            func_addr = ((func_addr_le & 0xFF) << 24) | \
                (((func_addr_le >> 8) & 0xFF) << 16) | \
                (((func_addr_le >> 16) & 0xFF) << 8) | \
                ((func_addr_le >> 24) & 0xFF)
            absolute_func_addr = parse_prel31(func_addr, entry_addr)

            # Extract exception data (second 4 bytes, little-endian)
            except_bytes = hex_data[i+8:i+16]
            except_data_le = int(except_bytes, 16)
            except_data = ((except_data_le & 0xFF) << 24) | \
                (((except_data_le >> 8) & 0xFF) << 16) | \
                (((except_data_le >> 16) & 0xFF) << 8) | \
                ((except_data_le >> 24) & 0xFF)

            # Check if it's inline unwind data (bit 31 set) or prel31 offset
            is_inline = bool(except_data & 0x80000000)
            unwind_addr = None

            if not is_inline:
                # It's a prel31 offset to exception data
                unwind_addr = parse_prel31(except_data, entry_addr + 4)

            entries.append(ExceptionEntry(
                entry_addr=entry_addr,
                function_addr=absolute_func_addr,
                unwind_data=except_data,
                is_inline=is_inline,
                unwind_addr=unwind_addr
            ))

    return entries


def main():
    parser = argparse.ArgumentParser(
        description='Extract function addresses and unwind data from ARM exception index'
    )
    parser.add_argument(
        'input',
        nargs='?',
        help='Input file (default: stdin)',
        type=argparse.FileType('r'),
        default=sys.stdin
    )
    parser.add_argument(
        '-o', '--output',
        help='Output file (default: stdout)',
        type=argparse.FileType('w'),
        default=sys.stdout
    )
    parser.add_argument(
        '--mode',
        choices=['functions', 'unwind', 'both', 'analyze'],
        default='functions',
        help='What to output: function addresses only, unwind data only, both, or analysis'
    )
    parser.add_argument(
        '--hex',
        action='store_true',
        help='Output addresses in hexadecimal format'
    )
    parser.add_argument(
        '--sort',
        action='store_true',
        help='Sort by function address'
    )
    parser.add_argument(
        '--unique',
        action='store_true',
        help='Remove duplicate function addresses'
    )
    parser.add_argument(
        '--decode-inline',
        action='store_true',
        help='Decode inline unwind instructions'
    )

    args = parser.parse_args()

    # Read input
    lines = args.input.readlines()
    if args.input != sys.stdin:
        args.input.close()

    # Parse the hex dump
    entries = parse_hex_dump(lines)

    # Apply filters
    if args.unique:
        seen_funcs = set()
        filtered_entries = []
        for entry in entries:
            if entry.function_addr not in seen_funcs:
                filtered_entries.append(entry)
                seen_funcs.add(entry.function_addr)
        entries = filtered_entries

    if args.sort:
        entries.sort(key=lambda x: x.function_addr)

    # Output based on mode
    if args.mode == 'functions':
        for entry in entries:
            if args.hex:
                args.output.write(f"0x{entry.function_addr:08x}\n")
            else:
                args.output.write(f"{entry.function_addr}\n")

    elif args.mode == 'unwind':
        for entry in entries:
            if entry.is_inline:
                if args.hex:
                    args.output.write(f"0x{entry.unwind_data:08x}\n")
                else:
                    args.output.write(f"{entry.unwind_data}\n")
            else:
                if args.hex:
                    args.output.write(f"0x{entry.unwind_addr:08x}\n")
                else:
                    args.output.write(f"{entry.unwind_addr}\n")

    elif args.mode == 'both':
        for entry in entries:
            func_str = f"0x{entry.function_addr:08x}" if args.hex else str(
                entry.function_addr)
            if entry.is_inline:
                unwind_str = f"0x{entry.unwind_data:08x}" if args.hex else str(
                    entry.unwind_data)
                args.output.write(f"{func_str}\tinline:{unwind_str}\n")
            else:
                unwind_str = f"0x{entry.unwind_addr:08x}" if args.hex else str(
                    entry.unwind_addr)
                args.output.write(f"{func_str}\tprel31:{unwind_str}\n")

    elif args.mode == 'analyze':
        inline_count = sum(1 for e in entries if e.is_inline)
        prel31_count = len(entries) - inline_count

        args.output.write(f"Total entries: {len(entries)}\n")
        args.output.write(f"Inline unwind data: {inline_count}\n")
        args.output.write(f"prel31 offsets: {prel31_count}\n")
        args.output.write(
            f"Inline percentage: {inline_count/len(entries)*100:.1f}%\n\n")

        for entry in entries:
            func_str = f"0x{entry.function_addr:08x}" if args.hex else str(
                entry.function_addr)
            if entry.is_inline:
                unwind_str = f"0x{entry.unwind_data:08x}"
                if args.decode_inline:
                    decoded = decode_inline_unwind(entry.unwind_data)
                    args.output.write(
                        f"{func_str}\tinline:{unwind_str} {decoded}\n")
                else:
                    args.output.write(f"{func_str}\tinline:{unwind_str}\n")
            else:
                unwind_str = f"0x{entry.unwind_addr:08x}" if args.hex else str(
                    entry.unwind_addr)
                args.output.write(f"{func_str}\tprel31→{unwind_str}\n")

    if args.output != sys.stdout:
        args.output.close()


if __name__ == '__main__':
    main()
