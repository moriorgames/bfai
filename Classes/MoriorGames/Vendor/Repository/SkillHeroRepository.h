#ifndef MORIOR_GAMES_REPOSITORY_SKILL_HERO_REPOSITORY_H
#define MORIOR_GAMES_REPOSITORY_SKILL_HERO_REPOSITORY_H

#include <vector>
#include "../Entity/Hero.h"
#include "../Parsers/SkillHeroParser.h"

class SkillHeroRepository
{
public:
    void init(const std::string &json);
    std::vector<SkillHero *> findSkillsByHero(Hero *);
    SkillHero *findBySkillAndHero(int skillId, int heroId);

private:
    std::vector<SkillHero *> items;
};

extern SkillHeroRepository *skillHeroRepo;

#endif
