#include "HeroView.h"

using MoriorGames::HeroView;

const std::string HeroView::NAME = "hero-node";

HeroView::HeroView(Layer *layer)
    : ViewHelper(layer)
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
    auto hero = new Sprite;
    hero->initWithSpriteFrameName(spriteAnimator->getFrameName("paul", "move"));
    hero->setPosition(400, 420);
    hero->runAction(detailAction());

    container->addChild(hero);
}

Action *HeroView::detailAction()
{
    return spriteAnimator->generateAction("paul", 24, "move", 0, 24);
}
