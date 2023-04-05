cmake_minimum_required(VERSION 3.0.0)
project(vector_dot)

set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -mfma -mavx2 -mavx")

file(GLOB_RECURSE sources_list "${PROJECT_SOURCE_DIR}/src/*.cpp")
include_directories("${PROJECT_SOURCE_DIR}/include")

add_executable(vector_dot ${sources_list})