# 需要最小的CMake版本
cmake_minimum_required(VERSION3.3)
# 工程的名称，会作为MSVS的Workspace的名字
project(inet_1)
 
# 全局变量：CMAKE_SOURCE_DIR CMake的起始目录，即源码的根目录
# 全局变量：PROJECT_NAME 工程的名称
# 全局变量：PROJECT_SOURCE_DIR 工程的源码根目录的完整路径
 
# 全局变量：构建输出目录。默认的，对于内部构建，此变量的值等于CMAKE_SOURCE_DIR；否则等于构建树的根目录
set(CMAKE_BINARY_DIR${CMAKE_SOURCE_DIR}/bin)  # ${}语法用于引用变量
# 全局变量：可执行文件的输出路径
set(EXECUTABLE_OUTPUT_PATH${CMAKE_BINARY_DIR})
# 全局变量：库文件的输出路径
set(LIBRARY_OUTPUT_PATH${CMAKE_BINARY_DIR})
# 设置头文件位置
include_directories("${PROJECT_SOURCE_DIR}")
# 设置C++标志位
set(CMAKE_CXX_FLAGS"${CMAKE_CXX_FLAGS} -std=c++11")
# 设置源文件集合
set(SOURCE_FILESmain.cpp)
# 添加需要构建的可执行文件，第二个以及后续参数是用于构建此文件的源码文件
add_executable(intellij_taste${SOURCE_FILES})
