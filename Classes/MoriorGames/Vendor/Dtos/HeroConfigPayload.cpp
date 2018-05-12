#include "HeroConfigPayload.h"

const std::string HeroConfigPayload::ADD = "add";

const std::string HeroConfigPayload::REMOVE = "remove";

const std::string HeroConfigPayload::CLEAR = "clear";

const std::string HeroConfigPayload::IMPROVE = "improve";

HeroConfigPayload::HeroConfigPayload(const std::string type, Hero *hero, Skill *skill)
    : type{type}, hero{hero}, skill{skill}
{
}

const std::string &HeroConfigPayload::getType() const
{
    return type;
}

Hero *HeroConfigPayload::getHero() const
{
    return hero;
}

Skill *HeroConfigPayload::getSkill() const
{
    return skill;
}
