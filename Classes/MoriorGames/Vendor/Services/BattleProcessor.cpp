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

//    auto activeBattleHero = battleContainer->getBattle()->getActiveBattleHero();
//    for (auto heroView:battleContainer->getHeroViews()) {
//        if (heroView->getHero() == activeBattleHero) {
//            auto coordinate = closestCoordinate(screenTouch);
//
//            auto battleAction = new BattleAction;
//            battleAction->setBattleHeroId(activeBattleHero->getBattleHeroId());
//            battleAction->setCoordinate(coordinate);
//            battleContainer->getBattleEventPublisher()->publish(battleAction);
//
//            // @TODO this has to be handled by Battle Processor after receive the Action
//            heroView->moveTo(coordinate);
//            activeBattleHero->setCoordinate(coordinate);
//            battleContainer->getGridSystem()->removeTilesByName(GridSystem::MOVE_NAME);
//        }
//    }
//    // @TODO this has to be handled by Battle Processor after receive the Action
//    battleContainer->getBattle()->nextHero();
//    battleContainer->buildPathScopeView();

    notifyObservers();
}

void BattleProcessor::registerObserver(BattleObservable *)
{

}

void BattleProcessor::removeObserver(BattleObservable *)
{

}
void BattleProcessor::notifyObservers()
{

}
