cmake_minimum_required(VERSION 3.15)
project(tool01)

set(CMAKE_CXX_STANDARD 14)

add_library(tool01 SHARED library.cpp library.h)