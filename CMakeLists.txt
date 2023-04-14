cmake_minimum_required(VERSION 3.25)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(externals)
add_subdirectory(my_http_parser)
add_subdirectory(client)
add_subdirectory(server)
