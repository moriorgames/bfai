#ifndef MORIOR_GAMES_VIEW_BATTLE_BATTLE_VIEW_H
#define MORIOR_GAMES_VIEW_BATTLE_BATTLE_VIEW_H

#include "../ViewHelper.h"
#include "HeroView.h"

namespace MoriorGames {

class BattleView: public ViewHelper
{
public:
    static const std::string NAME;

public:
    explicit BattleView(Layer *layer);

private:
    std::vector<HeroView *> heroViews;
    void addView() override;
};

}

#endif
