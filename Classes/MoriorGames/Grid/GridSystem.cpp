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

GridView *GridSystem::getGridView() const
{
    return gridView;
}

Coordinate *GridSystem::getClosestCoordinate(std::vector<Path> &paths, float x, float y)
{
    double tmpDistance = 5000;
    auto coordinate = new Coordinate(0, 0);
    for (auto path:paths) {

        auto distance = getDistance(x, y, path.coordinate);
        if (distance < tmpDistance) {
            coordinate = path.coordinate;
            tmpDistance = distance;
        }
    }

    return coordinate;
}

void GridSystem::displayGrid()
{
    for (auto coordinate:grid->getCoordinates()) {
        gridView->drawTile(coordinate, GridView::FILL_COLOR);
    }
}

double GridSystem::getDistance(float x, float y, Coordinate *coordinate)
{
    auto screenVec2 = coordinate2Screen->execute(coordinate);

    float x2 = screenVec2.x;
    float y2 = screenVec2.y;

    double distanceX = fabs(x2 - x) / 2;
    double distanceY = fabs(y2 - y) / 2;
    double sumDistance = distanceX + distanceY;

    return sumDistance;
}
