#include "PathFinder.h"

PathFinder::PathFinder(Grid *grid)
    : grid{grid}
{
    pathFinderArea = new PathFinderArea(grid);
    pathFinderShot = new PathFinderShot(grid);
}

std::vector<Path> &PathFinder::buildPathScope(Coordinate *origin, int range, bool withCollision)
{
    pathScope.clear();
    Path path;
    path.coordinate = origin;
    pathScope.push_back(path);

    for (int i = 0; i < range; ++i) {
        for (auto pathStruct:pathScope) {
            if (pathStruct.level == i) {
                for (auto axis:moveAxis(pathStruct.coordinate)) {
                    if (!withCollision || !axis->occupied) {
                        bool add = true;
                        for (auto limits:pathScope) {
                            if (limits.coordinate->x == axis->x && limits.coordinate->y == axis->y) {
                                add = false;
                                break;
                            }
                        }
                        if (add && grid->isValidCoordinate(axis)) {
                            Path newPath;
                            newPath.level = i + 1;
                            newPath.coordinate = axis;
                            pathScope.push_back(newPath);
                        }
                    }
                }
            }
        }
    }

    pathFinderShot->eraseForbiddenCoordinates(pathScope);

    return pathScope;
}

const std::vector<Path> &PathFinder::buildPathForArea(Coordinate *origin, int range)
{
    pathScope.clear();
    pathScope = pathFinderArea->buildPathScope(origin, range);

    return pathScope;
}

const std::vector<Path> &PathFinder::getPathScope() const
{
    return pathScope;
}

std::vector<Coordinate *> PathFinder::moveAxis(Coordinate *current)
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

    auto axis3 = grid->findByXY(x + 1, y);
    if (axis3 != nullptr) {
        axis.push_back(axis3);
    }

    auto axis4 = grid->findByXY(x - 1, y);
    if (axis4 != nullptr) {
        axis.push_back(axis4);
    }

    return axis;
}
