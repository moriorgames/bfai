#include "LoadingView.h"

LoadingView::LoadingView(Layer *layer)
    : ViewHelper(layer)
{
    addView();
}

void LoadingView::setLoadingBarPercentage(float percentage)
{
    loadingBar->setPercentage(percentage);
}

void LoadingView::addView()
{
    container = new Node;
    auto bottomPosition = position->getCenterBotPosition();
    auto loadingBarNode = new Node;

    // Loading Background Bar
    auto backgroundBar = Sprite::create("ui/loader-bar-border.png");

    // Loading Foreground Bar
    auto foregroundBar = Sprite::create("ui/loader-bar.png");

    loadingBar = new ProgressTimer;
    loadingBar->initWithSprite(foregroundBar);
    loadingBar->setType(ProgressTimer::Type::BAR);
    loadingBar->setMidpoint(Point(0, 0));
    loadingBar->setBarChangeRate(Point(1, 0));
    loadingBar->setPercentage(0);

    loadingBarNode->setPosition(bottomPosition.x, PADDING_LOADING_BAR * scale);
    loadingBarNode->addChild(backgroundBar);
    loadingBarNode->addChild(loadingBar);
    loadingBarNode->setScale(scale);
    container->addChild(loadingBarNode);

    layer->addChild(container, Z_ORDER_MENU_ITEMS);
}
