@echo off
rem Thực hiện cho Example_01
cd Examples\Example_01
rmdir /s /q build
mkdir build
cd build
cmake -G Ninja -DCMAKE_TOOLCHAIN_FILE=arm-none-eabi-gcc.cmake ..
ninja
STM32_Programmer_CLI -c port=SWD sn=52FF6C064849825033360667 -w Example_01.bin 0x08000000 -v -rst

rem Quay lại thư mục gốc
cd ..\..\Example_02

rem Thực hiện cho Example_02
rmdir /s /q build
mkdir build
cd build
cmake -G Ninja -DCMAKE_TOOLCHAIN_FILE=arm-none-eabi-gcc.cmake ..
ninja
STM32_Programmer_CLI -c port=SWD sn=52FF6F064849825057460467 -w Example_02.bin 0x08000000 -v -rst

rem Kết thúc
echo Done!