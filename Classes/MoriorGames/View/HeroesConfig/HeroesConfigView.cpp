#include "HeroesConfigView.h"
#include "LeftFrame.h"
#include "RightFrame.h"
#include "TopHud.h"
#include "../../Services/HeroesConfigProcessor.h"
#include "../../Services/HeroesConfigPublisher.h"

HeroesConfigView::HeroesConfigView(Layer *layer)
    : ViewHelper(layer)
{
    addView();
}

void HeroesConfigView::addView()
{
    auto heroesConfigProcessor = new HeroesConfigProcessor;
    auto publisher = new HeroesConfigPublisher;
    auto topHud = new TopHud(layer, publisher);
    auto rightFrame = new RightFrame(layer, publisher);
    auto leftFrame = new LeftFrame(layer, publisher);

    publisher->registerObserver(heroesConfigProcessor);
    publisher->registerObserver(topHud);
    publisher->registerObserver(rightFrame);
    publisher->registerObserver(leftFrame);
}
