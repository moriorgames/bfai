#include "BushView.h"
#include "../../Vendor/Config/StaticBushConfig.h"

BushView::BushView(Layer *layer, Coordinate2Screen *coordinate2Screen)
    : ViewHelper(layer), coordinate2Screen{coordinate2Screen}
{
    addView();
}

void BushView::addView()
{
    for (auto coord:StaticBushConfig::get()) {
        auto sprite = Sprite::create("img/bush.png");
        auto position = coordinate2Screen->execute(new Coordinate(coord.first, coord.second));
        sprite->setScale(scale);
        sprite->setPosition(position);
        sprite->setAnchorPoint({0.5, 0.25});
        layer->addChild(sprite, Z_ORDER_HEROES - coord.second - 1);
    }
}
