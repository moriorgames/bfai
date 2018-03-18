#ifndef MORIOR_GAMES_VIEW_BATTLE_BATTLE_BACKGROUND_VIEW_H
#define MORIOR_GAMES_VIEW_BATTLE_BATTLE_BACKGROUND_VIEW_H

#include "../ViewHelper.h"

namespace MoriorGames {

class BattleBackgroundView: public ViewHelper
{
public:
    const float PADDING_BATTLE_FIELD = 231;
    static const std::string NAME;

public:
    explicit BattleBackgroundView(Layer *layer);

private:
    void addView() override;
};

}

#endif