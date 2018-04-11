#include "BattleEventOnlinePublisher.h"

void BattleEventOnlinePublisher::publish(BattleAction *battleAction)
{
    auto json = BattleAction2Json::transform(battleAction);

//    socket->send(json);
}

void BattleEventOnlinePublisher::setBattleProcessor(BattleProcessor *battleProcessor)
{
}
