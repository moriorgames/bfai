#ifndef MORIOR_GAMES_SERVICES_SPRITES_INITIALIZER_H
#define MORIOR_GAMES_SERVICES_SPRITES_INITIALIZER_H

#include "cocos2d.h"

class SpritesInitializer
{
public:
    SpritesInitializer();

private:
    cocos2d::SpriteFrameCache *cacher;
    std::vector<std::string> sprites{
        "jaimie", "paul", "fractal", "bot", "portraits", "battle-effects", "world"
    };

    void addSprites();
};

#endif
