cmake_minimum_required(VERSION 3.0)

project(fs-tool
    VERSION 0.0.1
    DESCRIPTION "使用C++17的filesystem实现几个工程中常用的文件系统工具"
    HOMEPAGE_URL "https://github.com/breeze-wink/fs_tool"
    LANGUAGES CXX    
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(src ${PROJECT_SOURCE_DIR}/fs_tool)

enable_testing()

add_library(fs_tool SHARED ./fs_tool/fs_tool.cpp)

add_subdirectory(test/backup_files)
add_subdirectory(test/clean_old_files)
add_subdirectory(test/calc_dir_size)

target_include_directories(fs_tool PUBLIC ./fs_tool)
