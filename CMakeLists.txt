cmake_minimum_required(VERSION 3.0.0)

project(Singleton VERSION 3.9.0)

add_executable(Logger src/main.cpp)
#add_library(Singleton_lib lib/Singleton_lib.cpp)
add_library(Logger_lib lib/logger_lib.cpp)



#target_include_directories(Singleton_lib PUBLIC include)
target_include_directories(Logger_lib PUBLIC include)


#target_link_libraries(Logger Singleton_lib)
target_link_libraries(Logger Logger_lib)
