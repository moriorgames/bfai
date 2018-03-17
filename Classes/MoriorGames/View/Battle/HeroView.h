#ifndef MORIOR_GAMES_VIEW_BATTLE_HERO_VIEW_H
#define MORIOR_GAMES_VIEW_BATTLE_HERO_VIEW_H

#include "../ViewHelper.h"
#include "../../Vendor/Entity/Hero.h"
#include "../../Services/SpriteAnimator.h"

namespace MoriorGames {

class HeroView: public ViewHelper
{
public:
    int const WORLD_Y = 20;
    int const DETAIL_Y = 120;
    static const std::string NAME;

public:
    explicit HeroView(Layer *layer, Hero *hero);

private:
    Hero *hero;
    Node *container;
    SpriteAnimator *spriteAnimator;

    void addView() override;
    void addHero();
    Action *idleAction();
    Action *moveAction();
    Action *attackAction();
};

}

#endif
