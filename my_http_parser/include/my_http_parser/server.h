#pragma once

#include <functional>
#include <unordered_map>
#include <vector>

#include <WinSock2.h>

#include <llhttp.h>

#include <my_http_parser/connection.h>
#include <my_http_parser/response.h>
#include <my_http_parser/request.h>

namespace my_http_parser {

    using Handler = std::function<void(const Request& request, Response& response)>;

    struct HandlerHolder
    {
        Method m_method;
        Handler m_handler;
    };

    class Server
    {
    public:
        /**
         * Construct a server
         * @param listeningInterface The interface to bind to
         * @param listeningPort The port to bind to
         */
        Server(const std::string& listeningInterface, uint16_t listeningPort);

        /**
         * Destroy and clean a server
         */
        ~Server();

        /**
         * Start the server listening infinite loop for connection
         */
        void Listen();

        /**
         * Register a handler to a path and method
         * @param method The method to react to
         * @param path  The path to react on
         * @param handler The handler to call
         */
        void Handle(Method method, const std::string& path, Handler handler);

        /**
         * Register a handler to a path with the method as a GET
         * @param path  The path to react on
         * @param handler The handler to call
         */
        void Get(const std::string& path, Handler handler);

        /**
         * Register a handler to a path with the method as a POST
         * @param path  The path to react on
         * @param handler The handler to call
         */
        void Post(const std::string& path, Handler handler);

        /**
         * Register a handler to a path with the method as a PUT
         * @param path  The path to react on
         * @param handler The handler to call
         */
        void Put(const std::string& path, Handler handler);

        /**
         * Register a handler to a path with the method as a DELETE
         * @param path  The path to react on
         * @param handler The handler to call
         */
        void Delete(const std::string& path, Handler handler);
    private:
        SOCKET                                        m_serverSocket;
        std::vector<Connection>                       m_clientConnections;
        std::unordered_map<std::string,HandlerHolder> m_handlers;
    };
}