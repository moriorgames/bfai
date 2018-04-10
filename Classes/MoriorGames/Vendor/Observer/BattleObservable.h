#ifndef MORIOR_GAMES_VENDOR_OBSERVER_BATTLE_OBSERVABLE_H
#define MORIOR_GAMES_VENDOR_OBSERVER_BATTLE_OBSERVABLE_H

#include "../Entity/BattleAction.h"

class BattleObservable
{
public:
    virtual void update(BattleAction *) = 0;
};

#endif
