#include "BattleHeroesView.h"
#include "LeftFrame.h"
#include "RightFrame.h"
#include "../Buttons/MainMenuButton.h"

BattleHeroesView::BattleHeroesView(Layer *layer)
    : ViewHelper(layer)
{
    addView();
}

void BattleHeroesView::addView()
{
    new MainMenuButton(layer);
    addFrames();
}

void BattleHeroesView::addFrames()
{
    new LeftFrame(layer);
    new RightFrame(layer);
}
