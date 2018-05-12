#include "HeroesConfigProcessor.h"

void HeroesConfigProcessor::update(HeroConfigPayload *payload)
{
    if (payload->getType() == HeroConfigPayload::ADD) {
        heroesConfig->addHero(payload->getHero());
    }
    if (payload->getType() == HeroConfigPayload::REMOVE) {
        heroesConfig->removeHero(payload->getHero());
    }
    if (payload->getType() == HeroConfigPayload::CLEAR) {
        heroesConfig->clear();
    }
}
