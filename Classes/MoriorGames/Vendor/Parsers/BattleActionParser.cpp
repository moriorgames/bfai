#include "BattleActionParser.h"

BattleActionParser::BattleActionParser(std::string json)
    : JsonParser(json)
{
}

BattleAction *BattleActionParser::parse()
{
    auto battleAction = new BattleAction;

    addBattleActionData(battleAction, document);

    return battleAction;
}

void BattleActionParser::addBattleActionData(BattleAction *battleAction, const rapidjson::Value &data)
{
    auto coordinate = new Coordinate(getInt(data, "x"), getInt(data, "y"));

    battleAction->setBattleToken(getString(data, "battleToken"));
    battleAction->setUserToken(getString(data, "userToken"));
    battleAction->setId(getInt(data, "id"));
    battleAction->setBattleHeroId(getInt(data, "battleHeroId"));
    battleAction->setSkillId(getInt(data, "skillId"));
    battleAction->setCoordinate(coordinate);
}

