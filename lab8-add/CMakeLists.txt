cmake_minimum_required(VERSION 3.0.0)
project(lab8-add)

add_executable(add_avx2 main.cpp)
find_package(OpenMP)
if(OpenMP_CXX_FOUND)
    message("OpenMP found.")
    target_link_libraries(add_avx2 PUBLIC OpenMP::OpenMP_CXX)
endif()
