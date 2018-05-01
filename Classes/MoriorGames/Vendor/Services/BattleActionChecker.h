#ifndef MORIOR_GAMES_VENDOR_SERVICES_BATTLE_ACTION_CHECKER_H
#define MORIOR_GAMES_VENDOR_SERVICES_BATTLE_ACTION_CHECKER_H

#include "PathFinder.h"
#include "../Factories/PathBuilder.h"
#include "../Entity/BattleAction.h"

class BattleActionChecker
{
public:
    explicit BattleActionChecker(PathFinder *);
    bool check(Skill *, BattleHero *, BattleAction *);

private:
    PathBuilder *pathBuilder;
};

#endif
