#include "Coordinate2Screen.h"
#include "../Vendor/Grid/Grid.h"

Coordinate2Screen::Coordinate2Screen(int gridFactor)
    : gridFactor{gridFactor}
{
}

Vec2 Coordinate2Screen::execute(Coordinate *coordinate)
{
    return Vec2(axisXToScreen(coordinate->x), axisYToScreen(coordinate->y));
}

float Coordinate2Screen::axisXToScreen(int x)
{
    return visibleSize.width / 2 + x * Grid::TILE_SIZE * gridFactor;
}

float Coordinate2Screen::axisYToScreen(int y)
{
    return (Grid::CENTER_FACTOR * gridFactor) + (y * Grid::TILE_SIZE * gridFactor);
}

