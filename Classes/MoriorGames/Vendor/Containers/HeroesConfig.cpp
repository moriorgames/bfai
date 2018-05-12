#include "HeroesConfig.h"
#include "../Repository/SkillHeroRepository.h"
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
    if (isAbleToAddSkill(skill, heroToAdd)) {
        for (auto hero:heroes) {
            if (heroToAdd->getId() == hero->getId()) {
                heroToAdd->addSkill(skill);
                skill->print();
            }
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
        for (auto skill:hero->getSkills()) {
            auto skillHero = skillHeroRepo->findBySkillAndHero(skill->getId(), hero->getId());
            count += skillHero->getCost();
        }
    }

    return count;
}

bool HeroesConfig::isAbleToAddSkill(Skill *skill, Hero *heroToAdd)
{
    if (!skill->isUpgradable()) {
        return false;
    }

    if (skill->isUnique()) {
        for (auto skillToCheck:heroToAdd->getSkills()) {
            if (skillToCheck->getId() == skill->getId()) {
                return false;
            }
        }
    }

    auto skillHero = skillHeroRepo->findBySkillAndHero(skill->getId(), heroToAdd->getId());
    int totalCost = countBattleHeroesCost() + skillHero->getCost();

    return totalCost <= BATTLE_TOTAL_COST;
}
