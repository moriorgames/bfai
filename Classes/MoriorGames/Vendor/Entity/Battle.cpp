#include "Battle.h"

void Battle::addHero(BattleHero *battleHero)
{
    battleHero->setBattleHeroId(heroes.size() + 1);
    heroes.push_back(battleHero);
}

const std::vector<BattleHero *> &Battle::getBattleHeroes() const
{
    return heroes;
}

BattleHero *Battle::getActiveBattleHero()
{
    for (auto hero:heroes) {
        if (hero->getBattleHeroId() == activeHero) {
            return hero;
        }
    }

    return nullptr;
}

int Battle::getActiveSkill() const
{
    return activeSkill;
}

void Battle::setActiveSkill(int activeSkill)
{
    this->activeSkill = activeSkill;
}

void Battle::nextHero()
{
    std::for_each(heroes.begin(), heroes.end(), [&](BattleHero *hero)
    { hero->isActive = false; });

    for (auto hero:heroes) {
        if (hero->getBattleHeroId() > activeHero) {
            activeSkill = Skill::MOVE_ID;
            activeHero = hero->getBattleHeroId();
            hero->isActive = true;

            return;
        }
    }

    activeHero = 0;
    addTurn();
    nextHero();
}

void Battle::addTurn()
{
    std::for_each(heroes.begin(), heroes.end(), [&](BattleHero *hero)
    { hero->startTurn(); });
    turn++;
}

void Battle::print()
{
    printf("========= Battle: \n"
           " - activeHero %i\n"
           " - turn %i\n"
           " \n",
           activeHero,
           turn
    );
    for (auto hero:heroes) {
        hero->print();
    }
}
