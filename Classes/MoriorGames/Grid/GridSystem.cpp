#include "GridSystem.h"
#include "../Definitions.h"
#include "../Screen/ResolutionChecker.h"

USING_NS_CC;

const Color4F GridSystem::FILL_COLOR{0, 0, 0, 0};

const Color4F GridSystem::MOVE_FILL_COLOR{.2f, 1, .2f, .3f};

const Color4F GridSystem::BORDER_COLOR{0, 0, 0, .15f};

const std::string GridSystem::MOVE_NAME = "movement-node";

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
    height = width = Grid::TILE_SIZE / 2 * grid->getFactor();
    displayGrid();

    layer->addChild(gridTiles, Z_ORDER_GRID);
    layer->addChild(movementTiles, Z_ORDER_GRID);
}

Grid *GridSystem::getGrid() const
{
    return grid;
}

Coordinate2Screen *GridSystem::getCoordinate2Screen() const
{
    return coordinate2Screen;
}

void GridSystem::drawTile(Coordinate *coordinate, Color4F color, std::string nodeName)
{
    auto node = gridTiles;
    if (nodeName == MOVE_NAME) {
        node = movementTiles;
    }
    auto drawNode = DrawNode::create();
    auto screenVec2 = coordinate2Screen->execute(coordinate);

    Vec2 rectangle[4];
    rectangle[0] = Vec2(screenVec2.x + width, screenVec2.y + height);
    rectangle[1] = Vec2(screenVec2.x - width, screenVec2.y + height);
    rectangle[2] = Vec2(screenVec2.x - width, screenVec2.y - height);
    rectangle[3] = Vec2(screenVec2.x + width, screenVec2.y - height);

    drawNode->drawPolygon(rectangle, 4, color, 1, BORDER_COLOR);
    node->addChild(drawNode);
}

Coordinate *GridSystem::getClosestCoordinate(float x, float y)
{
    int i = 0;
    int index = 0;
    double distance = 5000;
    for (auto coordinate:grid->getCoordinates()) {

        double sumDistance = getDistance(x, y, coordinate);

        if (sumDistance < distance) {
            distance = sumDistance;
            index = i;
        }
        i++;
    }

    return grid->getCoordinates()[index];
}

void GridSystem::removeTilesByName(std::string nodeName)
{
    auto node = gridTiles;
    if (nodeName == MOVE_NAME) {
        node = movementTiles;
    }
    node->removeAllChildren();
}

void GridSystem::displayGrid()
{
    for (auto coordinate:grid->getCoordinates()) {
        drawTile(coordinate, FILL_COLOR);
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
