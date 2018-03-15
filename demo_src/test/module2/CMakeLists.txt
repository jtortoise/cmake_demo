include_directories(${PROJECT_SOURCE_DIR}/demo_src)

add_executable(module2_test module2_test.c)
set_target_properties(module2_test PROPERTIES 
                      RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test/module2)
target_link_libraries(module2_test module2)
