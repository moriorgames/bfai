#include "BattleHeroesConfig.h"
#include "../../Definitions.h"

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
    int totalCost = countBattleHeroesCost() + hero->getCost();
    if (totalCost <= BATTLE_TOTAL_COST && !hasHero(hero)) {
        heroes.push_back(hero);
    }
}

void BattleHeroesConfig::addSkillToHero(Skill *skill, Hero *heroToAdd)
{
    for (auto hero:heroes) {
        if (heroToAdd->getId() == hero->getId()) {
            heroToAdd->addSkill(skill);
        }
    }
}

void BattleHeroesConfig::removeHero(Hero *hero)
{
    heroes.erase(std::remove(heroes.begin(), heroes.end(), hero), heroes.end());
}

int BattleHeroesConfig::countBattleHeroesCost()
{
    int count = 0;
    for (auto hero:heroes) {
        count += hero->getCost();
    }

    return count;
}
