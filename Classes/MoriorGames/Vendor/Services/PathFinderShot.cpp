#include "PathFinderShot.h"

PathFinderShot::PathFinderShot(Grid *grid)
    : grid{grid}
{
}

void PathFinderShot::eraseForbiddenCoordinates(std::vector<Path> &pathScope)
{
    for (auto forbidden:calculateForbiddenCoordinate(pathScope)) {
        int index = 0;
        for (auto path:pathScope) {
            if (path.coordinate->isEqual(forbidden)) {
                pathScope.erase(pathScope.begin() + index);
            }
            index++;
        }
    }
}

std::vector<Coordinate *> PathFinderShot::calculateForbiddenCoordinate(std::vector<Path> &pathScope)
{
    std::vector<Coordinate *> forbidden;

    auto origin = pathScope.at(0).coordinate;

    // Angle / Distance
    std::vector<std::pair<double, double >> collision;

    for (int i = 1; i < pathScope.size(); ++i) {
        auto path = pathScope[i];
        auto destination = grid->findByXY(path.coordinate->x, path.coordinate->y);
        if (destination->occupied) {
            auto angle = atan2((float) origin->y - (float) destination->y, (float) origin->x - (float) destination->x);
            auto distance = getDistance(origin, destination);
            collision.emplace_back(angle, distance);
        }
    }

    for (auto collide:collision) {
        for (auto path:pathScope) {
            auto destination = grid->findByXY(path.coordinate->x, path.coordinate->y);
            auto angle = atan2((float) origin->y - (float) destination->y, (float) origin->x - (float) destination->x);
            auto dist = getDistance(origin, destination);
            if (angle >= collide.first - DEVIATION && angle <= collide.first + DEVIATION && dist > collide.second) {
                forbidden.push_back(new Coordinate(destination->x, destination->y));
            }
        }
    }

    return forbidden;
}

double PathFinderShot::getDistance(Coordinate *a, Coordinate *b)
{
    return fabs(a->x - b->x) / 2 + fabs(a->y - b->y) / 2;
}
