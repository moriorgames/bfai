#ifndef MORIOR_GAMES_VIEW_BATTLE_HERO_VIEW_H
#define MORIOR_GAMES_VIEW_BATTLE_HERO_VIEW_H

#include "../ViewHelper.h"
#include "../../Grid/GridSystem.h"
#include "../../Services/SpriteAnimator.h"
#include "../../Vendor/Entity/BattleHero.h"

namespace MoriorGames {

class HeroView: public ViewHelper
{
public:
    static const Point ANCHOR;

public:
    HeroView(Layer *, GridSystem *, BattleHero *);

private:
    GridSystem *gridSystem;
    BattleHero *hero;
    Node *container;
    SpriteAnimator *spriteAnimator;

    void addView() override;
    void addHero();
    void addHealthBar();
    Action *idleAction();
    Action *moveAction();
    Action *attackAction();
};

}

#endif
