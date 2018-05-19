#include "AI.h"
#include <cstdlib>

AI::AI(Battle *battle, Grid *grid, BattleEventPublishable *eventPublisher)
    : battle{battle}, grid{grid}, eventPublisher{eventPublisher}
{
    pathFinder = new PathFinder(grid);
}

void AI::process()
{
    if (!battle->isOnline()) {
        auto activeHero = battle->getActiveBattleHero();

        if (activeHero->getSide() == BattleHero::SIDE_VISITOR) {

            auto coordinate = calculateCoordinate(activeHero);
            auto battleAction = new BattleAction;
            battleAction->setBattleHeroId(
                activeHero->getBattleHeroId()
            );
            // @TODO this is causing some troubles we have to solve this in another way
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

    return closestCoordinateForMove(coordinateTarget, pathScope);
}

Coordinate *AI::coordinateForAction(BattleHero *activeHero, std::vector<Path> &pathScope)
{
    auto coordinateTarget = enemyCoordinateTarget(activeHero);
    auto coordinate = closestCoordinateForAction(coordinateTarget, pathScope);

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

Coordinate *AI::closestCoordinateForMove(Coordinate *coordinateTarget, std::vector<Path> &pathScope)
{
    int index = 0;

    // Index / Distance
    auto closest = closestDistance(coordinateTarget, pathScope);

    if (closest.size() >= DEVIATION_MOVEMENT) {
        int subIndex = rand() % DEVIATION_MOVEMENT;
        index = closest.at(subIndex).first;
    } else {
        index = closest.front().first;
    }

    return pathScope[index].coordinate;
}

Coordinate *AI::closestCoordinateForAction(Coordinate *coordinateTarget, std::vector<Path> &pathScope)
{
    auto closest = closestDistance(coordinateTarget, pathScope);
    auto index = closest.front().first;

    return pathScope[index].coordinate;
}

std::vector<std::pair<int, double >> AI::closestDistance(Coordinate *coordinateTarget, std::vector<Path> &pathScope)
{
    // Index / Distance
    std::vector<std::pair<int, double >> closest;
    for (int i = 0; i < pathScope.size(); ++i) {
        auto distance = getDistance(coordinateTarget, pathScope[i].coordinate);
        closest.emplace_back(i, distance);
    }
    std::sort(closest.begin(), closest.end(), [](std::pair<int, double> &left, std::pair<int, double> &right)
    {
        return left.second < right.second;
    });

    return closest;
}

double AI::getDistance(Coordinate *a, Coordinate *b)
{
    return fabs(a->x - b->x) / 2 + fabs(a->y - b->y) / 2;
}

double AI::getDistance(BattleHero *enemy, Coordinate *coordinate)
{
    return getDistance(enemy->getCoordinate(), coordinate) - (enemy->getAgro() / AGRO_FACTOR);
}
