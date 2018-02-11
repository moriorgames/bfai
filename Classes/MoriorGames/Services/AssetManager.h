#ifndef MORIOR_GAMES_SERVICES_ASSET_MANAGER_H
#define MORIOR_GAMES_SERVICES_ASSET_MANAGER_H

#include "cocos2d.h"

namespace MoriorGames {

class AssetManager
{
public:
    AssetManager();

private:
    cocos2d::SpriteFrameCache *cacher;
    std::vector<std::string> assets{
        "world-sprites"
    };

    void addAssets();
};

}

#endif
