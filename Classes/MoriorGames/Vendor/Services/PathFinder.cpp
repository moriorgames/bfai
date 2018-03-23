#include "PathFinder.h"

using MoriorGames::PathFinder;
using MoriorGames::Coordinate;
using MoriorGames::Grid;
using MoriorGames::Path;

PathFinder::PathFinder(int move, Coordinate *origin, Grid *grid)
    : move{move}, origin{origin}, grid{grid}
{
    buildPathScope();
}

std::vector<Coordinate *> PathFinder::find(Coordinate *target)
{
    std::vector<Coordinate *> path;

    for (int i = 0; i < move; ++i) {

    }


//    path.push_back(from);

    return path;
}

void PathFinder::buildPathScope()
{
    Path path;
    path.coordinate = origin;
    pathScope.push_back(path);

    for (int i = 0; i < move; ++i) {
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
}

const std::vector<Path> &PathFinder::getPathScope() const
{
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
