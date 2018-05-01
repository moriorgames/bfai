#ifndef MORIOR_GAMES_SCREEN_POSITION_H
#define MORIOR_GAMES_SCREEN_POSITION_H

#include "ScreenProperties.h"

class Position: public ScreenProperties
{
public:
    cocos2d::Point getLeftTopPosition();
    cocos2d::Point getLeftCenterPosition();
    cocos2d::Point getLeftBotPosition();

    cocos2d::Point getCenterTopPosition();
    cocos2d::Point getCenterCenterPosition();
    cocos2d::Point getCenterBotPosition();

    cocos2d::Point getRightTopPosition();
    cocos2d::Point getRightCenterPosition();
    cocos2d::Point getRightBotPosition();

private:
    float centerX();
    float centerY();
    float top();
    float bot();
    float left();
    float right();
};

#endif
