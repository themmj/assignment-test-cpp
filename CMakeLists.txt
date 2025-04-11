cmake_minimum_required(VERSION 3.10)

project(assignment-test-cpp)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# general settings
set(BINARY assignment-test)
set(BIN_DIR ${CMAKE_SOURCE_DIR}/out)
set(THIRD_PARTY_DIR ${CMAKE_SOURCE_DIR}/third-party)

# add gtest
include(${THIRD_PARTY_DIR}/FetchGTest.cmake)

# include dirs
set(INCLUDE_DIRS
    ${CMAKE_SOURCE_DIR}/src
)

# libraries
set(LIBRARIES
    GTest::gtest
    GTest::gtest_main
)

set(BIN_COMPILE_OPTIONS
    -Wall
    -Werror
    -Wextra
    -Wpedantic
    -Wconversion
    -Wcast-align
    -Wno-unused
    -Wshadow
    -D_ASSIGNMENT_RUNNING_TESTS
)

include(submissions/submission.cmake)

add_subdirectory(src)

