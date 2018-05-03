#include "BattleEventOfflinePublisher.h"

BattleEventOfflinePublisher::BattleEventOfflinePublisher(BattleProcessor *battleProcessor)
    : battleProcessor{battleProcessor}
{
}

void BattleEventOfflinePublisher::publish(BattleAction *battleAction)
{
    battleProcessor->processBattleAction(battleAction);
}
