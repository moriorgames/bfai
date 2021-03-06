#include "HeroesConfigScene.h"
#include "../View/BackgroundView.h"
#include "../View/HeroesConfig/HeroesConfigView.h"

USING_NS_CC;

Scene *HeroesConfigScene::createScene()
{
    auto scene = Scene::create();
    auto layer = HeroesConfigScene::create();
    scene->addChild(layer);

    return scene;
}

/**
 * on "init" you need to initialize your instance
 */
bool HeroesConfigScene::init()
{
    if (!Layer::init()) {
        return false;
    }

    new BackgroundView(this);
    new HeroesConfigView(this);

    return true;
}
