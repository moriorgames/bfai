#ifndef MORIOR_GAMES_VENDOR_ENTITY_SKILL_HERO_H
#define MORIOR_GAMES_VENDOR_ENTITY_SKILL_HERO_H

#include <string>

class SkillHero
{
public:
    int getSkillId() const;
    void setSkillId(int skillId);
    int getBattleHeroId() const;
    void setBattleHeroId(int battleHeroId);

    void print();

private:
    int skillId = 0, battleHeroId = 0;
};

#endif
