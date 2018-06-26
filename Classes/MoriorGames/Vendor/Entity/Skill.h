#ifndef MORIOR_GAMES_VENDOR_ENTITY_SKILL_H
#define MORIOR_GAMES_VENDOR_ENTITY_SKILL_H

#include <string>

class Skill
{
public:
    static short DAMAGE_ID;
    static short NEXT_TURN_ID;
    static short MOVE_ID;
    static short SINGLE_ATTACK_ID;
    static short EXTRA_SHOT_ID;
    static short START_BATTLE_ID;
    static short END_OF_BATTLE_ID;

    static short TYPE_BOOST_HEALTH;
    static short TYPE_BOOST_DAMAGE;
    static short TYPE_BOOST_RANGED;
    static short TYPE_BOOST_MOVE;
    static short TYPE_CONE_AREA_DAMAGE;
    static short TYPE_SPAWN;
    static short TYPE_EXTRA_SHOT;

public:
    int getId() const;
    void setId(int id);
    const std::string &getName() const;
    void setName(const std::string &name);
    const std::string &getSlug() const;
    void setSlug(const std::string &slug);
    short getType() const;
    void setType(short type);
    int getDamage() const;
    void setDamage(int damage);
    int getRanged() const;
    void setRanged(int ranged);
    int getExtra() const;
    void setExtra(int extra);
    bool isUnique() const;
    void setUnique(bool unique);
    bool isUpgradable() const;
    void setUpgradable(bool upgradable);

    void print();

protected:
    int id = 0;
    std::string name = "", slug = "";
    short type = 0;
    int damage = 0, ranged = 0, extra = 0;
    bool unique = true, upgradable = false;
};

#endif
