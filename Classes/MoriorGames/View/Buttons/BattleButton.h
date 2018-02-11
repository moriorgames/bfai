#ifndef MORIOR_GAMES_VIEW_BUTTONS_BATTLE_BUTTON_H
#define MORIOR_GAMES_VIEW_BUTTONS_BATTLE_BUTTON_H

#include "ui/CocosGUI.h"
#include "../ViewHelper.h"

namespace MoriorGames {

class BattleButton: public ViewHelper
{
public:
    int const BUTTON_Y = -110;
    static const std::string NAME;

public:
    explicit BattleButton(Layer *layer);

private:
    void addView() override;
};

}

#endif
