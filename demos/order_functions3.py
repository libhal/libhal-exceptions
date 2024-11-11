#!/usr/bin/env python3
import subprocess
import re
import argparse
import csv
from typing import NamedTuple, List


class Function(NamedTuple):
    name: str
    size: int
    orig_addr: int
    new_addr: int
    index: int


def get_sorted_functions(binary_path: str) -> List[Function]:
    """Get size-sorted functions using nm and calculate new addresses."""
    try:
        cmd = ['nm', '--size-sort', '--print-size', binary_path]
        nm_output = subprocess.check_output(
            cmd, universal_newlines=True, stderr=subprocess.PIPE)

        # First pass to get functions and find lowest address
        temp_functions = []
        lowest_addr = float('inf')
        for line in nm_output.splitlines():
            if ' t ' in line or ' T ' in line:
                parts = line.strip().split()
                if len(parts) >= 4:
                    addr = int(parts[0], 16)
                    size = int(parts[1], 16)
                    name = parts[3]
                    lowest_addr = min(lowest_addr, addr)
                    temp_functions.append((name, size, addr))

        # Sort by size in descending order
        temp_functions.sort(key=lambda x: x[1], reverse=True)

        # Calculate new sequential addresses
        current_addr = lowest_addr
        functions = []
        for idx, (name, size, orig_addr) in enumerate(temp_functions):
            functions.append(
                Function(name, size, orig_addr, current_addr, idx))
            # Align next address to 4-byte boundary
            current_addr = (current_addr + size + 3) & ~3

        return functions

    except subprocess.CalledProcessError as e:
        print(f"Error running nm: {e}")
        print(f"stderr: {e.stderr}")
        return []


def generate_linker_section(functions: List[Function]) -> str:
    """Generate linker script section with sorted functions."""
    script = []
    script.append("SECTIONS")
    script.append("{")
    script.append("  .text :")
    script.append("  {")

    # Add functions in size order
    for func in functions:
        script.append(f"    KEEP(*(.text.{func.name}))")

    # Add any remaining text sections
    script.append("    *(.text*)")
    script.append("    *(.rodata*)")
    script.append("  } > FLASH")
    script.append("}")

    return "\n".join(script)


def write_csv(functions: List[Function], filepath: str):
    """Write function information to CSV file."""
    with open(filepath, 'w', newline='') as csvfile:
        writer = csv.writer(csvfile)
        writer.writerow(['Index Entry', 'Function Name', 'Address'])
        for func in functions:
            writer.writerow([func.index, func.name, hex(func.new_addr)])


def format_size(size: int) -> str:
    """Format size in bytes to human-readable format."""
    if size < 1024:
        return f"{size:>8} B"
    elif size < 1024 * 1024:
        return f"{size/1024:>7.1f} KB"
    else:
        return f"{size/1024/1024:>7.1f} MB"


def main():
    parser = argparse.ArgumentParser(
        description='Generate size-sorted linker script section and CSV from ELF file'
    )
    parser.add_argument('binary', help='Path to the ELF binary')
    parser.add_argument('-o', '--output', help='Output linker script file')
    parser.add_argument('-c', '--csv', help='Output CSV file')
    parser.add_argument('--summary', action='store_true',
                        help='Show size summary of functions')
    args = parser.parse_args()

    # Get sorted functions
    functions = get_sorted_functions(args.binary)

    if not functions:
        print("No functions found in binary")
        return

    # Generate linker script
    linker_script = generate_linker_section(functions)

    # Output handling for linker script
    if args.output:
        with open(args.output, 'w') as f:
            f.write(linker_script)
        print(f"Linker script written to: {args.output}")
    else:
        print("\nLinker Script Section:")
        print("=" * 80)
        print(linker_script)
        print("=" * 80)

    # Output CSV if requested
    if args.csv:
        write_csv(functions, args.csv)
        print(f"CSV file written to: {args.csv}")

    # Print summary if requested
    if args.summary:
        total_size = sum(f.size for f in functions)
        print("\nFunction Size Summary:")
        print("-" * 90)
        print(f"{'Index':>5} {'Size':>10} {'New Addr':>12} {'Function Name':<50}")
        print("-" * 90)

        for func in functions:
            print(
                f"{func.index:>5} {format_size(func.size)} {func.new_addr:>#12x} {func.name:<50}")

        print("-" * 90)
        print(f"Total Functions: {len(functions)}")
        print(f"Total Size: {format_size(total_size)}")


if __name__ == '__main__':
    main()
