#ifndef MORIOR_GAMES_VENDOR_SERVICES_BATTLE_HERO_SPAWNER_H
#define MORIOR_GAMES_VENDOR_SERVICES_BATTLE_HERO_SPAWNER_H

#include "../Entity/Battle.h"
#include "../Entity/BattleAction.h"
#include "../Factories/BattleHeroInitializer.h"
#include "../Grid/Grid.h"

class BattleHeroSpawner
{
public:
    explicit BattleHeroSpawner(Battle *, Grid *);
    void spawn(Skill *, BattleHero *, BattleAction *);

private:
    Battle *battle;
    Grid *grid;
    BattleHeroInitializer *battleHeroInitializer;
};

#endif
