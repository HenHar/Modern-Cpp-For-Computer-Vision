cmake_minimum_required(VERSION 3.31)
project(homework_5)

set(CMAKE_CXX_STANDARD 17)

#set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

include_directories(include/)
set(OpenCV_DIR "/home/hendrik/libs/opencv/lib/cmake/opencv4")
find_package(OpenCV REQUIRED)
find_package(Catch2 REQUIRED)

# Add library with source files
add_library(mat_serialization src/serialize.cpp)
add_library(convert_dataset src/convertDataset.cpp)

add_executable(main src/main.cpp)

target_link_libraries(mat_serialization ${OpenCV_LIBS})
target_link_libraries(convert_dataset ${OpenCV_LIBS})
target_link_libraries(main mat_serialization convert_dataset ${OpenCV_LIBS})
