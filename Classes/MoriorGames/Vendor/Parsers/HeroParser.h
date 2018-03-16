#ifndef MORIOR_GAMES_VENDOR_PARSERS_HERO_PARSER_H
#define MORIOR_GAMES_VENDOR_PARSERS_HERO_PARSER_H

#include "JsonParser.h"
#include "../Entity/Hero.h"

namespace MoriorGames {

class HeroParser: public JsonParser
{
public:
    const char *ROW = "heroes";
    HeroParser(std::string json);
    std::vector<Hero *> parse();

private:
    Hero *create(const rapidjson::Value &data);
};

}

#endif
