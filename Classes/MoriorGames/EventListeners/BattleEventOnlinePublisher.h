#ifndef MORIOR_GAMES_EVENT_LISTENERS_BATTLE_EVENT_ONLINE_PUBLISHER_H
#define MORIOR_GAMES_EVENT_LISTENERS_BATTLE_EVENT_ONLINE_PUBLISHER_H

#include "BattleEventPublishable.h"

class BattleEventOnlinePublisher: public BattleEventPublishable
{
public:
    void publish(BattleAction *) override;
    void setBattleProcessor(BattleProcessor *) override;
};

#endif
