#include "CampaignParser.h"

CampaignParser::CampaignParser(std::string json)
    : JsonParser(json)
{
}

void CampaignParser::parse()
{
    addHeroesData(document);
    addSkillsHeroesData(document);
}

const std::vector<int> &CampaignParser::getHeroIds() const
{
    return heroIds;
}

const std::vector<std::pair<short, short>> &CampaignParser::getSkills() const
{
    return skills;
}

void CampaignParser::addHeroesData(const rapidjson::Value &data)
{
    if (document.HasMember(HEROES) && document[HEROES].IsArray()) {
        const Value &data = document[HEROES];
        for (auto itr = data.Begin(); itr != data.End(); ++itr) {
            heroIds.push_back(getInt(*itr, "heroId"));
        }
    }
}

void CampaignParser::addSkillsHeroesData(const rapidjson::Value &data)
{
    if (document.HasMember(SKILLS) && document[SKILLS].IsArray()) {
        const Value &data = document[SKILLS];
        for (auto itr = data.Begin(); itr != data.End(); ++itr) {
            skills.emplace_back(getInt(*itr, "battleHeroId"), getInt(*itr, "skillId"));
        }
    }
}
