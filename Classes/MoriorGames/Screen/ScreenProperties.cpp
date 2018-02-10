#include "ScreenProperties.h"

using MoriorGames::ScreenProperties;
USING_NS_CC;

ScreenProperties::ScreenProperties()
{
    auto director = Director::getInstance();
    visibleSize = director->getVisibleSize();
    origin = director->getVisibleOrigin();
    winSize = director->getWinSize();
}
