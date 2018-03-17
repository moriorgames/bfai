#include "BattleView.h"
#include "BattleBackgroundView.h"
#include "HeroView.h"
#include "../../Grid/GridSystem.h"
#include "../../Services/StringFileReader.h"
#include "../../Vendor/Parsers/HeroParser.h"

using MoriorGames::BattleView;

const std::string BattleView::NAME = "battle-node";

BattleView::BattleView(Layer *layer)
    : ViewHelper(layer)
{
    addView();
}

void BattleView::addView()
{
    new BattleBackgroundView(layer);
    new GridSystem(layer);

    std::string file = "data/heroes.json";
    auto json = (new StringFileReader)->getStringFromFile(file);
    auto parser = new HeroParser(json);
    for (auto hero:parser->parse()) {
        new HeroView(layer, hero);
    }
}
