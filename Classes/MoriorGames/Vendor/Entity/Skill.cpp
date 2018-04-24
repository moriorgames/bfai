#include "Skill.h"

short Skill::TYPE_NEXT_TURN = 1;

short Skill::TYPE_MOVE = 2;

short Skill::TYPE_SHOT = 3;

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

void Skill::print()
{
    printf("========= Skill: \n"
           " - id %i\n"
           " - name %s\n"
           " - slug %s\n"
           " - type %i\n"
           " \n",
           id,
           name.c_str(),
           slug.c_str(),
           type
    );
}
