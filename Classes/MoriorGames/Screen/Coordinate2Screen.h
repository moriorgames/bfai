#ifndef MORIOR_GAMES_SCREEN_COORDINATE_2_SCREEN_H
#define MORIOR_GAMES_SCREEN_COORDINATE_2_SCREEN_H

#include "cocos2d.h"
#include "ScreenProperties.h"
#include "../Vendor/ValueObjects/Coordinate.h"
USING_NS_CC;

class Coordinate2Screen: public ScreenProperties
{
public:
    explicit Coordinate2Screen(int gridFactor);
    cocos2d::Vec2 execute(Coordinate *coordinate);
    float axisXToScreen(int x);
    float axisYToScreen(int y);

private:
    int gridFactor;
};

#endif
