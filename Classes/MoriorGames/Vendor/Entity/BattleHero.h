#ifndef MORIOR_GAMES_VENDOR_ENTITY_BATTLE_HERO_H
#define MORIOR_GAMES_VENDOR_ENTITY_BATTLE_HERO_H

#include <string>
#include "Hero.h"
#include "../ValueObjects/Coordinate.h"

class BattleHero: public Hero
{
public:
    static const std::string SIDE_LOCAL;
    static const std::string SIDE_VISITOR;

    BattleHero();
    int getBattleHeroId() const;
    void setBattleHeroId(int battleHeroId);
    const std::string &getSide() const;
    void setSide(const std::string &side);
    int getCurrentHealth() const;
    void move();
    bool hasMoved();
    void addInjury(int injury);
    bool isDead();
    bool isVisible();
    void setVisible(bool);
    Coordinate *getCoordinate() const;
    void setCoordinate(Coordinate *);

    void startTurn();

    void copy(Hero *);
    void flip(Coordinate *);
    void print();
    bool isActive = false;
    bool flipped = false;
    bool spawned = false;

private:
    int battleHeroId = 0;
    std::string side = SIDE_LOCAL;
    int injury = 0;
    bool moved = false, dead = false, _visible = true;
    Coordinate *coordinate;
};

#endif
