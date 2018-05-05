#ifndef MORIOR_GAMES_VIEW_BUTTONS_MAIN_MENU_BUTTON_H
#define MORIOR_GAMES_VIEW_BUTTONS_MAIN_MENU_BUTTON_H

#include "ui/CocosGUI.h"
#include "../ViewHelper.h"

class MainMenuButton: public ViewHelper
{
public:
    int const BUTTON_X = 120;
    int const BUTTON_Y = -70;

    explicit MainMenuButton(Layer *layer);

private:
    void addView() override;
};

#endif
