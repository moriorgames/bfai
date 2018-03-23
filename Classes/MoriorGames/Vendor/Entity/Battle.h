#ifndef MORIOR_GAMES_VENDOR_ENTITY_BATTLE_H
#define MORIOR_GAMES_VENDOR_ENTITY_BATTLE_H

#include <vector>
#include "BattleHero.h"

namespace MoriorGames {

class Battle
{
public:
    void addHero(BattleHero *);
    const std::vector<BattleHero *> &getHeroes() const;
    BattleHero *getActiveHero();
    void nextHero();
    void addTurn();
    void print();

private:
    std::vector<BattleHero *> heroes;
    int activeHero = 1;
    int turn = 0;
};

}

#endif
