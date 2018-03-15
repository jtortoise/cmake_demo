include_directories(${PROJECT_SOURCE_DIR}/demo_src)

add_executable(module1_test module1_test.c)
set_target_properties(module1_test PROPERTIES 
                      RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test/module1)
target_link_libraries(module1_test module1)
