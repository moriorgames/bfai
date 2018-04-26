#ifndef MORIOR_GAMES_VIEW_BATTLE_GRID_VIEW_H
#define MORIOR_GAMES_VIEW_BATTLE_GRID_VIEW_H

#include "cocos2d.h"
#include "../../Screen/Coordinate2Screen.h"
#include "../../Vendor/Observer/BattleObservable.h"
#include "../../Vendor/Entity/BattleHero.h"
#include "../../Vendor/Services/PathFinder.h"
#include "../../Vendor/ValueObjects/Coordinate.h"
USING_NS_CC;

class GridView: public BattleObservable
{
public:
    static const Color4F FILL_COLOR;
    static const Color4F MOVE_FILL_COLOR;
    static const Color4F ATTACK_FILL_COLOR;
    static const Color4F BORDER_COLOR;

public:
    GridView(Layer *, PathFinder *, Coordinate2Screen *, float size);
    void drawTile(Coordinate *coordinate, Color4F color, Node *);
    void buildGrid(const std::vector<Coordinate *> &coordinates);
    void buildPathForMove(BattleHero *);
    void buildPathForAction(BattleHero *);
    void removeActionGrid();
    void update(BattleAction *) override;

private:
    Layer *layer;
    PathFinder *pathFinder;
    Coordinate2Screen *coordinate2Screen;
    float size = 0;
    Node *gridTiles = new Node, *actionTiles = new Node;

    void buildPathScopeView();
};

#endif
