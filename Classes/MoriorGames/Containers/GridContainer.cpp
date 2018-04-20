#include "GridContainer.h"
#include "../Screen/ResolutionChecker.h"

GridContainer::GridContainer(Layer *layer)
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
    pathFinder = new PathFinder(grid);
    displayGrid();
}

Grid *GridContainer::getGrid() const
{
    return grid;
}

Coordinate2Screen *GridContainer::getCoordinate2Screen() const
{
    return coordinate2Screen;
}

ClosestCoordinate *GridContainer::getClosestCoordinate() const
{
    return closestCoordinate;
}

PathFinder *GridContainer::getPathFinder() const
{
    return pathFinder;
}

GridView *GridContainer::getGridView() const
{
    return gridView;
}

void GridContainer::displayGrid()
{
    for (auto coordinate:grid->getCoordinates()) {
        gridView->drawTile(coordinate, GridView::FILL_COLOR);
    }
}
