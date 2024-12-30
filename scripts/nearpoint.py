import pandas as pd
import numpy as np
from sklearn.linear_model import LinearRegression
import math
import pprint
import logging

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
    # + 1 to account for the tail end of the index
    NUMBER_OF_BLOCKS = (LAST_FUNCTION >> block_power) + 1

    block_list = [Block(0, 0)] * NUMBER_OF_BLOCKS
    logging.info(f"len(block_list) = {len(block_list)}")

    index = 0
    block_start_index = 0

    # Lookup Table Region
    while index < len(exception_index) - 1:
        addr1 = exception_index[index]
        addr2 = exception_index[index + 1]
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
        BLOCK_START_ADDRESS = exception_index[block_start_index]
        BLOCK_NUMBER_START = (BLOCK_START_ADDRESS >> block_power)

        BLOCK_END_ADDRESS = exception_index[index]
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
        # logging.debug(f"[{start}, {end}]")

        if start == end:
            equations[iter] = Equation(start, 0)
            continue

        index_slice = exception_index[start:end + 1]

        # Perform linear fit
        X = index_slice.reshape(-1, 1)
        y = [*range(start, end + 1, 1)]
        # logging.debug(f"=> {y}")

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

    GUESS_OFFSET = round(INTER_BLOCK_LOCATION / AVERAGE_FUNCTION_SIZE)

    LOCATION = START + GUESS_OFFSET
    logging.debug(f"> AVERAGE_FUNCTION_SIZE = {AVERAGE_FUNCTION_SIZE}")
    logging.debug(f"> GUESS_OFFSET = {GUESS_OFFSET}")
    logging.debug(f"> LOCATION = {LOCATION}")

    return LOCATION


def function_entry_matches_address(address: int, exception_index: list,
                                   index: int):
    left_index = index
    right_index = min(index + 1, len(exception_index) - 1)
    return (exception_index[left_index] <= address and
            address < exception_index[right_index])


def prediction_error(address: int, exception_index: list, index: int):
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


def print_error_csv(entries: list, equations: list) -> int:
    over_cache_miss_count = 0
    print(f"actual_entry_number,address,error")
    for actual_entry_number, address in enumerate(entries):
        estimated_entry_number = predict_location(
            address=address, equations=equations, block_power=BLOCK_POWER)
        error = estimated_entry_number - actual_entry_number
        if abs(error) > 4:
            over_cache_miss_count += 1
            print(f"{actual_entry_number},{address},{ error }")
    return over_cache_miss_count


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


if __name__ == "__main__":
    csv_file = 'firefox.csv'
    data = pd.read_csv(csv_file)
    entries = data['memory_address'].values
    BLOCK_POWER = 10
    blocks = break_into_blocks(entries, block_power=BLOCK_POWER)
    logging.debug(pprint.pformat(blocks))

    equations = convert_blocks_to_linear_equations(blocks=blocks,
                                                   exception_index=entries, block_power=BLOCK_POWER)
    logging.debug(pprint.pformat(equations))
    logging.debug(f"len(equations) = {len(equations)}")
    logging.debug(f"len(entries) = {len(entries)}")

    if False:
        over_cache_miss_count = print_error_csv(entries=entries,
                                                equations=equations)
        logging.info(f"over_cache_miss_count={over_cache_miss_count}")
    if False:
        prompt_user_for_guess(entries=entries,
                              equations=equations,
                              block_power=BLOCK_POWER)

    exit(0)

    print("========================================================")
    over_cache_miss_count = 0
    for actual_entry_number, address in enumerate(entries):
        estimated_entry_number = predict_location(
            address=address, equations=equations, block_power=BLOCK_POWER)
        error = estimated_entry_number - actual_entry_number
        logging.info(f"[{actual_entry_number},{address}]: error = { error }")
        if abs(error) > 6:
            over_cache_miss_count += 1
    logging.info(f"over_cache_miss_count = {over_cache_miss_count}")

    print("--------------")
    SMALL_ENTRIES_SLICE = entries[-over_cache_miss_count:]
    SMALLER_BLOCK_POWER = BLOCK_POWER - 2
    small_blocks = break_into_blocks(
        exception_index=SMALL_ENTRIES_SLICE,
        block_power=SMALLER_BLOCK_POWER)
    logging.info(pprint.pformat(small_blocks))
    print("--------------")
    small_equations = convert_blocks_to_linear_equations(
        blocks=small_blocks,
        exception_index=SMALL_ENTRIES_SLICE,
        block_power=SMALLER_BLOCK_POWER)
    logging.debug(pprint.pformat(small_equations))

    SMALL_ENTRY_TRANSITION = entries[-over_cache_miss_count]

    print("+++++++++++++++++++++++")

    for actual_entry_number, address in enumerate(SMALL_ENTRIES_SLICE):
        NEW_ADDRESS = address - SMALL_ENTRY_TRANSITION
        estimated_entry_number = predict_location(
            address=NEW_ADDRESS,
            equations=small_equations,
            block_power=SMALLER_BLOCK_POWER)
        error = estimated_entry_number - actual_entry_number
        logging.info(
            f"SMALL:[{actual_entry_number},{address}]: error = { error }")

    print("========================================================")
    total_blocks_needed = len(blocks) + len(small_blocks)
    logging.info(f"total_blocks_needed = {total_blocks_needed}")

    for i in range(10):
        logging.info(f"guess #{i}")
        address = int(input("Provide a memory address: "))
        if address >= SMALL_ENTRY_TRANSITION:
            NEW_ADDRESS = address - SMALL_ENTRY_TRANSITION
            logging.info(
                f"Block power {SMALLER_BLOCK_POWER} region used! "
                f"Shifted Address {NEW_ADDRESS}")
            guess_location = predict_location(
                address=NEW_ADDRESS,
                equations=small_equations,
                block_power=SMALLER_BLOCK_POWER)
            guess_location += len(entries) - over_cache_miss_count
            # We use the normal entries and address for prediction error
            error = prediction_error(address=address,
                                     exception_index=entries,
                                     index=guess_location)
        else:
            logging.info(f"Block power {BLOCK_POWER} region used!")
            guess_location = predict_location(
                address=address, equations=equations, block_power=BLOCK_POWER)
            error = prediction_error(address=address,
                                     exception_index=entries,
                                     index=guess_location)
        logging.info(f"ERROR = { error }")
        if abs(error) > 8:
            logging.warning(
                "Error distance is greater than a single cache line")
