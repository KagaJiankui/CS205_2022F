cmake_minimum_required(VERSION 3.0.0)
project(lab1)

include_directories(${PROJECT_SOURCE_DIR}/include)
aux_source_directory(${PROJECT_SOURCE_DIR}/src lab1_source)

add_executable(lab1 ${lab1_source})
