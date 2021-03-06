#ifndef MORIOR_GAMES_VIEW_BATTLE_BATTLE_BACKGROUND_VIEW_H
#define MORIOR_GAMES_VIEW_BATTLE_BATTLE_BACKGROUND_VIEW_H

#include "../ViewHelper.h"

class BattleBackgroundView: public ViewHelper
{
public:
    const float PADDING_BATTLE_FIELD = 231;
    const float PADDING_MIDDLE_OBSTACLE = 640;
    const float PADDING_NEXUS = 830;
    const Point ANCHOR_NEXUS = {.54f, .58f};
    static const std::string NAME;

public:
    explicit BattleBackgroundView(Layer *layer);

private:
    void addView() override;
};

#endif
