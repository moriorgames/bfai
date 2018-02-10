#include "LogoScene.h"
#include "SplashScene.h"
#include "../View/LogoView.h"

using MoriorGames::LogoScene;
using MoriorGames::SplashScene;
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

    this->scheduleOnce(schedule_selector(LogoScene::goToSplashScene), SCENES_DELAY_TIME);

    return true;
}

void LogoScene::goToSplashScene(float delay)
{
    auto scene = SplashScene::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(SCENES_TRANSITION_TIME, scene));
}
