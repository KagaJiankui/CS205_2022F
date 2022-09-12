cmake_minimum_required(VERSION 3.0.0)
project("project1_CS205_2022F")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -std=c++11")

message(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/include)
aux_source_directory(${PROJECT_SOURCE_DIR}/src proj_sources)

add_executable(calc_debug ${proj_sources})