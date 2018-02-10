#include "LoadingView.h"

using MoriorGames::LoadingView;

LoadingView::LoadingView(Layer *layer)
    : ViewHelper(layer)
{
    addView();
}

void LoadingView::addView()
{
    container = new Node;

//    addTipLabel();
//    addLoadingBar();
//    addLoadingText();

    layer->addChild(container, Z_ORDER_MENU_ITEMS);
}
