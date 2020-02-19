# 加入 第三方库

cmake_minimum_required(VERSION 3.15)
project(CMakeLab)

set (CMAKE_BUILD_TYPE "Release") # Release


set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lmingw32") # 添加编译选项

file(GLOB_RECURSE src_aaa
        aaa/**.h
        aaa/**.cpp
        aaa/**.c
        )

# set 设置变量
set(SOURCE_FILES main.cpp ${src_aaa})
message(STATUS "--- SOURCE_FILES: ${SOURCE_FILES}") # 查看所有文件

set(INC_DIR ${PROJECT_SOURCE_DIR}/tool01)
set(LINK_DIR ${PROJECT_SOURCE_DIR}/libs) # 动态库 存放目录. 先构建 tool01 工程, 会导出 库 到这个目录


# 拷贝文件 方式一
#configure_file(
#        "${LINK_DIR}/libtool01.dll"
#        "${PROJECT_BINARY_DIR}/libtool01.dll"
#        COPYONLY
#)

# 拷贝文件 方式二: 批量拷贝. 将 动态库 拷贝到可执行文件目录, 不然找不到库会报错: exit code -1073741515 (0xC0000135)
set(libDstPath "${PROJECT_BINARY_DIR}")
file(GLOB libFiles # 匹配到需要拷贝的文件
  "${PROJECT_SOURCE_DIR}/libs/*"
)
message(STATUS "--- libFiles: ${libFiles}")
message(STATUS "--- libDstPath: ${libDstPath}")
file(COPY ${libFiles} DESTINATION ${libDstPath})


include_directories(${INC_DIR}) # 相当于gcc/clang 中的-I(i的大写字母)参数, 引入 头文件 目录
link_directories(${LINK_DIR}) # 相当于gcc 中的-L参数, 引入 库文件 目录

# 生成 可执行文件
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} tool01) # 相当于gcc中的-l(小写的l)参数, 链接 库文件

# 添加 预编译宏
add_definitions(
        -D USE_LOG=3 # 定义值
        -D USE_FILTER
)

set(p6 helloworld)
message(STATUS "--- p6=${p6}") # 输出日志

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

# 打包 源码
#set(CPACK_PACKAGING_INSTALL_PREFIX "/opt/${PROJECT_NAME}") # 从发布包中安装 源码 时，文件将放在/opt/${PROJECT_NAME}目录下
set(CPACK_SOURCE_GENERATOR "TGZ") # 打包文件 格式
set(CPACK_SOURCE_PACKAGE_FILE_NAME ${PROJECT_NAME}-${PROJECT_VERSION_FULL}-src) # 打包文件 名称

# 打包 可执行文件
#set(CMAKE_INSTALL_PREFIX "/opt/${PROJECT_NAME}") # 从发布包中安装 可执行文件 时，文件将放在/opt/${PROJECT_NAME}目录下
set(CPACK_GENERATOR "TGZ")
set(CPACK_PACKAGE_FILE_NAME ${PROJECT_NAME}-${PROJECT_VERSION_FULL}-bin)

include(CPack)
