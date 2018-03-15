#安装配置文件
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} 
        DESTINATION share
        PATTERN "*.txt" EXCLUDE)
