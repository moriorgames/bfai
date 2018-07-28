#ifndef MORIOR_GAMES_VIEW_BATTLE_TILE_DRAWER_H
#define MORIOR_GAMES_VIEW_BATTLE_TILE_DRAWER_H

#include "cocos2d.h"
#include "../../Screen/Coordinate2Screen.h"
#include "../../Vendor/ValueObjects/Coordinate.h"
USING_NS_CC;

class TileDrawer
{
public:
    const Color4F BORDER_COLOR{0, 0, 0, .05f};

    TileDrawer(float size, Coordinate2Screen *);
    void draw(Coordinate *, Color4F color, Node *);
    void debug(Coordinate *, Node *);

private:
    float size = 0;
    Coordinate2Screen *coordinate2Screen;
};

#endif
