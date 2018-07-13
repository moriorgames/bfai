#include "AI.h"
#include "Randomizer.h"

AI::AI(Battle *battle, BattleProcessor *battleProcessor, BattleEventPublishable *eventPublisher)
    : battle{battle}, battleProcessor{battleProcessor}, eventPublisher{eventPublisher}
{
}

void AI::update(BattleAction *)
{
    if (!battle->isOnline()) {
        auto activeHero = battle->getActiveBattleHero();

        if (activeHero->getSide() == BattleHero::SIDE_VISITOR && activeHero->getUserToken() == AI_TOKEN) {

            // Process Genetic Algorithm to choose better next move
            geneticAlgorithm();

//
//            auto action = new BattleAction(
//                battle->getToken(),
//                AI_TOKEN,
//                activeHero->getBattleHeroId(),
//                skillId
//            );
//            action->setCoordinate(coordinate);
//            eventPublisher->publish(action);
        }
    }
}

void AI::geneticAlgorithm()
{
    initialize();

    for (int generation = 0; generation < MAX_GENERATIONS; ++generation) {

        printf("==: Generation %i Population %lu\n", generation, dnas.size());

        calculateFitness();

//        generation = evaluate(generation);

//        environmentExtinction();

//        printBest();

//        newGeneration();
    }

    printf("\nFINISHED\n");
}

void AI::initialize()
{
    dnas.clear();
    for (int i = 0; i < POPULATION; ++i) {
        DNA dna;
        dnas.push_back(dna);
        // Full random
        mutate(dna, 100);
    }
}

void AI::mutate(DNA &dna, int mutationRate)
{
    if (mutationRate >= 100) {
        dna.x1 = Randomizer::randomize(-5, 5);
        dna.y1 = Randomizer::randomize(-5, 5);
        dna.skill1 = Randomizer::randomize(-5, 5);
        dna.x2 = Randomizer::randomize(-5, 5);
        dna.y2 = Randomizer::randomize(-5, 5);
        dna.skill2 = Randomizer::randomize(-5, 5);
    } else {
        if (Randomizer::randomize(0, 100) <= mutationRate) {
            dna.x1 = Randomizer::randomize(-5, 5);
        }
        if (Randomizer::randomize(0, 100) <= mutationRate) {
            dna.y1 = Randomizer::randomize(-5, 5);
        }
        if (Randomizer::randomize(0, 100) <= mutationRate) {
            dna.skill1 = Randomizer::randomize(-5, 5);
        }
        if (Randomizer::randomize(0, 100) <= mutationRate) {
            dna.x2 = Randomizer::randomize(-5, 5);
        }
        if (Randomizer::randomize(0, 100) <= mutationRate) {
            dna.y2 = Randomizer::randomize(-5, 5);
        }
        if (Randomizer::randomize(0, 100) <= mutationRate) {
            dna.skill2 = Randomizer::randomize(-5, 5);
        }
    }
}

void AI::calculateFitness()
{
    auto activeHero = battle->getActiveBattleHero();
    for (DNA dna:dnas) {

        // @todo WIP we have to know how to get the fitness for battle action process for "virtual Action"
        auto battleAction = new BattleAction(battle->getToken(), AI_TOKEN, activeHero->getBattleHeroId(), dna.skill1);
        auto coordinate = new Coordinate(dna.x1, dna.y1);
        battleAction->setCoordinate(coordinate);
        battleAction->setVirtualAction(true);

        battleProcessor->processBattleAction(battleAction);
        double fitness = battleAction->getFitnessMove() * WEIGHT_MOVE +
            battleAction->getFitnessDamage() * WEIGHT_DAMAGE;
        dna.fitness = fitness;

        delete coordinate;
        delete battleAction;
        printDNA(dna);
    }
}

void AI::printDNA(DNA &dna)
{
    printf("========= DNA: x1: %i y1: %i skill1: %i x2: %i y2: %i skill2: %i -- fitness: %f \n",
           dna.x1, dna.y1, dna.skill1, dna.x2, dna.y2, dna.skill2, dna.fitness
    );
}
