#ifndef MORIOR_GAMES_VENDOR_SERVICES_PATH_FINDER_H
#define MORIOR_GAMES_VENDOR_SERVICES_PATH_FINDER_H

#include <vector>
#include "PathFinderArea.h"
#include "PathFinderShot.h"
#include "../Containers/Path.h"
#include "../Grid/Grid.h"
#include "../ValueObjects/Coordinate.h"

class PathFinder
{
public:
    explicit PathFinder(Grid *grid);
    std::vector<Path> &buildPathScope(Coordinate *, int range, bool withCollision = false);
    const std::vector<Path> &buildPathForSight(Coordinate *, int range);
    const std::vector<Path> &buildPathForJump(Coordinate *, int range);
    const std::vector<Path> &buildPathForArea(Coordinate *, int range);
    const std::vector<Path> &buildPathForLine(Coordinate *, int range);
    const std::vector<Path> &getPathScope() const;

private:
    Grid *grid;
    PathFinderArea *pathFinderArea;
    PathFinderShot *pathFinderShot;
    std::vector<Path> pathScope;

    std::vector<Coordinate *> moveAxis(Coordinate *);
};

#endif
