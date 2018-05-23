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
    const std::string AI_TOKEN = "j54tfg4AeMP4O8z9FgtWJEZeFYmmrtS3LpoaKbQ47FB";
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

    Coordinate *enemyCoordinateTargetForMove(BattleHero *);
    Coordinate *enemyCoordinateTargetForAction(BattleHero *);
    Coordinate *closestCoordinateForMove(Coordinate *, std::vector<Path> &pathScope);
    Coordinate *closestCoordinateForAction(Coordinate *, std::vector<Path> &pathScope);
    std::vector<std::pair<int, double >> closestDistance(Coordinate *, std::vector<Path> &pathScope);
    double getDistance(BattleHero *, Coordinate *, bool withAgro = false);
    double getDistance(Coordinate *, Coordinate *);
};

#endif
