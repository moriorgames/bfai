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

    static const Color4F ACTION_COLOR;

    static const Color4F RANGE_COLOR;

    const int HEIGHT_ACTION_LIMIT = 7;

public:
    GridSystem();

    cocos2d::DrawNode *displayGrid();

    cocos2d::DrawNode *createForbiddenActionZone(std::string team, int points);

    cocos2d::DrawNode *createRangedZone(int x, int y, int ranged);

    cocos2d::Vec2 coordinateToScreen(Coordinate *coordinate);

    float axisYToScreen(int y);

    float axisXToScreen(int x);

    Coordinate *getClosestCoordinate(float posX, float posY, std::string team, bool isMechanic, int points);

    Grid *getGrid() const
    {
        return grid;
    }

private:

    Grid *grid;
    std::vector<MoriorGames::GridCoordinate *> coordinates;

    double getDistance(int i, float x, float y);

    bool isCoordinateAllowed(GridCoordinate *, std::string team, bool isMechanic, int points);

    int coordinateAdvantage(int points);
};

}

#endif
