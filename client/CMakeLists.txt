add_executable(client main.cpp)

target_link_libraries(client PUBLIC my_http_parser)