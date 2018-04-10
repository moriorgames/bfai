#ifndef MORIOR_GAMES_TRANSFORMERS_BATTLE_ACTION_2_JSON_H
#define MORIOR_GAMES_TRANSFORMERS_BATTLE_ACTION_2_JSON_H

#include <string>
#include "../Vendor/Entity/BattleAction.h"

class BattleAction2Json
{
public:
    static std::string transform(BattleAction *);
};

#endif
