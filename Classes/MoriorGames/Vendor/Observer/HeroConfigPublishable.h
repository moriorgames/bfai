#ifndef MORIOR_GAMES_VENDOR_OBSERVER_HERO_CONFIG_PUBLISHABLE_H
#define MORIOR_GAMES_VENDOR_OBSERVER_HERO_CONFIG_PUBLISHABLE_H

#include "HeroConfigObservable.h"

class HeroConfigPublishable
{
public:
    virtual void registerObserver(HeroConfigObservable *) = 0;
    virtual void removeObserver(HeroConfigObservable *) = 0;
    virtual void notifyObservers(HeroConfigPayload *) = 0;
};

#endif
