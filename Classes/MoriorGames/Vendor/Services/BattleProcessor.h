#ifndef MORIOR_GAMES_VENDOR_SERVICES_BATTLE_PROCESSOR_H
#define MORIOR_GAMES_VENDOR_SERVICES_BATTLE_PROCESSOR_H

#include "../Observer/BattlePublishable.h"
#include "../Entity/Battle.h"
#include "../Entity/BattleAction.h"

class BattleProcessor: public BattlePublishable
{
public:
    explicit BattleProcessor(Battle *);
    void registerObserver(BattleObservable *) override;
    void removeObserver(BattleObservable *) override;
    void notifyObservers() override;
    void execute();

private:
    Battle *battle;
    std::vector<BattleObservable *> observers;
};

#endif
