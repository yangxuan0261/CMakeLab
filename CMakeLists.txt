# 加入 其他模块

cmake_minimum_required(VERSION 3.15)
project(CMakeLab)

set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE SRC_aaa
        aaa/**.h
        aaa/**.cpp
        aaa/**.c
        )

set(SOURCE_FILES main.cpp ${SRC_aaa})

include_directories("${PROJECT_SOURCE_DIR}/tool02" "${PROJECT_SOURCE_DIR}")
add_subdirectory(tool02) # 指定需要编译的子目录, 产生的中间文件默认目录名为目录名

add_executable(CMakeLab ${SOURCE_FILES})

target_link_libraries(CMakeLab tool02)

# 安装
install(TARGETS CMakeLab tool02
RUNTIME DESTINATION bin
LIBRARY DESTINATION lib
)