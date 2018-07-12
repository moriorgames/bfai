#ifndef MORIOR_GAMES_VENDOR_SERVICES_BATTLE_PROCESSOR_H
#define MORIOR_GAMES_VENDOR_SERVICES_BATTLE_PROCESSOR_H

#include "PathFinder.h"
#include "BattleActionChecker.h"
#include "BattleHeroSpawner.h"
#include "MotionEngine.h"
#include "../Dtos/FitnessDTO.h"
#include "../Entity/Battle.h"
#include "../Entity/BattleAction.h"
#include "../Observer/BattlePublishable.h"
#include "../Grid/Grid.h"

class BattleProcessor: public BattlePublishable
{
public:
    explicit BattleProcessor(Battle *, Grid *);
    FitnessDTO *processBattleAction(BattleAction *, bool withFitness = false);
    void registerObserver(BattleObservable *) override;
    void removeObserver(BattleObservable *) override;

protected:
    void notifyObservers(BattleAction *) override;

private:
    Battle *battle;
    PathFinder *pathFinder;
    BattleHeroSpawner *battleHeroSpawner;
    BattleActionChecker *battleActionChecker;
    MotionEngine *motionEngine;
    FitnessDTO *fitnessDTO;
    Grid *grid;
    std::vector<BattleObservable *> observers;
    std::vector<BattleAction *> extraActions;

    bool battleActionProcess(BattleHero *, BattleAction *);
    void singleDamage(BattleHero *, BattleAction *);
    void areaDamage(Skill *, BattleHero *, BattleAction *);
    void performDamage(BattleHero *, BattleHero *, BattleAction *, int damage);
    bool checkEndOfBattle();
    bool isValidAreaOfEffect(BattleHero *, BattleAction *, Coordinate *);
};

#endif
