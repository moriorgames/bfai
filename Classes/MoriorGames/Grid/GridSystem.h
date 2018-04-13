#ifndef MORIOR_GAMES_GRID_GRID_SYSTEM_H
#define MORIOR_GAMES_GRID_GRID_SYSTEM_H

#include "GridSD.h"
#include "GridHD.h"
#include "GridHDR.h"
#include "../Screen/Coordinate2Screen.h"
#include "../Vendor/Containers/Path.h"
#include "../View/Battle/GridView.h"

class GridSystem
{
public:
    GridSystem(Layer *layer);
    Grid *getGrid() const;
    Coordinate2Screen *getCoordinate2Screen() const;
    GridView *getGridView() const;
    Coordinate *getClosestCoordinate(std::vector<Path> &paths, float x, float y);

private:
    Layer *layer;
    Grid *grid;
    GridView *gridView;
    Coordinate2Screen *coordinate2Screen;

    void displayGrid();
    double getDistance(float x, float y, Coordinate *);
};

#endif
