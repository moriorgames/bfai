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

        if (activeHero->getBattleHeroId() == 4 && !activeHero->hasMoved() &&
            activeHero->getSide() == BattleHero::SIDE_VISITOR && activeHero->getUserToken() == AI_TOKEN) {

            // Process Genetic Algorithm to choose better next move
            auto best = geneticAlgorithm();
            auto action = new BattleAction(
                battle->getToken(),
                AI_TOKEN,
                activeHero->getBattleHeroId(),
                best->skill1
            );
            action->setCoordinate(new Coordinate(best->x1, best->y1));
            action->print();
            eventPublisher->publish(action);
        }
    }
}

DNA *AI::geneticAlgorithm()
{
    initialize();

    for (int generation = 0; generation < MAX_GENERATIONS; ++generation) {

        printf("==: Generation %i Population %lu\n", generation, dnas.size());

        calculateFitness();

//        environmentExtinction();

        printBest();

//        newGeneration();
    }

    calculateFitness();
    auto best = getBest();
    dnas.clear();
    printf("\nFINISHED\n");

    return best;
}

void AI::initialize()
{
    for (int i = 0; i < POPULATION; ++i) {
        auto dna = new DNA;
        dnas.push_back(dna);
        // Full random
        mutate(dna, 100);
    }
}

void AI::mutate(DNA *dna, int mutationRate)
{
    auto coord = battle->getActiveBattleHero()->getCoordinate();
    if (mutationRate >= 100) {
        // @todo WIP duplication of code to assign X
        dna->x1 = coord->x + Randomizer::randomize(MIN_RAND_X, MAX_RAND_X);
        // @todo WIP duplication of code to assign Y
        dna->y1 = coord->y + Randomizer::randomize(MIN_RAND_Y, MAX_RAND_Y);
        dna->x2 = coord->x + Randomizer::randomize(MIN_RAND_X, MAX_RAND_X);
        dna->y2 = coord->y + Randomizer::randomize(MIN_RAND_Y, MAX_RAND_Y);
    } else {
        if (Randomizer::randomize(0, 100) <= mutationRate) {
            dna->x1 = coord->x + Randomizer::randomize(MIN_RAND_X, MAX_RAND_X);
        }
        if (Randomizer::randomize(0, 100) <= mutationRate) {
            dna->y1 = coord->y + Randomizer::randomize(MIN_RAND_Y, MAX_RAND_Y);
        }
        if (Randomizer::randomize(0, 100) <= mutationRate) {
            dna->x2 = coord->x + Randomizer::randomize(MIN_RAND_X, MAX_RAND_X);
        }
        if (Randomizer::randomize(0, 100) <= mutationRate) {
            dna->y2 = coord->y + Randomizer::randomize(MIN_RAND_Y, MAX_RAND_Y);
        }
    }
    dna->skill1 = 3;
    dna->skill2 = 4;
}

void AI::calculateFitness()
{
    auto activeHero = battle->getActiveBattleHero();
    for (auto dna:dnas) {

        auto battleAction = new BattleAction(battle->getToken(), AI_TOKEN, activeHero->getBattleHeroId(), dna->skill1);
        auto coordinate = new Coordinate(dna->x1, dna->y1);
        battleAction->setCoordinate(coordinate);
        battleAction->setVirtualAction(true);

        // @todo WIP Will use this boolean to perform another Battle Action
        auto endOfTurn = battleProcessor->processBattleActionSideEffects(activeHero, battleAction);
        double fitness = battleAction->getFitnessMove() * WEIGHT_MOVE +
            battleAction->getFitnessDamage() * WEIGHT_DAMAGE;
        dna->fitness = fitness;

        delete coordinate;
        delete battleAction;
    }
    sortByFitness();
}

void AI::sortByFitness()
{
    std::sort(dnas.begin(), dnas.end(), [](const DNA *a, const DNA *b) -> bool
    {
        return a->fitness > b->fitness;
    });
}

void AI::environmentExtinction()
{
    int size = dnas.size();
    int extinction = ceil(EXTINCTION * 0.01 * size);
    dnas.resize(size - extinction);
}

void AI::printBest()
{
    for (int i = 0; i < 10; ++i) {
        printDNA(dnas[i]);
    }
}

void AI::newGeneration()
{
    std::vector<int> matingPool = matingPoolCreator();
    std::vector<DNA *> newGeneration;

    for (int i = 0; i < POPULATION; ++i) {
        int father = Randomizer::randomize(0, matingPool.size() - 1);
        int mother = Randomizer::randomize(0, matingPool.size() - 1);

        // Each couple has between N child
        for (int j = 1; j <= Randomizer::randomize(1, REPRODUCTION); ++j) {
            // Pick 2 parents and update a child
            auto child = new DNA;

            if (j % 2 == 0) {
                child->x1 = dnas[matingPool[father]]->x1;
                child->y1 = dnas[matingPool[mother]]->y1;
            } else {
                child->x1 = dnas[matingPool[mother]]->x1;
                child->y1 = dnas[matingPool[father]]->y1;
            }

            mutate(child, MUTATION_RATE);
            newGeneration.push_back(child);
        }
    }

    matingPool.clear();
    dnas.clear();
    dnas = newGeneration;
}

std::vector<int> AI::matingPoolCreator()
{
    std::vector<int> matingPool;

    for (int index = 0; index < dnas.size(); ++index) {
        int matingPoolRatio = ENVIRONMENT * dnas[index]->fitness;
        for (int i = 0; i < matingPoolRatio; ++i) {
            matingPool.push_back(index);
        }
    }

    return matingPool;
}

DNA *AI::getBest()
{
    auto best = new DNA;
    best->x1 = dnas[0]->x1;
    best->y1 = dnas[0]->y1;
    best->skill1 = dnas[0]->skill1;
    best->x2 = dnas[0]->x2;
    best->y2 = dnas[0]->y2;
    best->skill2 = dnas[0]->skill2;

    return best;
}

void AI::printDNA(DNA *dna)
{
    printf("========= DNA: x1: %i y1: %i skill1: %i x2: %i y2: %i skill2: %i -- fitness: %f \n",
           dna->x1, dna->y1, dna->skill1, dna->x2, dna->y2, dna->skill2, dna->fitness
    );
}
