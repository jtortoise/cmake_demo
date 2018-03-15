# 普通模块1，生成静态库给主模块调用
# 因为模块1的组件依赖公共模块的组件，所以需要包含到其头文件以及链接其静态库
# 链接公共模块的库时，不用指定库路径，因为在上一层目录已经指定库的生成路径，cmake会到相应的路径进行库查找

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SRC_LIST)
add_library(module1 ${SRC_LIST})

# 指定依赖的公共模块组件头文件位置以及链接的组件库
include_directories(${PROJECT_SOURCE_DIR}/demo_src)
target_link_libraries(module1 common)

#安装头文件以及库文件
file(GLOB inc_files *.h)
get_filename_component(module_prefix ${CMAKE_CURRENT_SOURCE_DIR} NAME)
install(FILES ${inc_files} 
        DESTINATION include/${module_prefix})
install(TARGETS module1 
        DESTINATION lib)

