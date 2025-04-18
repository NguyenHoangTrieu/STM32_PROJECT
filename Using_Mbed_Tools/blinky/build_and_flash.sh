set -e
rm -rf cmake_build
mbed_tools configure -m STM32F411_DISCOVERY -t GCC_ARM
cd cmake_build/STM32F411_DISCOVERY/develop/GCC_ARM
cmake -G Ninja ../../../../
ninja