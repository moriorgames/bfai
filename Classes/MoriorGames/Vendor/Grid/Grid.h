#ifndef MORIOR_GAMES_VENDOR_GRID_GRID_H
#define MORIOR_GAMES_VENDOR_GRID_GRID_H

#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include "../ValueObjects/Coordinate.h"

class Grid
{
public:
    static const int TILES_QUANTITY;
    static const int TILE_SIZE;
    static const int CENTER_FACTOR;

    Grid();
    bool isValidCoordinate(Coordinate *);
    const std::vector<Coordinate *> &getCoordinates() const;
    virtual int getFactor();
    Coordinate *findByXY(int x, int y);

private:
    std::vector<Coordinate *> coordinates;
    std::vector<int> lines{3, 2, 1, 0, -1, -2, -3};

    void createGridCoordinates();
};

#endif
