#include "HeroView.h"
#include "../../Vendor/Repository/SkillRepository.h"

HeroView::HeroView(Layer *layer, BattleHero *battleHero, Coordinate2Screen *coordinate2Screen)
    : ViewHelper(layer), battleHero{battleHero}, coordinate2Screen{coordinate2Screen}
{
    battleHero->spawned = true;
    heroAnimator = new HeroAnimator(battleHero, coordinate2Screen);
    heroHitPointsView = new HeroHitPointsView(battleHero);
    addView();
}

void HeroView::update(BattleAction *battleAction)
{
    if (battleAction->getBattleHeroId() == battleHero->getBattleHeroId()) {

        if (battleAction->getSkillId() == Skill::NEXT_TURN_ID) {
            heroAnimator->stop();
        } else if (battleAction->getSkillId() == Skill::MOVE_ID) {
            heroAnimator->stop();
            container->runAction(heroAnimator->moveTo(battleHero->getCoordinate()));
        } else if (battleAction->getSkillId() == Skill::DAMAGE_ID) {
            heroHitPointsView->update();
            heroAnimator->hurt(container, battleAction);
        } else {
            heroAnimator->stop();
            heroAnimator->action();
        }
    }
    if (battleHero->isActive) {
        heroAnimator->move();
    }
    setLocalZOrder();
}

void HeroView::addView()
{
    container = new Node;
    container->setScale(scale);
    container->setCascadeOpacityEnabled(true);
    heroHitPointsView->addHitPoints(container);

    addHero();

    layer->addChild(container, Z_ORDER_HEROES);
    setLocalZOrder();
}

void HeroView::addHero()
{
    auto position = coordinate2Screen->execute(battleHero->getCoordinate());
    container->setPosition(position);
    container->addChild(heroAnimator->createSprite());
    if (battleHero->isNexus()) {
        auto base = Sprite::create("img/nexus.png");
        base->setPositionY(20);
        container->addChild(base, -1);
    }
}

void HeroView::setLocalZOrder()
{
    container->setLocalZOrder(Z_ORDER_HEROES - battleHero->getCoordinate()->y);
}
