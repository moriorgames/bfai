#include "SkillHeroRepository.h"

void SkillHeroRepository::init(const std::string &json)
{
    auto parser = new SkillHeroParser(json);
    for (auto item:parser->parse()) {
        items.push_back(item);
    }
}

SkillHero *SkillHeroRepository::findBySkillAndHero(int skillId, int heroId)
{
    for (auto item:items) {
        if (item->getSkillId() == skillId && item->getHeroId() == heroId) {
            return item;
        }
    }

    return nullptr;
}
