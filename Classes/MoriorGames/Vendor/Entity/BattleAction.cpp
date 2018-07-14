#include <cocos/deprecated/CCBool.h>
#include "BattleAction.h"

BattleAction::BattleAction(std::string battleToken, std::string userToken, int battleHeroId, int skillId)
    : battleToken{battleToken}, userToken{userToken}, battleHeroId{battleHeroId}, skillId{skillId}
{
}

const std::string &BattleAction::getBattleToken() const
{
    return battleToken;
}

const std::string &BattleAction::getUserToken() const
{
    return userToken;
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

int BattleAction::getExtra() const
{
    return extra;
}

void BattleAction::setExtra(int extra)
{
    BattleAction::extra = extra;
}

void BattleAction::print()
{
    printf("========= BattleAction: \n"
           " - battleToken %s\n"
           " - userToken %s\n"
           " - id %i\n"
           " - battleHeroId %i\n"
           " - skillId %i\n"
           " - x %i / y %i\n"
           " - extra %i\n"
           " \n",
           battleToken.c_str(),
           userToken.c_str(),
           id,
           battleHeroId,
           skillId,
           coordinate->x, coordinate->y,
           extra
    );
}
