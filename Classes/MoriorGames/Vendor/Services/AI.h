#ifndef MORIOR_GAMES_VENDOR_SERVICES_AI_H
#define MORIOR_GAMES_VENDOR_SERVICES_AI_H

#include <cmath>
#include <string>
#include "FitnessCalculator.h"
#include "../../EventListeners/BattleEventPublishable.h"
#include "../Entity/Battle.h"
#include "../Entity/BattleAction.h"

struct DNA
{
    int x1 = 0;
    int y1 = 0;
    int skill1 = 0;
    int x2 = 0;
    int y2 = 0;
    int skill2 = 0;
    double fitness = 0;
};

class AI
{
public:
    static const std::string AI_TOKEN;

    const int BEST_RANGE = 15;
    const int DEVIATION = 2;

    AI(Battle *, Grid *, BattleEventPublishable *);
    void update();

private:
    DNA *best;
    Battle *battle;
    PathFinder *pathFinder;
    FitnessCalculator *fitnessCalculator;
    BattleEventPublishable *eventPublisher;
    std::vector<DNA *> dnas;

    void fitnessAlgorithm();
    void initialize();
    void calculateFitness();
    void sortByFitness();
    void printBest();
    void createBest();
    void printDNA(DNA *dna);
};

#endif
