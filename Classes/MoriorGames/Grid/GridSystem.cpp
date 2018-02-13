#include "GridSystem.h"

using MoriorGames::GridSystem;
USING_NS_CC;

const Color4F GridSystem::GRID_COLOR{0, 0, 0, .2f};

const Color4F GridSystem::ACTION_COLOR{.9f, .2f, 0, .4f};

const Color4F GridSystem::RANGE_COLOR{.9f, .9f, .9f, .4f};

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
    float width = Grid::TILE_WIDTH / 2 * grid->getFactor();
    float height = Grid::TILE_SIZE / 2 * grid->getFactor();

    for (Coordinate *coordinate:coordinates) {

        Vec2 rectangle[4];
        rectangle[0] = Vec2(coordinateToScreen(coordinate).x + width, coordinateToScreen(coordinate).y + height);
        rectangle[1] = Vec2(coordinateToScreen(coordinate).x - width, coordinateToScreen(coordinate).y + height);
        rectangle[2] = Vec2(coordinateToScreen(coordinate).x - width, coordinateToScreen(coordinate).y - height);
        rectangle[3] = Vec2(coordinateToScreen(coordinate).x + width, coordinateToScreen(coordinate).y - height);

        drawNode->drawPolygon(rectangle, 4, GRID_COLOR, 1, GRID_COLOR);

    }

    return drawNode;
}

cocos2d::DrawNode *GridSystem::createForbiddenActionZone(std::string team, int points)
{
    auto drawNode = DrawNode::create();
    float size = Grid::TILE_SIZE / 2 * grid->getFactor();
    int maxY = HEIGHT_ACTION_LIMIT, minY = -HEIGHT_ACTION_LIMIT;
    int maxTopX = 0, minTopX = 0, maxBotX = 0, minBotX = 0;

    if (points > 0) {
        int advantage = coordinateAdvantage(points);

        if (team == TEAM_LOCAL) {
            minTopX = advantage;
            minBotX = advantage;
        }
        if (team == TEAM_VISITOR) {
            maxTopX = -advantage;
            maxBotX = -advantage;
        }
    }

    if (team == TEAM_LOCAL) {
        maxTopX = Grid::TILES_QUANTITY;
        maxBotX = Grid::TILES_QUANTITY;
    }
    if (team == TEAM_VISITOR) {
        minTopX = -Grid::TILES_QUANTITY;
        minBotX = -Grid::TILES_QUANTITY;
    }

    float leftTop = 0, rightTop = 0, leftBot = 0, rightBot = 0, topTop = 0, botBot = 0;

    for (GridCoordinate *coordinate:coordinates) {

        // Y axis
        if (coordinate->y == maxY) {
            topTop = coordinateToScreen(coordinate).y + size;
        }
        if (coordinate->y == minY) {
            botBot = coordinateToScreen(coordinate).y - size;
        }

        // X axis
        if (coordinate->x == minTopX && coordinate->y == maxY) {
            leftTop = coordinateToScreen(coordinate).x - size;
        }
        if (coordinate->x == minBotX && coordinate->y == minY) {
            leftBot = coordinateToScreen(coordinate).x - size;
        }

        if (coordinate->x == maxTopX && coordinate->y == maxY) {
            rightTop = coordinateToScreen(coordinate).x + size;
        }
        if (coordinate->x == maxBotX && coordinate->y == minY) {
            rightBot = coordinateToScreen(coordinate).x + size;
        }

    }

    Vec2 topLeft = {leftTop, topTop}, topRight = {rightTop, topTop},
        botLeft = {leftBot, botBot}, botRight = {rightBot, botBot};

    Vec2 rectangle[4];
    rectangle[0] = topLeft;
    rectangle[1] = topRight;
    rectangle[2] = botRight;
    rectangle[3] = botLeft;

    drawNode->drawPolygon(rectangle, 4, ACTION_COLOR, 1, ACTION_COLOR);

    return drawNode;
}

cocos2d::DrawNode *GridSystem::createRangedZone(int x, int y, int ranged)
{
    auto drawNode = DrawNode::create();
    auto center = Point(axisXToScreen(x), axisYToScreen(y));
    float range = ranged * Grid::TILE_WIDTH * grid->getFactor();

    drawNode->drawSolidCircle(center, range, 0, 50, 1, 0.9, RANGE_COLOR);

    return drawNode;
}

cocos2d::Vec2 GridSystem::coordinateToScreen(GridCoordinate *coordinate)
{
    return Vec2(axisXToScreen(coordinate->x), axisYToScreen(coordinate->y));
}

float GridSystem::axisYToScreen(int y)
{
    return (grid->getFactor() * Grid::CENTER_FACTOR) + (y * Grid::TILE_SIZE * grid->getFactor());
}

float GridSystem::axisXToScreen(int x)
{
    return visibleSize.width / 2 + x * Grid::TILE_WIDTH * grid->getFactor();
}

GridCoordinate *GridSystem::getClosestCoordinate(float posX, float posY, std::string team, bool isMechanic, int points)
{
    int index = 0;
    double distance = 5000;
    float x1 = posX, y1 = posY;
    for (int i = 0; i != coordinates.size(); i++) {

        if (!isCoordinateAllowed(coordinates[i], team, isMechanic, points)) {
            continue;
        }
        double sumDistance = getDistance(i, x1, y1);

        if (sumDistance < distance) {
            distance = sumDistance;
            index = i;
        }
    }

    return coordinates[index];
}

double GridSystem::getDistance(int i, float x, float y)
{
    auto screenCoordinate = coordinateToScreen(coordinates[i]);

    float x2 = screenCoordinate.x;
    float y2 = screenCoordinate.y;

    double distanceX = fabs(x2 - x) / 2;
    double distanceY = fabs(y2 - y) / 2;
    double sumDistance = distanceX + distanceY;

    return sumDistance;;
}

bool GridSystem::isCoordinateAllowed(GridCoordinate *coordinate, std::string team, bool isMechanic, int points)
{
    bool isAllowed = false;
    if (isMechanic) {
        isAllowed = true;
    } else {

        int advantage = coordinateAdvantage(points);

        if (team == TEAM_LOCAL) {
            if (coordinate->x < advantage) {
                isAllowed = true;
            }
        }

        if (team == TEAM_VISITOR) {
            advantage *= -1;
            if (coordinate->x > advantage) {
                isAllowed = true;
            }
        }
    }

    return isAllowed;
}

int GridSystem::coordinateAdvantage(int points)
{
    return points * Grid::ADVANTAGE;
}
