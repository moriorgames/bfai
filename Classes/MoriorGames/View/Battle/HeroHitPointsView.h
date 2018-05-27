#ifndef MORIOR_GAMES_VIEW_BATTLE_HERO_HIT_POINTS_VIEW_H
#define MORIOR_GAMES_VIEW_BATTLE_HERO_HIT_POINTS_VIEW_H

#include "cocos2d.h"
#include "../../Vendor/Entity/BattleHero.h"
#include "../../Services/FontCreator.h"
USING_NS_CC;

class HeroHitPointsView
{
public:
    const float POS_Y = 80;
    const float SIZE_FACTOR = 10;

    explicit HeroHitPointsView(BattleHero *);
    void addHitPoints(Node *);
    void hide();
    void show();
    void update();

private:
    Node *node;
    BattleHero *battleHero;
    ProgressTimer *hitPoints;
    FontCreator *fontCreator;
    Label *label;

    std::string hitText();
};

#endif
