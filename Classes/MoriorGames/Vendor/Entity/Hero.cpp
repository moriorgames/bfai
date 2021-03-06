#include "Hero.h"

Hero *Hero::clone()
{
    auto clone = new Hero;
    clone->setId(id);
    clone->setName(name);
    clone->setSlug(slug);
    clone->setUserToken(userToken);
    clone->setDamage(damage);
    clone->setRanged(ranged);
    clone->setHealth(health);
    clone->setMovement(movement);
    clone->setCost(cost);
    clone->setMoveFrames(moveFrames);
    clone->setAttackFrames(attackFrames);
    clone->setSize(size);
    clone->addAgro(agro);
    clone->setEnabled(enabled);
    for (auto skill:skills) {
        clone->addSkill(skill);
    }

    return clone;
}

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

const std::string &Hero::getUserToken() const
{
    return userToken;
}

void Hero::setUserToken(const std::string &userToken)
{
    this->userToken = userToken;
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

int Hero::getCost() const
{
    return cost;
}

void Hero::setCost(int cost)
{
    this->cost = cost;
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

int Hero::getAgro() const
{
    return agro;
}

void Hero::addAgro(int agro)
{
    this->agro += agro;
}

int Hero::getSize() const
{
    return size;
}

void Hero::setSize(int size)
{
    this->size = size;
}

bool Hero::isEnabled() const
{
    return enabled;
}

void Hero::setEnabled(bool enabled)
{
    this->enabled = enabled;
}

bool Hero::isNexus() const
{
    return id == NEXUS_ID;
}

const std::vector<Skill *> &Hero::getSkills() const
{
    return skills;
}

void Hero::addSkill(Skill *skill)
{
    skills.push_back(skill);
}

void Hero::clearSkills()
{
    skills.clear();
}

void Hero::print()
{
    printf("========= Hero: \n"
           " - id %i\n"
           " - name %s\n"
           " - slug %s\n"
           " - userToken %s\n"
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
           userToken.c_str(),
           damage,
           ranged,
           health,
           movement,
           moveFrames,
           attackFrames
    );
}
