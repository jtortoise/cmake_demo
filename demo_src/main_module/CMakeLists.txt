# 整合其它全部模块的库，生成一个包含全部模块的静态库或动态库
#add_library(${PROJECT_NAME} engineer.c)

# 基于生成的静动态库生成最终的可执行文件
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SRC_LIST)
add_executable(${PROJECT_NAME} ${SRC_LIST})

include_directories(${PROJECT_SOURCE_DIR}/demo_src)
target_link_libraries(${PROJECT_NAME} module1 module2)

#安装文件
install(TARGETS ${PROJECT_NAME} 
        DESTINATION bin)
