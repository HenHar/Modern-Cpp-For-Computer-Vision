cmake_minimum_required(VERSION 3.31)
project(homework6)



include_directories(include/)
include_directories(io_tools/)
# Add your class as a library (if it has .cpp files)
add_library(io_tools io_tools/io_tools.cpp)


add_executable(image
        src/test_image.cpp
        src/Image.cpp
)



target_link_libraries(image io_tools)
