#ifndef MORIOR_GAMES_VENDOR_GRID_COORDINATE_H
#define MORIOR_GAMES_VENDOR_GRID_COORDINATE_H

class Coordinate
{
public:
    explicit Coordinate(Coordinate *);
    Coordinate(int x, int y);
    bool isEqual(const Coordinate *);

    int x = 99, y = 99;
    bool occupied = false;
};

#endif
