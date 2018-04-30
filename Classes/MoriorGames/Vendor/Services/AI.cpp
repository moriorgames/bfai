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

        auto coordinate = calculateCoordinate(activeHero);
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

Coordinate *AI::calculateCoordinate(BattleHero *activeHero)
{
    if (!activeHero->hasMoved()) {
        auto pathScope = pathFinder->buildPathScope(activeHero->getCoordinate(), activeHero->getMovement(), true);

        return coordinateForMove(activeHero, pathScope);
    } else {
        auto pathScope = pathFinder->buildPathScope(activeHero->getCoordinate(), activeHero->getRanged());

        return coordinateForAction(activeHero, pathScope);
    }
}

Coordinate *AI::coordinateForMove(BattleHero *activeHero, std::vector<Path> &pathScope)
{
    auto coordinateTarget = enemyCoordinateTarget(activeHero);

    return closestCoordinate(coordinateTarget, pathScope);
}

Coordinate *AI::coordinateForAction(BattleHero *activeHero, std::vector<Path> &pathScope)
{
    auto coordinateTarget = enemyCoordinateTarget(activeHero);
    auto coordinate = closestCoordinate(coordinateTarget, pathScope);

    // Check selected coordinate does not belong to a hero on the same side as me
    for (auto hero:battle->getBattleHeroes()) {
        if (!hero->isDead() && hero->getSide() == BattleHero::SIDE_LOCAL) {
            if (hero->getCoordinate()->isEqual(coordinate)) {

                return coordinate;
            }
        }
    }

    return new Coordinate(99, 99);
}

Coordinate *AI::enemyCoordinateTarget(BattleHero *current)
{
    auto coordinateTarget = new Coordinate(0, 0);
    double distance = 5000;
    for (auto enemy:battle->getBattleHeroes()) {
        if (!enemy->isDead() && enemy->getSide() == BattleHero::SIDE_LOCAL) {
            auto tmpDistance = getDistance(enemy, current->getCoordinate());
            if (distance > tmpDistance) {
                coordinateTarget = enemy->getCoordinate();
                distance = tmpDistance;
            }
        }
    }

    return coordinateTarget;
}

double AI::getDistance(BattleHero *enemy, Coordinate *coordinate)
{
    return getDistance(enemy->getCoordinate(), coordinate) - (enemy->getAgro() / AGRO_FACTOR);
}

Coordinate *AI::closestCoordinate(Coordinate *coordinateTarget, std::vector<Path> &pathScope)
{
    double distance = 5000;
    int index = 0;
    for (int i = 0; i < pathScope.size(); ++i) {
        auto tmpDistance = getDistance(coordinateTarget, pathScope[i].coordinate);
        if (distance > tmpDistance) {
            distance = tmpDistance;
            index = i;
        }
    }

    return pathScope[index].coordinate;
}

double AI::getDistance(Coordinate *a, Coordinate *b)
{
    return fabs(a->x - b->x) / 2 + fabs(a->y - b->y) / 2;
}
