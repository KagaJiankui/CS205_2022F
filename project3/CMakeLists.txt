cmake_minimum_required (VERSION 3.0)
project(project3)

include_directories(${PROJECT_SOURCE_DIR}/include)
set(src_dir ${PROJECT_SOURCE_DIR}/src)
set(lib_dir ${PROJECT_SOURCE_DIR}/build)

add_library(matrixlib SHARED ${src_dir}/matrixlib.cpp)
target_link_libraries(matrixlib m)

# add_executable(test ${src_dir}/testlib.cpp)
# target_link_libraries(test ${lib_dir}/libmatrixlib.so)