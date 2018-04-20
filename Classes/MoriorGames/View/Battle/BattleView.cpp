#include "BattleView.h"
#include "../../Containers/BattleContainer.h"
#include "../../EventListeners/BattleEventListener.h"
#include "../../Services/StringFileReader.h"

const std::string BattleView::NAME = "battle-node";

BattleView::BattleView(Layer *layer)
    : ViewHelper(layer)
{
    addView();
}

void BattleView::addView()
{
    auto json = (new StringFileReader)->getStringFromFile("data/battle.json");

    auto battleContainer = new BattleContainer(layer, json);

    new BattleEventListener(
        layer, battleContainer->getBattle(), battleContainer->getEventPublisher(), battleContainer->getGridContainer()
    );
}
