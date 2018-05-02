#include "User.h"

int User::getId() const
{
    return id;
}

void User::setId(int id)
{
    this->id = id;
}

const std::string &User::getName() const
{
    return name;
}
void User::setName(const std::string &name)
{
    this->name = name;
}

const std::string &User::getSlug() const
{
    return slug;

}

void User::setSlug(const std::string &slug)
{
    this->slug = slug;
}

const std::string &User::getToken() const
{
    return token;
}

void User::setToken(const std::string &token)
{
    this->token = token;
}

int User::getExperience() const
{
    return experience;
}

void User::setExperience(int experience)
{
    this->experience = experience;
    this->level = 1;
}

void User::print()
{
    printf("========= User: \n"
           " - id %i\n"
           " - name %s\n"
           " - slug %s\n"
           " - token %s\n"
           " - level %i\n"
           " - experience %i\n"
           " \n",
           id,
           name.c_str(),
           slug.c_str(),
           token.c_str(),
           level,
           experience
    );
}
