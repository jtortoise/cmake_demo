#公共模块的编译过程是生成一个静态库给其它模块调用
#因为已经在上一层的cmake脚本中指定了生成的静态库存放的位置
#调用target_link_libraries的时候，cmake会自动搜寻库存放的位置进行链接，暂时不知道为什么

#依赖的源文件和头文件，因为只调用C库，不用指定其它头文件的位置以及链接其它库
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SRC_LIST)
add_library(common ${SRC_LIST})

#安装头文件以及库
get_filename_component(module_prefix ${CMAKE_CURRENT_SOURCE_DIR} NAME)
file(GLOB inc_files *.h)
install(FILES ${inc_files} 
        DESTINATION include/${module_prefix})
install(TARGETS common 
        DESTINATION lib)
