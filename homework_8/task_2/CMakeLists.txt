cmake_minimum_required(VERSION 3.31)
project(homework8)

set(CMAKE_CXX_STANDARD 20)

find_package(PNG REQUIRED)

include_directories(include/)

add_library(image src/Image.cpp
        src/IoStrategy.cpp)

add_executable(test_image
        src/test_image.cpp
)
target_link_libraries(test_image image PNG::PNG)