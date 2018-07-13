#include "MotionEngine.h"
#include "../Config/StaticBushConfig.h"
#include <cmath>

void MotionEngine::movement(BattleHero *battleHero, BattleAction *battleAction)
{
    if (battleAction->isVirtualAction()) {
        auto origin = battleHero->getCoordinate();
        auto destination = battleAction->getCoordinate();
        auto target = new Coordinate(-8, 0);
        double fitness = getDistance(target, origin) - getDistance(target, destination);
        battleAction->addFitnessMove(fitness);
    } else {
        battleHero->move();
        battleHero->flip(battleAction->getCoordinate());
        battleHero->getCoordinate()->occupied = false;
        battleAction->getCoordinate()->occupied = true;
        battleHero->setCoordinate(battleAction->getCoordinate());
        battleHero->setVisible(isVisibleCoordinate(battleHero->getCoordinate()));
    }
}

bool MotionEngine::isVisibleCoordinate(Coordinate *coordinate)
{
    for (auto coord:StaticBushConfig::get()) {
        if (coordinate->x == coord.first && coordinate->y == coord.second) {
            return false;
        }
    }

    return true;
}

double MotionEngine::getDistance(Coordinate *a, Coordinate *b)
{
    return fabs(a->x - b->x) / 2 + fabs(a->y - b->y) / 2;
}
