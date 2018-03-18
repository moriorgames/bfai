#include "BattleView.h"
#include "BattleBackgroundView.h"
#include "HeroView.h"
#include "../../Grid/GridSystem.h"
#include "../../Services/StringFileReader.h"
#include "../../Vendor/Parsers/HeroParser.h"
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
    new BattleBackgroundView(layer);
    auto gridSystem = new GridSystem(layer);

    std::string file = "data/heroes.json";
    auto json = (new StringFileReader)->getStringFromFile(file);
    auto parser = new HeroParser(json);

    BattleHero *hero;

    for (auto battleHero:parser->parseForBattle()) {
        if (battleHero->getId() == 1) {
            hero = battleHero;
        }
    }

    hero->setCoordinate(new Coordinate(0, 0));
    new HeroView(layer, gridSystem, hero);

    auto pathFinder = new PathFinder(2, new Coordinate(0, 0), gridSystem->getGrid());

    for (auto path:pathFinder->getPathScope()) {
        gridSystem->drawTile(path.coordinate, GridSystem::MOVE_FILL_COLOR);
    }
}
