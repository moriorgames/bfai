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

        auto coordinate = getCoordinateAction(activeHero);
        auto battleAction = new BattleAction;
        battleAction->setBattleHeroId(
            activeHero->getBattleHeroId()
        );
        if (coordinate->x == 99) {
            battleAction->setSkillId(Skill::NEXT_TURN_ID);
        } else {
            battleAction->setSkillId(
                battle->getActiveSkill()
            );
        }
        battleAction->setCoordinate(coordinate);
        eventPublisher->publish(battleAction);
    }
}

Coordinate *AI::getCoordinateAction(BattleHero *battleHero)
{
    std::vector<Path> pathScope;
    if (!battleHero->hasMoved()) {
        pathScope = pathFinder->buildPathScope(battleHero->getCoordinate(), battleHero->getMovement(), true);
    } else {
        pathScope = pathFinder->buildPathScope(battleHero->getCoordinate(), battleHero->getRanged());
    }

    return closestCoordinateWithEnemy(battleHero, pathScope);
}

Coordinate *AI::closestCoordinateWithEnemy(BattleHero *battleHero, std::vector<Path> &pathScope)
{
    auto closestCoordinate = new Coordinate(0, 0);
    double distance = 5000;
    for (auto enemy:battle->getBattleHeroes()) {
        if (!enemy->isDead() && enemy->getSide() == BattleHero::SIDE_LOCAL) {
            auto tmpDistance = getDistance(battleHero->getCoordinate(), enemy->getCoordinate());
            if (distance > tmpDistance) {
                closestCoordinate = enemy->getCoordinate();
                distance = tmpDistance;
            }
        }
    }

    distance = 5000;
    int index = 0;
    for (int i = 0; i < pathScope.size(); ++i) {
        auto tmpDistance = getDistance(closestCoordinate, pathScope[i].coordinate);
        if (distance > tmpDistance) {
            distance = tmpDistance;
            index = i;
        }
    }

    // Check selected coordinate does not belong to a hero on the same side as me
    auto coordinate = pathScope[index].coordinate;
    for (auto hero:battle->getBattleHeroes()) {
        if (!hero->isDead() && hero->getSide() == BattleHero::SIDE_VISITOR) {
            if (hero->getCoordinate()->isEqual(coordinate)) {
                return new Coordinate(99, 99);
            }
        }
    }

    return coordinate;
}

double AI::getDistance(Coordinate *a, Coordinate *b)
{
    return fabs(a->x - b->x) / 2 + fabs(a->y - b->y) / 2;
}
