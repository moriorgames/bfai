#include "Coordinate.h"

Coordinate::Coordinate(int x, int y)
    : x{x}, y{y}
{
}

Coordinate::Coordinate(Coordinate *coordinate)
    : x{coordinate->x}, y{coordinate->y}
{
}

bool Coordinate::isEqual(const Coordinate *coordinate)
{
    return coordinate->x == x && coordinate->y == y;
}
