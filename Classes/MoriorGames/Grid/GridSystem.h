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
    static const Color4F GRID_COLOR;

public:
    GridSystem(Layer *layer);
    cocos2d::Vec2 coordinateToScreen(Coordinate *coordinate);
    float axisYToScreen(int y);
    float axisXToScreen(int x);

private:
    Layer *layer;
    Grid *grid;
    std::vector<Coordinate *> coordinates;

    void displayGrid();
};

}

#endif
