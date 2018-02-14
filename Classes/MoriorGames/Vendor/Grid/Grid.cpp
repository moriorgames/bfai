#include "Grid.h"

using MoriorGames::Grid;
using MoriorGames::Coordinate;

const int Grid::TILES_QUANTITY = 8;

const int Grid::TILE_SIZE = 26;

const int Grid::CENTER_FACTOR = 150;

std::vector<Coordinate *> Grid::createGrid()
{
    generateTiles(TILES_QUANTITY, getLines());

    return coordinates;
}

int Grid::getFactor()
{
    return 0;
}

bool Grid::isAllowedLine(int y)
{
    for (auto compareY:getLines()) {
        if (compareY == y) {
            return true;
        }
    }

    return false;
}

bool Grid::collisionMidObstacles(int x, int y)
{
    if (x == 0 && (y == 4 || y == -4)) {
        return true;
    }
    if (x == 0 && (y == 3 || y == -3)) {
        return true;
    }
    if (x == 0 && (y == 2 || y == -2)) {
        return true;
    }
    if (x == 1 && (y == 3 || y == -3)) {
        return true;
    }

    return (x == -1 && (y == 3 || y == -3));
}

void Grid::generateTiles(int tileQuantity, std::vector<int> lineRange)
{
    int quantityLines = tileQuantity * 2 + 1;
    int initialX = -tileQuantity;

    for (int i = 0; i < quantityLines; ++i) {
        for (int y:lineRange) {
            int x = initialX + i;
            auto coordinate = new Coordinate(x, y);
            coordinates.push_back(coordinate);
        }
    }
}
