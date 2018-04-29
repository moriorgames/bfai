#ifndef MORIOR_GAMES_VIEW_BATTLE_HERO_VIEW_H
#define MORIOR_GAMES_VIEW_BATTLE_HERO_VIEW_H

#include "HeroAnimator.h"
#include "HeroHitPointsView.h"
#include "../ViewHelper.h"
#include "../../Screen/Coordinate2Screen.h"
#include "../../Vendor/Observer/BattleObservable.h"
#include "../../Vendor/Entity/BattleHero.h"

class HeroView: public ViewHelper, public BattleObservable
{
public:
    HeroView(Layer *, BattleHero *, Coordinate2Screen *);
    void update(BattleAction *) override;

private:
    Node *container;
    BattleHero *battleHero;
    Coordinate2Screen *coordinate2Screen;
    HeroAnimator *heroAnimator;
    HeroHitPointsView *heroHitPointsView;

    void addView() override;
    void addHero();
    void setLocalZOrder();
};

#endif
