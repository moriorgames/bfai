#ifndef MORIOR_GAMES_VIEW_BATTLE_BUSH_VIEW_H
#define MORIOR_GAMES_VIEW_BATTLE_BUSH_VIEW_H

#include "../ViewHelper.h"
#include "../../Screen/Coordinate2Screen.h"

class BushView: public ViewHelper
{
public:
    BushView(Layer *, Coordinate2Screen *);
    void addView() override;

private:
    Coordinate2Screen *coordinate2Screen;
};

#endif
