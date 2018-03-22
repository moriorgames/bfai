#ifndef MORIOR_GAMES_REPOSITORY_HERO_REPOSITORY_H
#define MORIOR_GAMES_REPOSITORY_HERO_REPOSITORY_H

#include <vector>
#include "../Parsers/HeroParser.h"

namespace MoriorGames {

class HeroRepository
{
public:
    void init(const std::string &json);
    Hero *findById(int id);

private:
    std::vector<Hero *> heroes;
};

}

extern MoriorGames::HeroRepository *heroRepo;

#endif
