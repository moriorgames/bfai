#include "BattleActionChecker.h"

BattleActionChecker::BattleActionChecker(PathFinder *pathFinder)
{
    pathBuilder = new PathBuilder(pathFinder);
}

bool BattleActionChecker::isActiveBattleHeroInTurn(BattleHero *active, BattleAction *action)
{
    return active->getUserToken() == action->getUserToken() && active->getBattleHeroId() == action->getBattleHeroId();
}

bool BattleActionChecker::isBattleActionAllowed(BattleHero *current, BattleHero *active, BattleAction *battleAction)
{
    return current->getBattleHeroId() == active->getBattleHeroId() &&
        current->getBattleHeroId() == battleAction->getBattleHeroId() &&
        isActiveBattleHeroInTurn(active, battleAction);
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
