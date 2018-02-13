#ifndef MORIOR_GAMES_VENDOR_GRID_GRID_H
#define MORIOR_GAMES_VENDOR_GRID_GRID_H

#include <cmath>
#include <vector>
#include "../ValueObjects/Coordinate.h"

namespace MoriorGames {

class Grid
{
public:
    static const int TILES_QUANTITY;

    static const int TILE_SIZE;

    static const int TILE_WIDTH;

    static const int CENTER_FACTOR;

    static const int ADVANTAGE;

public:
    std::vector<Coordinate *> createGrid();

    virtual int getFactor();

    static std::vector<int> getLines()
    {
        return {7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4, -5, -6, -7};
    }

    static bool isAllowedLine(int y);

    static bool collisionMidObstacles(int x, int y);

private:

    std::vector<Coordinate *> coordinates;

    void generateTiles(int tileQuantity, std::vector<int> lineRange);
};

}

#endif
