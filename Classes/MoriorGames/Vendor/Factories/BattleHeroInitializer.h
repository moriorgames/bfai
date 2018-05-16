#ifndef MORIOR_GAMES_VENDOR_FACTORIES_BATTLE_HERO_INITIALIZER_H
#define MORIOR_GAMES_VENDOR_FACTORIES_BATTLE_HERO_INITIALIZER_H

#include "../Entity/Battle.h"
#include "../Entity/BattleHero.h"

class BattleHeroInitializer
{
public:
    void init(Battle *, BattleHero *);
    void addSkillToHero(Skill *, Hero *);

private:
    void addBaseSkills(Battle *, BattleHero *);
};

#endif
