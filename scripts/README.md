# Scripts

The scripts for testing and playing around with libhal exceptions.

## Near Point Script?

```plaintext
usage: nearpoint.py [-h] [-b BLOCK_POWER] [-s SMALL_BLOCK_POWER] csv

positional arguments:
  csv                   csv file with columns entry_number and memory_address

options:
  -h, --help            show this help message and exit
  -b BLOCK_POWER, --block_power BLOCK_POWER
                        Set the block size based on a power of 2.
  -s SMALL_BLOCK_POWER, --small_block_power SMALL_BLOCK_POWER
                        Set the small block size based on a power of 2.
```

Test using `multi_levels.cpp` symbol CSV:

```bash
python3 nearpoint.py multi.csv -b 12 -s 7
```

Test using `firefox.cpp` sorted symbols CSV:

```bash
python3 nearpoint.py multi.csv -b 12
```
