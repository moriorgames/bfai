#include "BattleEventOnlinePublisher.h"

void BattleEventOnlinePublisher::publish(BattleAction *battleAction)
{
    BattleAction2Json::transform(battleAction);
}
