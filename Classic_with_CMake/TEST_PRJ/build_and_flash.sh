set -e
rm -rf build
mkdir build
cd build
cmake -G Ninja -DCMAKE_TOOLCHAIN_FILE=arm-none-eabi-gcc.cmake ..
ninja
sudo /home/npvinh/STMicroelectronics/STM32Cube/STM32CubeProgrammer/bin/STM32_Programmer_CLI -c port=SWD sn=0672FF525470514867054915 -w blinky.bin 0x08000000 -v -rst
cd ..
pytest -s test_uart.py