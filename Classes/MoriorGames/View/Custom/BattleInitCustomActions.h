#ifndef MORIOR_GAMES_VIEW_CUSTOM_BATTLE_INIT_CUSTOM_ACTIONS_H
#define MORIOR_GAMES_VIEW_CUSTOM_BATTLE_INIT_CUSTOM_ACTIONS_H

#include "cocos2d.h"
USING_NS_CC;

class BattleInitCustomActions
{
public:
    explicit BattleInitCustomActions(Layer *layer);

private:
    Node *node;

    void runActions(Layer *layer);
};

#endif
