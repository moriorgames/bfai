#ifndef MORIOR_GAMES_EVENT_LISTENERS_BATTLE_EVENT_OFFLINE_PUBLISHER_H
#define MORIOR_GAMES_EVENT_LISTENERS_BATTLE_EVENT_OFFLINE_PUBLISHER_H

#include "BattleEventPublishable.h"

class BattleEventOfflinePublisher: public BattleEventPublishable
{
public:
    void publish(BattleAction *) override;
    void setBattleProcessor(BattleProcessor *) override;

private:
    BattleProcessor *battleProcessor;
};

#endif
