#include "HeroAnimator.h"
#include "../../Definitions.h"

HeroAnimator::HeroAnimator(BattleHero *battleHero, Coordinate2Screen *coordinate2Screen)
    : sprite{sprite}, battleHero{battleHero}, coordinate2Screen{coordinate2Screen}
{
    spriteAnimator = new SpriteAnimator;
}

Sprite *HeroAnimator::createSprite()
{
    sprite = new Sprite;
    sprite->initWithSpriteFrameName(spriteAnimator->getFrameName(battleHero->getSlug()));
    sprite->setAnchorPoint(ANCHOR);

    return sprite;
}

void HeroAnimator::stop()
{
    sprite->stopAllActions();
    sprite->setSpriteFrame(spriteAnimator->getFrameName(battleHero->getSlug()));
}

void HeroAnimator::move()
{
    sprite->runAction(moveAnimation());
}

Action *HeroAnimator::moveTo(Coordinate *coordinate)
{
    move();
    sprite->runAction(moveAnimation());
    auto moveTo = MoveTo::create(1, coordinate2Screen->execute(coordinate));
    auto callback = CallFunc::create([this]()
                                     { stop(); });

    return Sequence::create(moveTo, callback, nullptr);
}

void HeroAnimator::action()
{
    sprite->runAction(actionAnimation());
}

Action *HeroAnimator::moveAnimation()
{
    return spriteAnimator->generateAction(battleHero->getSlug(), "move", battleHero->getMoveFrames(), FPS);
}

Action *HeroAnimator::actionAnimation()
{
    return spriteAnimator->generateSingleAction(battleHero->getSlug(), "attack", battleHero->getAttackFrames(), FPS);
}
