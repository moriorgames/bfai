#include "SkillRepository.h"

void SkillRepository::init(const std::string &json)
{
    auto parser = new SkillParser(json);
    for (auto item:parser->parse()) {
        items.push_back(item);
    }
}

Skill *SkillRepository::findById(int id)
{
    for (auto item:items) {
        if (item->getId() == id) {
            return item;
        }
    }

    return nullptr;
}

Skill *SkillRepository::findByType(int type)
{
    for (auto item:items) {
        if (item->getType() == type) {
            return item;
        }
    }

    return nullptr;
}
