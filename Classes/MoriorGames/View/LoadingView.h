#ifndef MORIOR_GAMES_VIEW_LOADING_VIEW_H
#define MORIOR_GAMES_VIEW_LOADING_VIEW_H

#include "ViewHelper.h"

namespace MoriorGames {

class LoadingView: public ViewHelper
{
public:
    const int PADDING_BOTTOM = 50;
    const int TIPS = 7;
    const int PADDING_BOTTOM_TEXT = 100;
    const int PADDING_LOADING_BAR = 120;
    static const std::string LOADING_BAR_NAME;

public:
    explicit LoadingView(Layer *layer);
    void setLoadingBarPercentage(float percentage);

private:
    Node *container;
    ProgressTimer *loadingBar;

    void addLoadingBar();

    void addView() override;
};

}

#endif
