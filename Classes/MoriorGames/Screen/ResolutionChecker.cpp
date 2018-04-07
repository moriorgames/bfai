#include "ResolutionChecker.h"
#include "Resolution.h"

USING_NS_CC;

bool ResolutionChecker::isHDR()
{
    return Director::getInstance()->getVisibleSize().width >= Resolution::HDR_WIDTH;
}

bool ResolutionChecker::isHD()
{
    return !ResolutionChecker::isHDR() && Director::getInstance()->getVisibleSize().width >= Resolution::HD_WIDTH;
}

bool ResolutionChecker::isSD()
{
    return !ResolutionChecker::isHDR() && !ResolutionChecker::isHD();
}
