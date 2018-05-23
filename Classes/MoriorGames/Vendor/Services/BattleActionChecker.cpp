#include "BattleActionChecker.h"

BattleActionChecker::BattleActionChecker(PathFinder *pathFinder)
{
    pathBuilder = new PathBuilder(pathFinder);
}

bool BattleActionChecker::isBattleActionAllowed(BattleHero *current, BattleHero *active, BattleAction *battleAction)
{
    return current->getBattleHeroId() == active->getBattleHeroId() &&
        current->getBattleHeroId() == battleAction->getBattleHeroId() &&
        current->getUserToken() == battleAction->getUserToken();
}

bool BattleActionChecker::isSkillAllowed(Skill *skill, BattleHero *battleHero, BattleAction *battleAction)
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
