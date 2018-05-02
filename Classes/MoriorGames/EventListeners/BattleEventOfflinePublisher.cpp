#include "BattleEventOfflinePublisher.h"

BattleEventOfflinePublisher::BattleEventOfflinePublisher(BattleProcessor *battleProcessor)
    : battleProcessor{battleProcessor}
{
}

void BattleEventOfflinePublisher::publish(BattleAction *battleAction)
{
    BattleAction2Json::transform(battleAction);
    battleProcessor->processBattleAction(battleAction);
}
