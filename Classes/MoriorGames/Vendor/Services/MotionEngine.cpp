#include "MotionEngine.h"
#include "../Config/StaticBushConfig.h"

void MotionEngine::movement(BattleHero *battleHero, BattleAction *battleAction)
{
    battleHero->move();
    battleHero->flip(battleAction->getCoordinate());
    battleHero->getCoordinate()->occupied = false;
    battleAction->getCoordinate()->occupied = true;
    battleHero->setCoordinate(battleAction->getCoordinate());
    battleHero->setVisible(isVisibleCoordinate(battleHero->getCoordinate()));
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
