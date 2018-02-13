#ifndef MORIOR_GAMES_VENDOR_GRID_COORDINATE_H
#define MORIOR_GAMES_VENDOR_GRID_COORDINATE_H

namespace MoriorGames {

class Coordinate
{
public:
    int x, y;
    Coordinate(int x, int y);
    Coordinate(Coordinate *coordinate);
};

}

#endif
