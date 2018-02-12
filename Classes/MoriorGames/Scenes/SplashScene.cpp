#include "SplashScene.h"
#include "../Scenes/MainMenuScene.h"
#include "../Services/SpritesInitializer.h"
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

    this->schedule(schedule_selector(SplashScene::increaseLoadingBar), LOADER_BAR_DELAY);

    return true;
}

void SplashScene::increaseLoadingBar(float delay)
{
    loadingBarPercentage += 3;
    loadingView->setLoadingBarPercentage(loadingBarPercentage);
    if (loadingBarPercentage == 66) {
        new SpritesInitializer();
    }
    if (loadingBarPercentage > 99) {
        this->unschedule(schedule_selector(SplashScene::increaseLoadingBar));
        SplashScene::goToMainMenuScene();
    }
}

#ifdef DEBUG_SCENE
#include "../Scenes/BattleScene.h"
#endif

void SplashScene::goToMainMenuScene()
{
    Scene *scene;
    if (DEBUG_SCENE) {
        scene = BattleScene::createScene();
    } else {
        scene = MainMenuScene::createScene();
    }
    Director::getInstance()->replaceScene(TransitionFade::create(SCENES_TRANSITION_TIME, scene));
}
