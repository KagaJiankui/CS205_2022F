set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")
cmake_minimum_required(VERSION 3.0.0)
project(lab5)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0")

include_directories(${PROJECT_SOURCE_DIR}/include)
aux_source_directory(${PROJECT_SOURCE_DIR}/src source_dir)

add_executable(stuinfo ${source_dir})