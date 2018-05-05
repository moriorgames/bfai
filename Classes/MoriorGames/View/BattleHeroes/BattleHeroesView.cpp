#include "BattleHeroesView.h"
#include "../Buttons/MainMenuButton.h"

BattleHeroesView::BattleHeroesView(Layer *layer)
    : ViewHelper(layer)
{
    addView();
}

void BattleHeroesView::addView()
{
    new MainMenuButton(layer);
}
