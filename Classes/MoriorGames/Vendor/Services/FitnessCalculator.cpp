#include "FitnessCalculator.h"
#include "AI.h"
#include "Randomizer.h"
#include "../Parsers/BattleActionParser.h"
#include "../Repository/SkillRepository.h"
#include "../Repository/HeroRepository.h"
#include <algorithm>
#include <cmath>

FitnessCalculator::FitnessCalculator(Battle *battle, Grid *grid)
    : battle{battle}, grid{grid}
{
    pathFinder = new PathFinder(grid);
}

double FitnessCalculator::calculate(BattleHero *battleHero, BattleAction *battleAction)
{
    fitnessMove = 0;
    fitnessDamage = 0;

    auto coord = grid->findByXY(battleAction->getCoordinate()->x, battleAction->getCoordinate()->y);
    if (coord) {

        battleAction->setCoordinate(coord);

        auto skillId = battleAction->getSkillId();
        auto skill = skillRepo->findById(skillId);
        auto skillType = skill->getType();

        if (!battleHero->hasMoved() && (skillId == Skill::MOVE_ID || skillType == Skill::TYPE_EXTRA_SHOT)) {
            if (skillType == Skill::TYPE_EXTRA_SHOT) {
                singleDamage(battleHero, battleAction->getCoordinate());
            } else {
                moveAssignation(battleHero, battleAction);
            }

            return fitnessWeight();
        }

        bool isSkillType = (skillId == Skill::SINGLE_ATTACK_ID || skillType == Skill::TYPE_EXTRA_SHOT);
        if (isSkillType) {
            singleDamage(battleHero, battleAction->getCoordinate());
        } else {

            if (skillType == Skill::TYPE_SPAWN) {
                // @TODO something
            }
            if (skillType == Skill::TYPE_CONE_AREA_DAMAGE) {
                areaDamage(skill, battleHero, battleAction);
            }
            if (skillType == Skill::TYPE_JUMP) {
                moveAssignation(battleHero, battleAction);
            }
            if (skillType == Skill::TYPE_SHIELD) {
                for (auto hero:battle->getBattleHeroes()) {
                    if (!hero->isDead() && hero->getCoordinate()->isEqual(battleAction->getCoordinate())
                        && hero->getSide() == battleHero->getSide()) {
                        addFitnessDamage(skill->getExtra());
                    }
                }
            }
        }
    }

    return fitnessWeight();
}

void FitnessCalculator::singleDamage(BattleHero *attacker, Coordinate *coordinate)
{
    for (auto defender:battle->getBattleHeroes()) {
        if (!defender->isDead() &&
            defender->getCoordinate()->isEqual(coordinate) &&
            defender->getSide() != attacker->getSide()) {
            addFitnessDamage(attacker->getDamage());
        }
    }
}

void FitnessCalculator::areaDamage(Skill *skill, BattleHero *attacker, BattleAction *battleAction)
{
    auto pathScope = pathFinder->buildPathForArea(attacker->getCoordinate(), skill->getRanged());
    for (auto path:pathScope) {
        if (isValidAreaOfEffect(attacker, battleAction, path.coordinate)) {
            singleDamage(attacker, path.coordinate);
        }
    }
}

// @todo duplicated code on Battle processor
bool FitnessCalculator::isValidAreaOfEffect(BattleHero *battleHero, BattleAction *battleAction, Coordinate *coordinate)
{
    auto x = battleHero->getCoordinate()->x;

    return (x > battleAction->getCoordinate()->x && x > coordinate->x) ||
        (x < battleAction->getCoordinate()->x && x < coordinate->x);
}

void FitnessCalculator::moveAssignation(BattleHero *battleHero, BattleAction *battleAction)
{
    auto origin = battleHero->getCoordinate();
    auto destination = battleAction->getCoordinate();
    auto target = new Coordinate(-8, Randomizer::randomize(-2, 2));
    double fitness = getDistance(target, origin) - getDistance(target, destination);
    addFitnessMove(fitness);
}

void FitnessCalculator::addFitnessDamage(double fitness)
{
    fitnessDamage += fitness;
}

void FitnessCalculator::addFitnessMove(double fitness)
{
    fitnessMove += fitness;
}

double FitnessCalculator::getDistance(Coordinate *a, Coordinate *b)
{
    return fabs(a->x - b->x) / 2 + fabs(a->y - b->y) / 2;
}

double FitnessCalculator::fitnessWeight()
{
    return fitnessMove * WEIGHT_MOVE + fitnessDamage * WEIGHT_DAMAGE;
}
