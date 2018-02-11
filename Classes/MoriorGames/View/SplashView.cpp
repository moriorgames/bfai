#include "SplashView.h"

using MoriorGames::SplashView;

SplashView::SplashView(Layer *layer)
    : ViewHelper(layer)
{
    addView();
}

void SplashView::addView()
{
    auto splashScreen = Sprite::create("img/splash-screen.jpg");
    splashScreen->setScale(scale);
    splashScreen->setPosition(centerPosition);

    layer->addChild(splashScreen, Z_ORDER_BACKGROUND);
}
