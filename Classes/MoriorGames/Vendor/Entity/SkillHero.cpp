#include "SkillHero.h"

int SkillHero::getSkillId() const
{
    return skillId;
}

void SkillHero::setSkillId(int skillId)
{
    this->skillId = skillId;
}

int SkillHero::getBattleHeroId() const
{
    return battleHeroId;
}

void SkillHero::setBattleHeroId(int battleHeroId)
{
    this->battleHeroId = battleHeroId;
}

void SkillHero::print()
{
    printf("========= SkillHero: \n"
           " - skillId %i\n"
           " - battleHeroId %i\n"
           " \n",
           skillId,
           battleHeroId
    );
}
