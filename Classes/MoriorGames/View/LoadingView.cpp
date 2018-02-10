#include "LoadingView.h"

using MoriorGames::LoadingView;

const std::string LoadingView::LOADING_BAR_NAME = "loading-bar";

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

//    addTipLabel();
    addLoadingBar();
//    addLoadingText();

    layer->addChild(container, Z_ORDER_MENU_ITEMS);
}

void LoadingView::addLoadingBar()
{
    auto bottomPosition = position->getBottomCenteredPosition();
    auto loadingBarNode = new Node;

    // Loading Background Bar
    auto backgroundBar = Sprite::create("asset-loader-bar-border.png");

    // Loading Foreground Bar
    auto foregroundBar = Sprite::create("asset-loader-bar.png");

    loadingBar = new ProgressTimer;
    loadingBar->initWithSprite(foregroundBar);
    loadingBar->setName(LOADING_BAR_NAME);
    loadingBar->setType(ProgressTimer::Type::BAR);
    loadingBar->setMidpoint(Point(0, 0));
    loadingBar->setBarChangeRate(Point(1, 0));
    loadingBar->setPercentage(0);

    loadingBarNode->setPosition(bottomPosition.x, PADDING_LOADING_BAR * scale);
    loadingBarNode->addChild(backgroundBar);
    loadingBarNode->addChild(loadingBar);
    loadingBarNode->setScale(scale);

    container->addChild(loadingBarNode, Z_ORDER_MENU_ITEMS);
}
