#include "LoadingTitleView.h"

LoadingTitleView::LoadingTitleView(Layer *layer)
    : ViewHelper(layer)
{
    addView();
}

void LoadingTitleView::setEllipsis(int progress)
{
    std::string text;
    if (progress % 6 <= 1) {
        text = base + "...";
    } else if (progress % 6 <= 3) {
        text = base + "..";
    } else {
        text = base + ".";
    }
    titleLabel->setString(text);
}

void LoadingTitleView::addView()
{
    fontCreator = new FontCreator;
    base = translator->tr("match_maker_looking_for_rivals");
    container = new Node;
    auto bottomPosition = position->getCenterBotPosition();

    titleLabel = fontCreator->titleLabel(base, "fonts/title.otf", 45);
    titleLabel->setAnchorPoint({0, 0});
    titleLabel->setScale(scale);
    titleLabel->setPositionX(bottomPosition.x - PADDING_TITLE * scale);
    titleLabel->setPositionY(PADDING_TITLE * scale);
    container->addChild(titleLabel);

    layer->addChild(container, Z_ORDER_MENU_ITEMS);
}
