#ifndef MORIOR_GAMES_VIEW_VIEW_HELPER_H
#define MORIOR_GAMES_VIEW_VIEW_HELPER_H

#include "cocos2d.h"
USING_NS_CC;

namespace MoriorGames {

class ViewHelper
{
public:
    explicit ViewHelper(Layer *layer);

protected:
    Layer *layer;
    float scale;
};

}

#endif
