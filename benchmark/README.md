# How to run the benchmark

## Perquisites

This README.md assumes you have setup Conan, the libhal Conan remote package
server, and the libhal profiles already. If you have **NOT** done so already,
please follow the [🚀 Getting Started](https://libhal.github.io/latest/getting_started/) guide.

If you plan to test this on actual hardware, you'll need:

1. An stm32f103c8 MCU
2. A debugger that PyOCD supports
3. A logic analyzer that supports sigrok-cli

You will need to install PyOCD and signrok-cli before proceeding.

Assume all commands are executed within this `benchmark/` directory.

## Generating tests

The `generated_tests` folder should contain tests, but if you need to generate
new tests run:

```bash
cd benchmarks
python3 gen_depth_tests.py
```

If you plan to commit this change remember to run clang-format over all of the files like so, while in the benchmark directory:

```bash
find generated_tests -iname '*.cpp' | xargs clang-format -i
```

## Creating the runtimes

If the version within the `conanfile.py` is not the same as the command below,
then change it to the correct version. All builds are on Release mode for the
highest performance. But that doesn't stop you from trying out the other build
types and seeing the performance.

For `builtin` exceptions:

```bash
conan create .. -pr stm32f103c8 -pr arm-gcc-14.2 --version=1.2.0 -s build_type=Release
```

For `estell` exceptions:

```bash
conan create .. -pr stm32f103c8 -pr arm-gcc-14.2 --version=1.2.0 -s build_type=Release -o "*:runtime=estell"
```

## Building the binaries

We want to test everything so you'll need to build the binaries for both
runtimes:

```bash
conan build . -pr stm32f103c8 -pr arm-gcc-14.2 -s build_type=Release -b missing
```

```bash
conan build . -pr stm32f103c8 -pr arm-gcc-14.2 -o "*:runtime=estell" -s build_type=Release -b missing
```

## Running the HALbORD benchmark

If you don't have a HALbORD P3, no worries you can use a PyOCD debugger and
your sigrok compatible logic analyzer. Please connect everything up now. Do not
worry about flashing the device, the script will do this for you. Expect to
wear out your flash memory 😆.

If you have a HALbORD, simply connect your stm32f103c8 MicroMod to the device
and plug the `USB_U` (NOT HOST) port into your computer.

To execute the benchmark you can either supply the python script with a binary
file to flash OR provide it a newline delimitated list of executable paths.

```bash
python3 halbord_benchmark.py -o all_tests.csv -f all_tests.list
```

We currently provide the following test lists within the directory:

1. `all_tests.list`
2. `except_tests.list`
3. `result_tests.list`
