#include "SplashScene.h"
#include "../Scenes/MainMenuScene.h"
#include "../Services/SpritesInitializer.h"
#include "../Services/StringFileReader.h"
#include "../Vendor/Entity/User.h"
#include "../Vendor/Parsers/UserParser.h"
#include "../Vendor/Repository/HeroRepository.h"
#include "../Vendor/Repository/SkillRepository.h"
#include "../Vendor/Repository/SkillHeroRepository.h"
#include "../View/SplashView.h"

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
        auto stringFileReader = new StringFileReader;
        auto userJson = stringFileReader->getStringFromFile("data/user.json");
        playerUser = (new UserParser(userJson))->parse();
        auto apiJson = stringFileReader->getStringFromFile("data/api-data.json");
        heroRepo->init(apiJson);
        skillRepo->init(apiJson);
        skillHeroRepo->init(apiJson);
    }
    if (loadingBarPercentage > 99) {
        this->unschedule(schedule_selector(SplashScene::increaseLoadingBar));
        SplashScene::goToMainMenuScene();
    }
}

#ifdef DEBUG_SCENE
#include "HeroesConfigScene.h"
#include "BattleScene.h"
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
