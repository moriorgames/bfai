#include "AI.h"
#include "Randomizer.h"

const std::string AI::AI_TOKEN = "j54tfg4AeMP4O8z9FgtWJEZeFYmmrtS3LpoaKbQ47FB";

AI::AI(Battle *battle, Grid *grid, BattleEventPublishable *eventPublisher)
    : battle{battle}, eventPublisher{eventPublisher}
{
    pathFinder = new PathFinder(grid);
    pathBuilder = new PathBuilder(pathFinder);
    fitnessCalculator = new FitnessCalculator(battle, grid);
    best = new DNA;
}

void AI::update()
{
    if (!battle->isOnline()) {
        auto activeHero = battle->getActiveBattleHero();
        if (activeHero->getUserToken() == AI_TOKEN) {

            // Process Genetic Algorithm to choose better next move
            if (!activeHero->hasMoved()) {
                fitnessAlgorithm();
            }

            int x = best->x1;
            int y = best->y1;
            int skillId = best->skill1;
            if (activeHero->hasMoved()) {
                x = best->x2;
                y = best->y2;
                skillId = best->skill2;
            }
            auto action = new BattleAction(battle->getToken(), AI_TOKEN, activeHero->getBattleHeroId(), skillId);
            action->setCoordinate(new Coordinate(x, y));
            if (action->getSkillId() == Skill::SINGLE_ATTACK_ID) {
                for (auto enemy:battle->getBattleHeroes()) {
                    if (enemy->getSide() == activeHero->getSide()
                        && enemy->getCoordinate()->isEqual(action->getCoordinate())) {
                        action->setSkillId(Skill::NEXT_TURN_ID);
                    }
                }
            }
            action->print();

            eventPublisher->publish(action);
        }
    }
}

void AI::fitnessAlgorithm()
{
    initialize();

    calculateFitness();

//    printBest();

    createBest();
    dnas.clear();
}

void AI::initialize()
{
    auto activeHero = battle->getActiveBattleHero();
    pathFinder->buildPathScope(activeHero->getCoordinate(), activeHero->getMovement(), true);

    Skill *extraSkill = new Skill;
    extraSkill->setId(0);
    for (auto skill:activeHero->getSkills()) {
        if (skill->isUnique() && skill->getId() >= 9) {
            extraSkill = skill;
            break;
        }
    }

    auto pathScopeMovement = pathFinder->getPathScope();
    auto pathScopeExtra = pathFinder->getPathScope();
    for (auto pathMove:pathScopeMovement) {
        for (auto pathAction:pathFinder->buildPathScope(pathMove.coordinate, activeHero->getRanged())) {
            auto dna = new DNA;
            dna->x1 = pathMove.coordinate->x;
            dna->y1 = pathMove.coordinate->y;
            dna->skill1 = Skill::MOVE_ID;
            dna->x2 = pathAction.coordinate->x;
            dna->y2 = pathAction.coordinate->y;
            dna->skill2 = Skill::SINGLE_ATTACK_ID;
            dnas.push_back(dna);
        }
    }
    if (extraSkill->getId() > 0) {
        int initialX = activeHero->getCoordinate()->x;
        int initialY = activeHero->getCoordinate()->y;
        for (auto pathMove:pathScopeExtra) {
            activeHero->getCoordinate()->x = pathMove.coordinate->x;
            activeHero->getCoordinate()->y = pathMove.coordinate->y;
            for (auto pathAction:pathBuilder->build(extraSkill, activeHero)) {
                auto dna = new DNA;
                dna->x1 = pathMove.coordinate->x;
                dna->y1 = pathMove.coordinate->y;
                dna->skill1 = Skill::MOVE_ID;
                dna->x2 = pathAction.coordinate->x;
                dna->y2 = pathAction.coordinate->y;
                dna->skill2 = extraSkill->getId();
                dnas.push_back(dna);
            }
        }
        activeHero->getCoordinate()->x = initialX;
        activeHero->getCoordinate()->y = initialY;
    }
}

void AI::calculateFitness()
{
    auto activeHero = battle->getActiveBattleHero();
    for (auto dna:dnas) {
        auto battleAction1 = new BattleAction(battle->getToken(), AI_TOKEN, activeHero->getBattleHeroId(), dna->skill1);
        auto coordinate1 = new Coordinate(dna->x1, dna->y1);
        battleAction1->setCoordinate(coordinate1);
        dna->fitness = fitnessCalculator->calculate(activeHero, battleAction1);

        auto battleAction2 = new BattleAction(battle->getToken(), AI_TOKEN, activeHero->getBattleHeroId(), dna->skill2);
        auto coordinate2 = new Coordinate(dna->x2, dna->y2);
        battleAction2->setCoordinate(coordinate2);
        dna->fitness += fitnessCalculator->calculate(activeHero, battleAction2);

        delete coordinate1;
        delete battleAction1;
        delete coordinate2;
        delete battleAction2;
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

void AI::printBest()
{
    for (int i = 0; i < BEST_RANGE; ++i) {
        printDNA(dnas[i]);
    }
}

void AI::createBest()
{
    int i = 0;
    if (dnas.size() >= DEVIATION) {
        i = Randomizer::randomize(0, DEVIATION);
    }
    best->x1 = dnas[i]->x1;
    best->y1 = dnas[i]->y1;
    best->skill1 = dnas[i]->skill1;
    best->x2 = dnas[i]->x2;
    best->y2 = dnas[i]->y2;
    best->skill2 = dnas[i]->skill2;
    best->fitness = dnas[i]->fitness;
    printf("BEST:\n");
    printDNA(best);
}

void AI::printDNA(DNA *dna)
{
    printf("========= DNA: x1: %i y1: %i skill1: %i x2: %i y2: %i skill2: %i -- fitness: %f \n",
           dna->x1, dna->y1, dna->skill1, dna->x2, dna->y2, dna->skill2, dna->fitness
    );
}
