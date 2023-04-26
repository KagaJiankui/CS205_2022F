cmake_minimum_required(VERSION 3.10)
project(project3)

include_directories("${PROJECT_SOURCE_DIR}/include")
file(GLOB_RECURSE src_all "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_compile_definitions(USE_AVX2)
# add_compile_definitions(USE_OMP)
add_compile_definitions(OMP_THREAD=16)
find_package(OpenMP REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OPENMP_CXX_FLAGS} -march=native -g -O0 -msse4.1 -mssse3 -msse3 -msse2 -msse -mavx -mavx2")
add_executable(conv_test ${src_all})
target_link_libraries(conv_test PUBLIC OpenMP::OpenMP_CXX)