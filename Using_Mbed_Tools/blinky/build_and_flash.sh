<<<<<<< HEAD
set -e
rm -rf cmake_build
mbed_tools configure -m STM32F411_DISCOVERY -t GCC_ARM
cd cmake_build/STM32F411_DISCOVERY/develop/GCC_ARM
cmake -G Ninja ../../../../
ninja
=======

>>>>>>> 6f1e4cdd055dd43e7e5b92c4a6a9d0a206e6d05a
