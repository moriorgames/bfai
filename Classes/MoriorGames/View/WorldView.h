#ifndef MORIOR_GAMES_VIEW_LOADING_VIEW_H
#define MORIOR_GAMES_VIEW_LOADING_VIEW_H

#include "ViewHelper.h"
#include "../Services/SpriteAnimator.h"

namespace MoriorGames {

class WorldView: public ViewHelper
{
public:
    int const WORLD_Y = 20;
    int const DETAIL_Y = 120;
    static const std::string NAME;

public:
    explicit WorldView(Layer *layer);

private:
    Node *container;
    SpriteAnimator *spriteAnimator;

    void addView() override;
    void addWorld();
    Action *detailAction();
};

}

#endif
