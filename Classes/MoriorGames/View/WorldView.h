#ifndef MORIOR_GAMES_VIEW_LOADING_VIEW_H
#define MORIOR_GAMES_VIEW_LOADING_VIEW_H

#include "ViewHelper.h"

namespace MoriorGames {

class WorldView: public ViewHelper
{
public:
    int const DETAIL_Y = 30;
    static const std::string WORLD_NAME;

public:
    explicit WorldView(Layer *layer);

private:
    Node *container;

    void addView() override;
    void addWorld();
    Action *detailAction();
};

}

#endif
