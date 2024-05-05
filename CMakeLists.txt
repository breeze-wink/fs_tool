cmake_minimum_required(VERSION 3.0)

project(fs-tool
    VERSION 0.0.1
    DESCRIPTION "使用C++17的filesystem实现几个工程中常用的文件系统工具"
    HOMEPAGE_URL "https://github.com/breeze-wink/fs_tool"
    LANGUAGES CXX    
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
enable_testing()

