#include "HeroAnimator.h"
#include "../../Vendor/Utils/TextUtils.h"
#include "../../Definitions.h"

HeroAnimator::HeroAnimator(BattleHero *battleHero, Coordinate2Screen *coordinate2Screen)
    : battleHero{battleHero}, coordinate2Screen{coordinate2Screen}
{
    fontCreator = new FontCreator;
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

void HeroAnimator::hurt(BattleAction *battleAction)
{
    auto hit = Sequence::createWithTwoActions(
        TintTo::create(0.15, HIT_COLOR),
        TintTo::create(0.15, DEFAULT_COLOR)
    );
    auto damaged = Sequence::create(hit, hit, hit, nullptr);

    sprite->runAction(damaged);

    auto damageLabel = fontCreator->damageLabel(to_string(battleAction->getExtra()));
    auto jump = JumpBy::create(0.35, Vec2(0, 0), 20, 1);
    auto damageSeq = Sequence::create(jump, jump, RemoveSelf::create(true), nullptr);
    damageLabel->runAction(damageSeq);

    sprite->addChild(damageLabel);
}

Action *HeroAnimator::moveAnimation()
{
    return spriteAnimator->generateAction(battleHero->getSlug(), "move", battleHero->getMoveFrames(), FPS);
}

Action *HeroAnimator::actionAnimation()
{
    return spriteAnimator->generateSingleAction(battleHero->getSlug(), "attack", battleHero->getAttackFrames(), FPS);
}
