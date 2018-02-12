#include "BattleScene.h"
#include "../View/BattleBackgroundView.h"

using MoriorGames::BattleScene;
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

    new BattleBackgroundView(this);

    return true;
}
