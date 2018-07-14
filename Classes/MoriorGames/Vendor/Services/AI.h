#ifndef MORIOR_GAMES_VENDOR_SERVICES_AI_H
#define MORIOR_GAMES_VENDOR_SERVICES_AI_H

#include <cmath>
#include <c++/v1/string>
#include "../../EventListeners/BattleEventPublishable.h"
#include "../Entity/Battle.h"
#include "../Entity/BattleAction.h"
#include "../Services/BattleProcessor.h"

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
    const int BEST_RANGE = 10;
    const int MIN_RAND_X = -5;
    const int MAX_RAND_X = 5;
    const int MIN_RAND_Y = -4;
    const int MAX_RAND_Y = 4;
    const int POPULATION = 100;
    const int MAX_GENERATIONS = 1;
    const int EXTINCTION = 30;
    const int ENVIRONMENT = 10;
    const int REPRODUCTION = 3;
    const int MUTATION_RATE = 1;

    const double WEIGHT_MOVE = 1.5;
    const double WEIGHT_DAMAGE = 3.5;

    const std::string AI_TOKEN = "j54tfg4AeMP4O8z9FgtWJEZeFYmmrtS3LpoaKbQ47FB";

    AI(Battle *, BattleProcessor *, BattleEventPublishable *);
    void update();

private:
    Battle *battle;
    BattleProcessor *battleProcessor;
    BattleEventPublishable *eventPublisher;
    std::vector<DNA *> dnas;

    DNA *geneticAlgorithm();
    void initialize();
    void mutate(DNA *dna, int mutationRate);
    void calculateFitness();
    void sortByFitness();
    void environmentExtinction();
    void printBest();
    void newGeneration();
    std::vector<int> matingPoolCreator();
    DNA *getBest();
    void printDNA(DNA *dna);
};

#endif
