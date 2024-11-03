cmake_minimum_required(VERSION 3.28)
project(homework2)


include_directories(include/)
add_library(libipb_arithmetic src/subtract.cpp  src/sum.cpp)
add_executable(main src/main.cpp)

target_link_libraries(main libipb_arithmetic)


