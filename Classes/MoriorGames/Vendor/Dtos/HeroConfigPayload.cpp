#include "HeroConfigPayload.h"

const std::string HeroConfigPayload::ADD = "add";

const std::string HeroConfigPayload::REMOVE = "remove";

const std::string HeroConfigPayload::CLEAR = "clear";

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
