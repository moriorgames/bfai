#ifndef MORIOR_GAMES_VENDOR_PARSERS_SKILL_HERO_PARSER_H
#define MORIOR_GAMES_VENDOR_PARSERS_SKILL_HERO_PARSER_H

#include "JsonParser.h"
#include "../Entity/SkillHero.h"

class SkillHeroParser: public JsonParser
{
public:
    const char *ROW = "skills";
    explicit SkillHeroParser(std::string json);
    std::vector<SkillHero *> parse();

private:
    void addData(SkillHero *, const rapidjson::Value &data);
};

#endif
