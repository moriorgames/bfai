#ifndef MORIOR_GAMES_VIEW_BATTLE_HERO_HIT_POINTS_VIEW_H
#define MORIOR_GAMES_VIEW_BATTLE_HERO_HIT_POINTS_VIEW_H

#include "cocos2d.h"
#include "../../Vendor/Entity/BattleHero.h"
USING_NS_CC;

class HeroHitPointsView
{
public:
    explicit HeroHitPointsView(BattleHero *);
    void addHitPoints(Node *);
    void update();

private:
    BattleHero *battleHero;
    ProgressTimer *hitPoints;
};

#endif
