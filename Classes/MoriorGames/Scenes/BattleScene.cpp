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

    battleView = new BattleView(this);

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
//    std::string socketHost = container->getBattleClient()->getSocketHost(port);
//    socket->init(*this, socketHost);
}

void BattleScene::onOpen(Socket *ws)
{
}

void BattleScene::onMessage(Socket *ws, const Socket::Data &data)
{
    // Sync first time when get checksum
    std::string json = data.bytes;
//    synchroTurn = container->getBattleManager()->getBattleParser()->parseAction(json);
}

void BattleScene::onClose(Socket *ws)
{
}

void BattleScene::onError(Socket *ws, const Socket::ErrorCode &error)
{
}
