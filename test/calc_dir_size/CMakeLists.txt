project(calc_dir_size_test)

add_executable(${PROJECT_NAME} calc_dir_size_test.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${src})

target_link_libraries(${PROJECT_NAME} PUBLIC fs_tool)

