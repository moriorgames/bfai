#include "SplashScene.h"

using MoriorGames::SplashScene;
USING_NS_CC;

Scene *SplashScene::createScene()
{
    auto scene = Scene::create();
    auto layer = SplashScene::create();
    scene->addChild(layer);

    return scene;
}

/**
 * on "init" you need to initialize your instance
 */
bool SplashScene::init()
{
    if (!Layer::init()) {
        return false;
    }

    return true;
}

void SplashScene::goToMainMenuScene(float delay)
{

}
