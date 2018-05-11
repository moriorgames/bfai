#ifndef MORIOR_GAMES_VIEW_BATTLE_HEROES_TOP_HUD_H
#define MORIOR_GAMES_VIEW_BATTLE_HEROES_TOP_HUD_H

#include "ui/CocosGUI.h"
#include "../ViewHelper.h"
#include "../../Services/FontCreator.h"

class TopHud: public ViewHelper
{
public:
    int const ITEM_X = 900;
    int const ITEM_Y = -70;

    explicit TopHud(Layer *layer);

private:
    Node *node;
    FontCreator *fontCreator;

    void addView() override;
    void addResetButton();
};

#endif
