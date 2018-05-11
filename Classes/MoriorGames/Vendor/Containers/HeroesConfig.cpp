#include "HeroesConfig.h"
#include "../../Definitions.h"

bool HeroesConfig::hasHero(Hero *currentHero)
{
    for (auto hero:heroes) {
        if (hero->getId() == currentHero->getId()) {
            return true;
        }
    }

    return false;
}

void HeroesConfig::clear()
{
    heroes.clear();
}

void HeroesConfig::addHero(Hero *hero)
{
    int totalCost = countBattleHeroesCost() + hero->getCost();
    if (totalCost <= BATTLE_TOTAL_COST && !hasHero(hero)) {
        heroes.push_back(hero);
    }
}

void HeroesConfig::addSkillToHero(Skill *skill, Hero *heroToAdd)
{
    for (auto hero:heroes) {
        if (heroToAdd->getId() == hero->getId()) {
            heroToAdd->addSkill(skill);
        }
    }
}

void HeroesConfig::removeHero(Hero *hero)
{
    heroes.erase(std::remove(heroes.begin(), heroes.end(), hero), heroes.end());
}

int HeroesConfig::countBattleHeroesCost()
{
    int count = 0;
    for (auto hero:heroes) {
        count += hero->getCost();
    }

    return count;
}
