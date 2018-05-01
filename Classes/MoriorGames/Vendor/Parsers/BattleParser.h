#ifndef MORIOR_GAMES_VENDOR_PARSERS_BATTLE_PARSER_H
#define MORIOR_GAMES_VENDOR_PARSERS_BATTLE_PARSER_H

#include "JsonParser.h"
#include "../Entity/Battle.h"

struct SkillHero
{
    int skillId = 0;
    int battleHeroId = 0;
};

class BattleParser: public JsonParser
{
public:
    const char *HEROES = "heroes";
    const char *SKILLS = "skillsHeroes";
    explicit BattleParser(std::string json);
    Battle *parse();
    std::vector<SkillHero> parseSkills();

private:
    void addHeroesData(Battle *, const rapidjson::Value &data);
    void addHeroData(Battle *, const rapidjson::Value &data);
};

#endif
