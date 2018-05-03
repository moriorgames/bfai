#include "BattleScene.h"
#include "MainMenuScene.h"

USING_NS_CC;

Scene *BattleScene::createScene()
{
    auto scene = Scene::create();
    auto layer = BattleScene::create();
    scene->addChild(layer);

    return scene;
}

/**
 * on "init" you need to initialize your instance
 */
bool BattleScene::init()
{
    if (!Layer::init()) {
        return false;
    }

    socket = new Socket;
    battleView = new BattleView(this, socket);
    connectToSocket(8080);

    this->schedule(schedule_selector(BattleScene::scheduledEvents), 3.f);

    return true;
}

void BattleScene::scheduledEvents(float delay)
{
    battleView->ai();
}

void BattleScene::goToMainMenuScene(float delay)
{
    auto scene = MainMenuScene::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(SCENES_TRANSITION_TIME, scene));
}

void BattleScene::connectToSocket(int port)
{
    std::string socketHost = "127.0.0.1:8080";
    socket->init(*this, socketHost);
}

void BattleScene::onOpen(Socket *ws)
{
}

void BattleScene::onMessage(Socket *ws, const Socket::Data &data)
{
    std::string json = data.bytes;
    battleView->processOnlineAction(data.bytes);
    CCLOG("%s", data.bytes);
}

void BattleScene::onClose(Socket *ws)
{
}

void BattleScene::onError(Socket *ws, const Socket::ErrorCode &error)
{
}
