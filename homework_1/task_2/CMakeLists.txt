cmake_minimum_required(VERSION 3.13)  # CMake version check
project(task_2)               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 17)            # Enable c++14 standard


set (CMAKE_INSTALL_PREFIX /install)

include_directories(include/)

add_library(ipb_arithmetic src/subtract.cpp  src/sum.cpp)
add_executable(main src/main.cpp)
target_link_libraries(main ipb_arithmetic)


# install
install(TARGETS ipb_arithmetic DESTINATION ${PROJECT_SOURCE_DIR}/install/lib)
install(DIRECTORY include/ DESTINATION ${PROJECT_SOURCE_DIR}/install/include/)
