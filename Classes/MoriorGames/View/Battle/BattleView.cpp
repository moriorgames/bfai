#include "BattleView.h"
#include "BattleBackgroundView.h"
#include "../../EventListeners/HeroMoveEventListener.h"
#include "../../Grid/GridSystem.h"
#include "../../Services/StringFileReader.h"
#include "../../Vendor/Factories/BattleFactory.h"
#include "../../Vendor/Parsers/HeroParser.h"
#include "../../Vendor/Repository/HeroRepository.h"
#include "../../Vendor/Services/PathFinder.h"

const std::string BattleView::NAME = "battle-node";

BattleView::BattleView(Layer *layer)
    : ViewHelper(layer)
{
    addView();
}

void BattleView::addView()
{
    battleContainer = new BattleContainer(layer);
    new BattleBackgroundView(layer);

    auto json = (new StringFileReader)->getStringFromFile("data/battle.json");
    auto battle = (new BattleFactory)->execute(json, heroRepo);

    for (auto battleHero:battle->getHeroes()) {
        battleContainer->addHeroView(new HeroView(layer, battleContainer->getGridSystem(), battleHero));
    }

    for (auto path:battleContainer->getPathFinder()->buildPathScope(battle->getActiveHero())) {
        battleContainer->getGridSystem()->drawTile(path.coordinate, GridSystem::MOVE_FILL_COLOR, GridSystem::MOVE_NAME);
    }

    new HeroMoveEventListener(layer, battleContainer->getGridSystem(), battleContainer, battle);
}
