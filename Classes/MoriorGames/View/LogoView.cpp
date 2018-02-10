#include "LogoView.h"

using MoriorGames::LogoView;

LogoView::LogoView(Layer *layer)
    : ViewHelper(layer)
{
}

void LogoView::addLogo()
{
    auto logo = Sprite::create("main-logo.png");
    logo->setScale(scale);
    logo->setPosition(centerPosition);

    layer->addChild(logo, Z_ORDER_BACKGROUND);
}
