#ifndef MORIOR_GAMES_VENDOR_OBSERVER_HERO_CONFIG_PUBLISHABLE_H
#define MORIOR_GAMES_VENDOR_OBSERVER_HERO_CONFIG_PUBLISHABLE_H

#include "HeroConfigObservable.h"

class HeroConfigPublishable
{
public:
    virtual void registerObserver(BattleHeroConfigObservable *) = 0;
    virtual void removeObserver(BattleHeroConfigObservable *) = 0;

protected:
    virtual void notifyObservers(BattleHeroConfigDto *) = 0;
};

#endif
