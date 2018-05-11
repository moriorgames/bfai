#include "HeroesConfigView.h"
#include "LeftFrame.h"
#include "RightFrame.h"
#include "TopHud.h"

HeroesConfigView::HeroesConfigView(Layer *layer)
    : ViewHelper(layer)
{
    addView();
}

void HeroesConfigView::addView()
{
    new TopHud(layer);
    addFrames();
}

void HeroesConfigView::addFrames()
{
    new LeftFrame(layer);
    new RightFrame(layer);
}
