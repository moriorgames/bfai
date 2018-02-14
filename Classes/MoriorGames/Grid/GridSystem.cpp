#include "GridSystem.h"

using MoriorGames::GridSystem;
USING_NS_CC;

const Color4F GridSystem::GRID_COLOR{0, 0, 0, .2f};

GridSystem::GridSystem()
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

    coordinates = grid->createGrid();
}

cocos2d::DrawNode *GridSystem::displayGrid()
{
    auto drawNode = DrawNode::create();
    float width = Grid::TILE_SIZE / 2 * grid->getFactor();
    float height = Grid::TILE_SIZE / 2 * grid->getFactor();

    for (auto coordinate:coordinates) {

        Vec2 rectangle[4];
        rectangle[0] = Vec2(coordinateToScreen(coordinate).x + width, coordinateToScreen(coordinate).y + height);
        rectangle[1] = Vec2(coordinateToScreen(coordinate).x - width, coordinateToScreen(coordinate).y + height);
        rectangle[2] = Vec2(coordinateToScreen(coordinate).x - width, coordinateToScreen(coordinate).y - height);
        rectangle[3] = Vec2(coordinateToScreen(coordinate).x + width, coordinateToScreen(coordinate).y - height);

        drawNode->drawPolygon(rectangle, 4, GRID_COLOR, 1, GRID_COLOR);

    }

    return drawNode;
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
