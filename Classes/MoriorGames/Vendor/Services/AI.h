#ifndef MORIOR_GAMES_VENDOR_SERVICES_AI_H
#define MORIOR_GAMES_VENDOR_SERVICES_AI_H

#include <cmath>
#include "PathFinder.h"
#include "../../EventListeners/BattleEventPublishable.h"
#include "../Entity/Battle.h"
#include "../Entity/BattleAction.h"
#include "../Grid/Grid.h"

class AI
{
public:
    const float AGRO_FACTOR = 4;
    const int DEVIATION_MOVEMENT = 2;

    AI(Battle *, Grid *, BattleEventPublishable *);
    void process();

private:
    Battle *battle;
    Grid *grid;
    BattleEventPublishable *eventPublisher;
    PathFinder *pathFinder;

    Coordinate *calculateCoordinate(BattleHero *);

    Coordinate *coordinateForMove(BattleHero *, std::vector<Path> &pathScope);
    Coordinate *coordinateForAction(BattleHero *, std::vector<Path> &pathScope);

    Coordinate *enemyCoordinateTarget(BattleHero *);
    Coordinate *closestCoordinateForMove(Coordinate *, std::vector<Path> &pathScope);
    Coordinate *closestCoordinateForAction(Coordinate *, std::vector<Path> &pathScope);
    std::vector<std::pair<int, double >> closestDistance(Coordinate *, std::vector<Path> &pathScope);
    double getDistance(BattleHero *, Coordinate *);
    double getDistance(Coordinate *, Coordinate *);
};

#endif
