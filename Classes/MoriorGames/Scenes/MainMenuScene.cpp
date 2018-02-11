#include "MainMenuScene.h"
#include "../View/Buttons/BattleButton.h"
#include "../View/BackgroundView.h"
#include "../View/WorldView.h"

using MoriorGames::MainMenuScene;
USING_NS_CC;

Scene *MainMenuScene::createScene()
{
    auto scene = Scene::create();
    auto layer = MainMenuScene::create();
    scene->addChild(layer);

    return scene;
}

/**
 * on "init" you need to initialize your instance
 */
bool MainMenuScene::init()
{
    if (!Layer::init()) {
        return false;
    }

    new BackgroundView(this);
    new WorldView(this);
    new BattleButton(this);

    return true;
}
