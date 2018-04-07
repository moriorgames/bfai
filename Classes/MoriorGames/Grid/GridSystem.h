#ifndef MORIOR_GAMES_GRID_GRID_SYSTEM_H
#define MORIOR_GAMES_GRID_GRID_SYSTEM_H

#include "GridSD.h"
#include "GridHD.h"
#include "GridHDR.h"
#include "../Screen/Coordinate2Screen.h"
#include "../Vendor/Containers/Path.h"

class GridSystem
{
public:
    static const Color4F FILL_COLOR;
    static const Color4F MOVE_FILL_COLOR;
    static const Color4F BORDER_COLOR;
    static const std::string MOVE_NAME;

public:
    GridSystem(Layer *layer);
    Grid *getGrid() const;
    Coordinate2Screen *getCoordinate2Screen() const;
    void drawTile(Coordinate *coordinate, Color4F color, std::string nodeName = "");
    Coordinate *getClosestCoordinate(std::vector<Path> &paths, float x, float y);
    void removeTilesByName(std::string nodeName = "");

private:
    Node *gridTiles = new Node;
    Node *movementTiles = new Node;
    Layer *layer;
    Grid *grid;
    Coordinate2Screen *coordinate2Screen;
    float height = 0;
    float width = 0;

    void displayGrid();
    double getDistance(float x, float y, Coordinate *);
};

#endif
