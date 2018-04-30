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
