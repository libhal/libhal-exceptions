#!/usr/bin/env python3
"""
HALbORD Flash and Pulse Analysis Script
Flashes programs via pyOCD and captures pulse data via Sigrok Logic Analyzer

Usage:
	python halboard_benchmark.py program1.bin program2.elf program3.hex
	python halboard_benchmark.py --file programs.txt
	python halboard_benchmark.py --target stm32f103c8 program.bin
"""

import argparse
import subprocess
import time
import csv
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
                    stdout, stderr = sigrok_process.communicate(
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

        return pulse_durations


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
        nargs='*',
        help='Program files to flash and test'
    )
    parser.add_argument(
        '--file', '-f',
        type=Path,
        help='File containing list of programs (one per line)'
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
        default='16m',
        help='Sample rate (default: 16m for 16MHz)'
    )
    parser.add_argument(
        '--samples', '-n',
        type=int,
        default=1000000,
        help='Number of samples to capture (default: 1000000)'
    )
    parser.add_argument(
        '--timeout',
        type=int,
        default=10,
        help='Capture timeout in seconds (default: 10)'
    )
    parser.add_argument(
        '--output', '-o',
        type=Path,
        help='Output CSV file (default: stdout)'
    )

    args = parser.parse_args()

    # Determine program list
    programs = []
    if args.file:
        programs = load_programs_from_file(args.file)
    elif args.programs:
        programs = [Path(p) for p in args.programs]
    else:
        parser.error("Must specify either program files or --file")

    if not programs:
        logger.error("No valid programs found")
        sys.exit(1)

    # Verify all programs exist
    for program in programs:
        if not program.exists():
            logger.error(f"Program file not found: {program}")
            sys.exit(1)

    controller = HALbORDController(
        target_type=args.target,
        logic_channel=args.channel,
        sample_rate=args.sample_rate,
        num_samples=args.samples
    )

    # Prepare CSV output
    results = []

    logger.info(f"Processing {len(programs)} programs")

    for program_path in programs:
        logger.info(f"\n{'='*50}")
        logger.info(f"Processing: {program_path}")

        # Flash and capture in coordinated fashion
        flash_success, pulse_durations = controller.flash_and_capture(
            program_path,
            timeout_seconds=args.timeout
        )

        if not flash_success:
            logger.error(f"Failed to flash {program_path}, skipping")
            results.append([str(program_path), "FLASH_FAILED"])
            continue

        if not pulse_durations:
            logger.warning(f"No pulses captured for {program_path}")
            results.append([str(program_path), "NO_PULSES"])
        else:
            # Round to 2 decimal places for readability
            rounded_durations = [round(duration, 2)
                                 for duration in pulse_durations]
            results.append([str(program_path)] + rounded_durations)
            logger.info(
                f"Captured {len(pulse_durations)} pulses: {rounded_durations} μs")

    if args.output:
        with open(args.output, 'w', newline='') as csvfile:
            writer = csv.writer(csvfile)
            writer.writerow(['Program'] + [f'Pulse_{i+1}_us' for i in range(
                max(len(row)-1 for row in results) if results else 0)])
            writer.writerows(results)
        logger.info(f"Results written to {args.output}")
    else:
        writer = csv.writer(sys.stdout)
        writer.writerow(['Program'] + [f'Pulse_{i+1}_us' for i in range(
            max(len(row)-1 for row in results) if results else 0)])
        writer.writerows(results)


if __name__ == "__main__":
    main()
