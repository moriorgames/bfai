#include "GridSystem.h"
#include "../Definitions.h"

USING_NS_CC;

const Color4F GridSystem::FILL_COLOR{0, 0, 0, 0};

const Color4F GridSystem::MOVE_FILL_COLOR{.2f, 1, .2f, .3f};

const Color4F GridSystem::BORDER_COLOR{0, 0, 0, .15f};

const std::string GridSystem::MOVE_NAME = "movement-node";

GridSystem::GridSystem(Layer *layer)
    : layer{layer}
{
    if (isHDR()) {
        grid = new GridHDR;
    }

    if (isHD()) {
        grid = new GridHD;
    }

    if (isSD()) {
        grid = new GridSD;
    }

    height = width = Grid::TILE_SIZE / 2 * grid->getFactor();
    displayGrid();

    layer->addChild(gridTiles, Z_ORDER_GRID);
    layer->addChild(movementTiles, Z_ORDER_GRID);
}

Grid *GridSystem::getGrid() const
{
    return grid;
}

cocos2d::Vec2 GridSystem::coordinateToScreen(Coordinate *coordinate)
{
    return Vec2(axisXToScreen(coordinate->x), axisYToScreen(coordinate->y));
}

float GridSystem::axisYToScreen(int y)
{
    return (grid->getFactor() * Grid::CENTER_FACTOR) + (y * Grid::TILE_SIZE * grid->getFactor());
}

float GridSystem::axisXToScreen(int x)
{
    return visibleSize.width / 2 + x * Grid::TILE_SIZE * grid->getFactor();
}

void GridSystem::drawTile(Coordinate *coordinate, Color4F color, std::string nodeName)
{
    auto node = gridTiles;
    if (nodeName == MOVE_NAME) {
        node = movementTiles;
    }
    auto drawNode = DrawNode::create();

    Vec2 rectangle[4];
    rectangle[0] = Vec2(coordinateToScreen(coordinate).x + width, coordinateToScreen(coordinate).y + height);
    rectangle[1] = Vec2(coordinateToScreen(coordinate).x - width, coordinateToScreen(coordinate).y + height);
    rectangle[2] = Vec2(coordinateToScreen(coordinate).x - width, coordinateToScreen(coordinate).y - height);
    rectangle[3] = Vec2(coordinateToScreen(coordinate).x + width, coordinateToScreen(coordinate).y - height);

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
    auto screenCoordinate = coordinateToScreen(coordinate);

    float x2 = screenCoordinate.x;
    float y2 = screenCoordinate.y;

    double distanceX = fabs(x2 - x) / 2;
    double distanceY = fabs(y2 - y) / 2;
    double sumDistance = distanceX + distanceY;

    return sumDistance;
}
