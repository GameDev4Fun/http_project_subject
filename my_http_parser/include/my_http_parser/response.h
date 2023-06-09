#pragma once

#include <string>

#include <my_http_parser/method.h>

namespace my_http_parser {
    class Response
    {
    public:
        /**
         * Return the HTTP code of the response
         * @return
         */
        [[nodiscard]] uint8_t GetCode() const { return m_code; }

        /**
         * Return the body of the response
         * @return
         */
        [[nodiscard]] const std::string& GetBody() const { return m_body; }
    private:
        uint8_t     m_code;
        std::string m_body;
    };
}