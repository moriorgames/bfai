#include "HeroHitPointsView.h"
#include "../../Vendor/Utils/TextUtils.h"

HeroHitPointsView::HeroHitPointsView(BattleHero *battleHero)
    : battleHero{battleHero}
{
    fontCreator = new FontCreator;
}

void HeroHitPointsView::addHitPoints(Node *container)
{
    node = new Node;
    node->setCascadeOpacityEnabled(true);
    node->setPositionY(POS_Y + battleHero->getSize() * SIZE_FACTOR);

    auto hitPointsBack = Sprite::create("ui/hit-points-back.png");

    auto hitPointSprite = Sprite::create(
        battleHero->getSide() == BattleHero::SIDE_LOCAL ? "ui/hit-points-local.png" : "ui/hit-points-visitor.png"
    );
    hitPoints = new ProgressTimer;
    hitPoints->initWithSprite(hitPointSprite);
    hitPoints->setType(ProgressTimer::Type::BAR);
    hitPoints->setMidpoint(Point(0, 0));
    hitPoints->setBarChangeRate(Point(1, 0));

    label = fontCreator->hitPointsLabel(hitText());
    label->setPositionY(8);

    update();

    node->addChild(hitPointsBack);
    node->addChild(hitPoints);
    node->addChild(label);

    container->addChild(node);
}

void HeroHitPointsView::update()
{
    hitPoints->setPercentage(float(battleHero->getCurrentHealth()) / float(battleHero->getHealth()) * 100);
    label->setString(hitText());
}

std::string HeroHitPointsView::hitText()
{
    return to_string(battleHero->getCurrentHealth()) + "/" + to_string(battleHero->getHealth());
}
