#!/usr/bin/env python3
"""
HALbORD Flash and Pulse Analysis Script
Flashes programs via pyOCD and captures pulse data via Sigrok Logic Analyzer

Usage:
	python halboard_benchmark.py program1.bin program2.elf program3.hex
	python halboard_benchmark.py --file programs.txt
	python halboard_benchmark.py --target stm32f103c8 program.bin
"""

import pandas as pd
import argparse
import subprocess
import time
import sys
import tempfile
import logging
from pathlib import Path
from typing import List, Tuple
from pyocd.core.helpers import ConnectHelper
from pyocd.flash.file_programmer import FileProgrammer

# Configure logging
logging.basicConfig(level=logging.INFO,
                    format='%(asctime)s - %(levelname)s - %(message)s')
logger = logging.getLogger(__name__)


class HALbORDController:
    """Controller for flashing programs and capturing pulse data using HALbORD"""

    def __init__(self, target_type: str = "stm32f103rc", logic_channel: str = "D4",
                 sample_rate: str = "16m", num_samples: int = 1000000):
        self.target_type = target_type
        self.logic_channel = logic_channel
        self.sample_rate = sample_rate
        self.num_samples = num_samples
        self.sample_rate_hz = self._parse_sample_rate(sample_rate)

    def _parse_sample_rate(self, rate_str: str) -> int:
        """Convert sample rate string to Hz"""
        rate_str = rate_str.lower()
        if rate_str.endswith('m'):
            return int(float(rate_str[:-1]) * 1_000_000)
        elif rate_str.endswith('k'):
            return int(float(rate_str[:-1]) * 1_000)
        else:
            return int(rate_str)

    def flash_and_capture(self, program_path: Path, timeout_seconds: int = 30) -> Tuple[bool, List[float]]:
        """Flash a program and capture pulses in coordinated fashion"""
        try:
            logger.info(
                f"Flashing {program_path} to target {self.target_type}")

            with ConnectHelper.session_with_chosen_probe(
                    target_override=self.target_type
            ) as session:
                if session is None:
                    logger.error(
                        "Failed to connect to target. Is the debugger connected?")
                    return False, []

                target = session.board.target

                # Flash the program
                programmer = FileProgrammer(session, chip_erase="chip")
                programmer.program(str(program_path))

                # Start capture in background BEFORE resetting
                logger.info(
                    f"Starting background capture on channel {self.logic_channel}")

                # Create temporary file for captured data
                with tempfile.NamedTemporaryFile(mode='w+', suffix='.txt', delete=False) as temp_file:
                    temp_path = temp_file.name

                # Build sigrok-cli command
                cmd = [
                    'sigrok-cli',
                    '--driver', 'fx2lafw',
                    '--channels', self.logic_channel,
                    '--config', f'samplerate={self.sample_rate}',
                    '--samples', str(self.num_samples),
                    # Falling edge trigger
                    '--triggers', f'{self.logic_channel}=f',
                    '-O', 'hex:width=128',
                    '--output-file', temp_path
                ]

                logger.info(f"Running: {' '.join(cmd)}")

                # Start sigrok-cli process in background
                sigrok_process = subprocess.Popen(
                    cmd,
                    stdout=subprocess.PIPE,
                    stderr=subprocess.PIPE,
                    text=True
                )

                # Give sigrok a moment to initialize and start waiting for trigger
                time.sleep(2)

                # Now reset the device to start the benchmark
                logger.info("Resetting device to start benchmark")
                target.reset()

                # Wait for sigrok to complete
                try:
                    _, stderr = sigrok_process.communicate(
                        timeout=timeout_seconds)

                    if sigrok_process.returncode != 0:
                        logger.error(f"sigrok-cli failed: {stderr}")
                        return True, []  # Flash succeeded but capture failed

                    # Parse the captured data
                    pulse_durations = self._analyze_hex_data(temp_path)

                    # Clean up temp file
                    Path(temp_path).unlink()

                    logger.info(
                        f"Successfully flashed and captured {len(pulse_durations)} pulses")
                    return True, pulse_durations

                except subprocess.TimeoutExpired:
                    logger.error(
                        f"Capture timed out after {timeout_seconds} seconds")
                    sigrok_process.kill()
                    sigrok_process.wait()
                    return True, []  # Flash succeeded but capture timed out
        except Exception as e:
            logger.error(f"Failed to flash and capture {program_path}: {e}")
            return False, []

    def _post_process(self, pulses: List[float]):
        previous_pulse: float = pulses[0]
        for i, pulse in enumerate(pulses, 1):
            # When the delta between the previous pulse and the next is more
            # than 2 microseconds, we return the list from this point on
            if (previous_pulse - pulse) < -1:
                trim_point = i - 1
                logger.debug(f"  trimmed pulses: {pulses[:trim_point]}")
                logger.debug(f"remaining pulses: {pulses[trim_point:]}")
                return pulses[trim_point:]
            previous_pulse = pulse
        return pulses

    def _analyze_hex_data(self, hex_file_path: str) -> List[float]:
        """Analyze hex dump data to extract low pulse durations in microseconds"""
        pulse_durations = []

        try:
            with open(hex_file_path, 'r') as file:
                lines = file.readlines()

            # Skip header lines and find data lines
            data_lines = []
            for line in lines:
                line = line.strip()
                if line.startswith(f'{self.logic_channel}:'):
                    # Extract hex bytes after the channel identifier
                    hex_part = line[len(f'{self.logic_channel}:'):].strip()
                    hex_bytes = hex_part.split()
                    data_lines.extend(hex_bytes)

            # Convert hex bytes to bit stream
            bit_stream = []
            for hex_byte in data_lines:
                if len(hex_byte) == 2:  # Valid hex byte
                    try:
                        byte_value = int(hex_byte, 16)
                        # Convert to 8 bits (MSB first)
                        for i in range(7, -1, -1):
                            bit_stream.append((byte_value >> i) & 1)
                    except ValueError:
                        continue

            if not bit_stream:
                logger.warning("No valid data found in hex dump")
                return []

            # Find pulse durations (low periods between high periods)
            in_pulse = False
            pulse_start = 0

            for sample_num, bit_value in enumerate(bit_stream):
                # Falling edge (start of pulse)
                if not in_pulse and bit_value == 0:
                    in_pulse = True
                    pulse_start = sample_num
                elif in_pulse and bit_value == 1:  # Rising edge (end of pulse)
                    pulse_duration_samples = sample_num - pulse_start
                    pulse_duration_us = (
                        pulse_duration_samples / self.sample_rate_hz) * 1_000_000
                    pulse_durations.append(pulse_duration_us)
                    in_pulse = False

            # Handle case where capture ends while still in a pulse
            if in_pulse:
                pulse_duration_samples = len(bit_stream) - pulse_start
                pulse_duration_us = (pulse_duration_samples /
                                     self.sample_rate_hz) * 1_000_000
                pulse_durations.append(pulse_duration_us)

        except Exception as e:
            logger.error(f"Failed to analyze hex data: {e}")

        POST_PROCESSED_PULSES = self._post_process(pulse_durations)
        return POST_PROCESSED_PULSES


def load_programs_from_file(file_path: Path) -> List[Path]:
    """Load program paths from a text file"""
    programs = []
    try:
        with open(file_path, 'r') as f:
            for line in f:
                line = line.strip()
                if line and not line.startswith('#'):
                    program_path = Path(line)
                    if program_path.exists():
                        programs.append(program_path)
                    else:
                        logger.warning(
                            f"Program file not found: {program_path}")
    except Exception as e:
        logger.error(f"Failed to load programs from file: {e}")

    return programs


def main():
    parser = argparse.ArgumentParser(
        description="Flash programs and capture pulse durations using HALbORD"
    )
    parser.add_argument(
        'programs',
        default="test_order.csv",
        help='File containing CSV of "binary_path,pulse_ordering"'
    )
    parser.add_argument(
        '--verbose', '-v',
        action='store_true',
        help='Enable verbose output'
    )
    parser.add_argument(
        '--target', '-t',
        default='stm32f103rc',
        help='Target microcontroller (default: stm32f103rc)'
    )
    parser.add_argument(
        '--channel', '-c',
        default='D4',
        help='Logic analyzer channel (default: D4)'
    )
    parser.add_argument(
        '--sample-rate', '-s',
        default='24m',
        help='Sample rate (default: 16m for 16MHz)'
    )
    parser.add_argument(
        '--samples', '-n',
        type=int,
        default=1_000_000,
        help='Number of samples to capture (default: 1000000)'
    )
    parser.add_argument(
        '--timeout',
        type=int,
        default=10,
        help='Capture timeout in seconds (default: 10)'
    )

    args = parser.parse_args()

    if args.verbose:
        logger.setLevel(level=logging.DEBUG)
        logger.info("Debug logging enabled!")

    # Determine program list
    binary_map = {}
    if args.programs:
        try:
            df = pd.read_csv(args.programs)
            binary_map = dict(zip(df['executable'], df['pulse_order']))
        except Exception as e:
            logger.error(f"Failed to load binary map: {e}")
            sys.exit(1)
    if not binary_map:
        logger.error("No valid programs found")
        sys.exit(1)

    # Verify all programs exist
    exit_after_loop = False
    for program, pulse_order in binary_map.items():
        if not Path(program).exists():
            logger.error(f"Program file not found: {program}")
            exit_after_loop = True
        if not Path(pulse_order).exists():
            logger.error(f"Program file not found: {program}")
            exit_after_loop = True

    if exit_after_loop:
        sys.exit(1)

    controller = HALbORDController(
        target_type=args.target,
        logic_channel=args.channel,
        sample_rate=args.sample_rate,
        num_samples=args.samples
    )

    # Prepare CSV output
    results = []

    logger.info(f"Processing {len(binary_map.items())} programs")

    for program_path, pulse_order_path in binary_map.items():
        logger.info(f"\n{'='*50}")
        logger.info(f"Processing: {program_path}")

        # Flash and capture in coordinated fashion
        flash_success, pulse_durations = controller.flash_and_capture(
            Path(program_path),
            timeout_seconds=args.timeout
        )

        if not flash_success:
            logger.error(f"Failed to flash {program_path}, skipping")
            results.append([str(program_path), "FLASH_FAILED"])
            continue

        if not pulse_durations:
            logger.warning(f"No pulses captured for {program_path}")
            results.append([str(program_path), "NO_PULSES"])
            rounded_durations = ["NO_PULSES"] * len(pulse_durations)
        else:
            # Round to 2 decimal places for readability
            rounded_durations = [round(duration, 2)
                                 for duration in pulse_durations]
            results.append([str(program_path)] + rounded_durations)
            logger.info(
                f"Captured {len(pulse_durations)} pulses: {rounded_durations} μs")

        df = pd.read_csv(pulse_order_path)
        # Set the pulse_us column to all of our pulse durations since they
        # should be in the same exact order.
        df['pulse_us'] = rounded_durations
        df.to_csv(pulse_order_path, index=False)


if __name__ == "__main__":
    main()


# If and when I want to test out dwt counter values
#
# from pyocd.core.target import Target
# from pyocd.debug.elf.symbols import ELFSymbolProvider
# elf = str((program_path.parent / program_path.stem).absolute())
# target.elf = elf
# logger.debug(f"elf = {elf}")
# provider = ELFSymbolProvider(target.elf)
# start_addr = provider.get_symbol_value("_Z5startv")
# end_addr = provider.get_symbol_value("_Z3endv")
