#include "BattleProcessor.h"
#include "../Parsers/BattleActionParser.h"
#include "../Repository/SkillRepository.h"
#include "../Repository/HeroRepository.h"

BattleProcessor::BattleProcessor(Battle *battle, Grid *grid)
    : battle{battle}, grid{grid}
{
    pathFinder = new PathFinder(grid);
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
}

bool BattleProcessor::battleActionProcess(BattleHero *battleHero, BattleAction *battleAction)
{
    if (!battleHero->hasMoved() && battleAction->getSkillId() == Skill::MOVE_ID) {
        movement(battleHero, battleAction);

        return false;
    }

    if (battleAction->getSkillId() == Skill::SINGLE_ATTACK_ID) {
        singleDamage(battleHero, battleAction);
    } else {

        auto skill = skillRepo->findById(battleAction->getSkillId());
        if (skill->getType() == Skill::TYPE_SPAWN) {
            spawn(skill, battleHero, battleAction);
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
        if (defender->getCoordinate()->isEqual(battleAction->getCoordinate())) {
            auto damage = attacker->getDamage();
            defender->addInjury(damage);
            if (defender->isDead()) {
                battleAction->getCoordinate()->occupied = false;
            }

            auto damageAction = new BattleAction;
            damageAction->setSkillId(Skill::DAMAGE_ID);
            damageAction->setBattleHeroId(defender->getBattleHeroId());
            damageAction->setExtra(damage);
            extraActions.push_back(damageAction);
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

bool BattleProcessor::isBattleActionAllowed(BattleHero *battleHero, BattleAction *battleAction)
{
    return battleHero->getBattleHeroId() == battleAction->getBattleHeroId() &&
        battleHero->getBattleHeroId() == battle->getActiveBattleHero()->getBattleHeroId();
}
