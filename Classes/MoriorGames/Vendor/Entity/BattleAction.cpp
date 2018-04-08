#include "BattleAction.h"

int BattleAction::getId() const
{
    return id;
}

void BattleAction::setId(int id)
{
    this->id = id;
}

int BattleAction::getBattleHeroId() const
{
    return battleHeroId;
}

void BattleAction::setBattleHeroId(int battleHeroId)
{
    this->battleHeroId = battleHeroId;
}

int BattleAction::getSkillId() const
{
    return skillId;
}

void BattleAction::setSkillId(int skillId)
{
    this->skillId = skillId;
}

Coordinate *BattleAction::getCoordinate() const
{
    return coordinate;
}

void BattleAction::setCoordinate(Coordinate *coordinate)
{
    this->coordinate = coordinate;
}

void BattleAction::print()
{
}
