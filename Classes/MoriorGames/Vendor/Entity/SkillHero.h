#ifndef MORIOR_GAMES_VENDOR_ENTITY_SKILL_HERO_H
#define MORIOR_GAMES_VENDOR_ENTITY_SKILL_HERO_H

#include <string>

class SkillHero
{
public:
    int getSkillId() const;
    void setSkillId(int skillId);
    int getHeroId() const;
    void setHeroId(int heroId);
    int getBattleHeroId() const;
    void setBattleHeroId(int battleHeroId);
    int getCost() const;
    void setCost(int cost);

    void print();

private:
    int skillId = 0, heroId = 0, battleHeroId = 0, cost = 0;
};

#endif
