#include "SplashScene.h"
#include "../View/SplashView.h"

using MoriorGames::SplashScene;
using MoriorGames::SplashView;
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

    new SplashView(this);
    loadingView = new LoadingView(this);

    return true;
}

void SplashScene::increaseLoadingBar(float delay)
{

}

void SplashScene::goToMainMenuScene(float delay)
{

}
