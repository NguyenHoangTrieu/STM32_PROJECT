rmdir /s /q cmake_build
mbed-tools configure -m STM32F411_DISCOVERY -t GCC_ARM
cd cmake_build\STM32F411_DISCOVERY\develop\GCC_ARM
cmake -G Ninja ../../../../ (to main CmakeList)
ninja
STM32_Programmer_CLI -c port=SWD sn=52FF6F064849825057460467 -w blinky.bin 0x08000000 -v -rst