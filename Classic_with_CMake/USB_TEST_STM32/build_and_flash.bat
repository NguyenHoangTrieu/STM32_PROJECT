rmdir /S /Q build
mkdir build
cd build
cmake -G Ninja -DCMAKE_TOOLCHAIN_FILE=cmake/gcc-arm-none-eabi.cmake ..
ninja
STM32_Programmer_CLI -c port=SWD sn=52FF6E064849825043360667 -w USB_TEST_STM32.bin 0x08000000 -v -rst