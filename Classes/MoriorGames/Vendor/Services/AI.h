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

    const int BEST_RANGE = 5;
    const int MIN_RAND_X = -5;
    const int MAX_RAND_X = 5;
    const int MIN_RAND_Y = -4;
    const int MAX_RAND_Y = 4;
    const int POPULATION = 50;
    const int MAX_GENERATIONS = 5;
    const int EXTINCTION = 30;
    const int ENVIRONMENT = 10;
    const int REPRODUCTION = 3;
    const int MUTATION_RATE = 1;

    AI(Battle *, FitnessCalculator *, BattleEventPublishable *);
    void update();

private:
    DNA *best;
    Battle *battle;
    FitnessCalculator *fitnessCalculator;
    BattleEventPublishable *eventPublisher;
    std::vector<DNA *> dnas;
    int initialX = 0;
    int initialY = 0;

    void geneticAlgorithm();
    void initialize();
    void mutate(DNA *dna, int mutationRate);
    void calculateFitness();
    void sortByFitness();
    void environmentExtinction();
    void printBest();
    void newGeneration();
    std::vector<int> matingPoolCreator();
    void createBest();
    void printDNA(DNA *dna);
};

#endif
