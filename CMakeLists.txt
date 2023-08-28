cmake_minimum_required(VERSION 3.16)
project(homework)

set(CMAKE_CXX_STANDARD 11)

file(GLOB src_dir "src/*.cpp")
file(GLOB include_dir "include/*.h")
message(will find sources in ${CMAKE_CURRENT_SOURCE_DIR}/src)
message(will find headers${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(task main.cpp ${src_dir} ${include_dir})



