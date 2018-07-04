#include "HeroesConfig.h"
#include "../Repository/HeroRepository.h"
#include "../Repository/SkillHeroRepository.h"
#include "../../Definitions.h"
#include <algorithm>

const std::vector<Hero *> &HeroesConfig::getHeroes() const
{
    return heroes;
}

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
    for (auto hero:heroes) {
        hero->clearSkills();
    }
    heroes.clear();
}

void HeroesConfig::addHero(Hero *hero)
{
    int totalCost = countBattleHeroesCost() + hero->getCost();
    if (totalCost <= BATTLE_TOTAL_COST && !hasHero(hero)) {
        heroes.push_back(hero->clone());
    }
}

void HeroesConfig::addSkillToHero(Skill *skill, Hero *hero)
{
    if (isAbleToAddSkill(skill, hero)) {
        for (auto heroToAdd:heroes) {
            if (heroToAdd->getId() == hero->getId()) {
                heroToAdd->addSkill(skill);
            }
        }
    }
}

void HeroesConfig::removeHero(Hero *heroToRemove)
{
    for (int i = 0; i < heroes.size(); ++i) {
        if (heroes[i]->getId() == heroToRemove->getId()) {
            heroes.erase(heroes.begin() + i);
        }
    }
}

int HeroesConfig::countBattleHeroesCost()
{
    int count = 0;
    for (auto hero:heroes) {
        count += hero->getCost();
        for (auto skill:hero->getSkills()) {
            auto skillHero = skillHeroRepo->findBySkillAndHero(skill->getId(), hero->getId());
            count += skillHero->getCost();
        }
    }

    return count;
}

bool HeroesConfig::isAbleToAddSkill(Skill *skill, Hero *heroToCheck)
{
    if (!skill->isUpgradable()) {
        return false;
    }

    if (skill->isUnique()) {
        for (auto hero:heroes) {
            if (heroToCheck->getId() == hero->getId()) {
                for (auto skillToCheck:hero->getSkills()) {
                    if (skillToCheck->getId() == skill->getId()) {
                        return false;
                    }
                }
            }
        }
    }

    auto skillHero = skillHeroRepo->findBySkillAndHero(skill->getId(), heroToCheck->getId());
    int totalCost = countBattleHeroesCost() + skillHero->getCost();

    return totalCost <= BATTLE_TOTAL_COST;
}

bool HeroesConfig::isAbleToAddHero()
{
    return MAX_HEROES > heroes.size();
}
