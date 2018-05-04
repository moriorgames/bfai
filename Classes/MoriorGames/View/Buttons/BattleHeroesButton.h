#ifndef MORIOR_GAMES_VIEW_BUTTONS_BATTLE_HEROES_BUTTON_H
#define MORIOR_GAMES_VIEW_BUTTONS_BATTLE_HEROES_BUTTON_H

#include "ui/CocosGUI.h"
#include "../ViewHelper.h"

class BattleHeroesButton: public ViewHelper
{
public:
    int const BUTTON_X = 300;
    static const std::string NAME;

public:
    explicit BattleHeroesButton(Layer *layer);

private:
    void addView() override;
};

#endif
