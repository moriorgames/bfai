#include "GridView.h"
#include "../../Definitions.h"

const Color4F GridView::FILL_COLOR{0, 0, 0, 0};

const Color4F GridView::MOVE_FILL_COLOR{.2f, 1, .2f, .3f};

const Color4F GridView::ATTACK_FILL_COLOR{1, .2f, .2f, .3f};

const Color4F GridView::HIDDEN_COLOR{0, 0, 0, .25f};

GridView::GridView(Layer *layer, Battle *battle, PathFinder *pathFinder, TileDrawer *tileDrawer)
    : layer{layer}, battle{battle}, pathFinder{pathFinder}, tileDrawer{tileDrawer}
{
    pathBuilder = new PathBuilder(pathFinder);
    actionTiles->setCascadeOpacityEnabled(true);

    layer->addChild(gridTiles, Z_ORDER_GRID);
    layer->addChild(actionTiles, Z_ORDER_GRID);
    layer->addChild(hiddenTiles, Z_ORDER_HIDDEN);
}

void GridView::drawTile(Coordinate *coordinate, Color4F color, Node *node)
{
    tileDrawer->draw(coordinate, color, node);
}

void GridView::drawGrid(const std::vector<Coordinate *> &coordinates)
{
    for (auto coordinate:coordinates) {
        drawTile(coordinate, GridView::FILL_COLOR, gridTiles);
    }
}

void GridView::drawHiddenArea(const std::vector<Coordinate *> &coordinates)
{
    hiddenTiles->removeAllChildren();
    for (auto coordinate:coordinates) {
        drawTile(coordinate, GridView::HIDDEN_COLOR, hiddenTiles);
    }
}

void GridView::drawPath(Skill *skill, BattleHero *battleHero)
{
    auto pathScope = pathBuilder->build(skill, battleHero);
    auto color = GridView::MOVE_FILL_COLOR;
    if (skill->getId() != Skill::MOVE_ID) {
        color = GridView::ATTACK_FILL_COLOR;
    }
    for (auto path:pathScope) {
        drawTile(path.coordinate, color, actionTiles);
    }
}

void GridView::removeActionGrid()
{
    actionTiles->removeAllChildren();
}

void GridView::hideActionTiles()
{
    actionTiles->setOpacity(0);
}

void GridView::showActionTiles()
{
    actionTiles->setOpacity(255);
}

void GridView::update(BattleAction *)
{
    removeActionGrid();
    buildPathScopeView();
}

void GridView::buildPathScopeView()
{
    auto battleHero = battle->getActiveBattleHero();
    auto skill = new Skill;
    if (!battleHero->hasMoved()) {
        skill->setId(Skill::MOVE_ID);
        drawPath(skill, battleHero);
    } else {
        skill->setId(Skill::SINGLE_ATTACK_ID);
        drawPath(skill, battleHero);
    }
}
