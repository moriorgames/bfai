#include "BattleView.h"
#include "BattleBackgroundView.h"
#include "../../EventListeners/BattleEventListener.h"
#include "../../Grid/GridSystem.h"
#include "../../Services/StringFileReader.h"
#include "../../Vendor/Parsers/HeroParser.h"
#include "../../Vendor/Repository/HeroRepository.h"
#include "../../Vendor/Services/PathFinder.h"

const std::string BattleView::NAME = "battle-node";

BattleView::BattleView(Layer *layer)
    : ViewHelper(layer)
{
    addView();
}

void BattleView::addView()
{
    auto json = (new StringFileReader)->getStringFromFile("data/battle.json");
    new BattleBackgroundView(layer);

    battleContainer = new BattleContainer(layer, json);

    new BattleEventListener(layer, battleContainer);
}
