#ifndef MORIOR_GAMES_SCREEN_SCREEN_PROPERTIES_H
#define MORIOR_GAMES_SCREEN_SCREEN_PROPERTIES_H

#include "cocos2d.h"
#include "Resolution.h"

class ScreenProperties
{
public:
    ScreenProperties();

protected:
    cocos2d::Size visibleSize;
    cocos2d::Vec2 origin;
    cocos2d::Size winSize;
};

#endif
