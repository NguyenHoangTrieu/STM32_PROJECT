set -e
rm -rf build
mkdir build
cd build
cmake -G Ninja -DCMAKE_TOOLCHAIN_FILE=arm-none-eabi-gcc.cmake ..
ninja