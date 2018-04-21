#ifndef MORIOR_GAMES_REPOSITORY_SKILL_REPOSITORY_H
#define MORIOR_GAMES_REPOSITORY_SKILL_REPOSITORY_H

#include <vector>
#include "../Parsers/SkillParser.h"

class SkillRepository
{
public:
    void init(const std::string &json);
    Skill *findById(int id);
    Skill *findByType(int type);

private:
    std::vector<Skill *> items;
};

extern SkillRepository *skillRepo;

#endif
