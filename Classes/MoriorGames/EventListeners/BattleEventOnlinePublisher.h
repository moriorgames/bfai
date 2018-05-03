#ifndef MORIOR_GAMES_EVENT_LISTENERS_BATTLE_EVENT_ONLINE_PUBLISHER_H
#define MORIOR_GAMES_EVENT_LISTENERS_BATTLE_EVENT_ONLINE_PUBLISHER_H

#include "BattleEventPublishable.h"
#include "../Http/Client.h"

class BattleEventOnlinePublisher: public BattleEventPublishable
{
public:
    explicit BattleEventOnlinePublisher(Socket *);
    void publish(BattleAction *) override;

private:
    Socket *socket;
};

#endif
