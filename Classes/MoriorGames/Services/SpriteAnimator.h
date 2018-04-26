#ifndef MORIOR_GAMES_SERVICES_SPRITE_ANIMATOR_H
#define MORIOR_GAMES_SERVICES_SPRITE_ANIMATOR_H

#include "cocos2d.h"
#include "../Definitions.h"
USING_NS_CC;

class SpriteAnimator
{
public:
    Action *generateAction(std::string entity, std::string action, int frames, float duration);
    Action *generateSingleAction(std::string entity, std::string action, int frames, float duration);

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

#endif
