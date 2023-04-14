add_library(my_http_parser STATIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/client.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/method.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/request.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/response.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/server.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/connection.cpp

        ${CMAKE_CURRENT_SOURCE_DIR}/include/my_http_parser/client.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/my_http_parser/method.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/my_http_parser/request.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/my_http_parser/response.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/my_http_parser/server.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/my_http_parser/connection.h)

target_include_directories(my_http_parser PUBLIC include)

target_link_libraries(my_http_parser PUBLIC llhttp::llhttp nlohmann_json)