CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
project(cmake_demo)

SET(CMAKE_INCLUDE_CURRENT_DIR ON)

#暂时先手动添加各个子目录
add_subdirectory(demo_config)
add_subdirectory(demo_doc)
add_subdirectory(demo_resources)
add_subdirectory(demo_src)

