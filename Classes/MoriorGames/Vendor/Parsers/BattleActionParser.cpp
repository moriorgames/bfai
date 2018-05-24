#include "BattleActionParser.h"

BattleActionParser::BattleActionParser(std::string json)
    : JsonParser(json)
{
}

BattleAction *BattleActionParser::parse()
{
    return createBattleActionFromData(document);
}

BattleAction *BattleActionParser::createBattleActionFromData(const rapidjson::Value &data)
{
    auto action = new BattleAction(
        getString(data, "battleToken"),
        getString(data, "userToken"),
        getInt(data, "battleHeroId"),
        getInt(data, "skillId")
    );
    action->setId(getInt(data, "id"));
    action->setCoordinate(new Coordinate(getInt(data, "x"), getInt(data, "y")));

    return action;
}
