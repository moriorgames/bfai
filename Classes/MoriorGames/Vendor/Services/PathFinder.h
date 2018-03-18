#ifndef MORIOR_GAMES_VENDOR_SERVICES_PATH_FINDER_H
#define MORIOR_GAMES_VENDOR_SERVICES_PATH_FINDER_H

#include <vector>
#include "../Grid/Grid.h"

namespace MoriorGames {

struct Path
{
    int level = 0;
    Coordinate *coordinate = nullptr;
};

class PathFinder
{
public:
    PathFinder(int move, Coordinate *origin, Grid *grid);
    std::vector<Coordinate *> find(Coordinate *target);
    const std::vector<Path> &getPathScope() const;

private:
    int move;
    Coordinate *origin;
    Grid *grid;
    std::vector<Path> pathScope;

    void buildPathScope();
    std::vector<Coordinate *> moveAxis(Coordinate *current);
};

}

#endif
