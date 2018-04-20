#ifndef MORIOR_GAMES_VIEW_BATTLE_BATTLE_VIEW_H
#define MORIOR_GAMES_VIEW_BATTLE_BATTLE_VIEW_H

#include "../ViewHelper.h"

class BattleView: public ViewHelper
{
public:
    static const std::string NAME;

public:
    explicit BattleView(Layer *layer);

private:
    void addView() override;
};

#endif
