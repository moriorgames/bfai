#include "Hero.h"

int Hero::getId() const
{
    return id;
}

void Hero::setId(int id)
{
    this->id = id;
}

const std::string &Hero::getName() const
{
    return name;
}

void Hero::setName(const std::string &name)
{
    this->name = name;
}

const std::string &Hero::getSlug() const
{
    return slug;
}

void Hero::setSlug(const std::string &slug)
{
    this->slug = slug;
}

int Hero::getDamage() const
{
    return damage;
}

void Hero::setDamage(int damage)
{
    this->damage = damage;
}

int Hero::getRanged() const
{
    return ranged;
}

void Hero::setRanged(int ranged)
{
    this->ranged = ranged;
}

int Hero::getHealth() const
{
    return health;
}

void Hero::setHealth(int health)
{
    this->health = health;
}

int Hero::getMovement() const
{
    return movement;
}

void Hero::setMovement(int movement)
{
    this->movement = movement;
}

int Hero::getMoveFrames() const
{
    return moveFrames;
}

void Hero::setMoveFrames(int moveFrames)
{
    this->moveFrames = moveFrames;
}

int Hero::getAttackFrames() const
{
    return attackFrames;
}

void Hero::setAttackFrames(int attackFrames)
{
    this->attackFrames = attackFrames;
}

const std::vector<Skill *> &Hero::getSkills() const
{
    return skills;
}

void Hero::addSkill(Skill *skill)
{
    skills.push_back(skill);
}

void Hero::print()
{
    printf("========= Hero: \n"
           " - id %i\n"
           " - name %s\n"
           " - slug %s\n"
           " - damage %i\n"
           " - ranged %i\n"
           " - health %i\n"
           " - movement %i\n"
           " - moveFrames %i\n"
           " - attackFrames %i\n"
           " \n",
           id,
           name.c_str(),
           slug.c_str(),
           damage,
           ranged,
           health,
           movement,
           moveFrames,
           attackFrames
    );
}
