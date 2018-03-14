#include "BattleScene.h"
#include "../Grid/GridSystem.h"
#include "../View/BattleBackgroundView.h"
#include "../View/HeroView.h"

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
    auto gridSystem = new GridSystem();

    auto grid = gridSystem->displayGrid();
    this->addChild(grid, Z_ORDER_GRID);

    new HeroView(this);

    return true;
}
