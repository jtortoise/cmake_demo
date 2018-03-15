include_directories(${PROJECT_SOURCE_DIR}/demo_src)

add_executable(common_test common_test.c)
set_target_properties(common_test PROPERTIES
                      RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test/common_modules)
target_link_libraries(common_test common)
