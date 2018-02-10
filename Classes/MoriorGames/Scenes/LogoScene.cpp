#include "LogoScene.h"

using MoriorGames::LogoScene;
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

    return true;
}

void LogoScene::goToSplashScene(float delay)
{
}
