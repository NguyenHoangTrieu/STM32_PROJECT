set -e
rm -rf cmake_build
mbed_tools compile -m STM32F411_DISCOVERY -t GCC_ARM
cd cmake_build/STM32F411_DISCOVERY/develop/GCC_ARM
cd ../../../../
sudo /home/npvinh/STMicroelectronics/STM32Cube/STM32CubeProgrammer/bin/STM32_Programmer_CLI -c port=SWD sn=52FF6E064849825043360667 -w blinky.bin 0x08000000 -v -rst
pytest -s test_uart.py
