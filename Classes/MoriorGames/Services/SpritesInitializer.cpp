#include "SpritesInitializer.h"

using MoriorGames::SpritesInitializer;
USING_NS_CC;

SpritesInitializer::SpritesInitializer()
{
    addSprites();
}

void SpritesInitializer::addSprites()
{
    cacher = SpriteFrameCache::getInstance();
    for (std::string &sprite:sprites) {
        cacher->addSpriteFramesWithFile("sprites/" + sprite + ".plist");
    }
}
