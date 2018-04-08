#include "Action.h"

int Action::getId() const
{
    return id;
}

void Action::setId(int id)
{
    this->id = id;
}

int Action::getBattleHeroId() const
{
    return battleHeroId;
}

void Action::setBattleHeroId(int battleHeroId)
{
    this->battleHeroId = battleHeroId;
}

int Action::getSkillId() const
{
    return skillId;
}

void Action::setSkillId(int skillId)
{
    this->skillId = skillId;
}

Coordinate *Action::getCoordinate() const
{
    return coordinate;
}

void Action::setCoordinate(Coordinate *coordinate)
{
    this->coordinate = coordinate;
}

void Action::print()
{

}
