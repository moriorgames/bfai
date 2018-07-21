#ifndef MORIOR_GAMES_VENDOR_PARSERS_CAMPAIGN_PARSER_H
#define MORIOR_GAMES_VENDOR_PARSERS_CAMPAIGN_PARSER_H

#include "JsonParser.h"

class CampaignParser: public JsonParser
{
public:
    const char *HEROES = "heroes";
    const char *SKILLS = "skillsHeroes";
    explicit CampaignParser(std::string json);
    void parse();
    const std::vector<int> &getHeroIds() const;
    const std::vector<std::pair<short, short>> &getSkills() const;

private:
    std::vector<int> heroIds;
    std::vector<std::pair<short, short>> skills;

    void addHeroesData(const rapidjson::Value &data);
    void addSkillsHeroesData(const rapidjson::Value &data);
};

#endif
