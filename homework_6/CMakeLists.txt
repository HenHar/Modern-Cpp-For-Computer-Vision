cmake_minimum_required(VERSION 3.31)
project(homework6)

include_directories(.)
include_directories(homework/homework_6/include/)
include_directories(include/)
include_directories(io_tools/)

add_library(io_tools io_tools/io_tools.cpp)
add_library(image src/Image.cpp)

target_link_libraries(image io_tools)

add_executable(test_image
        src/test_image.cpp
)
target_link_libraries(test_image image)
