#include "RightFrame.h"

RightFrame::RightFrame(Layer *layer)
    : ViewHelper(layer)
{
    addView();
}

void RightFrame::addView()
{
    auto background = Sprite::create("ui/frame-battle-heroes.png");
    background->setScale(scale);
    background->setPosition(centerPosition);
    background->setPositionX(centerPosition.x + FRAME_X * scale);

    layer->addChild(background, Z_ORDER_BACKGROUND);
}
