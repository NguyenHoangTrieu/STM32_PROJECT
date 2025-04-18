set -e
cd Examples/Example_01
rm -rf build
mkdir build
cd build
cmake -G Ninja -DCMAKE_TOOLCHAIN_FILE=arm-none-eabi-gcc.cmake ..
ninja
cd ../../Example_02
rm -rf build
mkdir build
cd build
cmake -G Ninja -DCMAKE_TOOLCHAIN_FILE=arm-none-eabi-gcc.cmake ..
ninja
echo Done!
