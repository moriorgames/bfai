#include "BattleAction.h"

const std::string &BattleAction::getBattleToken() const
{
    return battleToken;
}

void BattleAction::setBattleToken(const std::string &battleToken)
{
    this->battleToken = battleToken;
}

const std::string &BattleAction::getUserToken() const
{
    return userToken;
}

void BattleAction::setUserToken(const std::string &userToken)
{
    this->userToken = userToken;
}

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

int BattleAction::getExtra() const
{
    return extra;
}

void BattleAction::setExtra(int extra)
{
    BattleAction::extra = extra;
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
    printf("========= BattleAction: \n"
           " - id %i\n"
           " - battleHeroId %i\n"
           " - skillId %i\n"
           " - extra %i\n"
           " \n",
           id,
           battleHeroId,
           skillId,
           extra
    );
}
