# add STM32F411 Discovery board support
# This file is part of the mbed OS project.
# No copyright is required for this file.
add_library(mbed-stm32f411-discovery INTERFACE)

target_sources(mbed-stm32f411-discovery
    INTERFACE
        PeripheralPins.c
)

target_include_directories(mbed-stm32f411-discovery
    INTERFACE
        .
)

target_link_libraries(mbed-stm32f411-discovery INTERFACE mbed-stm32f411xe)