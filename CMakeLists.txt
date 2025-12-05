cmake_minimum_required(VERSION 3.10)

project(MUGE VERSION 1.0 LANGUAGES CXX)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 包含头文件目录
include_directories(include)

# 源文件
file(GLOB SOURCES "src/*.cpp")

# 生成可执行文件
add_executable(muge ${SOURCES})
