#ifndef MORIOR_GAMES_VIEW_BATTLE_HERO_VIEW_H
#define MORIOR_GAMES_VIEW_BATTLE_HERO_VIEW_H

#include "../ViewHelper.h"
#include "../../Grid/GridSystem.h"
#include "../../Services/SpriteAnimator.h"
#include "../../Vendor/Observer/BattleObservable.h"
#include "../../Vendor/Entity/BattleHero.h"

class HeroView: public ViewHelper, public BattleObservable
{
public:
    static const Point ANCHOR;

public:
    HeroView(Layer *, GridSystem *, BattleHero *);
    BattleHero *getHero() const;
    void moveTo(Coordinate *);
    void update(BattleAction *) override;

private:
    Node *container;
    GridSystem *gridSystem;
    BattleHero *hero;
    SpriteAnimator *spriteAnimator;

    void addView() override;
    void addHero();
    void addHealthBar();
    Action *idleAction();
    Action *moveAction();
    Action *attackAction();
};

#endif
