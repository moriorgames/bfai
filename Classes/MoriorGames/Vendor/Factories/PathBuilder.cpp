#include "PathBuilder.h"

PathBuilder::PathBuilder(PathFinder *pathFinder)
    : pathFinder{pathFinder}
{
}

const std::vector<Path> &PathBuilder::build(Skill *skill, BattleHero *battleHero)
{
    if (skill->getId() == Skill::MOVE_ID) {

        return pathFinder->buildPathScope(battleHero->getCoordinate(), battleHero->getMovement(), true);

    } else if (skill->getId() == Skill::SINGLE_ATTACK_ID) {

        return pathFinder->buildPathScope(battleHero->getCoordinate(), battleHero->getRanged());

    } else if (skill->getType() == Skill::TYPE_AREA_DAMAGE) {

        return pathFinder->buildPathForArea(battleHero->getCoordinate(), skill->getRanged());

    } else {

        return pathFinder->buildPathScope(battleHero->getCoordinate(), skill->getRanged(), true);
    }
}
