#ifndef MORIOR_GAMES_VIEW_BUTTONS_BATTLE_BUTTON_H
#define MORIOR_GAMES_VIEW_BUTTONS_BATTLE_BUTTON_H

#include "ui/CocosGUI.h"
#include "../ViewHelper.h"

class BattleButton: public ViewHelper
{
public:
    float const BUTTON_X = -300;
    float const BUTTON_Y = 0;

    explicit BattleButton(Layer *layer);

private:
    void addView() override;
};

#endif
