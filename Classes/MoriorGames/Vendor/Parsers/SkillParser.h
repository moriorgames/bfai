#ifndef MORIOR_GAMES_VENDOR_PARSERS_SKILL_PARSER_H
#define MORIOR_GAMES_VENDOR_PARSERS_SKILL_PARSER_H

#include "JsonParser.h"
#include "../Entity/Skill.h"

class SkillParser: public JsonParser
{
public:
    const char *ROW = "skills";
    explicit SkillParser(std::string json);
    std::vector<Skill *> parse();

private:
    void addData(Skill *, const rapidjson::Value &data);
};

#endif
