#include "Position.h"

cocos2d::Point Position::getLeftTopPosition()
{
    return cocos2d::Point(left(), top());
}

cocos2d::Point Position::getLeftCenterPosition()
{
    return cocos2d::Point(left(), centerY());
}

cocos2d::Point Position::getLeftBotPosition()
{
    return cocos2d::Point(left(), bot());
}

cocos2d::Point Position::getCenterTopPosition()
{
    return cocos2d::Point(centerX(), top());
}

cocos2d::Point Position::getCenterCenterPosition()
{
    return cocos2d::Point(centerX(), centerY());
}

cocos2d::Point Position::getCenterBotPosition()
{
    return cocos2d::Point(centerX(), bot());
}

cocos2d::Point Position::getRightTopPosition()
{
    return cocos2d::Point(right(), top());
}

cocos2d::Point Position::getRightCenterPosition()
{
    return cocos2d::Point(right(), centerY());
}

cocos2d::Point Position::getRightBotPosition()
{
    return cocos2d::Point(right(), bot());
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
