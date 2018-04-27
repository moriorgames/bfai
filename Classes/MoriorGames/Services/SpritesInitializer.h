#ifndef MORIOR_GAMES_SERVICES_ASSET_MANAGER_H
#define MORIOR_GAMES_SERVICES_ASSET_MANAGER_H

#include "cocos2d.h"

class SpritesInitializer
{
public:
    SpritesInitializer();

private:
    cocos2d::SpriteFrameCache *cacher;
    std::vector<std::string> sprites{
        "jaimie", "paul", "fractal", "world"
    };

    void addSprites();
};

#endif
