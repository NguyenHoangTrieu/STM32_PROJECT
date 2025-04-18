rmdir /s /q cmake_build
mbed-tools configure -m STM32F411_DISCOVERY -t GCC_ARM
cd cmake_build\STM32F411_DISCOVERY\develop\GCC_ARM
cmake -G Ninja ../../../../ (to main CmakeList)
ninja
