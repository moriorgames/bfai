#ifndef MORIOR_GAMES_VENDOR_OBSERVER_HERO_CONFIG_OBSERVABLE_H
#define MORIOR_GAMES_VENDOR_OBSERVER_HERO_CONFIG_OBSERVABLE_H

#include "../Dtos/HeroConfigPayload.h"

class HeroConfigObservable
{
public:
    virtual void update(HeroConfigPayload *) = 0;
};

#endif
