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
    auto activeHero = this->activeHero;
    auto it = std::find_if(heroes.begin(), heroes.end(), [activeHero](BattleHero *battleHero)
    { return battleHero->getBattleHeroId() > activeHero; });

    if (it != heroes.end()) {
        this->activeHero = (*it)->getBattleHeroId();
    } else {
        this->activeHero = 0;
        addTurn();
        nextHero();
    }
}

void Battle::addTurn()
{
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
