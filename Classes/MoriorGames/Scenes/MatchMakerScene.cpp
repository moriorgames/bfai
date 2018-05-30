#include "MatchMakerScene.h"
#include "../Scenes/BattleScene.h"
#include "../Services/StringFileReader.h"
#include "../Transformers/HeroesConfig2Json.h"
#include "../Vendor/Entity/User.h"
#include "../View/SplashView.h"

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

    json = (new HeroesConfig2Json)->transform(heroesConfig);
    new SplashView(this);
    loadingView = new LoadingView(this);

    this->schedule(schedule_selector(MatchMakerScene::increaseLoadingBar), LOADER_BAR_DELAY);

    return true;
}

void MatchMakerScene::increaseLoadingBar(float delay)
{
    loadingBarPercentage += 3;
    loadingView->setLoadingBarPercentage(loadingBarPercentage);
    if (loadingBarPercentage == 66) {

    }
    if (loadingBarPercentage > 99) {
        this->unschedule(schedule_selector(MatchMakerScene::increaseLoadingBar));
        MatchMakerScene::goToBattleScene();
    }
}

void MatchMakerScene::goToBattleScene()
{
    auto scene = BattleScene::createScene(json);
    Director::getInstance()->replaceScene(TransitionFade::create(SCENES_TRANSITION_TIME, scene));
}
