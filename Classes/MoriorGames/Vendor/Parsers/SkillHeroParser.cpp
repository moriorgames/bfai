#include "SkillHeroParser.h"

SkillHeroParser::SkillHeroParser(std::string json)
    : JsonParser(json)
{
}

std::vector<SkillHero *> SkillHeroParser::parse()
{
    std::vector<SkillHero *> items;

    if (document.HasMember(ROW) && document[ROW].IsArray()) {

        const Value &data = document[ROW];
        for (auto itr = data.Begin(); itr != data.End(); ++itr) {
            if ((*itr).IsObject()) {
                auto skill = new SkillHero;
                addData(skill, *itr);
                skill->print();
                items.push_back(skill);
            }
        }
    }

    return items;
}

void SkillHeroParser::addData(SkillHero *item, const rapidjson::Value &data)
{
    item->setSkillId(getInt(data, "skillId"));
    item->setHeroId(getInt(data, "heroId"));
    item->setCost(getInt(data, "cost"));
}
