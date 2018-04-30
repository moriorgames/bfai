#include "AI.h"
#include <cstdlib>

AI::AI(Battle *battle, Grid *grid, BattleEventPublishable *eventPublisher)
    : battle{battle}, grid{grid}, eventPublisher{eventPublisher}
{
    pathFinder = new PathFinder(grid);
}

void AI::process()
{
    auto activeHero = battle->getActiveBattleHero();

    if (activeHero->getSide() == BattleHero::SIDE_VISITOR) {

        auto coordinate = getRandomCoordinate(activeHero);
        auto battleAction = new BattleAction;
        battleAction->setBattleHeroId(
            activeHero->getBattleHeroId()
        );
        battleAction->setSkillId(
            battle->getActiveSkill()
        );
        battleAction->setCoordinate(coordinate);
        eventPublisher->publish(battleAction);
    }
    printf("Rule the world :D \n");
}

Coordinate *AI::getRandomCoordinate(BattleHero *battleHero)
{
    std::vector<Path> pathScope;
    if (!battleHero->hasMoved()) {
        pathScope = pathFinder->buildPathScope(battleHero->getCoordinate(), battleHero->getMovement(), true);
    } else {
        pathScope = pathFinder->buildPathScope(battleHero->getCoordinate(), battleHero->getRanged());
    }

    int index = rand() % pathScope.size();

    return pathScope[index].coordinate;
}
