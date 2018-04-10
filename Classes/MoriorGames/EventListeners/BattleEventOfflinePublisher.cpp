#include "BattleEventOfflinePublisher.h"

void BattleEventOfflinePublisher::publish(BattleAction *battleAction)
{
    BattleAction2Json::transform(battleAction);
}
