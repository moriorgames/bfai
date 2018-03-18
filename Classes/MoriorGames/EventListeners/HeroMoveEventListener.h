#ifndef MORIOR_GAMES_EVENT_LISTENERS_HERO_MOVE_EVENT_LISTENER_H
#define MORIOR_GAMES_EVENT_LISTENERS_HERO_MOVE_EVENT_LISTENER_H

#include "cocos2d.h"
#include "../Grid/GridSystem.h"
#include "../Vendor/ValueObjects/Coordinate.h"
#include "../View/Battle/HeroView.h"
USING_NS_CC;

using MoriorGames::Coordinate;

namespace MoriorGames {

class HeroMoveEventListener
{
public:
    HeroMoveEventListener(Layer *layer, GridSystem *gridSystem, HeroView *heroView);
    bool onTouchBegin(Touch *touch, Event *event);
    bool onTouchMove(Touch *touch, Event *event);
    bool onTouchEnd(Touch *touch, Event *event);

private:
    Layer *layer;
    GridSystem *gridSystem;
    HeroView *heroView;

    bool isTouchWithinBoundariesOfBattleField(Vec2 screenTouch);
    Coordinate *closestCoordinate(Vec2 screenTouch);
};

}

#endif
