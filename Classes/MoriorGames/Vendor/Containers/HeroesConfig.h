#ifndef MORIOR_GAMES_VENDOR_CONTAINERS_HEROES_CONFIG_H
#define MORIOR_GAMES_VENDOR_CONTAINERS_HEROES_CONFIG_H

#include <vector>
#include "../Entity/Hero.h"

class HeroesConfig
{
public:
    const short MAX_HEROES = 4;

    const std::vector<Hero *> &getHeroes() const;
    bool hasHero(Hero *);
    void clear();
    void addHero(Hero *);
    void addSkillToHero(Skill *, Hero *);
    void removeHero(Hero *);
    int countBattleHeroesCost();
    bool isAbleToAddSkill(Skill *skill, Hero *hero);
    bool isAbleToAddHero();

protected:
    std::vector<Hero *> heroes;
};

extern HeroesConfig *heroesConfig;

#endif
