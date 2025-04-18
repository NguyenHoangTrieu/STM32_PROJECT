set -e
rm -rf cmake_build
mbed_tools compile -m STM32F411_DISCOVERY -t GCC_ARM
