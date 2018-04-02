#include "PathFinder.h"

PathFinder::PathFinder(Grid *grid)
    : grid{grid}
{
}

const std::vector<Path> &PathFinder::buildPathScope(BattleHero *battleHero)
{
    Path path;
    path.coordinate = battleHero->getCoordinate();
    pathScope.push_back(path);

    for (int i = 0; i < battleHero->getMovement(); ++i) {
        for (auto pathStruct:pathScope) {
            if (pathStruct.level == i) {
                for (auto axis:moveAxis(pathStruct.coordinate)) {
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

    return pathScope;
}

std::vector<Coordinate *> PathFinder::moveAxis(Coordinate *current)
{
    std::vector<Coordinate *> axis;
    axis.push_back(new Coordinate(current->x, current->y + 1));
    axis.push_back(new Coordinate(current->x, current->y - 1));
    axis.push_back(new Coordinate(current->x + 1, current->y));
    axis.push_back(new Coordinate(current->x - 1, current->y));

    return axis;
}
