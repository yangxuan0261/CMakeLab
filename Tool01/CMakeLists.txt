cmake_minimum_required(VERSION 3.15)
project(tool01)

set(CMAKE_CXX_STANDARD 14)

add_library(tool01 SHARED library.cpp library.h)

set_target_properties(tool01 PROPERTIES OUTPUT_NAME "hello") # 修改导出的库名. 将原来导出为 libtool01.so 的库名修改为 libhello.so