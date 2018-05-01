#include "Battle.h"

void Battle::addHero(BattleHero *battleHero)
{
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
        if (!hero->isDead() && hero->getBattleHeroId() > activeHero) {
            activeHero = hero->getBattleHeroId();
            activeSkill = Skill::MOVE_ID;
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

void Battle::localWin()
{
    localWins = true;
}

void Battle::visitorWin()
{
    visitorWins = true;
}

bool Battle::isLocalWinner()
{
    return localWins;
}

bool Battle::isVisitorWinner()
{
    return visitorWins;
}

bool Battle::isOnline()
{
    return _isOnline;
}

void Battle::setOnline(bool online)
{
    this->_isOnline = online;
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
