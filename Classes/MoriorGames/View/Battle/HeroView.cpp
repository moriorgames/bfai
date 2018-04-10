#include "HeroView.h"

const Point HeroView::ANCHOR{0.5, 0.35};

HeroView::HeroView(Layer *layer, GridSystem *gridSystem, BattleHero *hero)
    : ViewHelper(layer), gridSystem{gridSystem}, hero{hero}
{
    spriteAnimator = new SpriteAnimator;
    addView();
}

BattleHero *HeroView::getHero() const
{
    return hero;
}

void HeroView::moveTo(Coordinate *coordinate)
{
    auto coordinate2Screen = gridSystem->getCoordinate2Screen();
    auto action = MoveTo::create(1, coordinate2Screen->execute(coordinate));

    container->runAction(action);
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
    auto sprite = new Sprite;
    sprite->initWithSpriteFrameName(spriteAnimator->getFrameName(hero->getSlug()));
    sprite->runAction(moveAction());
    sprite->setAnchorPoint(ANCHOR);

    auto coordinate2Screen = gridSystem->getCoordinate2Screen();
    auto position = coordinate2Screen->execute(hero->getCoordinate());
    container->setPosition(position);
    container->addChild(sprite);
}

Action *HeroView::moveAction()
{
    return spriteAnimator->generateAction(hero->getSlug(), hero->getMoveFrames(), "move", 0, FPS);
}

void HeroView::addHealthBar()
{
    int position = 37;
    for (int i = 0; i < hero->getCurrentHealth(); ++i) {
        auto hitPoint = Sprite::create("img/hit-point.png");
        hitPoint->setPosition(position, 110);
        container->addChild(hitPoint);
        position -= 18;
    }
}

void HeroView::update(BattleAction *battleAction)
{
}
