#include "BattleEventOfflinePublisher.h"

void BattleEventOfflinePublisher::publish(BattleAction *battleAction)
{
    battleProcessor->processBattleAction(battleAction);
}

void BattleEventOfflinePublisher::setBattleProcessor(BattleProcessor *battleProcessor)
{
    this->battleProcessor = battleProcessor;
}
