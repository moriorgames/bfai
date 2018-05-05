#ifndef MORIOR_GAMES_VIEW_BATTLE_HEROES_RIGHT_FRAME_H
#define MORIOR_GAMES_VIEW_BATTLE_HEROES_RIGHT_FRAME_H

#include "../ViewHelper.h"

class RightFrame: public ViewHelper
{
public:
    int const FRAME_X = 500;

    explicit RightFrame(Layer *);

private:
    void addView() override;
};

#endif
