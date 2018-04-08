#ifndef MORIOR_GAMES_VENDOR_GRID_COORDINATE_H
#define MORIOR_GAMES_VENDOR_GRID_COORDINATE_H

class Coordinate
{
public:
    explicit Coordinate(Coordinate *coordinate);
    Coordinate(int x, int y);

    int x, y;
};

#endif
