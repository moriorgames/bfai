#ifndef MORIOR_GAMES_VENDOR_OBSERVER_BATTLE_PUBLISHABLE_H
#define MORIOR_GAMES_VENDOR_OBSERVER_BATTLE_PUBLISHABLE_H

#include "BattleObservable.h"

class BattlePublishable
{
public:
    virtual void registerObserver(BattleObservable *) = 0;
    virtual void removeObserver(BattleObservable *) = 0;
    virtual void notifyObservers() = 0;
};

#endif
