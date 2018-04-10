#ifndef MORIOR_GAMES_FACTORIES_BATTLE_EVENT_PUBLISHER_FACTORY_H
#define MORIOR_GAMES_FACTORIES_BATTLE_EVENT_PUBLISHER_FACTORY_H

#include "../EventListeners/BattleEventPublishable.h"

class BattleEventPublisherFactory
{
public:
    BattleEventPublishable *execute();
};

#endif
