#ifndef MORIOR_GAMES_VENDOR_CONTAINERS_BATTLE_HEROES_CONFIG_H
#define MORIOR_GAMES_VENDOR_CONTAINERS_BATTLE_HEROES_CONFIG_H

#include <vector>
#include "../Entity/Hero.h"

class BattleHeroesConfig
{
public:
    bool hasHero(Hero *);
    void clear();
    void addHero(Hero *);
    void removeHero(Hero *);
    int countBattleHeroesCost();

protected:
    std::vector<Hero *> heroes;
};

extern BattleHeroesConfig *battleHeroesConfig;

#endif
