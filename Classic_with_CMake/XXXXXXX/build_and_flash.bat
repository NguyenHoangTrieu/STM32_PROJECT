rmdir /S /Q build
mkdir build
cd build
cmake -G Ninja -DCMAKE_TOOLCHAIN_FILE=cmake/gcc-arm-none-eabi.cmake ..
ninja
STM32_Programmer_CLI -c port=SWD sn=066AFF303430484257141026 -w XXXXXXX.bin 0x08000000 -v -rst