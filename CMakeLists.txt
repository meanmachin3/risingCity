cmake_minimum_required(VERSION 3.13)  # CMake version check
project(risingCity)
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

# Add main.cpp file of project root directory as source file
set(SOURCE_FILES main.cpp)
set(TEST_FILES tests/tests.cpp)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(risingCity ${SOURCE_FILES})

add_executable(test ${TEST_FILES})

add_test(test test)