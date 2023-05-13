cmake_minimum_required(VERSION 3.10)
project(lab10)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g -Wall -fdiagnostics-color=always -fdiagnostics-show-category=name -fdiagnostics-format=vi")

include_directories(${PROJECT_SOURCE_DIR}/include)
set(ex1_source ${PROJECT_SOURCE_DIR}/src/exercise1.cpp)
set(ex2_source ${PROJECT_SOURCE_DIR}/src/exercise2.cpp)
set(ex3_source ${PROJECT_SOURCE_DIR}/src/exercise3.cpp)

add_executable(exercise1 ${ex1_source})
add_executable(exercise3 ${ex3_source})
# target_link_libraries(mycomplex m)