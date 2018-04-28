#include "GridContainer.h"
#include "../Screen/ResolutionChecker.h"

GridContainer::GridContainer(Layer *layer, Battle *battle)
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
    for (auto battleHero:battle->getBattleHeroes()) {
        auto coordinate = grid->findByXY(battleHero->getCoordinate()->x, battleHero->getCoordinate()->y);
        coordinate->occupied = true;
        battleHero->setCoordinate(coordinate);
    }
    closestCoordinate = new ClosestCoordinate(coordinate2Screen);
    float size = Grid::TILE_SIZE / 2 * grid->getFactor();
    pathFinder = new PathFinder(grid);
    auto tileDrawer = new TileDrawer(size, coordinate2Screen);
    gridView = new GridView(layer, battle, pathFinder, tileDrawer);
    gridView->buildGrid(grid->getCoordinates());
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
