#include "BattleView.h"
#include "BattleBackgroundView.h"
#include "../../EventListeners/HeroMoveEventListener.h"
#include "../../Grid/GridSystem.h"
#include "../../Services/StringFileReader.h"
#include "../../Vendor/Factories/BattleFactory.h"
#include "../../Vendor/Parsers/HeroParser.h"
#include "../../Vendor/Repository/HeroRepository.h"
#include "../../Vendor/Services/PathFinder.h"

using MoriorGames::BattleView;
using MoriorGames::PathFinder;

const std::string BattleView::NAME = "battle-node";

BattleView::BattleView(Layer *layer)
    : ViewHelper(layer)
{
    addView();
}

void BattleView::addView()
{
    battleContainer = new BattleContainer;
    new BattleBackgroundView(layer);
    auto gridSystem = new GridSystem(layer);

    auto json = (new StringFileReader)->getStringFromFile("data/battle.json");
    auto battle = (new BattleFactory)->execute(json, heroRepo);

    for (auto battleHero:battle->getHeroes()) {
        battleContainer->addHeroView(new HeroView(layer, gridSystem, battleHero));
    }

    auto pathFinder = new PathFinder(battle->getActiveHero()->getMovement(),
                                     battle->getActiveHero()->getCoordinate(),
                                     gridSystem->getGrid());

    for (auto path:pathFinder->getPathScope()) {
        gridSystem->drawTile(path.coordinate, GridSystem::MOVE_FILL_COLOR);
    }

    new HeroMoveEventListener(layer, gridSystem, battleContainer, battle);
}
