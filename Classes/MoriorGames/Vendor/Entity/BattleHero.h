#ifndef MORIOR_GAMES_VENDOR_ENTITY_BATTLE_HERO_H
#define MORIOR_GAMES_VENDOR_ENTITY_BATTLE_HERO_H

#include <string>
#include "Hero.h"
#include "../ValueObjects/Coordinate.h"

namespace MoriorGames {

class BattleHero: public Hero
{
public:
    BattleHero();
    static const std::string SIDE_PLAYER;
    static const std::string SIDE_ENEMY;

private:
    std::string side = SIDE_PLAYER;
    int injury = 0;
    bool dead = false;
    Coordinate *coordinate;

public:
    const std::string &getSide() const;
    void setSide(const std::string &side);
    int getCurrentHealth() const;
    void addInjury(int injury);
    bool isDead();
    void setCoordinate(Coordinate *);
    Coordinate *getCoordinate() const;

    void print();
};

}

#endif
