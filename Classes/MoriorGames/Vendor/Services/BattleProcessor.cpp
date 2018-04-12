#include "BattleProcessor.h"
#include "../Parsers/BattleActionParser.h"

BattleProcessor::BattleProcessor(Battle *battle)
    : battle{battle}
{
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

//    // @TODO this has to be handled by Battle Processor after receive the Action
//    battleContainer->getGridSystem()->removeTilesByName(GridSystem::MOVE_NAME);
//    battleContainer->buildPathScopeView();

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
