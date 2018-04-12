#ifndef MORIOR_GAMES_VENDOR_SERVICES_BATTLE_PROCESSOR_H
#define MORIOR_GAMES_VENDOR_SERVICES_BATTLE_PROCESSOR_H

#include "../Observer/BattlePublishable.h"
#include "../Entity/Battle.h"
#include "../Entity/BattleAction.h"

class BattleProcessor: public BattlePublishable
{
public:
    explicit BattleProcessor(Battle *);
    void processBattleAction(BattleAction *);
    void registerObserver(BattleObservable *) override;
    void removeObserver(BattleObservable *) override;

protected:
    void notifyObservers(BattleAction *) override;

private:
    Battle *battle;
    std::vector<BattleObservable *> observers;
};

#endif
