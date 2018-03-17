#ifndef MORIOR_GAMES_VENDOR_PARSERS_HERO_PARSER_H
#define MORIOR_GAMES_VENDOR_PARSERS_HERO_PARSER_H

#include "JsonParser.h"
#include "../Entity/Hero.h"
#include "../Entity/BattleHero.h"

namespace MoriorGames {

class HeroParser: public JsonParser
{
public:
    const char *ROW = "heroes";
    HeroParser(std::string json);
    std::vector<Hero *> parse();
    std::vector<BattleHero *> parseForBattle();

private:
    void addData(Hero *, const rapidjson::Value &data);
};

}

#endif
