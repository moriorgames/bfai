#include "LeftFrame.h"

LeftFrame::LeftFrame(Layer *layer)
    : ViewHelper(layer)
{
    addView();
}

void LeftFrame::addView()
{
    auto background = Sprite::create("ui/frame-battle-heroes.png");
    background->setScale(scale);
    background->setPosition(centerPosition);
    background->setPositionX(centerPosition.x - FRAME_X * scale);

    layer->addChild(background, Z_ORDER_BACKGROUND);
}
