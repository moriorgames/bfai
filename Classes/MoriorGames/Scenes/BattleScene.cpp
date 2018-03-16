#include "BattleScene.h"
#include "../Grid/GridSystem.h"
#include "../Vendor/Parsers/HeroParser.h"
#include "../View/BattleBackgroundView.h"
#include "../View/HeroView.h"

using MoriorGames::BattleScene;
using MoriorGames::HeroParser;
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

    std::string fileName = "data/heroes.json";
    auto fileUtils = FileUtils::getInstance();
    auto jsonFile = fileUtils->fullPathForFilename(fileName);
    if (fileUtils->isFileExist(jsonFile)) {
        auto json = fileUtils->getStringFromFile(jsonFile);
        auto parser = new HeroParser(json);
        for (auto hero:parser->parse()) {
            new HeroView(this, hero);
        }
    }

    return true;
}
