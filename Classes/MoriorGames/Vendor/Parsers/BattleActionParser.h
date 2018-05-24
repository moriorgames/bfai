#ifndef MORIOR_GAMES_VENDOR_PARSERS_BATTLE_ACTION_PARSER_H
#define MORIOR_GAMES_VENDOR_PARSERS_BATTLE_ACTION_PARSER_H

#include "JsonParser.h"
#include "../Entity/BattleAction.h"

class BattleActionParser: public JsonParser
{
public:
    const char *ROW = "actions";
    explicit BattleActionParser(std::string json);
    BattleAction *parse();

private:
    BattleAction *createBattleActionFromData(const rapidjson::Value &data);
};

#endif
