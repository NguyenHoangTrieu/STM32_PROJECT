target_sources(ili9341 PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/ili9341.c
)
target_include_directories(ili9341 PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)