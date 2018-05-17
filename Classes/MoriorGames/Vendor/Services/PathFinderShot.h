#ifndef MORIOR_GAMES_VENDOR_SERVICES_PATH_FINDER_SHOT_H
#define MORIOR_GAMES_VENDOR_SERVICES_PATH_FINDER_SHOT_H

#include <vector>
#include "../Containers/Path.h"
#include "../Grid/Grid.h"
#include "../ValueObjects/Coordinate.h"

class PathFinderShot
{
public:
    const double DEVIATION = 0.33;

    explicit PathFinderShot(Grid *grid);
    void eraseForbiddenCoordinates(std::vector<Path> &pathScope);

private:
    Grid *grid;

    std::vector<Coordinate *> calculateForbiddenCoordinate(std::vector<Path> &pathScope);
    double getDistance(Coordinate *a, Coordinate *b);
};

#endif
