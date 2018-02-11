#include "AssetManager.h"

using MoriorGames::AssetManager;
USING_NS_CC;

AssetManager::AssetManager()
{
    addAssets();
}

void AssetManager::addAssets()
{
    cacher = SpriteFrameCache::getInstance();
    for (std::string &file:assets) {
        cacher->addSpriteFramesWithFile(file + ".plist");
    }
}
