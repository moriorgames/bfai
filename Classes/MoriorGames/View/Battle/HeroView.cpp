#include "HeroView.h"

using MoriorGames::HeroView;

const Point HeroView::ANCHOR{0.5, 0.35};

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
    addHealthBar();

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

void MoriorGames::HeroView::addHealthBar()
{
    int position = 37;
    for (int i = 0; i < hero->getCurrentHealth(); ++i) {
        auto hitPoint = Sprite::create("img/hit-point.png");
        hitPoint->setPosition(position, 110);
        container->addChild(hitPoint);
        position -= 18;
    }
}
