#ifndef MORIOR_GAMES_VENDOR_CONTAINERS_HEROES_CONFIG_H
#define MORIOR_GAMES_VENDOR_CONTAINERS_HEROES_CONFIG_H

#include <vector>
#include "../Entity/Hero.h"

class HeroesConfig
{
public:
    bool hasHero(Hero *);
    void clear();
    void addHero(Hero *);
    void addSkillToHero(Skill *, Hero *);
    void removeHero(Hero *);
    int countBattleHeroesCost();

protected:
    std::vector<Hero *> heroes;
};

extern HeroesConfig *heroesConfig;

#endif
