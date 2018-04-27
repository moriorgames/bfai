#ifndef MORIOR_GAMES_VIEW_BATTLE_HERO_VIEW_H
#define MORIOR_GAMES_VIEW_BATTLE_HERO_VIEW_H

#include "HeroAnimator.h"
#include "../ViewHelper.h"
#include "../../Screen/Coordinate2Screen.h"
#include "../../Vendor/Observer/BattleObservable.h"
#include "../../Vendor/Entity/BattleHero.h"

class HeroView: public ViewHelper, public BattleObservable
{
public:
    HeroView(Layer *, Coordinate2Screen *, BattleHero *);
    void update(BattleAction *) override;

private:
    Node *container;
    Node *hitPoints;
    Coordinate2Screen *coordinate2Screen;
    BattleHero *battleHero;
    HeroAnimator *heroAnimator;

    void addView() override;
    void addHero();
    void buildHealthBar();
};

#endif
