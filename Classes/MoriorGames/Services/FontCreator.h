#ifndef MORIOR_GAMES_SERVICES_ASSET_MANAGER_H
#define MORIOR_GAMES_SERVICES_ASSET_MANAGER_H

#include "cocos2d.h"
USING_NS_CC;

class FontCreator
{
public:
    Label *buttonLabel(std::string text, std::string font = "fonts/buttons-label.otf", float size = 90);
    Label *damageLabel(std::string text, std::string font = "fonts/buttons-label.otf", float size = 50);
    Label *hitPointsLabel(std::string text, std::string font = "fonts/buttons-label.otf", float size = 24);
};

#endif
