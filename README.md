# sx1280

This library is an adaptation of the code of Stuart Robinson, it allows you to use LoRa modulation with an sx1280 radio module with your raspberry pi pico and the C/C++ SDK. This library was tested with ebyte modules (E28-2G4M27S). 

Here is an example of CMakeList :

    # Set minimum required version of CMake
    cmake_minimum_required(VERSION 3.12)
    #include build functions from Pico SDK
    include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)
    # Set name of project (as PROJECT_NAME) and C/C++ Standards
    project(sx1280 C CXX ASM)
    set(CMAKE_C_STANDARD 11)
    set(CMAKE_CXX_STANDARD 17)
    # Creates a pico-sdk subdirectory in our project for the libraries
    pico_sdk_init()

    # point out the CMake, where to find the executable source file
    add_executable(${PROJECT_NAME}
        rx.cpp
        Settings.h
        SX1280_Def.h
        SX1280.h
        SX1280.cpp
    )
    # create map/bin/hex/uf2 files.
    pico_add_extra_outputs(${PROJECT_NAME})
    # Pull in our pico_stdlib which pulls in commonly used features (gpio, timer-delay etc)
    target_link_libraries(${PROJECT_NAME}
            pico_stdlib
            hardware_spi
    )

    pico_enable_stdio_usb(${PROJECT_NAME} 1)
    pico_enable_stdio_uart(${PROJECT_NAME} 0)
