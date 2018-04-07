#ifndef MORIOR_GAMES_SCREEN_RESOLUTION_CHECKER_H
#define MORIOR_GAMES_SCREEN_RESOLUTION_CHECKER_H

#include "cocos2d.h"

class ResolutionChecker
{
public:
    static bool isHDR();
    static bool isHD();
    static bool isSD();
};

#endif
