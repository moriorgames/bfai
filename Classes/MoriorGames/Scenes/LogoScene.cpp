#include "LogoScene.h"
#include "../View/LogoView.h"

using MoriorGames::LogoScene;
using MoriorGames::LogoView;
USING_NS_CC;

Scene *LogoScene::createScene()
{
    auto scene = Scene::create();
    auto layer = LogoScene::create();
    scene->addChild(layer);

    return scene;
}

/**
 * on "init" you need to initialize your instance
 */
bool LogoScene::init()
{
    if (!Layer::init()) {
        return false;
    }

    (new LogoView(this))->addLogo();

    return true;
}

void LogoScene::goToSplashScene(float delay)
{
}
