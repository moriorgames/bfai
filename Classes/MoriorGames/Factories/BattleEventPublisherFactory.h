#ifndef MORIOR_GAMES_FACTORIES_BATTLE_EVENT_PUBLISHER_FACTORY_H
#define MORIOR_GAMES_FACTORIES_BATTLE_EVENT_PUBLISHER_FACTORY_H

#include "../EventListeners/BattleEventPublishable.h"
#include "../Http/Client.h"

class BattleEventPublisherFactory
{
public:
    static const short ONLINE;
    static const short OFFLINE;

    static BattleEventPublishable *execute(short connectionType, BattleProcessor *, Socket *);
};

#endif
