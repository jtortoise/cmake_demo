aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SRC_LIST)
add_library(module2 ${SRC_LIST})

include_directories(${PROJECT_SOURCE_DIR}/demo_src)
target_link_libraries(module2 common)

#安装头文件以及库文件
file(GLOB inc_files *.h)
get_filename_component(module_prefix ${CMAKE_CURRENT_SOURCE_DIR} NAME)
install(FILES ${inc_files} 
        DESTINATION include/${module_prefix})
install(TARGETS module2 
        DESTINATION lib)
