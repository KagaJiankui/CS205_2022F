cmake_minimum_required(VERSION 3.0.0)
project(lab1)

include_directories(${PROJECT_SOURCE_DIR}/include)
set(source_lab1 ${PROJECT_SOURCE_DIR}/src)

add_executable(add ${source_lab1}/main.cpp ${source_lab1}/add.cpp)
add_executable(cout_test ${source_lab1}/cout_test.cpp)