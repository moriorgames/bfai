#ifndef MORIOR_GAMES_VIEW_BATTLE_HEROES_LEFT_FRAME_H
#define MORIOR_GAMES_VIEW_BATTLE_HEROES_LEFT_FRAME_H

#include "../ViewHelper.h"

class LeftFrame: public ViewHelper
{
public:
    int const FRAME_X = 500;

    explicit LeftFrame(Layer *);

private:
    void addView() override;
};

#endif
