#!/usr/bin/env python3
import subprocess
import re
import argparse
from typing import NamedTuple, List


class Function(NamedTuple):
    name: str
    size: int
    addr: int


def get_sorted_functions(binary_path: str) -> List[Function]:
    """Get size-sorted functions using nm."""
    try:
        # Use nm with size sort and demangle options
        cmd = ['nm', '--size-sort', '--demangle',
               '--print-size', '--radix=d', binary_path]
        nm_output = subprocess.check_output(
            cmd, universal_newlines=True, stderr=subprocess.PIPE)

        functions = []
        for line in nm_output.splitlines():
            # Look for text section symbols (t or T)
            if ' t ' in line or ' T ' in line:
                parts = line.strip().split()
                if len(parts) >= 4:  # addr size type name
                    addr = int(parts[0], 16)
                    size = int(parts[1], 10)  # Size in decimal
                    name = parts[3]
                    functions.append(Function(name, size, addr))

        # Sort by size in descending order
        return sorted(functions, key=lambda x: x.size, reverse=True)

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
        description='Generate size-sorted linker script section from ELF file'
    )
    parser.add_argument('binary', help='Path to the ELF binary')
    parser.add_argument('-o', '--output', help='Output linker script file')
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

    # Output handling
    if args.output:
        with open(args.output, 'w') as f:
            f.write(linker_script)
        print(f"Linker script written to: {args.output}")
    else:
        print("\nLinker Script Section:")
        print("=" * 80)
        print(linker_script)
        print("=" * 80)

    # Print summary if requested
    if args.summary:
        total_size = sum(f.size for f in functions)
        print("\nFunction Size Summary:")
        print("-" * 80)
        print(f"{'Size':>10} {'Address':>12} {'Function Name':<50}")
        print("-" * 80)

        for func in functions:
            print(f"{format_size(func.size)} {func.addr:>#12x} {func.name:<50}")

        print("-" * 80)
        print(f"Total Functions: {len(functions)}")
        print(f"Total Size: {format_size(total_size)}")


if __name__ == '__main__':
    main()
