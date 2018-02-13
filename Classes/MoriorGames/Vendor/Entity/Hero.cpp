#include "Hero.h"

using MoriorGames::Hero;

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
