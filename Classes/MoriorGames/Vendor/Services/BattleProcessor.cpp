#include "BattleProcessor.h"
#include "../Parsers/BattleActionParser.h"
#include "../Repository/SkillRepository.h"

BattleProcessor::BattleProcessor(Battle *battle, Grid *grid)
    : battle{battle}, grid{grid}
{
    pathFinder = new PathFinder(grid);
}

void BattleProcessor::processBattleAction(BattleAction *battleAction)
{
    for (auto battleHero:battle->getBattleHeroes()) {
        if (isBattleActionAllowed(battleHero, battleAction)) {
            battleActionProcess(battleHero, battleAction);
            break;
        }
    }

    battle->nextHero();
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
    for (auto observer:observers) {
        observer->update(battleAction);
    }
    for (auto extraAction:extraActions) {
        for (auto observer:observers) {
            observer->update(extraAction);
        }
    }
    extraActions.clear();
}

bool BattleProcessor::isBattleActionAllowed(BattleHero *battleHero, BattleAction *battleAction)
{
    return battleHero->getBattleHeroId() == battleAction->getBattleHeroId() &&
        battleHero->getBattleHeroId() == battle->getActiveBattleHero()->getBattleHeroId();
}

void BattleProcessor::battleActionProcess(BattleHero *battleHero, BattleAction *battleAction)
{
    if (battleAction->getSkillId() == Skill::MOVE_ID) {
        movement(battleHero, battleAction);

        return;
    }

    auto skill = skillRepo->findById(battleAction->getSkillId());
    if (skill->getType() == Skill::TYPE_SINGLE_ATTACK) {
        singleDamage(battleHero, battleAction);
    }
}

void BattleProcessor::movement(BattleHero *battleHero, BattleAction *battleAction)
{
    battleHero->setCoordinate(battleAction->getCoordinate());
}

void BattleProcessor::singleDamage(BattleHero *attacker, BattleAction *battleAction)
{
    for (auto defender:battle->getBattleHeroes()) {
        if (defender->getCoordinate()->isEqual(battleAction->getCoordinate())) {
            auto damage = attacker->getDamage();
            defender->addInjury(damage);

            auto damageAction = new BattleAction;
            damageAction->setSkillId(Skill::DAMAGE_ID);
            damageAction->setBattleHeroId(defender->getBattleHeroId());
            damageAction->setExtra(damage);
            damageAction->print();
            extraActions.push_back(damageAction);
            break;
        }
    }
}
