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
    AI(Battle *, Grid *, BattleEventPublishable *);
    void process();

private:
    Battle *battle;
    Grid *grid;
    BattleEventPublishable *eventPublisher;
    PathFinder *pathFinder;

    Coordinate *getCoordinateAction(BattleHero *);
    Coordinate *closestCoordinateWithEnemy(BattleHero *, std::vector<Path> &pathScope);
    double getDistance(Coordinate *, Coordinate *);
};

#endif
