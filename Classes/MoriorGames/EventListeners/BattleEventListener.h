#ifndef MORIOR_GAMES_EVENT_LISTENERS_BATTLE_EVENT_LISTENER_H
#define MORIOR_GAMES_EVENT_LISTENERS_BATTLE_EVENT_LISTENER_H

#include "cocos2d.h"
#include "BattleActionDispatcher.h"
#include "../Grid/GridSystem.h"
#include "../Services/BattleContainer.h"
#include "../Vendor/Entity/Battle.h"
#include "../Vendor/ValueObjects/Coordinate.h"
#include "../View/Battle/HeroView.h"
USING_NS_CC;

class BattleEventListener
{
public:
    BattleEventListener(Layer *layer, BattleContainer *battleContainer);
    bool onTouchBegin(Touch *touch, Event *event);
    bool onTouchMove(Touch *touch, Event *event);
    bool onTouchEnd(Touch *touch, Event *event);

private:
    Layer *layer;
    BattleContainer *battleContainer;
    BattleActionDispatcher *battleActionDispatcher;

    bool isTouchWithinBoundariesOfBattleField(Vec2 screenTouch);
    Coordinate *closestCoordinate(Vec2 screenTouch);
};

#endif
