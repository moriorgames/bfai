#include "Grid.h"

const int Grid::TILES_QUANTITY = 8;

const int Grid::TILE_SIZE = 26;

const int Grid::CENTER_FACTOR = 150;

Grid::Grid()
{
    createGridCoordinates();
}

bool Grid::isValidCoordinate(Coordinate *coordinate)
{
    if (abs(coordinate->x) <= TILES_QUANTITY) {
        for (auto line:lines)
            if (coordinate->y == line) {
                return true;
            }
    }

    return false;
}

const std::vector<Coordinate *> &Grid::getCoordinates() const
{
    return coordinates;
}

/**
 * @todo Theres a more performant way to access coordinates data. A 2 dimensional vector of ints
 * we can check this if we use a lot this function and slows down the program.
 */
Coordinate *Grid::findByXY(int x, int y)
{
    auto it = find_if(coordinates.begin(), coordinates.end(), [x, y](Coordinate *coordinate)
    { return coordinate->x == x && coordinate->y == y; });

    if (it != coordinates.end()) {

        return *it;
    }

    return nullptr;
}

int Grid::getFactor()
{
    return 0;
}

void Grid::createGridCoordinates()
{
    int kTiles = TILES_QUANTITY;
    int quantityLines = kTiles * 2 + 1;
    int initialX = -kTiles;

    for (int i = 0; i < quantityLines; ++i) {
        for (int y:lines) {
            int x = initialX + i;
            auto coordinate = new Coordinate(x, y);
            if (y == 0 && (x >= -3 && x <= 3)) {
                coordinate->occupied = true;
            }
            coordinates.push_back(coordinate);
        }
    }
}
