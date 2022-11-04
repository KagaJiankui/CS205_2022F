cmake_minimum_required(VERSION 3.12)

#add_definitions(-DWITH_NEON)
add_definitions(-DWITH_AVX2)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -march=native")
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -O3 -march=native")

project(dotp)

ADD_EXECUTABLE(dotp main.cpp timeeval_mult.cpp matoperation.cpp)
add_executable(add_avx2 main.cpp timeeval_add_omp.cpp matoperation.cpp)

find_package(OpenMP)
if(OpenMP_CXX_FOUND)
    message("OpenMP found.")
    target_link_libraries(dotp PUBLIC OpenMP::OpenMP_CXX)
    target_link_libraries(add_avx2 PUBLIC OpenMP::OpenMP_CXX)
endif()
