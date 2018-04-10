#ifndef MORIOR_GAMES_EVENT_LISTENERS_BATTLE_EVENT_PUBLISHABLE_H
#define MORIOR_GAMES_EVENT_LISTENERS_BATTLE_EVENT_PUBLISHABLE_H

#include "../Vendor/Entity/BattleAction.h"
#include "../Transformers/BattleAction2Json.h"

class BattleEventPublishable
{
public:
    virtual void publish(BattleAction *) = 0;
};

#endif
