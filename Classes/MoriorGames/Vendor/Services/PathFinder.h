#ifndef MORIOR_GAMES_VENDOR_SERVICES_PATH_FINDER_H
#define MORIOR_GAMES_VENDOR_SERVICES_PATH_FINDER_H

#include <vector>
#include "../Containers/Path.h"
#include "../Grid/Grid.h"
#include "../ValueObjects/Coordinate.h"

class PathFinder
{
public:
    PathFinder(Grid *grid);
    const std::vector<Path> &buildPathScope(Coordinate *, int range, bool withCollision = false);
    const std::vector<Path> &buildPathForArea(Coordinate *, int range);
    const std::vector<Path> &getPathScope() const;

private:
    Grid *grid;
    std::vector<Path> pathScope;

    std::vector<Coordinate *> moveAxis(Coordinate *);
    std::vector<Coordinate *> moveAreaAxis(Coordinate *);
};

#endif
