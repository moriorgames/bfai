#include "HeroView.h"

using MoriorGames::HeroView;

const std::string HeroView::NAME = "hero-node";

const Point HeroView::ANCHOR{0.5, 0.3};

HeroView::HeroView(Layer *layer, GridSystem *gridSystem, BattleHero *hero)
    : ViewHelper(layer), gridSystem{gridSystem}, hero{hero}
{
    spriteAnimator = new SpriteAnimator;
    addView();
}

void HeroView::addView()
{
    container = new Node;
    container->setScale(scale);

    addHero();

    layer->addChild(container, Z_ORDER_HEROES);
}

void HeroView::addHero()
{
    auto sprite = new Sprite;
    sprite->initWithSpriteFrameName(spriteAnimator->getFrameName(hero->getSlug()));
    sprite->runAction(moveAction());
    sprite->setAnchorPoint(ANCHOR);

    auto position = gridSystem->coordinateToScreen(hero->getCoordinate());
    container->setPosition(position);
    container->addChild(sprite);
}

Action *HeroView::moveAction()
{
    return spriteAnimator->generateAction(hero->getSlug(), hero->getMoveFrames(), "move", 0, FPS);
}
