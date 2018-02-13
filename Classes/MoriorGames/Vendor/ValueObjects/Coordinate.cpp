#include "Coordinate.h"

using MoriorGames::Coordinate;

Coordinate::Coordinate(int x, int y)
    : x{x}, y{y}
{
}

Coordinate::Coordinate(Coordinate *coordinate)
    : x{coordinate->x}, y{coordinate->y}
{
}
