#ifndef MORIOR_GAMES_VENDOR_PARSERS_BATTLE_PARSER_H
#define MORIOR_GAMES_VENDOR_PARSERS_BATTLE_PARSER_H

#include "JsonParser.h"
#include "../Entity/Battle.h"
#include "../Entity/SkillHero.h"

class BattleParser: public JsonParser
{
public:
    const char *HEROES = "heroes";
    const char *SKILLS = "skillsHeroes";
    explicit BattleParser(std::string json);
    Battle *parse();

private:
    void addBattleData(Battle *, const rapidjson::Value &data);
    void addHeroesData(Battle *, const rapidjson::Value &data);
    void addHeroData(Battle *, const rapidjson::Value &data);
    void addSkillsHeroesData(Battle *, const rapidjson::Value &data);
    void addSkillHeroData(Battle *, const rapidjson::Value &data);
};

#endif
