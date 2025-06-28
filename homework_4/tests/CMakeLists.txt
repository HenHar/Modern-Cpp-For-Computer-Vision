cmake_minimum_required(VERSION 3.31)
project(test_vector)

find_package(Catch2 REQUIRED)
include(CTest)
include(Catch)

set(TEST_BINARY ${PROJECT_NAME}_test)

include_directories(../include/)
# Define the library BEFORE using it
add_library(ipb_algorithm INTERFACE)
target_include_directories(ipb_algorithm INTERFACE ./include/)


add_executable(${TEST_BINARY}
               test_named_vector.cpp
               #test_ipb_algorithm.cpp
               test_main.cpp)

target_link_libraries(${TEST_BINARY} ipb_algorithm Catch2::Catch2WithMain)
catch_discover_tests(${TEST_BINARY})
