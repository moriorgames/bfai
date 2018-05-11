#include "Skill.h"

short Skill::DAMAGE_ID = 1;

short Skill::NEXT_TURN_ID = 2;

short Skill::MOVE_ID = 3;

short Skill::SINGLE_ATTACK_ID = 4;

short Skill::END_OF_BATTLE_ID = 99;

// ---------- TYPES

short Skill::TYPE_BOOST_HEALTH = 1;

short Skill::TYPE_BOOST_DAMAGE = 2;

short Skill::TYPE_BOOST_RANGED = 3;

short Skill::TYPE_BOOST_MOVE = 4;

short Skill::TYPE_CONE_AREA_DAMAGE = 5;

short Skill::TYPE_SPAWN = 6;

int Skill::getId() const
{
    return id;
}

void Skill::setId(int id)
{
    this->id = id;
}

const std::string &Skill::getName() const
{
    return name;
}

void Skill::setName(const std::string &name)
{
    this->name = name;
}

const std::string &Skill::getSlug() const
{
    return slug;
}

void Skill::setSlug(const std::string &slug)
{
    this->slug = slug;
}

short Skill::getType() const
{
    return type;
}

void Skill::setType(short type)
{
    this->type = type;
}

int Skill::getDamage() const
{
    return damage;
}

void Skill::setDamage(int damage)
{
    this->damage = damage;
}

int Skill::getRanged() const
{
    return ranged;
}

void Skill::setRanged(int ranged)
{
    this->ranged = ranged;
}

int Skill::getExtra() const
{
    return extra;
}

void Skill::setExtra(int extra)
{
    this->extra = extra;
}

int Skill::getCost() const
{
    return cost;
}

void Skill::setCost(int cost)
{
    this->cost = cost;
}

bool Skill::isUnique() const
{
    return unique;
}

void Skill::setUnique(bool unique)
{
    this->unique = unique;
}

bool Skill::isUpgradable() const
{
    return upgradable;
}

void Skill::setUpgradable(bool upgradable)
{
    this->upgradable = upgradable;
}

void Skill::print()
{
    printf("========= Skill: \n"
           " - id %i\n"
           " - name %s\n"
           " - slug %s\n"
           " - type %i\n"
           " - damage %i\n"
           " - ranged %i\n"
           " - extra %i\n"
           " - cost %i\n"
           " - unique %i\n"
           " \n",
           id,
           name.c_str(),
           slug.c_str(),
           type,
           damage,
           ranged,
           extra,
           cost,
           unique
    );
}
