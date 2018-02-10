#include "BackgroundView.h"
#include "../Services/SoundPlayer.h"

using MoriorGames::BackgroundView;
using MoriorGames::SoundPlayer;

const std::string BackgroundView::BACKGROUND_NAME = "background-node";

BackgroundView::BackgroundView(Layer *layer)
    : ViewHelper(layer)
{
    addView();
}

void BackgroundView::addView()
{
    auto background = Sprite::create("img-background.jpg");
    background->setScale(scale);
    background->setPosition(centerPosition);
    background->setName(BACKGROUND_NAME);

    layer->addChild(background, Z_ORDER_BACKGROUND);
    SoundPlayer::playBackgroundMusic("s-main-menu-theme.mp3");
}
