import subprocess
import re
from collections import OrderedDict


def get_functions(elf_file):
    # Run objdump to get symbol table
    cmd = ['arm-none-eabi-objdump', '-t', elf_file]
    result = subprocess.run(cmd, capture_output=True, text=True)

    # Parse the output to get function symbols
    functions = OrderedDict()
    for line in result.stdout.split('\n'):
        if ' F .text' in line:
            parts = line.split()
            address = int(parts[0], 16)
            name = parts[-1]
            functions[address] = {'name': name, 'size': 0}

    return functions


def get_text_section_end(elf_file):
    # Run objdump to get section headers
    cmd = ['arm-none-eabi-objdump', '-h', elf_file]
    result = subprocess.run(cmd, capture_output=True, text=True)

    # Find the .text section
    for line in result.stdout.split('\n'):
        if '.text' in line:
            parts = line.split()
            size = int(parts[2], 16)
            vma = int(parts[3], 16)
            return vma + size

    raise ValueError(".text section not found")


def calculate_function_sizes(functions, text_end):
    sorted_addresses = sorted(functions.keys())
    for i, addr in enumerate(sorted_addresses):
        if i < len(sorted_addresses) - 1:
            next_addr = sorted_addresses[i + 1]
            functions[addr]['size'] = next_addr - addr
        else:
            functions[addr]['size'] = text_end - addr


def generate_linker_script(functions, output_file):
    with open(output_file, 'w') as f:
        f.write("SECTIONS\n{\n  .text :\n  {\n")
        for addr, func in functions.items():
            f.write(f"    {func['name']} = .;\n")
        f.write("  } > FLASH\n\n")
        f.write("  /* Other sections... */\n")
        f.write("}\n")


def main(elf_file, output_file):
    functions = get_functions(elf_file)
    text_end = get_text_section_end(elf_file)
    calculate_function_sizes(functions, text_end)

    # Sort functions by address
    sorted_functions = OrderedDict(sorted(functions.items()))

    # Print function information
    print("Function Name\tAddress\t\tSize")
    print("-" * 40)
    for addr, func in sorted_functions.items():
        print(f"{func['name']}\t0x{addr:08x}\t{func['size']}")

    # Generate linker script
    generate_linker_script(sorted_functions, output_file)
    print(f"\nLinker script generated: {output_file}")


if __name__ == "__main__":
    import sys
    if len(sys.argv) != 3:
        print("Usage: python script.py <elf_file> <output_linker_script>")
        sys.exit(1)

    main(sys.argv[1], sys.argv[2])
