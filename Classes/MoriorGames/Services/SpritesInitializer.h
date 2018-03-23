#ifndef MORIOR_GAMES_SERVICES_ASSET_MANAGER_H
#define MORIOR_GAMES_SERVICES_ASSET_MANAGER_H

#include "cocos2d.h"

namespace MoriorGames {

class SpritesInitializer
{
public:
    SpritesInitializer();

private:
    cocos2d::SpriteFrameCache *cacher;
    std::vector<std::string> sprites{
        "paul", "jaimie", "world"
    };

    void addSprites();
};

}

#endif
