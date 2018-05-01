#include "BattleActionChecker.h"

BattleActionChecker::BattleActionChecker(PathFinder *pathFinder)
{
    pathBuilder = new PathBuilder(pathFinder);
}

bool BattleActionChecker::check(Skill *skill, BattleHero *battleHero, BattleAction *battleAction)
{
    if (battleAction->getCoordinate() != nullptr) {
        for (auto path:pathBuilder->build(skill, battleHero)) {
            if (battleAction->getCoordinate()->isEqual(path.coordinate)) {
                return true;
            }
        }
    }

    return false;
}
