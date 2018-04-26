#include "BattleProcessor.h"
#include "../Parsers/BattleActionParser.h"

BattleProcessor::BattleProcessor(Battle *battle, Grid *grid)
    : battle{battle}, grid{grid}
{
    pathFinder = new PathFinder(grid);
}

void BattleProcessor::processBattleAction(BattleAction *battleAction)
{
    for (auto battleHero:battle->getBattleHeroes()) {
        if (battleHero->getBattleHeroId() == battleAction->getBattleHeroId()) {
            battleHero->setCoordinate(battleAction->getCoordinate());
            break;
        }
    }

    battle->nextHero();
    pathFinder->buildPathScope(battle->getActiveBattleHero());

    notifyObservers(battleAction);
}

void BattleProcessor::registerObserver(BattleObservable *observer)
{
    observers.push_back(observer);
}

void BattleProcessor::removeObserver(BattleObservable *observer)
{
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void BattleProcessor::notifyObservers(BattleAction *battleAction)
{
    for (auto observer:observers) {
        observer->update(battleAction);
    }
}
