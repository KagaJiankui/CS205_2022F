cmake_minimum_required(VERSION 3.0.0)
project(lab2 VERSION 0.1.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -O0 -std=c++11")

include_directories(${PROJECT_SOURCE_DIR}/include)
set(dir_src ${PROJECT_SOURCE_DIR}/src)

add_executable(main_1 ${dir_src}/main_1.cpp ${dir_src}/mul.cpp)
add_executable(ex_2 ${dir_src}/ex_2.cpp)
add_executable(ex_3 ${dir_src}/ex_3.cpp)
add_executable(overflow ${dir_src}/overflow.cpp)
add_executable(ascii2int ${dir_src}/ascii_to_int.cpp)
add_executable(ieee754bin ${dir_src}/ieee754bin.cpp)