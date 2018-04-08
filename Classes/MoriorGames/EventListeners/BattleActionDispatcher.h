#ifndef MORIOR_GAMES_EVENT_LISTENERS_BATTLE_ACTION_DISPATCHER_H
#define MORIOR_GAMES_EVENT_LISTENERS_BATTLE_ACTION_DISPATCHER_H

#include <string>
#include "../Vendor/Entity/BattleAction.h"

class BattleActionDispatcher
{
public:
    void sendAction(BattleAction *);
};

#endif
