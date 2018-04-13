#ifndef MORIOR_GAMES_VIEW_BATTLE_GRID_VIEW_H
#define MORIOR_GAMES_VIEW_BATTLE_GRID_VIEW_H

#include "cocos2d.h"
#include "../../Screen/Coordinate2Screen.h"
#include "../../Vendor/ValueObjects/Coordinate.h"
#include "../../Vendor/Observer/BattleObservable.h"
USING_NS_CC;

class GridView: public BattleObservable
{
public:
    static const Color4F FILL_COLOR;
    static const Color4F MOVE_FILL_COLOR;
    static const Color4F BORDER_COLOR;
    static const std::string MOVE_NAME;

public:
    GridView(Layer *, Coordinate2Screen *, float size);
    void drawTile(Coordinate *coordinate, Color4F color, std::string nodeName = "");
    void removeTilesByName(std::string nodeName);
    void update(BattleAction *) override;

private:
    Layer *layer;
    Coordinate2Screen *coordinate2Screen;
    float size = 0;
    Node *gridTiles = new Node;
    Node *movementTiles = new Node;
};

#endif
