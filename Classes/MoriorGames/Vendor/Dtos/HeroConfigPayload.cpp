#include "HeroConfigPayload.h"

const std::string HeroConfigPayload::ADD = "add";

const std::string HeroConfigPayload::REMOVE = "remove";

const std::string HeroConfigPayload::CLEAR = "clear";

HeroConfigPayload::HeroConfigPayload(std::string type, Hero *hero)
    : type{type}, hero{hero}
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
