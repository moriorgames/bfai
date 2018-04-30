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
    const float AGRO_FACTOR = 3;

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
    Coordinate *closestCoordinate(Coordinate *, std::vector<Path> &pathScope);
    double getDistance(BattleHero *, Coordinate *);
    double getDistance(Coordinate *, Coordinate *);
};

#endif
