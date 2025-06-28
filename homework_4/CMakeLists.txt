cmake_minimum_required(VERSION 3.5)
project(homework4)



include_directories(include/)

# Create INTERFACE library (header-only)
add_library(ipb_algorithm INTERFACE)
# Specify include directories for the library
target_include_directories(ipb_algorithm INTERFACE ./include/)


# Create executable
add_executable(test_vector src/test_vector.cpp)

# Link library to executable (this automatically inherits the include directories)
target_link_libraries(test_vector ipb_algorithm)


