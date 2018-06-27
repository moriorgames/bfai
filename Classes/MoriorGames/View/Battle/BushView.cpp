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
        std::string img = "img/bush1.png";
        if (coord.first % 2 != 0) {
            img = "img/bush2.png";
        }
        auto sprite = Sprite::create(img);
        auto position = coordinate2Screen->execute(new Coordinate(coord.first, coord.second));
        sprite->setScale(scale);
        sprite->setPosition(position);
        sprite->setAnchorPoint({0.5, 0.25});
        if (coord.second < 0) {
            sprite->setFlippedX(true);
        }
        layer->addChild(sprite, Z_ORDER_HEROES - coord.second);
    }
}
