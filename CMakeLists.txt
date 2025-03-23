cmake_minimum_required(VERSION 3.16.3)
project(web_server VERSION 0.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_compile_options(-Wall -Wextra -Wpedantic)

add_executable(web_server_main src/web_server.cpp)
target_link_libraries(web_server_main pthread)
