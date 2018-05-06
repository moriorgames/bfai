#include "BattleHeroesView.h"
#include "LeftFrame.h"
#include "RightFrame.h"
#include "TopHud.h"

BattleHeroesView::BattleHeroesView(Layer *layer)
    : ViewHelper(layer)
{
    addView();
}

void BattleHeroesView::addView()
{
    new TopHud(layer);
    addFrames();
}

void BattleHeroesView::addFrames()
{
    new LeftFrame(layer);
    new RightFrame(layer);
}
