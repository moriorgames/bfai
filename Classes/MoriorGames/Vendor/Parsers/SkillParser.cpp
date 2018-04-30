#include "SkillParser.h"

SkillParser::SkillParser(std::string json)
    : JsonParser(json)
{
}

std::vector<Skill *> SkillParser::parse()
{
    std::vector<Skill *> items;

    if (document.HasMember(ROW) && document[ROW].IsArray()) {

        const Value &data = document[ROW];
        for (auto itr = data.Begin(); itr != data.End(); ++itr) {
            if ((*itr).IsObject()) {
                auto skill = new Skill;
                addData(skill, *itr);
                items.push_back(skill);
            }
        }
    }

    return items;
}

void SkillParser::addData(Skill *item, const rapidjson::Value &data)
{
    item->setId(getInt(data, "id"));
    item->setName(getString(data, "name"));
    item->setSlug(getString(data, "slug"));
    item->setType(getInt(data, "type"));
    item->setDamage(getInt(data, "damage"));
    item->setRanged(getInt(data, "ranged"));
    item->setExtra(getInt(data, "extra"));
}

