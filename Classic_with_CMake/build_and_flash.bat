rmdir /S /Q build
mkdir build
cd build
cmake -G Ninja -DCMAKE_TOOLCHAIN_FILE=cmake/gcc-arm-none-eabi.cmake ..
ninja
@REM STM32_Programmer_CLI -c port=SWD sn=54FF72064885525637190787 -w ../stm32wb5x_BLE_Stack_full_fw.bin 0x080CE000 -v -rst
STM32_Programmer_CLI -c port=SWD sn=54FF72064885525637190787 -w Test_WB55.elf 0x08000000 -v -rst