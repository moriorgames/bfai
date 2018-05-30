#ifndef MORIOR_GAMES_VIEW_LOADING_TITLE_VIEW_H
#define MORIOR_GAMES_VIEW_LOADING_TITLE_VIEW_H

#include "ViewHelper.h"
#include "../Services/FontCreator.h"

class LoadingTitleView: public ViewHelper
{
public:
    const int PADDING_TITLE = 120;

    explicit LoadingTitleView(Layer *layer);
    void setEllipsis(int progress);

private:
    std::string base;
    Label *titleLabel;
    Node *container;
    FontCreator *fontCreator;

    void addView() override;
};

#endif
