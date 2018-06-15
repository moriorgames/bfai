#include "Client.h"
#include "../Vendor/Utils/TextUtils.h"
#include "../Definitions.h"

Client::Client()
{
    _apiHost = "https://moriorgames.com/api/";
}

void Client::apiBattle()
{
    auto method = network::HttpRequest::Type::POST;
    std::string endpoint = "battle";
    std::string data = R"(userToken=562cce32-7268-4910-8a87-76bc99dbf115&json={"hello":"world"})";

    HttpCallback callback = [=](network::HttpClient *client, network::HttpResponse *response)
    {
        if (response->getResponseCode() == 200) {
            std::vector<char> *buffer = response->getResponseData();
            std::string json(buffer->begin(), buffer->end());
            CCLOG("%s", json.c_str());

        } else {
            CCLOG("cocos2d --------- Fail with code %i", int(response -> getResponseCode()));
            CCLOG("cocos2d --------- Error buffer:");
            CCLOG("%s", response->getErrorBuffer());
        }
    };

    request(method, endpoint, callback);
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
    std::string socketHost = "ws://some.url.com:" + to_string(port);
    if (SANDBOX_MODE) {
        socketHost = "127.0.0.1:" + to_string(port);
    }

    return socketHost;
}
