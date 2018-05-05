#include "BattleHeroesScene.h"
#include "../View/BackgroundView.h"
#include "../View/BattleHeroes/BattleHeroesView.h"

USING_NS_CC;

Scene *BattleHeroesScene::createScene()
{
    auto scene = Scene::create();
    auto layer = BattleHeroesScene::create();
    scene->addChild(layer);

    return scene;
}

/**
 * on "init" you need to initialize your instance
 */
bool BattleHeroesScene::init()
{
    if (!Layer::init()) {
        return false;
    }

    new BackgroundView(this);
    new BattleHeroesView(this);

    return true;
}
