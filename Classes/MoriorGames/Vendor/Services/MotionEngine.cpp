#include "MotionEngine.h"

void MotionEngine::movement(BattleHero *battleHero, BattleAction *battleAction)
{
    battleHero->move();
    battleHero->flip(battleAction->getCoordinate());
    battleHero->getCoordinate()->occupied = false;
    battleAction->getCoordinate()->occupied = true;
    battleHero->setCoordinate(battleAction->getCoordinate());
}
