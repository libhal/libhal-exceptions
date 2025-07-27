import struct
import argparse
import logging

# format: 80084bc 14feff7f 38cbff7f 01000000 5ccbff7f


def parse_prel31(address: int, prel31_offset: int, endianness: str = 'little'):
    """Convert PREL31 value to signed 32-bit integer"""
    # Handle endianness by byte-swapping if needed
    if endianness == 'little':
        # Convert displayed hex to actual little-endian value
        offset_bytes = struct.pack('>I', prel31_offset)
        offset = struct.unpack('<I', offset_bytes)[0]
    else:
        offset = prel31_offset

    # Mask to 31 bits and sign extend
    offset &= 0x7FFFFFFF
    if offset & 0x40000000:  # Check bit 30 (sign bit)
        offset -= 0x80000000

    logging.debug(f"offset = {offset}")
    return address + offset


def parse_hex(value):
    """Parse hex string or int"""
    if isinstance(value, str) and value.startswith('0x'):
        return int(value, 16)
    return int(value)


def main():
    logging.getLogger().setLevel(logging.DEBUG)
    parser = argparse.ArgumentParser(
        description='Generate nearpoint exception tables and linker script from ELF file'
    )
    parser.add_argument('prel31_offset', help='value to convert',
                        type=parse_hex)
    parser.add_argument('-a', '--address',
                        help='Address of the prel31 offset value which is needed to get an absolute value. The default of 0 returns the relative offset from the value',
                        type=parse_hex,
                        default=0)

    parser.add_argument('-e', "--endian",
                        help='Set the endianess of the prel31_offset. The address must be big endian (or the way its spelled)',
                        type=str,
                        choices=['big', 'little'],
                        default='little')
    args = parser.parse_args()

    logging.info(
        f"Address: 0x{args.address:08x}, PREL31: 0x{args.prel31_offset:08x}")
    absolute_address = parse_prel31(
        args.address, args.prel31_offset, args.endian)
    logging.info(f"Result 0x{absolute_address:08x}")

    return 0


if __name__ == '__main__':
    exit(main())
