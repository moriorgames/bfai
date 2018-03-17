#include "HeroView.h"

using MoriorGames::HeroView;

const std::string HeroView::NAME = "hero-node";

HeroView::HeroView(Layer *layer, Hero *hero)
    : ViewHelper(layer), hero{hero}
{
    spriteAnimator = new SpriteAnimator;
    addView();
}

void HeroView::addView()
{
    container = new Node;
    container->setScale(scale);

    addHero();

    layer->addChild(container, Z_ORDER_WORLD);
}

void HeroView::addHero()
{
    auto sprite = new Sprite;
    sprite->initWithSpriteFrameName(spriteAnimator->getFrameName(hero->getSlug()));
    sprite->setPosition(400, 420);
    sprite->runAction(moveAction());

    container->addChild(sprite);
}

Action *HeroView::moveAction()
{
    return spriteAnimator->generateAction(hero->getSlug(), hero->getMoveFrames(), "move", 0, 24);
}
