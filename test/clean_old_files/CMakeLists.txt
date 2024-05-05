project(clean_test)

add_executable(${PROJECT_NAME} clean_test.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${src})
target_link_libraries(${PROJECT_NAME} PUBLIC fs_tool)

add_test(
    NAME ${PROJECT_NAME}
    COMMAND ${PROJECT_NAME}
)