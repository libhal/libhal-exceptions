# Scripts

The scripts for testing and playing around with libhal exceptions.

## Near Point Script?

```plaintext
usage: nearpoint.py [-h] [-b BLOCK_POWER] [-s SMALL_BLOCK_POWER] [-n] file

positional arguments:
  file                  text file with a list of function addresses in your code starting from 0 to N where N is the last function
                        address, or output from the command: nm app.elf --size-sort --radix=d | grep " [Tt] " | awk '{print $1}'

options:
  -h, --help            show this help message and exit
  -b BLOCK_POWER, --block_power BLOCK_POWER
                        Set the block size based on a power of 2.
  -s SMALL_BLOCK_POWER, --small_block_power SMALL_BLOCK_POWER
                        Set the small block size based on a power of 2.
  -n, --nm              The input file is actually output from an NM command: nm app.elf --size-sort --radix=d | grep " [Tt] " | awk
                        '{print $1}'
```

The script works with output from nm following this:

```bash
python3 nearpoint.py --tool-prefix="/path/to/arm-none-eabi/bin/" --map="app.elf.map" app.elf
```

After

What this will do is create a size sorted list of each function in the program
and output its starting address. This easy to execute script enable 3rd parties
to send us this information in a mostly erased fashion to compare against our
application. Even if the application does not use exceptions.

```bash
python3 scripts/nearpoint.py demos/multi_levels.elf.nm -n -b 10
```
