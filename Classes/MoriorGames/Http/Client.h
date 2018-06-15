#ifndef MORIOR_GAMES_HTTP_CLIENT_H
#define MORIOR_GAMES_HTTP_CLIENT_H

#include "cocos2d.h"
#include "network/HttpClient.h"
#include "network/WebSocket.h"

USING_NS_CC;
using methodType = cocos2d::network::HttpRequest::Type;
typedef cocos2d::network::WebSocket Socket;

typedef std::function<void(network::HttpClient *client, network::HttpResponse *response)> HttpCallback;

class InvalidRequest: public std::exception
{
public:
    const char *what() const throw()
    {
        return "C++ InvalidRequest Exception";
    }
};

class Client
{
public:
    Client();
    void apiBattle();
    void request(methodType method, const std::string &endpoint, HttpCallback &callback, const char *data = "");

    std::string getSocketHost(int port);

private:
    std::string _apiHost;

};

#endif
