#ifndef MORIOR_GAMES_VIEW_HEROES_CONFIG_HEROES_CONFIG_VIEW_H
#define MORIOR_GAMES_VIEW_HEROES_CONFIG_HEROES_CONFIG_VIEW_H

#include "../ViewHelper.h"

class HeroesConfigView: public ViewHelper
{
public:
    int const FRAME_X = 500;

    explicit HeroesConfigView(Layer *);

private:
    void addView() override;
    void addTopHud();
    void addFrames();
};

#endif
