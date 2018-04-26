#include "GridView.h"
#include "../../Definitions.h"

const Color4F GridView::FILL_COLOR{0, 0, 0, 0};

const Color4F GridView::MOVE_FILL_COLOR{.2f, 1, .2f, .3f};

const Color4F GridView::ATTACK_FILL_COLOR{1, .2f, .2f, .3f};

GridView::GridView(Layer *layer, Battle *battle, PathFinder *pathFinder, TileDrawer *tileDrawer)
    : layer{layer}, battle{battle}, pathFinder{pathFinder}, tileDrawer{tileDrawer}
{
    layer->addChild(gridTiles, Z_ORDER_GRID);
    layer->addChild(actionTiles, Z_ORDER_GRID);
}

void GridView::drawTile(Coordinate *coordinate, Color4F color, Node *node)
{
    tileDrawer->draw(coordinate, color, node);
}

void GridView::buildGrid(const std::vector<Coordinate *> &coordinates)
{
    for (auto coordinate:coordinates) {
        drawTile(coordinate, GridView::FILL_COLOR, gridTiles);
    }
}

void GridView::buildPathForMove(BattleHero *battleHero)
{
    for (auto path:pathFinder->buildPathScope(battleHero)) {
        drawTile(path.coordinate, GridView::MOVE_FILL_COLOR, actionTiles);
    }
}

void GridView::buildPathForAction(BattleHero *battleHero)
{
    for (auto path:pathFinder->buildPathScope(battleHero)) {
        drawTile(path.coordinate, GridView::ATTACK_FILL_COLOR, actionTiles);
    }
}

void GridView::removeActionGrid()
{
    actionTiles->removeAllChildren();
}

void GridView::update(BattleAction *)
{
    removeActionGrid();
    buildPathScopeView();
}

void GridView::buildPathScopeView()
{
    for (auto path:pathFinder->buildPathScope(battle->getActiveBattleHero())) {
        drawTile(path.coordinate, GridView::MOVE_FILL_COLOR, actionTiles);
    }
}
