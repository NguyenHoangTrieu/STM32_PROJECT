target_sources(STM32F429I-Discovery PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/stm32f429i_discovery.c
    ${CMAKE_CURRENT_SOURCE_DIR}/stm32f429i_discovery_ts.c
    ${CMAKE_CURRENT_SOURCE_DIR}/stm32f429i_discovery_sdram.c
    ${CMAKE_CURRENT_SOURCE_DIR}/stm32f429i_discovery_lcd.c
    ${CMAKE_CURRENT_SOURCE_DIR}/stm32f429i_discovery_io.c
    ${CMAKE_CURRENT_SOURCE_DIR}/stm32f429i_discovery_gyroscope.c
    ${CMAKE_CURRENT_SOURCE_DIR}/stm32f429i_discovery_eeprom.c
)
target_include_directories(STM32F429I-Discovery PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(STM32F429I-Discovery
${CMAKE_CURRENT_SOURCE_DIR}/../../../mbed-os
)