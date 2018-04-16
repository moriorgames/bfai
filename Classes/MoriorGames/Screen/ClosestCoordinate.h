#ifndef MORIOR_GAMES_SCREEN_CLOSEST_COORDINATE_H
#define MORIOR_GAMES_SCREEN_CLOSEST_COORDINATE_H

#include <cmath>
#include <vector>
#include "Coordinate2Screen.h"
#include "../Vendor/Containers/Path.h"
#include "../Vendor/ValueObjects/Coordinate.h"

class ClosestCoordinate
{
public:
    explicit ClosestCoordinate(Coordinate2Screen *);
    Coordinate *execute(std::vector<Path> &paths, float x, float y);

private:
    Coordinate2Screen *coordinate2Screen;

    double getDistance(Coordinate *, float x, float y);
};

#endif
