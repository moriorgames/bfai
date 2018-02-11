#ifndef MORIOR_GAMES_SERVICES_SPRITE_ANIMATOR_H
#define MORIOR_GAMES_SERVICES_SPRITE_ANIMATOR_H

#include "cocos2d.h"
#include "../Definitions.h"
USING_NS_CC;

namespace MoriorGames {

class SpriteAnimator
{
public:
    cocos2d::Action *generateAction(
        std::string entity,
        float frames,
        std::string action = "default",
        int direction = 0,
        float duration = 0,
        int module = 0
    );

    std::string getFrameName(
        std::string entity, std::string action = "default", int direction = 0, int frame = 10
    );

private:
    std::vector<int> allowedDirections{
        CARTESIAN_EAST,
        CARTESIAN_NORTHEAST,
        CARTESIAN_NORTH,
        CARTESIAN_NORTHWEST,
        CARTESIAN_WEST,
        CARTESIAN_SOUTHWEST,
        CARTESIAN_SOUTH,
        CARTESIAN_SOUTHEAST
    };

    bool isAllowedDirection(int direction);
};

}

#endif
