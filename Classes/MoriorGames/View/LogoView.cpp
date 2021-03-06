#include "LogoView.h"
#include "../Services/SoundPlayer.h"

LogoView::LogoView(Layer *layer)
    : ViewHelper(layer)
{
    addView();
}

void LogoView::addView()
{
    auto logo = Sprite::create("img/main-logo.png");
    logo->setScale(scale);
    logo->setPosition(centerPosition);

    layer->addChild(logo, Z_ORDER_BACKGROUND);
    SoundPlayer::playEffect("sounds/morior-games-effect.mp3");
}
