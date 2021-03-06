#ifndef MORIOR_GAMES_VENDOR_ENTITY_HERO_H
#define MORIOR_GAMES_VENDOR_ENTITY_HERO_H

#include <string>
#include <vector>
#include "Skill.h"

class Hero
{
public:
    const int NEXUS_ID = 1;

    Hero *clone();
    int getId() const;
    void setId(int id);
    const std::string &getName() const;
    void setName(const std::string &name);
    const std::string &getSlug() const;
    const std::string &getUserToken() const;
    void setUserToken(const std::string &userToken);
    void setSlug(const std::string &slug);
    int getDamage() const;
    void setDamage(int damage);
    int getRanged() const;
    void setRanged(int ranged);
    int getHealth() const;
    void setHealth(int health);
    int getMovement() const;
    void setMovement(int movement);
    int getCost() const;
    void setCost(int cost);
    int getMoveFrames() const;
    void setMoveFrames(int moveFrames);
    int getAttackFrames() const;
    void setAttackFrames(int attackFrames);
    int getAgro() const;
    void addAgro(int agro);
    int getSize() const;
    void setSize(int size);
    bool isEnabled() const;
    void setEnabled(bool enabled);
    bool isNexus() const;

    const std::vector<Skill *> &getSkills() const;
    void addSkill(Skill *);
    void clearSkills();

    void print();

protected:
    int id = 0;
    std::string name = "", slug = "", userToken = "";
    int damage = 0, ranged = 0, health = 0, movement = 0, cost = 0, moveFrames = 0, attackFrames = 0, agro = 0,
        size = 0;
    bool enabled = false;

    std::vector<Skill *> skills;
};

#endif
