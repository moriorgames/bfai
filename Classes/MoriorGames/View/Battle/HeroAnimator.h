#ifndef MORIOR_GAMES_VIEW_BATTLE_HERO_ANIMATOR_H
#define MORIOR_GAMES_VIEW_BATTLE_HERO_ANIMATOR_H

#include "cocos2d.h"
#include "../../Screen/Coordinate2Screen.h"
#include "../../Services/FontCreator.h"
#include "../../Services/SpriteAnimator.h"
#include "../../Vendor/Entity/BattleAction.h"
#include "../../Vendor/Entity/BattleHero.h"
USING_NS_CC;

class HeroAnimator
{
public:
    const Point ANCHOR{0.5, 0.35};
    const Color3B HIT_COLOR{255, 0, 0};
    const Color3B DEFAULT_COLOR{255, 255, 255};

    HeroAnimator(BattleHero *, Coordinate2Screen *);
    Sprite *createSprite();
    void stop();
    void move();
    Action *moveTo(Coordinate *);
    Action *jumpTo(Node *, Coordinate *);
    void action();
    void hurt(Node *, BattleAction *);

private:
    const float MOVE_SEEP = .7;
    const float JUMP_SEEP = .35;

    Sprite *sprite;
    BattleHero *battleHero;
    Coordinate2Screen *coordinate2Screen;
    FontCreator *fontCreator;
    SpriteAnimator *spriteAnimator;

    Action *moveAnimation();
    Action *actionAnimation();
    Action *deathAnimation();
};

#endif
