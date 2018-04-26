#ifndef MORIOR_GAMES_VIEW_BATTLE_HERO_VIEW_H
#define MORIOR_GAMES_VIEW_BATTLE_HERO_VIEW_H

#include "../ViewHelper.h"
#include "../../Services/SpriteAnimator.h"
#include "../../Screen/Coordinate2Screen.h"
#include "../../Vendor/Observer/BattleObservable.h"
#include "../../Vendor/Entity/BattleHero.h"

class HeroView: public ViewHelper, public BattleObservable
{
public:
    static const Point ANCHOR;

public:
    HeroView(Layer *, Coordinate2Screen *, BattleHero *);
    void stop();
    void moveTo(Coordinate *);
    void action();
    void update(BattleAction *) override;

private:
    Node *container;
    Sprite *heroSprite;
    Coordinate2Screen *coordinate2Screen;
    BattleHero *battleHero;
    SpriteAnimator *spriteAnimator;

    void addView() override;
    void addHero();
    void addHealthBar();
    Action *moveAction();
    Action *attackAction();
};

#endif
