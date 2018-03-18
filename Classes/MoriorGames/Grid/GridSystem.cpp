#include "GridSystem.h"
#include "../Definitions.h"

using MoriorGames::GridSystem;
USING_NS_CC;

const Color4F GridSystem::FILL_COLOR{0, 0, 0, 0};

const Color4F GridSystem::MOVE_FILL_COLOR{.2f, 1, .2f, .3f};

const Color4F GridSystem::BORDER_COLOR{0, 0, 0, .15f};

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

void MoriorGames::GridSystem::drawTile(Coordinate *coordinate, Color4F color)
{
    auto drawNode = DrawNode::create();

    Vec2 rectangle[4];
    rectangle[0] = Vec2(coordinateToScreen(coordinate).x + width, coordinateToScreen(coordinate).y + height);
    rectangle[1] = Vec2(coordinateToScreen(coordinate).x - width, coordinateToScreen(coordinate).y + height);
    rectangle[2] = Vec2(coordinateToScreen(coordinate).x - width, coordinateToScreen(coordinate).y - height);
    rectangle[3] = Vec2(coordinateToScreen(coordinate).x + width, coordinateToScreen(coordinate).y - height);

    drawNode->drawPolygon(rectangle, 4, color, 1, BORDER_COLOR);

    layer->addChild(drawNode, Z_ORDER_GRID);
}

void GridSystem::displayGrid()
{
    for (auto coordinate:grid->getCoordinates()) {
        drawTile(coordinate, FILL_COLOR);
    }
}
