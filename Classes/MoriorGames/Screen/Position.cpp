#include "Position.h"

cocos2d::Point Position::getCenteredPosition()
{
    return cocos2d::Point(centerX(), centerY());
}

cocos2d::Point Position::getBottomCenteredPosition()
{
    return cocos2d::Point(centerX(), bot());
}

cocos2d::Point Position::getTopCenteredPosition()
{
    return cocos2d::Point(centerX(), top());
}

cocos2d::Point Position::getLeftCenteredPosition()
{
    return cocos2d::Point(left(), centerY());
}

cocos2d::Point Position::getRightCenteredPosition()
{
    return cocos2d::Point(right(), centerY());
}

cocos2d::Point Position::getTopLeftPosition()
{
    return cocos2d::Point(left(), top());
}

cocos2d::Point Position::getTopRightPosition()
{
    return cocos2d::Point(right(), top());
}

cocos2d::Point Position::getBotRightPosition()
{
    return cocos2d::Point(right(), bot());
}

cocos2d::Point Position::getBotLeftPosition()
{
    return cocos2d::Point(left(), bot());
}

float Position::centerX()
{
    return visibleSize.width / 2 + origin.x;
}

float Position::centerY()
{
    return visibleSize.height / 2 + origin.y;
}

float Position::top()
{
    return visibleSize.height;
}

float Position::bot()
{
    return 0;
}

float Position::left()
{
    return 0;
}

float Position::right()
{
    return winSize.width;
}
