#include "HeroHitPointsView.h"

HeroHitPointsView::HeroHitPointsView(BattleHero *battleHero)
    : battleHero{battleHero}
{
}

void HeroHitPointsView::addHitPoints(Node *container)
{
    auto hitPointsBack = Sprite::create("ui/hit-points-back.png");
    hitPointsBack->setPositionY(110);

    auto hitPointSprite = Sprite::create(
        battleHero->getSide() == BattleHero::SIDE_PLAYER ? "ui/hit-points-local.png" : "ui/hit-points-visitor.png"
    );
    hitPoints = new ProgressTimer;
    hitPoints->initWithSprite(hitPointSprite);
    hitPoints->setType(ProgressTimer::Type::BAR);
    hitPoints->setMidpoint(Point(0, 0));
    hitPoints->setBarChangeRate(Point(1, 0));
    hitPoints->setPositionY(110);
    update();

    container->addChild(hitPointsBack);
    container->addChild(hitPoints);
}

void HeroHitPointsView::update()
{
    hitPoints->setPercentage(float(battleHero->getCurrentHealth()) / float(battleHero->getHealth()) * 100);
}
