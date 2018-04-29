#ifndef MORIOR_GAMES_VENDOR_SERVICES_BATTLE_PROCESSOR_H
#define MORIOR_GAMES_VENDOR_SERVICES_BATTLE_PROCESSOR_H

#include "PathFinder.h"
#include "../Entity/Battle.h"
#include "../Entity/BattleAction.h"
#include "../Factories/BattleFactory.h"
#include "../Observer/BattlePublishable.h"
#include "../Grid/Grid.h"

class BattleProcessor: public BattlePublishable
{
public:
    explicit BattleProcessor(Battle *, Grid *);
    void processBattleAction(BattleAction *);
    void registerObserver(BattleObservable *) override;
    void removeObserver(BattleObservable *) override;

protected:
    void notifyObservers(BattleAction *) override;

private:
    Battle *battle;
    PathFinder *pathFinder;
    BattleFactory *battleFactory;
    Grid *grid;
    std::vector<BattleObservable *> observers;
    std::vector<BattleAction *> extraActions;

    bool battleActionProcess(BattleHero *, BattleAction *);
    void movement(BattleHero *, BattleAction *);
    void singleDamage(BattleHero *, BattleAction *);
    void spawn(Skill *, BattleHero *);
    bool isBattleActionAllowed(BattleHero *, BattleAction *);
};

#endif
