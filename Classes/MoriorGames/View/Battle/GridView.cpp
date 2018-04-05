#include "GridView.h"
#include "../../Definitions.h"

const Color4F GridView::FILL_COLOR{0, 0, 0, 0};

const Color4F GridView::MOVE_FILL_COLOR{.2f, 1, .2f, .3f};

const Color4F GridView::BORDER_COLOR{0, 0, 0, .15f};

const std::string GridView::MOVE_NAME = "movement-node";

GridView::GridView(Layer *layer, Coordinate2Screen *coordinate2Screen)
    : layer{layer}, coordinate2Screen{coordinate2Screen}
{
    layer->addChild(gridTiles, Z_ORDER_GRID);
    layer->addChild(movementTiles, Z_ORDER_GRID);
}

void GridView::drawTile(Coordinate *coordinate, Color4F color, std::string nodeName)
{
    auto node = gridTiles;
    if (nodeName == MOVE_NAME) {
        node = movementTiles;
    }
    auto drawNode = DrawNode::create();
    auto screenVec2 = coordinate2Screen->execute(coordinate);

    Vec2 rectangle[4];
    rectangle[0] = Vec2(screenVec2.x + width, screenVec2.y + height);
    rectangle[1] = Vec2(screenVec2.x - width, screenVec2.y + height);
    rectangle[2] = Vec2(screenVec2.x - width, screenVec2.y - height);
    rectangle[3] = Vec2(screenVec2.x + width, screenVec2.y - height);

    drawNode->drawPolygon(rectangle, 4, color, 1, BORDER_COLOR);
    node->addChild(drawNode);
}