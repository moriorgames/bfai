#include "AI.h"
#include <cstdlib>

AI::AI(Battle *battle, BattleProcessor *battleProcessor, BattleEventPublishable *eventPublisher)
    : battle{battle}, battleProcessor{battleProcessor}, eventPublisher{eventPublisher}
{
}

void AI::update(BattleAction *)
{
    if (!battle->isOnline()) {
        auto activeHero = battle->getActiveBattleHero();

        if (activeHero->getSide() == BattleHero::SIDE_VISITOR && activeHero->getUserToken() == AI_TOKEN) {

            // Process Genetic Algorithm to choose better next move
            geneticAlgorithm();

//
//            auto action = new BattleAction(
//                battle->getToken(),
//                AI_TOKEN,
//                activeHero->getBattleHeroId(),
//                skillId
//            );
//            action->setCoordinate(coordinate);
//            eventPublisher->publish(action);
        }
    }
}

void AI::geneticAlgorithm()
{

}
