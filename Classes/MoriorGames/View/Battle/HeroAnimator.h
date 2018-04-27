#ifndef MORIOR_GAMES_VIEW_BATTLE_HERO_ANIMATOR_H
#define MORIOR_GAMES_VIEW_BATTLE_HERO_ANIMATOR_H

#include "cocos2d.h"
#include "../../Screen/Coordinate2Screen.h"
#include "../../Services/SpriteAnimator.h"
#include "../../Vendor/Entity/BattleHero.h"
USING_NS_CC;

class HeroAnimator
{
public:
    const Point ANCHOR{0.5, 0.35};

    HeroAnimator(BattleHero *, Coordinate2Screen *);
    Sprite *createSprite();
    void stop();
    void move();
    Action *moveTo(Coordinate *);
    void action();

private:
    Sprite *sprite;
    BattleHero *battleHero;
    Coordinate2Screen *coordinate2Screen;
    SpriteAnimator *spriteAnimator;

    Action *moveAnimation();
    Action *actionAnimation();
};

#endif
