#ifndef MORIOR_GAMES_EVENT_LISTENERS_BATTLE_EVENT_LISTENER_H
#define MORIOR_GAMES_EVENT_LISTENERS_BATTLE_EVENT_LISTENER_H

#include "cocos2d.h"
#include "BattleEventPublishable.h"
#include "../Grid/GridSystem.h"
#include "../Containers/BattleContainer.h"
#include "../Vendor/Entity/Battle.h"
#include "../Vendor/ValueObjects/Coordinate.h"
#include "../View/Battle/HeroView.h"
USING_NS_CC;

class BattleEventListener
{
public:
    BattleEventListener(Layer *, BattleContainer *, BattleEventPublishable *);
    bool onTouchBegin(Touch *, Event *);
    bool onTouchMove(Touch *, Event *);
    bool onTouchEnd(Touch *, Event *);

private:
    Layer *layer;
    BattleContainer *battleContainer;
    BattleEventPublishable *battleEventPublishable;

    bool isTouchWithinBoundariesOfBattleField(Vec2 screenTouch);
    Coordinate *closestCoordinate(Vec2 screenTouch);
};

#endif
