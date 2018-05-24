#include "BattleProcessor.h"
#include "../Parsers/BattleActionParser.h"
#include "../Repository/SkillRepository.h"
#include "../Repository/HeroRepository.h"
#include <algorithm>

BattleProcessor::BattleProcessor(Battle *battle, Grid *grid)
    : battle{battle}, grid{grid}
{
    pathFinder = new PathFinder(grid);
    battleActionChecker = new BattleActionChecker(pathFinder);
    battleHeroSpawner = new BattleHeroSpawner(battle, grid);
}

void BattleProcessor::processBattleAction(BattleAction *battleAction)
{
    if (battleAction->getSkillId() == Skill::START_BATTLE_ID) {
        battle->nextHero();
        notifyObservers(battleAction);

        return;
    }

    bool endOfTurn = true;
    auto activeHero = battle->getActiveBattleHero();
    if (battleActionChecker->isActiveBattleHeroInTurn(activeHero, battleAction)) {

        for (auto battleHero:battle->getBattleHeroes()) {
            if (battleActionChecker->isBattleActionAllowed(battleHero, activeHero, battleAction)) {
                auto coord = battleAction->getCoordinate();
                battleAction->setCoordinate(grid->findByXY(coord->x, coord->y));
                endOfTurn = battleActionProcess(battleHero, battleAction);
                break;
            }
        }

        if (endOfTurn) {
            battle->nextHero();
        } else {
            battle->setActiveSkill(Skill::SINGLE_ATTACK_ID);
        }

        notifyObservers(battleAction);
    }
}

void BattleProcessor::registerObserver(BattleObservable *observer)
{
    observers.push_back(observer);
}

void BattleProcessor::removeObserver(BattleObservable *observer)
{
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void BattleProcessor::notifyObservers(BattleAction *battleAction)
{
    bool endOfBattle = checkEndOfBattle();
    auto count = observers.size();
    for (int i = 0; i < count; ++i) {
        observers[i]->update(battleAction);
    }
    for (auto extraAction:extraActions) {
        for (int i = 0; i < count; ++i) {
            observers[i]->update(extraAction);
        }
    }
    extraActions.clear();
    if (endOfBattle) {
        observers.clear();
    }
}

bool BattleProcessor::battleActionProcess(BattleHero *battleHero, BattleAction *battleAction)
{
    auto skill = skillRepo->findById(battleAction->getSkillId());
    if (!battleActionChecker->isSkillAllowed(skill, battleHero, battleAction)) {

        return true;
    }

    if (!battleHero->hasMoved() && battleAction->getSkillId() == Skill::MOVE_ID) {
        movement(battleHero, battleAction);

        return false;
    }

    if (battleAction->getSkillId() == Skill::SINGLE_ATTACK_ID) {
        singleDamage(battleHero, battleAction);
    } else {

        if (skill->getType() == Skill::TYPE_SPAWN) {
            battleHeroSpawner->spawn(skill, battleHero, battleAction);
        }
        if (skill->getType() == Skill::TYPE_CONE_AREA_DAMAGE) {
            areaDamage(skill, battleHero, battleAction);
        }
    }

    return true;
}

void BattleProcessor::movement(BattleHero *battleHero, BattleAction *battleAction)
{
    battleHero->move();
    battleHero->flip(battleAction->getCoordinate());
    battleHero->getCoordinate()->occupied = false;
    battleAction->getCoordinate()->occupied = true;
    battleHero->setCoordinate(battleAction->getCoordinate());
}

void BattleProcessor::singleDamage(BattleHero *attacker, BattleAction *battleAction)
{
    attacker->flip(battleAction->getCoordinate());
    for (auto defender:battle->getBattleHeroes()) {
        if (!defender->isDead() && defender->getCoordinate()->isEqual(battleAction->getCoordinate())) {

            auto damage = attacker->getDamage();
            performDamage(defender, attacker, battleAction, damage);

            break;
        }
    }
}

void BattleProcessor::areaDamage(Skill *skill, BattleHero *attacker, BattleAction *battleAction)
{
    auto pathScope = pathFinder->buildPathForArea(attacker->getCoordinate(), skill->getRanged());
    for (auto path:pathScope) {
        if (isValidAreaOfEffect(attacker, battleAction, path.coordinate)) {
            for (auto defender:battle->getBattleHeroes()) {
                if (!defender->isDead() && defender->getCoordinate()->isEqual(path.coordinate)) {
                    performDamage(defender, attacker, battleAction, skill->getDamage());
                }
            }
        }
    }
}

void BattleProcessor::performDamage(BattleHero *defender, BattleHero *attacker, BattleAction *battleAction, int damage)
{
    defender->addInjury(damage);
    if (defender->isDead()) {
        battleAction->getCoordinate()->occupied = false;
    }

    attacker->addAgro(damage);

    auto damageAction = new BattleAction;
    damageAction->setSkillId(Skill::DAMAGE_ID);
    damageAction->setBattleHeroId(defender->getBattleHeroId());
    damageAction->setExtra(damage);
    extraActions.push_back(damageAction);
}

bool BattleProcessor::checkEndOfBattle()
{
    bool localDeath = true, visitorDeath = true;
    for (auto hero:battle->getBattleHeroes()) {
        if (!hero->isNexus()) {
            if (hero->getSide() == BattleHero::SIDE_LOCAL && !hero->isDead()) {
                localDeath = false;
            }
            if (hero->getSide() == BattleHero::SIDE_VISITOR && !hero->isDead()) {
                visitorDeath = false;
            }
        }
    }
    for (auto hero:battle->getBattleHeroes()) {
        if (hero->isNexus() && hero->isDead()) {
            if (hero->getSide() == BattleHero::SIDE_LOCAL) {
                localDeath = true;
            }
            if (hero->getSide() == BattleHero::SIDE_VISITOR) {
                visitorDeath = true;
            }
        }
    }

    if (localDeath) {
        battle->visitorWin();
    }
    if (visitorDeath) {
        battle->localWin();
    }
    if (localDeath || visitorDeath) {
        auto endOfBattleAction = new BattleAction;
        endOfBattleAction->setSkillId(Skill::END_OF_BATTLE_ID);
        extraActions.push_back(endOfBattleAction);
    }

    return localDeath || visitorDeath;
}

bool BattleProcessor::isValidAreaOfEffect(BattleHero *battleHero, BattleAction *battleAction, Coordinate *coordinate)
{
    auto x = battleHero->getCoordinate()->x;

    return (x > battleAction->getCoordinate()->x && x > coordinate->x) ||
        (x < battleAction->getCoordinate()->x && x < coordinate->x);
}
