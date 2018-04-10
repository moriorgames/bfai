#include "BattleProcessor.h"

BattleProcessor::BattleProcessor(Battle *battle)
    : battle{battle}
{
}

void BattleProcessor::execute()
{
}

void BattleProcessor::registerObserver(BattleObservable *)
{

}

void BattleProcessor::removeObserver(BattleObservable *)
{

}

void BattleProcessor::notifyObservers()
{

}
