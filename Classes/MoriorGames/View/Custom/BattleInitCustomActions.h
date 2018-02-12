#ifndef MORIOR_GAMES_VIEW_BACKGROUND_VIEW_H
#define MORIOR_GAMES_VIEW_BACKGROUND_VIEW_H

#include "cocos2d.h"
USING_NS_CC;

namespace MoriorGames {

class BattleInitCustomActions
{
public:
    explicit BattleInitCustomActions(Layer *layer);

private:
    Node *node;

    void runActions(Layer *layer);
};

}

#endif
