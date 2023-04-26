cmake_minimum_required(VERSION 3.10)
project(lab10)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g")

include_directories(${PROJECT_SOURCE_DIR}/include)
file(GLOB_RECURSE source ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_executable(mycomplex ${source})
# target_link_libraries(mycomplex m)