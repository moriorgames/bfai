#ifndef MORIOR_GAMES_VENDOR_GRID_COORDINATE_H
#define MORIOR_GAMES_VENDOR_GRID_COORDINATE_H

namespace MoriorGames {

class Coordinate
{
public:
    int x, y;
    explicit Coordinate(Coordinate *coordinate);
    Coordinate(int x, int y);
};

}

#endif
