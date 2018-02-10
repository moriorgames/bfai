#include "LogoView.h"
#include "../Services/SoundPlayer.h"

using MoriorGames::LogoView;
using MoriorGames::SoundPlayer;

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
    SoundPlayer::playEffect("s-morior-games.mp3");
}
