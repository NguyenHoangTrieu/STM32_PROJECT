set -e
rm -rf cmake_build
mbed_tools compile -m DISCO_F429ZI -t GCC_ARM
cd cmake_build/DISCO_F429ZI/develop/GCC_ARM
sudo /home/npvinh/STMicroelectronics/STM32Cube/STM32CubeProgrammer/bin/STM32_Programmer_CLI -c port=SWD sn=0672FF525470514867054915 -w lcd.bin 0x08000000 -v -rst
cd ../../../../
pytest -s test_uart.py
