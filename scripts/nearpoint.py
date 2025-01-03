import pandas as pd
from sklearn.linear_model import LinearRegression
import numpy as np
import math
import pprint
import logging
import argparse
from pathlib import Path


# Configure the logging module
logging.basicConfig(level=logging.INFO)


class Block:
    def __init__(self, start_entry: int, end_entry: int):
        self.start = start_entry
        self.end = end_entry

    def __repr__(self):
        return f"Block(start='{self.start}', end={self.end})"


def break_into_blocks(exception_index: list, block_power: int = 8):
    logging.debug("break_into_blocks()")
    if block_power < 3:
        raise Exception("Block size power greater than 7")

    BLOCK_SIZE = (1 << block_power) - 1
    LAST_FUNCTION = exception_index[-1]
    FIRST_FUNCTION = exception_index[0]
    PROGRAM_LENGTH = LAST_FUNCTION - FIRST_FUNCTION
    # + 1 to account for the tail end of the index
    NUMBER_OF_BLOCKS = (PROGRAM_LENGTH >> block_power) + 1

    block_list = [Block(0, 0)] * NUMBER_OF_BLOCKS
    logging.info(f"len(block_list) = {len(block_list)}")

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
            block_list[i] = Block(index, index)

        index += 1

    logging.info(f"Lookup Region Ends @ {index}")

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
            block_list[BLOCK_NUMBER_START] = Block(block_start_index, index)
            block_start_index = index
        elif BLOCK_INDEX_DELTA > 1:
            raise Exception("Not sure what to do in this situation! 😅")

    # Set the last block to the last block start index available
    block_list[-1] = Block(block_start_index, index)

    return block_list


class Equation:
    def __init__(self, start_entry: int, average_function_size: int):
        self.entry = start_entry
        self.size = average_function_size

    def __repr__(self):
        return f"Equation(entry='{self.entry}', function_size={self.size})"


def convert_blocks_to_linear_equations(blocks: list,
                                       exception_index: list,
                                       block_power: int = 8):
    BLOCK_SIZE = 1 << block_power
    equations = [Equation(0, 0)] * len(blocks)

    logging.debug("convert_blocks_to_linear_equations()")

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
        if (math.isclose(SLOPE, 0)):
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
    EQUATION = equations[EQUATION_INDEX]
    START = EQUATION.entry

    logging.debug(f"> INTER_BLOCK_LOCATION = {INTER_BLOCK_LOCATION}")
    logging.debug(f"> EQUATION_INDEX = {EQUATION_INDEX}")
    logging.debug(f"> START = {START}")

    AVERAGE_FUNCTION_SIZE = EQUATION.size
    if AVERAGE_FUNCTION_SIZE == 0:
        return START

    GUESS_OFFSET = math.ceil(INTER_BLOCK_LOCATION / AVERAGE_FUNCTION_SIZE)

    LOCATION = START + GUESS_OFFSET
    logging.debug(f"> AVERAGE_FUNCTION_SIZE = {AVERAGE_FUNCTION_SIZE}")
    logging.debug(f"> GUESS_OFFSET = {GUESS_OFFSET}")
    logging.debug(f"> LOCATION = {LOCATION}")

    return LOCATION


def function_entry_matches_address(address: int, exception_index: list,
                                   index: int):
    if index >= len(exception_index) - 1:
        return address >= exception_index[index]
    else:
        return (exception_index[index] <= address and
                address < exception_index[index + 1])


def prediction_error(address: int, exception_index: list, index: int):
    if not (0 <= index and index <= len(exception_index) - 1):
        logging.error("Index out of bounds! CLAMPING!!")
        index = min(index, len(exception_index) - 1)

    if function_entry_matches_address(address, exception_index, index):
        return 0

    if address < exception_index[index]:
        for i in range(index, 0, -1):
            if function_entry_matches_address(address, exception_index, i):
                return i - index
    if address > exception_index[index]:
        for i in range(index, len(exception_index) - 1, 1):
            if function_entry_matches_address(address, exception_index, i):
                return i - index

    return len(exception_index) - index


def clamp(n, smallest, largest):
    return max(smallest, min(n, largest))


def write_error_csv(filename: str,
                    entries: list,
                    equations: list,
                    block_power: int,
                    address_offset: int = 0) -> int:
    over_cache_miss_count = 0
    small_block_start = 0
    max_error = 0

    with open(filename, "w") as f:
        f.write(f"actual_entry_number,address,error\n")
        for actual_entry_number, address in enumerate(entries):
            NEW_ADDRESS = address - address_offset
            estimated_entry_number = predict_location(
                address=NEW_ADDRESS,
                equations=equations,
                block_power=block_power)
            logging.debug(
                f"est:{estimated_entry_number}, act:{actual_entry_number}")
            logging.debug(
                f"   ori:{address}, new:{NEW_ADDRESS}")
            error = abs(estimated_entry_number - actual_entry_number)
            if error > max_error:
                max_error = error
            f.write(f"{actual_entry_number},{address},{error}\n")
            if error > 8:
                over_cache_miss_count += 1
                if small_block_start == 0:
                    small_block_start = actual_entry_number
                    logging.info(f"small_block_start = {small_block_start}")

    logging.info(f"max_error = {max_error}")
    return over_cache_miss_count, small_block_start


def prompt_user_for_guess(entries: list,
                          equations: list,
                          block_power: int) -> int:
    guess_count = 0
    while True:
        try:
            logging.info(f"guess #{guess_count}")
            guess_count += 1
            address = int(input("Provide a memory address: "))
            guess_location = predict_location(address=address,
                                              equations=equations,
                                              block_power=block_power)
            guess_location = clamp(guess_location, 0, len(entries) - 1)
            error = prediction_error(address=address,
                                     exception_index=entries,
                                     index=guess_location)
            logging.info(f"ERROR = { error }")
            if abs(error) > 8:
                logging.warning(
                    "Error distance is greater than a single cache line")
        except ValueError:  # break if the input is not an integer
            break


class NearPointTable:
    def __init__(self):
        pass


def make_smaller_block_table(small_block_start: int,
                             entries: list,
                             block_power: int):
    SMALL_TABLE_ADDRESS = entries[small_block_start]
    SMALL_ENTRIES_SLICE = entries[small_block_start:]

    blocks = break_into_blocks(
        exception_index=SMALL_ENTRIES_SLICE,
        block_power=block_power)

    equations = convert_blocks_to_linear_equations(
        blocks=blocks,
        exception_index=SMALL_ENTRIES_SLICE,
        block_power=block_power)

    return (equations, SMALL_TABLE_ADDRESS)


def prompt_user_for_guess_with_small(entries: list,
                                     equations: list,
                                     block_power: int,
                                     small_equations: list,
                                     small_block_start: int,
                                     small_table_address_start: int,
                                     small_block_power: int) -> int:
    guess_count = 0
    final_equation_block = small_table_address_start >> block_power
    total_blocks_needed = len(small_equations) + final_equation_block
    total_bytes_needed = total_blocks_needed * 4
    final_entry_address = entries[-1]
    percent_increase = (total_bytes_needed / final_entry_address) * 100
    logging.info(
        f"📏 total_blocks_needed = {total_blocks_needed} x 4B = {total_bytes_needed}, or +{percent_increase:.5f}%")
    while True:
        try:
            logging.info(f"guess #{guess_count}")
            guess_count += 1
            address = int(input("Provide a memory address: "))

            if address > small_table_address_start:
                logging.warning("Using small table")
                NEW_ADDRESS = address - small_table_address_start
                logging.info(
                    f"new address = {NEW_ADDRESS}, {small_table_address_start}")
                guess_location = predict_location(
                    address=NEW_ADDRESS,
                    equations=small_equations,
                    block_power=small_block_power)
                guess_location += small_block_start - 1
                guess_location = clamp(guess_location, 0, len(entries) - 1)
                # We use the normal entries and address for prediction error
                error = prediction_error(address=address,
                                         exception_index=entries,
                                         index=guess_location)
            else:
                guess_location = predict_location(address=address,
                                                  equations=equations,
                                                  block_power=block_power)
                guess_location = clamp(guess_location, 0, len(entries) - 1)
                error = prediction_error(address=address,
                                         exception_index=entries,
                                         index=guess_location)
            logging.info(f"guess_location = {guess_location}")
            logging.info(f"ERROR = { error }")
            if abs(error) > 8:
                logging.warning(
                    "Error distance is greater than a single cache line")
        except ValueError:  # break if the input is not an integer
            break


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "csv",
        help="csv file with columns entry_number and memory_address",
        type=Path)
    parser.add_argument(
        "-b",
        "--block_power",
        help="Set the block size based on a power of 2.",
        default=10,
        type=int)
    parser.add_argument(
        "-s",
        "--small_block_power",
        help="Set the small block size based on a power of 2.",
        default=7,
        type=int)
    parser.add_argument(
        "-n",
        "--nm",
        help="""The csv file is actually output from an NM command:
        nm app.elf --size-sort --radix=d | grep " [Tt] " | awk '{print $1}'
        """,
        action='store_true')
    args = parser.parse_args()
    csv_file = args.csv
    if args.nm:
        with open(csv_file) as f:
            sorted_sizes = [int(line.strip()) for line in f]
        sorted_sizes.reverse()
        entries = []
        function_address = 0
        for next_function_size in sorted_sizes:
            entries.append(function_address)
            function_address += next_function_size
        entries.append(function_address)
    else:
        entries = pd.read_csv(csv_file)['memory_address'].values
    BLOCK_POWER = args.block_power
    SMALL_BLOCK_POWER = args.small_block_power

    if BLOCK_POWER <= SMALL_BLOCK_POWER:
        logging.error(f"Block power must be greater than small block power!")
        logging.error(f"Block power       = {BLOCK_POWER}")
        logging.error(f"Small Block Power = {SMALL_BLOCK_POWER}")
        exit(1)

    logging.info(f"Block power = {BLOCK_POWER}, size = {1 << BLOCK_POWER}")
    logging.info(
        f"Small Block Power = {SMALL_BLOCK_POWER}, size = {1 << SMALL_BLOCK_POWER}")

    blocks = break_into_blocks(entries, block_power=BLOCK_POWER)
    logging.debug(pprint.pformat(blocks))

    equations = convert_blocks_to_linear_equations(blocks=blocks,
                                                   exception_index=entries, block_power=BLOCK_POWER)
    logging.debug(pprint.pformat(equations))
    logging.debug(f"len(equations) = {len(equations)}")
    logging.debug(f"len(entries) = {len(entries)}")

    if True:
        over_cache_miss_count, small_block_start = write_error_csv(
            filename=f"{csv_file}.error.csv",
            entries=entries,
            equations=equations,
            block_power=BLOCK_POWER)
        logging.info(f"over_cache_miss_count={over_cache_miss_count}")
    if False:
        prompt_user_for_guess(entries=entries,
                              equations=equations,
                              block_power=BLOCK_POWER)
    if True and over_cache_miss_count > 0:
        (small_equations, small_table_address_start) = make_smaller_block_table(
            small_block_start=small_block_start,
            entries=entries,
            block_power=SMALL_BLOCK_POWER)

    if True and over_cache_miss_count > 0:
        # logging.basicConfig(level=logging.DEBUG, force=True)
        write_error_csv(
            filename=f"{csv_file}.error_small.csv",
            entries=entries[small_block_start:],
            equations=small_equations,
            block_power=SMALL_BLOCK_POWER,
            address_offset=small_table_address_start,
        )
        # logging.basicConfig(level=logging.INFO, force=True)
    if True:
        if over_cache_miss_count == 0:
            small_equations = []
            small_block_start = len(entries) - 1
            small_table_address_start = entries[-1]
            small_block_power = SMALL_BLOCK_POWER

        prompt_user_for_guess_with_small(
            entries=entries,
            equations=equations,
            block_power=BLOCK_POWER,
            small_equations=small_equations,
            small_block_start=small_block_start,
            small_table_address_start=small_table_address_start,
            small_block_power=SMALL_BLOCK_POWER)
