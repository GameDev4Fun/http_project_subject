#include <my_http_parser/method.h>

namespace my_http_parser {
    static Method ParseMethod(const char* method, size_t  size)
    {
        //TODO : parse the method from the data sent by llhttp
        return Method::Unknown;
    }

    static Method ParseMethod(const std::string& method)
    {
        return ParseMethod(method.c_str(), method.size());
    }
}