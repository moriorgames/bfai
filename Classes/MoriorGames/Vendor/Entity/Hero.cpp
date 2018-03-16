#include "Hero.h"

using MoriorGames::Hero;

const std::string Hero::SIDE_PLAYER = "side-player";

const std::string Hero::SIDE_ENEMY = "side-enemy";

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

const std::string &Hero::getSide() const
{
    return side;
}

void Hero::setSide(const std::string &side)
{
    this->side = side;
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

int Hero::getInjury() const
{
    return injury;
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

void Hero::addInjury()
{
    injury++;
}

void Hero::print()
{

}
