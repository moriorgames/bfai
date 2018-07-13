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

bool BattleAction::isVirtualAction() const
{
    return _isVirtualAction;
}

void BattleAction::setVirtualAction(bool _isVirtualAction)
{
    this->_isVirtualAction = _isVirtualAction;
}

double BattleAction::getFitnessMove() const
{
    return fitnessMove;
}

void BattleAction::addFitnessMove(double fitnessMove)
{
    this->fitnessMove += fitnessMove;
}

double BattleAction::getFitnessDamage() const
{
    return fitnessDamage;
}

void BattleAction::addFitnessDamage(double fitnessDamage)
{
    this->fitnessDamage += fitnessDamage;
}

void BattleAction::print()
{
    printf("========= BattleAction: \n"
           " - battleToken %s\n"
           " - userToken %s\n"
           " - id %i\n"
           " - battleHeroId %i\n"
           " - skillId %i\n"
           " - extra %i\n"
           " - _isVirtualAction %i\n"
           " - fitnessMove %f\n"
           " - fitnessDamage %f\n"
           " \n",
           battleToken.c_str(),
           userToken.c_str(),
           id,
           battleHeroId,
           skillId,
           extra,
           _isVirtualAction,
           fitnessMove,
           fitnessDamage
    );
}
