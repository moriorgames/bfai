#ifndef MORIOR_GAMES_SERVICES_SPRITE_ANIMATOR_H
#define MORIOR_GAMES_SERVICES_SPRITE_ANIMATOR_H

#include "cocos2d.h"
USING_NS_CC;

namespace MoriorGames {

class SpriteAnimator
{
public:
    std::string getFrameName(
        std::string entity, std::string action = "default", int direction = 0, int frame = 10
    );
};

}

#endif
