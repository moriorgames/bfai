#include "HeroView.h"

const Point HeroView::ANCHOR{0.5, 0.35};

HeroView::HeroView(Layer *layer, Coordinate2Screen *coordinate2Screen, BattleHero *battleHero)
    : ViewHelper(layer), coordinate2Screen{coordinate2Screen}, battleHero{battleHero}
{
    spriteAnimator = new SpriteAnimator;
    heroSprite = new Sprite;
    addView();
}

void HeroView::stop()
{
    heroSprite->stopAllActions();
}

void HeroView::moveTo(Coordinate *coordinate)
{
    auto moveTo = MoveTo::create(1, coordinate2Screen->execute(coordinate));
    auto callback = CallFunc::create([this]() { stop(); });

    container->runAction(Sequence::create(moveTo, callback, nullptr));
}

void HeroView::action()
{
}

void HeroView::addView()
{
    container = new Node;
    container->setScale(scale);

    addHero();
    addHealthBar();

    layer->addChild(container, Z_ORDER_HEROES);
}

void HeroView::addHero()
{
    heroSprite->initWithSpriteFrameName(spriteAnimator->getFrameName(battleHero->getSlug()));
    heroSprite->setAnchorPoint(ANCHOR);

    auto position = coordinate2Screen->execute(battleHero->getCoordinate());
    container->setPosition(position);
    container->addChild(heroSprite);
}

void HeroView::addHealthBar()
{
    int position = 37;
    for (int i = 0; i < battleHero->getCurrentHealth(); ++i) {
        auto hitPoint = Sprite::create("img/hit-point.png");
        hitPoint->setPosition(position, 110);
        container->addChild(hitPoint);
        position -= 18;
    }
}

void HeroView::update(BattleAction *battleAction)
{
    if (battleHero->isActive) {
        heroSprite->runAction(moveAction());
    }
    if (battleAction->getBattleHeroId() == battleHero->getBattleHeroId()) {
        moveTo(battleHero->getCoordinate());
    }
}

Action *HeroView::moveAction()
{
    return spriteAnimator->generateAction(battleHero->getSlug(), battleHero->getMoveFrames(), "move", 0, FPS);
}

Action *HeroView::attackAction()
{
    return spriteAnimator->generateAction(battleHero->getSlug(), battleHero->getAttackFrames(), "attack", 0, FPS);
}
