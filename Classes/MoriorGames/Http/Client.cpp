#include "Client.h"
#include "../Vendor/Utils/TextUtils.h"
#include "../Definitions.h"

Client::Client()
{
    if (SANDBOX_MODE) {
        _apiHost = "http://localhost:8000/app_dev.php/functions";
        _battleHost = "http://localhost:8001/app_dev.php";
    } else {
        _apiHost = "https://some.url.com/functions";
        _battleHost = "https://some.url.com";
    }
}

void Client::request(methodType method, const std::string &endpoint, HttpCallback &callback, const char *data)
{
    network::HttpRequest *request = new network::HttpRequest();
    request->setUrl(_apiHost + endpoint);
    request->setRequestType(method);
    request->setRequestData(data, strlen(data));
    request->setResponseCallback(callback);
    network::HttpClient::getInstance()->sendImmediate(request);
    request->release();
}

std::string Client::getSocketHost(int port)
{
    std::string socketHost = "ws://some.socket.url.com:" + to_string(port);
    if (SANDBOX_MODE) {
        socketHost = "127.0.0.1:" + to_string(port);
    }

    return socketHost;
}
