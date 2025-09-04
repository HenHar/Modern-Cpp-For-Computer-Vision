cmake_minimum_required(VERSION 3.31)
project(test_homework8)

find_package(GTest REQUIRED)
find_package(PNG REQUIRED)

add_subdirectory(.. parent EXCLUDE_FROM_ALL)
include_directories(../include)

set(TEST_BINARY ${PROJECT_NAME}_test)

add_executable(${TEST_BINARY}
        test_init.cpp
        test_from_png.cpp
        test_from_ppm.cpp
        test_resize.cpp)

target_link_libraries(${TEST_BINARY} image GTest::Main PNG::PNG)
gtest_discover_tests(${TEST_BINARY} WORKING_DIRECTORY
        ${CMAKE_CURRENT_SOURCE_DIR})