#include "PathFinder.h"

using MoriorGames::PathFinder;
using MoriorGames::Coordinate;

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
    Path path{origin};
    pathScope.push_back(path);
    for (int i = 0; i < move; ++i) {
        int x = 0;
        int y = 0;

        // UP
        x = origin->x;
        y = origin->y + 1;

    }
}
