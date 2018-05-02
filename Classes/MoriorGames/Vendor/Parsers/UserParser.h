#ifndef MORIOR_GAMES_VENDOR_PARSERS_USER_PARSER_H
#define MORIOR_GAMES_VENDOR_PARSERS_USER_PARSER_H

#include "JsonParser.h"
#include "../Entity/User.h"
#include "../Entity/BattleHero.h"

class UserParser: public JsonParser
{
public:
    const char *ROW = "user";
    explicit UserParser(std::string json);
    User *parse();

private:
    void addData(User *, const rapidjson::Value &data);
};

#endif
