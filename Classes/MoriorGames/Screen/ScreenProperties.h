#ifndef MORIOR_GAMES_SCREEN_SCREEN_PROPERTIES_H
#define MORIOR_GAMES_SCREEN_SCREEN_PROPERTIES_H

#include "cocos2d.h"
#include "Resolution.h"

namespace MoriorGames {

class ScreenProperties
{
public:
    ScreenProperties();

    inline bool isHDR()
    {
        return visibleSize.width >= Resolution::HDR_WIDTH;
    };

    inline bool isHD()
    {
        return !isHDR() && visibleSize.width >= Resolution::HD_WIDTH;
    };

    inline bool isSD()
    {
        return !isHDR() && !isHD();
    };

protected:
    cocos2d::Size visibleSize;
    cocos2d::Vec2 origin;
    cocos2d::Size winSize;
};

}

#endif
