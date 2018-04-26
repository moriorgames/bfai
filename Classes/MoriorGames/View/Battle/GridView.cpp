#include "GridView.h"
#include "../../Definitions.h"

const Color4F GridView::FILL_COLOR{0, 0, 0, 0};

const Color4F GridView::MOVE_FILL_COLOR{.2f, 1, .2f, .3f};

const Color4F GridView::ATTACK_FILL_COLOR{1, .2f, .2f, .3f};

const Color4F GridView::BORDER_COLOR{0, 0, 0, .05f};

GridView::GridView(Layer *layer,
                   Battle *battle,
                   PathFinder *pathFinder,
                   Coordinate2Screen *coordinate2Screen,
                   float size)
    : layer{layer}, battle{battle}, pathFinder{pathFinder}, coordinate2Screen{coordinate2Screen}, size{size}
{
    layer->addChild(gridTiles, Z_ORDER_GRID);
    layer->addChild(actionTiles, Z_ORDER_GRID);
}

void GridView::drawTile(Coordinate *coordinate, Color4F color, Node *node)
{
    auto drawNode = DrawNode::create();
    auto screenVec2 = coordinate2Screen->execute(coordinate);

    Vec2 rectangle[4];
    rectangle[0] = Vec2(screenVec2.x + size, screenVec2.y + size);
    rectangle[1] = Vec2(screenVec2.x - size, screenVec2.y + size);
    rectangle[2] = Vec2(screenVec2.x - size, screenVec2.y - size);
    rectangle[3] = Vec2(screenVec2.x + size, screenVec2.y - size);

    drawNode->drawPolygon(rectangle, 4, color, 1, BORDER_COLOR);
    node->addChild(drawNode);
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
