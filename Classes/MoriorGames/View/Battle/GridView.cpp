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

void GridView::buildPathForMove(BattleHero *hero)
{
    for (auto path:pathFinder->buildPathScope(hero->getCoordinate(), hero->getMovement(), true)) {
        drawTile(path.coordinate, GridView::MOVE_FILL_COLOR, actionTiles);
    }
}

void GridView::buildPathForAction(BattleHero *hero)
{
    for (auto path:pathFinder->buildPathScope(hero->getCoordinate(), hero->getRanged())) {
        drawTile(path.coordinate, GridView::ATTACK_FILL_COLOR, actionTiles);
    }
}

void GridView::buildPathForSkill(BattleHero *hero, Skill *skill)
{
    for (auto path:pathFinder->buildPathScope(hero->getCoordinate(), skill->getRanged(), true)) {
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
    auto battleHero = battle->getActiveBattleHero();
    if (!battleHero->hasMoved()) {
        buildPathForMove(battleHero);
    } else {
        buildPathForAction(battleHero);
    }
}
