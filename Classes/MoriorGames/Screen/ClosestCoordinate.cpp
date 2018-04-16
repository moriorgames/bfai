#include "ClosestCoordinate.h"

ClosestCoordinate::ClosestCoordinate(Coordinate2Screen *coordinate2Screen)
    : coordinate2Screen{coordinate2Screen}
{
}

Coordinate *ClosestCoordinate::execute(std::vector<Path> &paths, float x, float y)
{
    double tmpDistance = 5000;
    auto coordinate = new Coordinate(0, 0);
    for (auto path:paths) {

        auto distance = getDistance(path.coordinate, x, y);
        if (distance < tmpDistance) {
            coordinate = path.coordinate;
            tmpDistance = distance;
        }
    }

    return coordinate;
}

double ClosestCoordinate::getDistance(Coordinate *coordinate, float x, float y)
{
    auto screenVec2 = coordinate2Screen->execute(coordinate);

    float x2 = screenVec2.x;
    float y2 = screenVec2.y;

    double distanceX = fabs(x2 - x) / 2;
    double distanceY = fabs(y2 - y) / 2;
    double sumDistance = distanceX + distanceY;

    return sumDistance;
}
