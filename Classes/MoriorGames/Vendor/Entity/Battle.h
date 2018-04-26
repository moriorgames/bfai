#ifndef MORIOR_GAMES_VENDOR_ENTITY_BATTLE_H
#define MORIOR_GAMES_VENDOR_ENTITY_BATTLE_H

#include <vector>
#include <algorithm>
#include "BattleHero.h"

class Battle
{
public:
    const int DEFAULT_SKILL_MOVE = 2;

    void addHero(BattleHero *);
    const std::vector<BattleHero *> &getBattleHeroes() const;
    BattleHero *getActiveBattleHero();
    int getActiveSkill() const;
    void setActiveSkill(int activeSkill);
    void nextHero();
    void addTurn();
    void print();

private:
    std::vector<BattleHero *> heroes;
    int activeHero = 0;
    int activeSkill = DEFAULT_SKILL_MOVE;
    int turn = 0;
};

#endif
