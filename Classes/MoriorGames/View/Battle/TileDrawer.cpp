#include "TileDrawer.h"

TileDrawer::TileDrawer(float size, Coordinate2Screen *coordinate2Screen)
    : size{size}, coordinate2Screen{coordinate2Screen}
{
}

void TileDrawer::draw(Coordinate *coordinate, Color4F color, Node *node)
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