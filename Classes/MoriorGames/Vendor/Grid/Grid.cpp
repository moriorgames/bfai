#include "Grid.h"

using MoriorGames::Grid;
using MoriorGames::Coordinate;

const int Grid::TILES_QUANTITY = 8;

const int Grid::TILE_SIZE = 26;

const int Grid::CENTER_FACTOR = 150;

std::vector<Coordinate *> Grid::createGridCoordinates()
{
    generateTiles();

    return coordinates;
}

int Grid::getFactor()
{
    return 0;
}

void Grid::generateTiles()
{
    int kTiles = TILES_QUANTITY;
    int quantityLines = kTiles * 2 + 1;
    int initialX = -kTiles;

    for (int i = 0; i < quantityLines; ++i) {
        for (int y:lines) {
            int x = initialX + i;
            auto coordinate = new Coordinate(x, y);
            coordinates.push_back(coordinate);
        }
    }
}

void Grid::printCoordinates()
{
    int counter = 0;
    for (auto coordinate:coordinates) {
        std::cout << "X: " << coordinate->x << " Y: " << coordinate->y << std::endl;
        counter++;
    }
    std::cout << "Total: " << counter << std::endl;
}
