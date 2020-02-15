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

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} tool02)

# 添加 预编译宏
add_definitions(
        -D USE_FILTER
)

# 安装
install(TARGETS ${PROJECT_NAME} tool02
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        )

# 打包
set(VERSION_MAJOR 1)
set(VERSION_MINOR 3)
set(VERSION_PATCH 1)

include(InstallRequiredSystemLibraries)
set(CPACK_PACKAGE_DIRECTORY ${PROJECT_SOURCE_DIR}/pack) #  打包后的存放目录
set(CPACK_RESOURCE_FILE_LICENSE "${PROJECT_SOURCE_DIR}/License.txt") # 协议
set(CPACK_PACKAGE_VERSION_MAJOR "${VERSION_MAJOR}") # 版本号
set(CPACK_PACKAGE_VERSION_MINOR "${VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${VERSION_PATCH}")
set(PROJECT_VERSION_FULL ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}) # 版本号
set(CPACK_SOURCE_IGNORE_FILES # 忽略文件
        ${PROJECT_SOURCE_DIR}/build
        ${PROJECT_SOURCE_DIR}/cmake-build-debug
        ${PROJECT_SOURCE_DIR}/pack
        ${PROJECT_SOURCE_DIR}/.idea
        ${PROJECT_SOURCE_DIR}/.DS_Store
        ${PROJECT_SOURCE_DIR}/.git
        ${PROJECT_SOURCE_DIR}/.gitignore
        ${PROJECT_SOURCE_DIR}/.vscode)

set(CPACK_SOURCE_GENERATOR "TGZ") # 打包格式
set(CPACK_SOURCE_PACKAGE_FILE_NAME ${PROJECT_NAME}-${PROJECT_VERSION_FULL}) # 打包文件名称

include(CPack)

