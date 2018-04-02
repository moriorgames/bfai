#ifndef MORIOR_GAMES_VENDOR_PARSERS_BATTLE_PARSER_H
#define MORIOR_GAMES_VENDOR_PARSERS_BATTLE_PARSER_H

#include "JsonParser.h"
#include "../Entity/Battle.h"

class BattleParser: public JsonParser
{
public:
    const char *ROW = "heroes";
    explicit BattleParser(std::string json);
    Battle *parse();

private:
    void addHeroesData(Battle *, const rapidjson::Value &data);
    void addHeroData(Battle *, const rapidjson::Value &data);
};

#endif
