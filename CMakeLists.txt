cmake_minimum_required(VERSION 3.13)
# 1 Create an INTERFACE library aggregating all the common parts of the application
add_library(myinterface INTERFACE)

# note cmake policy is to use absolute paths for interface libraries.
target_sources(myinterface INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}/test.c
        ${CMAKE_CURRENT_LIST_DIR}/mine.c
        ${CMAKE_CURRENT_LIST_DIR}/sun.c
        )

target_compile_definitions(myinterface INTERFACE
        )

target_link_libraries( myinterface INTERFACE
        test
        pico_stdlib
        hardware_gpio
        pico_binary_info
        hardware_i2c
        )

include(pico_sdk_import.cmake)

project(test_project C CXX ASM)
set(CMAKE_C_STANDARD 11)


pico_sdk_init()

add_executable(test
test.c
)

target_link_libraries(test myinterface)

pico_enable_stdio_usb(test 1)
pico_enable_stdio_uart(test 1)

pico_add_extra_outputs(test)

