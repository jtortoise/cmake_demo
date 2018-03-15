include_directories(${PROJECT_SOURCE_DIR}/demo_src)

add_executable(main_module_test main_module_test.c)
set_target_properties(main_module_test PROPERTIES 
                      RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test/main_module)
target_link_libraries(main_module_test module1 module2)
