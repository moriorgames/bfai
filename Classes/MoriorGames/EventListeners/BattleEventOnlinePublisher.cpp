#include "BattleEventOnlinePublisher.h"

BattleEventOnlinePublisher::BattleEventOnlinePublisher(Socket *socket)
    : socket{socket}
{
}

void BattleEventOnlinePublisher::publish(BattleAction *battleAction)
{
    auto json = BattleAction2Json::transform(battleAction);
    socket->send(json);
}
