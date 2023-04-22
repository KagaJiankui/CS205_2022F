cmake_minimum_required(VERSION 3.10)
project(lab9)

file(GLOB_RECURSE src_main "${PROJECT_SOURCE_DIR}/*_main.cpp")

foreach(sources ${src_main})
  string(REGEX MATCHALL "[0-9A-Za-z_]*.cpp" tmp1 ${sources})
  string(REPLACE "_main.cpp" "" exe_name ${tmp1})
  message(${exe_name})
  add_executable(${exe_name} ${sources})
endforeach()