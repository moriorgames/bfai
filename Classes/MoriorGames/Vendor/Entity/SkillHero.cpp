#include "SkillHero.h"

int SkillHero::getSkillId() const
{
    return skillId;
}

void SkillHero::setSkillId(int skillId)
{
    this->skillId = skillId;
}

int SkillHero::getHeroId() const
{
    return 0;
}

void SkillHero::setHeroId(int heroId)
{
    this->heroId = heroId;
}

int SkillHero::getBattleHeroId() const
{
    return battleHeroId;
}

void SkillHero::setBattleHeroId(int battleHeroId)
{
    this->battleHeroId = battleHeroId;
}

int SkillHero::getCost() const
{
    return cost;
}

void SkillHero::setCost(int cost)
{
    this->cost = cost;
}

void SkillHero::print()
{
    printf("========= SkillHero: \n"
           " - skillId %i\n"
           " - heroId %i\n"
           " - battleHeroId %i\n"
           " - cost %i\n"
           " \n",
           skillId,
           heroId,
           battleHeroId,
           cost
    );
}
