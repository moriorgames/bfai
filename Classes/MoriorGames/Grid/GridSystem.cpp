#include "GridSystem.h"
#include "../Definitions.h"
#include "../Screen/ResolutionChecker.h"

USING_NS_CC;

GridSystem::GridSystem(Layer *layer)
    : layer{layer}
{
    if (ResolutionChecker::isHDR()) {
        grid = new GridHDR;
    }

    if (ResolutionChecker::isHD()) {
        grid = new GridHD;
    }

    if (ResolutionChecker::isSD()) {
        grid = new GridSD;
    }

    coordinate2Screen = new Coordinate2Screen(grid->getFactor());
    closestCoordinate = new ClosestCoordinate(coordinate2Screen);
    float size = Grid::TILE_SIZE / 2 * grid->getFactor();
    gridView = new GridView(layer, coordinate2Screen, size);
    displayGrid();
}

Grid *GridSystem::getGrid() const
{
    return grid;
}

Coordinate2Screen *GridSystem::getCoordinate2Screen() const
{
    return coordinate2Screen;
}

ClosestCoordinate *GridSystem::getClosestCoordinate() const
{
    return closestCoordinate;
}

GridView *GridSystem::getGridView() const
{
    return gridView;
}
void GridSystem::displayGrid()
{
    for (auto coordinate:grid->getCoordinates()) {
        gridView->drawTile(coordinate, GridView::FILL_COLOR);
    }
}
