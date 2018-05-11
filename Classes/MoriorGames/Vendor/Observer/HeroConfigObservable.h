#ifndef MORIOR_GAMES_VENDOR_OBSERVER_HERO_CONFIG_OBSERVABLE_H
#define MORIOR_GAMES_VENDOR_OBSERVER_HERO_CONFIG_OBSERVABLE_H

#include "../Dtos/HeroConfigDto.h"

class HeroConfigObservable
{
public:
    virtual void update(HeroConfigDto *) = 0;
};

#endif
