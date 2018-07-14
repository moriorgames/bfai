#ifndef MORIOR_GAMES_VENDOR_SERVICES_FITNESS_CALCULATOR_H
#define MORIOR_GAMES_VENDOR_SERVICES_FITNESS_CALCULATOR_H

#include "PathFinder.h"
#include "BattleActionChecker.h"
#include "../Entity/Battle.h"
#include "../Entity/BattleAction.h"
#include "../Grid/Grid.h"

class FitnessCalculator
{
public:
    explicit FitnessCalculator(Battle *, Grid *);
    double calculate(BattleHero *, BattleAction *);

private:
    const double WEIGHT_MOVE = 1.5;
    const double WEIGHT_DAMAGE = 3.5;

    double fitnessMove = 0;
    double fitnessDamage = 0;

    Battle *battle;
    PathFinder *pathFinder;
    BattleActionChecker *battleActionChecker;
    Grid *grid;

    void singleDamage(BattleHero *, BattleAction *);
    void areaDamage(Skill *, BattleHero *, BattleAction *);
    bool isValidAreaOfEffect(BattleHero *, BattleAction *, Coordinate *);
    void addFitnessDamage(double fitness);
    void addFitnessMove(double fitness);
    double getDistance(Coordinate *, Coordinate *);
    double fitnessWeight();
};

#endif
