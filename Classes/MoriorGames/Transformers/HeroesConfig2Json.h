#ifndef MORIOR_GAMES_TRANSFORMERS_HEROES_CONFIG_2_JSON_H
#define MORIOR_GAMES_TRANSFORMERS_HEROES_CONFIG_2_JSON_H

#include <string>
#include "../Vendor/Containers/HeroesConfig.h"

class HeroesConfig2Json
{
public:
    std::string transform(HeroesConfig *);

private:

    std::string heroesRows(HeroesConfig *);
    std::string heroRow(std::string userToken, std::string side, int battleHeroId, int heroId, short x, short y);
};

#endif
