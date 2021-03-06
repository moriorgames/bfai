#include "BackgroundView.h"
#include "../Services/SoundPlayer.h"

const std::string BackgroundView::NAME = "background-node";

BackgroundView::BackgroundView(Layer *layer)
    : ViewHelper(layer)
{
    addView();
}

void BackgroundView::addView()
{
    auto background = Sprite::create("img/background.jpg");
    background->setScale(scale);
    background->setPosition(centerPosition);
    background->setName(NAME);

    layer->addChild(background, Z_ORDER_BACKGROUND);
    SoundPlayer::playBackgroundMusic("sounds/main-menu-theme.mp3");
}
