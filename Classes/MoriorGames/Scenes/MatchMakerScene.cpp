#include "MatchMakerScene.h"
#include "../Http/Client.h"
#include "../Scenes/BattleScene.h"
#include "../Services/StringFileReader.h"
#include "../Vendor/Entity/User.h"

USING_NS_CC;

Scene *MatchMakerScene::createScene()
{
    auto scene = Scene::create();
    auto layer = MatchMakerScene::create();
    scene->addChild(layer);

    return scene;
}

/**
 * on "init" you need to initialize your instance
 */
bool MatchMakerScene::init()
{
    if (!Layer::init()) {
        return false;
    }

    matchMakerView = new MatchMakerView(this);
    this->schedule(schedule_selector(MatchMakerScene::update), 0.1);

    return true;
}

void MatchMakerScene::update(float delay)
{
    if (matchMakerView->update()) {
        this->unschedule(schedule_selector(MatchMakerScene::update));
        MatchMakerScene::goToBattleScene(matchMakerView->getBattleJson());
    };
}

void MatchMakerScene::goToBattleScene(std::string json)
{
    auto scene = BattleScene::createScene(json);
    Director::getInstance()->replaceScene(TransitionFade::create(SCENES_TRANSITION_TIME, scene));
}
