#ifndef MORIOR_GAMES_REPOSITORY_HERO_REPOSITORY_H
#define MORIOR_GAMES_REPOSITORY_HERO_REPOSITORY_H

#include <vector>
#include "../Parsers/HeroParser.h"

class HeroRepository
{
public:
    void init(const std::string &json);
    const std::vector<Hero *> &findAll() const;
    Hero *findById(int id);

private:
    std::vector<Hero *> items;
};

extern HeroRepository *heroRepo;

#endif
