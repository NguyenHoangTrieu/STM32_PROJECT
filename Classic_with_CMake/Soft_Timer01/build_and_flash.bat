set -e
cd Examples/Example_01
rm -rf build
mkdir build
cd build
cmake -G Ninja -DCMAKE_TOOLCHAIN_FILE=arm-none-eabi-gcc.cmake ..
ninja
STM32_Programmer_CLI -c port=SWD sn=52FF6C064849825033360667 -w Example_01.bin 0x08000000 -v -rst
cd ../../Example_02
rm -rf build
mkdir build
cd build
cmake -G Ninja -DCMAKE_TOOLCHAIN_FILE=arm-none-eabi-gcc.cmake ..
ninja
STM32_Programmer_CLI -c port=SWD sn=52FF6F064849825057460467 -w Example_02.bin 0x08000000 -v -rst
echo Done!
