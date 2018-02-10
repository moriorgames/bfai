#ifndef MORIOR_GAMES_VIEW_LOADING_VIEW_H
#define MORIOR_GAMES_VIEW_LOADING_VIEW_H

#include "ViewHelper.h"

namespace MoriorGames {

class LoadingView: public ViewHelper
{
public:
    explicit LoadingView(Layer *layer);

private:
    Node *container;
    ProgressTimer *loadingBar;

    void addView() override;
};

}

#endif
