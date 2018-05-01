#include "BattleProcessor.h"
#include "../Parsers/BattleActionParser.h"
#include "../Repository/SkillRepository.h"
#include "../Repository/HeroRepository.h"

BattleProcessor::BattleProcessor(Battle *battle, Grid *grid)
    : battle{battle}, grid{grid}
{
    pathFinder = new PathFinder(grid);
    battleActionChecker = new BattleActionChecker(pathFinder);
    battleFactory = new BattleFactory;
}

void BattleProcessor::processBattleAction(BattleAction *battleAction)
{
    bool endOfTurn = true;
    for (auto battleHero:battle->getBattleHeroes()) {
        if (isBattleActionAllowed(battleHero, battleAction)) {
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
    if (!battleActionChecker->check(skill, battleHero, battleAction)) {

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
            spawn(skill, battleHero, battleAction);
        }
        if (skill->getType() == Skill::TYPE_AREA_DAMAGE) {
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

void BattleProcessor::spawn(Skill *skill, BattleHero *battleHero, BattleAction *battleAction)
{
    auto spawnHero = new BattleHero;
    spawnHero->setId(skill->getExtra());
    spawnHero->setSide(battleHero->getSide());
    auto coordinate = grid->findByXY(battleAction->getCoordinate()->x, battleAction->getCoordinate()->y);
    coordinate->occupied = true;
    spawnHero->setCoordinate(coordinate);
    battleFactory->initBattleHero(spawnHero);

    battle->addHero(spawnHero);
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
        if (hero->getSide() == BattleHero::SIDE_LOCAL && !hero->isDead()) {
            localDeath = false;
        }
        if (hero->getSide() == BattleHero::SIDE_VISITOR && !hero->isDead()) {
            visitorDeath = false;
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

bool BattleProcessor::isBattleActionAllowed(BattleHero *battleHero, BattleAction *battleAction)
{
    return battleHero->getBattleHeroId() == battleAction->getBattleHeroId() &&
        battleHero->getBattleHeroId() == battle->getActiveBattleHero()->getBattleHeroId();
}

bool BattleProcessor::isValidAreaOfEffect(BattleHero *battleHero, BattleAction *battleAction, Coordinate *coordinate)
{
    auto x = battleHero->getCoordinate()->x;

    return (x > battleAction->getCoordinate()->x && x > coordinate->x) ||
        (x < battleAction->getCoordinate()->x && x < coordinate->x);
}
