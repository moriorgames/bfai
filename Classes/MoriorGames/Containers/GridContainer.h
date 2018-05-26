#ifndef MORIOR_GAMES_CONTAINERS_GRID_CONTAINER_H
#define MORIOR_GAMES_CONTAINERS_GRID_CONTAINER_H

#include "../Grid/GridSD.h"
#include "../Grid/GridHD.h"
#include "../Grid/GridHDR.h"
#include "../Screen/ClosestCoordinate.h"
#include "../Services/TeamSight.h"
#include "../Vendor/Containers/Path.h"
#include "../Vendor/Entity/Battle.h"
#include "../Vendor/Services/PathFinder.h"
#include "../View/Battle/GridView.h"
USING_NS_CC;

class GridContainer
{
public:
    explicit GridContainer(Layer *, Battle *);
    Grid *getGrid() const;
    Coordinate2Screen *getCoordinate2Screen() const;
    ClosestCoordinate *getClosestCoordinate() const;
    PathFinder *getPathFinder() const;
    GridView *getGridView() const;
    TeamSight *getTeamSight() const;

private:
    Layer *layer;
    Grid *grid;
    GridView *gridView;
    Coordinate2Screen *coordinate2Screen;
    ClosestCoordinate *closestCoordinate;
    PathFinder *pathFinder;
    TeamSight *teamSight;
};

#endif
