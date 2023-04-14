add_executable(server main.cpp)

target_link_libraries(server PUBLIC my_http_parser)