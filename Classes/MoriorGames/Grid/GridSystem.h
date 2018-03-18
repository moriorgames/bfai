#ifndef MORIOR_GAMES_GRID_GRID_SYSTEM_H
#define MORIOR_GAMES_GRID_GRID_SYSTEM_H

#include "GridSD.h"
#include "GridHD.h"
#include "GridHDR.h"
#include "../Screen/ScreenProperties.h"

using MoriorGames::Grid;
using MoriorGames::Coordinate;

namespace MoriorGames {

class GridSystem: public ScreenProperties
{
public:
    static const Color4F FILL_COLOR;
    static const Color4F MOVE_FILL_COLOR;
    static const Color4F BORDER_COLOR;

public:
    GridSystem(Layer *layer);
    Grid *getGrid() const;
    cocos2d::Vec2 coordinateToScreen(Coordinate *coordinate);
    float axisYToScreen(int y);
    float axisXToScreen(int x);
    void drawTile(Coordinate *coordinate, Color4F color);

private:
    Layer *layer;
    Grid *grid;
    float height = 0;
    float width = 0;

    void displayGrid();
};

}

#endif
