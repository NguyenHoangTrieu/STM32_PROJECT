target_sources(Fonts PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/font8.c
    ${CMAKE_CURRENT_SOURCE_DIR}/font12.c
    ${CMAKE_CURRENT_SOURCE_DIR}/font16.c
    ${CMAKE_CURRENT_SOURCE_DIR}/font20.c
    ${CMAKE_CURRENT_SOURCE_DIR}/font24.c
)

target_include_directories(Fonts PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)