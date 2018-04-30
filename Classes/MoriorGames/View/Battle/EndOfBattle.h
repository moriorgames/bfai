#ifndef MORIOR_GAMES_VIEW_BATTLE_END_OF_BATTLE_H
#define MORIOR_GAMES_VIEW_BATTLE_END_OF_BATTLE_H

#include "../ViewHelper.h"

class EndOfBattle: public ViewHelper
{
public:
    explicit EndOfBattle(Layer *layer);

private:
    void addView() override;
};

#endif
