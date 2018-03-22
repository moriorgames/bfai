#ifndef MORIOR_GAMES_FACTORIES_BATTLE_FACTORY_H
#define MORIOR_GAMES_FACTORIES_BATTLE_FACTORY_H

#include <string>
#include "../Entity/Battle.h"
#include "../Repository/HeroRepository.h"

namespace MoriorGames {

class BattleFactory
{
public:
    Battle *execute(const std::string &json, HeroRepository *);
};

}

#endif
