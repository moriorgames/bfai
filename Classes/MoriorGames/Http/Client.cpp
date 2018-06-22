#include "Client.h"
#include "../Scenes/BattleScene.h"
#include "../Vendor/Entity/User.h"
#include "../Vendor/Utils/TextUtils.h"
#include "../Vendor/Parsers/BattleParser.h"
#include "../Transformers/HeroesConfig2Json.h"
#include "../Definitions.h"

Client::Client()
{
    _apiHost = "https://moriorgames.com/api/";
}

void Client::apiBattle()
{
    auto method = network::HttpRequest::Type::POST;
    std::string endpoint = "battle";
    auto json = (new HeroesConfig2Json)->transform(heroesConfig);
    std::string data = "userToken=" + playerUser->getToken() + "&json=" + json;

    HttpCallback callback = [=](network::HttpClient *client, network::HttpResponse *response)
    {
        if (response->getResponseCode() == 200) {
            std::vector<char> *buffer = response->getResponseData();
            std::string json(buffer->begin(), buffer->end());
            auto battle = (new BattleParser(json))->parse();
            if (battle->getStatus() == BATTLE_IN_PROGRESS) {
                auto scene = BattleScene::createScene(json);
                Director::getInstance()->replaceScene(TransitionFade::create(SCENES_TRANSITION_TIME, scene));
            }

        } else {
            CCLOG("cocos2d --------- Fail with code %i", int(response -> getResponseCode()));
            CCLOG("cocos2d --------- Error buffer:");
            CCLOG("%s", response->getErrorBuffer());
        }
    };

    request(method, endpoint, callback, data.c_str());
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
