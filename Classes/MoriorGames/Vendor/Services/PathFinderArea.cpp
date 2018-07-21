#include "PathFinderArea.h"

PathFinderArea::PathFinderArea(Grid *grid)
    : grid{grid}
{
}

const std::vector<Path> &PathFinderArea::buildPathScope(Coordinate *origin, int range)
{
    pathScope.clear();
    Path pathLeft;
    pathLeft.coordinate = new Coordinate(origin->x, origin->y);
    pathLeft.coordinate->x--;
    pathScope.push_back(pathLeft);
    Path pathRight;
    pathRight.coordinate = new Coordinate(origin->x, origin->y);
    pathRight.coordinate->x++;
    pathScope.push_back(pathRight);

    for (int i = 0; i < range; ++i) {
        for (auto pathStruct:pathScope) {
            if (pathStruct.level == i) {
                if (pathStruct.coordinate->x > origin->x) {
                    auto axisRight = grid->findByXY(pathStruct.coordinate->x + 1, pathStruct.coordinate->y);
                    if (axisRight != nullptr && !axisRight->isEqual(origin)) {
                        addPathForAxis(axisRight, i);
                    }
                } else {
                    auto axisLeft = grid->findByXY(pathStruct.coordinate->x - 1, pathStruct.coordinate->y);
                    if (axisLeft != nullptr && !axisLeft->isEqual(origin)) {
                        addPathForAxis(axisLeft, i);
                    }
                }
            }
        }
    }

    return pathScope;
}

const std::vector<Path> &PathFinderArea::buildPathScopeLine(Coordinate *origin, int range)
{
    pathScope.clear();
    auto baseLeft = new Coordinate(origin->x, origin->y);
    baseLeft->x--;
    auto baseRight = new Coordinate(origin->x, origin->y);
    baseRight->x++;

    for (int i = 0; i < range; ++i) {
        Path pathLeft;
        pathLeft.coordinate = new Coordinate(baseLeft->x, baseLeft->y);
        pathLeft.coordinate->x--;
        if (grid->isValidCoordinate(pathLeft.coordinate)) {
            pathScope.push_back(pathLeft);
        }
        Path pathRight;
        pathRight.coordinate = new Coordinate(baseRight->x, baseRight->y);
        pathRight.coordinate->x++;
        if (grid->isValidCoordinate(pathRight.coordinate)) {
            pathScope.push_back(pathRight);
        }

        baseLeft->x--;
        baseRight->x++;
    }

    return pathScope;
}

void PathFinderArea::addPathForAxis(Coordinate *origin, int index)
{
    for (auto axis:moveAxis(origin)) {
        bool add = true;
        for (auto limits:pathScope) {
            if (limits.coordinate->x == axis->x && limits.coordinate->y == axis->y) {
                add = false;
                break;
            }
        }
        if (add && grid->isValidCoordinate(axis)) {
            Path newPath;
            newPath.level = index + 1;
            newPath.coordinate = axis;
            pathScope.push_back(newPath);
        }
    }
    bool add = true;
    for (auto limits:pathScope) {
        if (limits.coordinate->x == origin->x && limits.coordinate->y == origin->y) {
            add = false;
            break;
        }
    }
    if (add) {
        Path newPath;
        newPath.level = index + 1;
        newPath.coordinate = origin;
        pathScope.push_back(newPath);
    }
}

std::vector<Coordinate *> PathFinderArea::moveAxis(Coordinate *current)
{
    int x = current->x;
    int y = current->y;
    std::vector<Coordinate *> axis;
    auto axis1 = grid->findByXY(x, y + 1);
    if (axis1 != nullptr) {
        axis.push_back(axis1);
    }

    auto axis2 = grid->findByXY(x, y - 1);
    if (axis2 != nullptr) {
        axis.push_back(axis2);
    }

    return axis;
}
