#ifndef MORIOR_GAMES_VIEW_BATTLE_HEROES_BATTLE_HEROES_VIEW_H
#define MORIOR_GAMES_VIEW_BATTLE_HEROES_BATTLE_HEROES_VIEW_H

#include "../ViewHelper.h"

class BattleHeroesView: public ViewHelper
{
public:
    int const FRAME_X = 500;

    explicit BattleHeroesView(Layer *);

private:
    void addView() override;
    void addFrames();
};

#endif
