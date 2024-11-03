cmake_minimum_required(VERSION 3.28)
project(homework3)

include_directories(include/)

link_directories()
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# set executables folder
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

## COMPILATION
add_library(html_writer src/html_writer.cpp)
add_library(image_browser src/image_browser.cpp)
add_executable(create_image_browser src/main.cpp)
target_link_libraries(create_image_browser image_browser html_writer)
