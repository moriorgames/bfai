#ifndef MORIOR_GAMES_VENDOR_SERVICES_MOTION_ENGINE_H
#define MORIOR_GAMES_VENDOR_SERVICES_MOTION_ENGINE_H

#include "../Entity/BattleAction.h"
#include "../Entity/BattleHero.h"

class MotionEngine
{
public:
    void movement(BattleHero *, BattleAction *);
};

#endif
