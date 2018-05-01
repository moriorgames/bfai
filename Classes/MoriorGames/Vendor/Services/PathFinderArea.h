#ifndef MORIOR_GAMES_VENDOR_SERVICES_PATH_FINDER_AREA_H
#define MORIOR_GAMES_VENDOR_SERVICES_PATH_FINDER_AREA_H

#include <vector>
#include "../Containers/Path.h"
#include "../Grid/Grid.h"
#include "../ValueObjects/Coordinate.h"

class PathFinderArea
{
public:
    explicit PathFinderArea(Grid *grid);
    const std::vector<Path> &buildPathScope(Coordinate *, int range);

private:
    Grid *grid;
    std::vector<Path> pathScope;

    void addPathForAxis(Coordinate *, int index);
    std::vector<Coordinate *> moveAxis(Coordinate *);
};

#endif
