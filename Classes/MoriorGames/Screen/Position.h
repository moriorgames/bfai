#ifndef MORIOR_GAMES_SCREEN_POSITION_H
#define MORIOR_GAMES_SCREEN_POSITION_H

#include "ScreenProperties.h"

class Position: public ScreenProperties
{
public:
    cocos2d::Point getCenteredPosition();
    cocos2d::Point getBottomCenteredPosition();
    cocos2d::Point getTopCenteredPosition();
    cocos2d::Point getLeftCenteredPosition();
    cocos2d::Point getRightCenteredPosition();
    cocos2d::Point getTopLeftPosition();
    cocos2d::Point getTopRightPosition();
    cocos2d::Point getBotRightPosition();
    cocos2d::Point getBotLeftPosition();

private:
    float centerX();
    float centerY();
    float top();
    float bot();
    float left();
    float right();
};

#endif
