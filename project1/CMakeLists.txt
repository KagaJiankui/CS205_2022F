cmake_minimum_required(VERSION 3.0.0)
project("project1_CS205_2022F")

set(CMAKE_C_COMPILER "clang")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O0 -std=c11")

message(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/include)
aux_source_directory(${PROJECT_SOURCE_DIR}/src proj_sources)

add_executable(calc_debug ${proj_sources})