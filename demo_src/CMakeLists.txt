#指定生成的可执行文件存放位置
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
#指定生成的静态库文件存放位置
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
#指定生成的动态库文件存放位置
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

#暂时手动添加各个子目录
add_subdirectory(common_modules)
add_subdirectory(module1)
add_subdirectory(module2)
add_subdirectory(test)
add_subdirectory(main_module)

