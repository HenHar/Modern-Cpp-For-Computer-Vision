cmake_minimum_required(VERSION 3.31)
project(testing)

set(OpenCV_DIR "/home/hendrik/libs/opencv/lib/cmake/opencv4")
include_directories(../include/)
find_package(Catch2 REQUIRED)
find_package(OpenCV REQUIRED)
include(CTest)
include(Catch)


add_subdirectory(.. parent EXCLUDE_FROM_ALL)
include_directories(../include)

add_library(sifts_internal SHARED sifts_internal.cpp)
target_link_libraries(sifts_internal ${OpenCV_LIBS})

set(TEST_BINARY ${PROJECT_NAME}_test)
add_executable(${TEST_BINARY}
               test_serialize.cpp
               test_convert_dataset.cpp
               test_main.cpp)

target_link_libraries(${TEST_BINARY}
                      convert_dataset
                      mat_serialization
                      sifts_internal
                      Catch2::Catch2WithMain)

catch_discover_tests(${TEST_BINARY} WORKING_DIRECTORY
                     ${CMAKE_CURRENT_SOURCE_DIR})
