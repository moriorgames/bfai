#ifndef MORIOR_GAMES_VENDOR_SERVICES_BATTLE_PROCESSOR_H
#define MORIOR_GAMES_VENDOR_SERVICES_BATTLE_PROCESSOR_H

#include "../Entity/Battle.h"

class BattleProcessor
{
public:
    explicit BattleProcessor(Battle *);
    void execute();

private:
    Battle *battle;
};

#endif
