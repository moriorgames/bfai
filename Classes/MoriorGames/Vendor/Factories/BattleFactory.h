#ifndef MORIOR_GAMES_VENDOR_FACTORIES_BATTLE_FACTORY_H
#define MORIOR_GAMES_VENDOR_FACTORIES_BATTLE_FACTORY_H

#include <string>
#include "../Entity/Battle.h"
#include "../Parsers/BattleParser.h"

class BattleFactory
{
public:
    Battle *execute(const std::string &json);

private:
    void initNexus();
};

#endif
