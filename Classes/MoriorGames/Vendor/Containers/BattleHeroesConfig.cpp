#include "BattleHeroesConfig.h"

bool BattleHeroesConfig::hasHero(Hero *currentHero)
{
    for (auto hero:heroes) {
        if (hero->getId() == currentHero->getId()) {
            return true;
        }
    }

    return false;
}

void BattleHeroesConfig::clear()
{
    heroes.clear();
}

void BattleHeroesConfig::addHero(Hero *hero)
{
    if (!hasHero(hero)) {
        heroes.push_back(hero);
    }
}

void BattleHeroesConfig::removeHero(Hero *hero)
{
    heroes.erase(std::remove(heroes.begin(), heroes.end(), hero), heroes.end());
}
