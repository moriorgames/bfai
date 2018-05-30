#ifndef MORIOR_GAMES_VIEW_LOADING_VIEW_H
#define MORIOR_GAMES_VIEW_LOADING_VIEW_H

#include "ViewHelper.h"

class LoadingView: public ViewHelper
{
public:
    const int PADDING_LOADING_BAR = 120;

    explicit LoadingView(Layer *layer);
    void setLoadingBarPercentage(float percentage);

private:
    Node *container;
    ProgressTimer *loadingBar;

    void addView() override;
};

#endif
