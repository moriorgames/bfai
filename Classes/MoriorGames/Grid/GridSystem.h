#ifndef MORIOR_GAMES_GRID_GRID_SYSTEM_H
#define MORIOR_GAMES_GRID_GRID_SYSTEM_H

#include "GridSD.h"
#include "GridHD.h"
#include "GridHDR.h"
#include "../Screen/ClosestCoordinate.h"
#include "../Vendor/Containers/Path.h"
#include "../View/Battle/GridView.h"

class GridSystem
{
public:
    GridSystem(Layer *layer);
    Grid *getGrid() const;
    Coordinate2Screen *getCoordinate2Screen() const;
    ClosestCoordinate *getClosestCoordinate() const;
    GridView *getGridView() const;

private:
    Layer *layer;
    Grid *grid;
    GridView *gridView;
    Coordinate2Screen *coordinate2Screen;
    ClosestCoordinate *closestCoordinate;

    void displayGrid();
};

#endif
