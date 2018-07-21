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

BattleHero *HeroView::getBattleHero() const
{
    return battleHero;
}

void HeroView::hide()
{
    container->setOpacity(0);
    heroHitPointsView->hide();
    battleHero->setHidden(true);
}

void HeroView::show()
{
    container->setOpacity(255);
    heroHitPointsView->show();
    battleHero->setHidden(false);
}

void HeroView::update(BattleAction *battleAction)
{
    if (battleAction->getBattleHeroId() == battleHero->getBattleHeroId()) {

//        // @todo I'm sure it will be used in future
//        auto skill = skillRepo->findById(battleAction->getSkillId());

        if (battleAction->getSkillId() == Skill::NEXT_TURN_ID) {
            heroAnimator->stop();
        } else if (battleAction->getSkillId() == Skill::MOVE_ID) {
            heroAnimator->stop();
            container->runAction(heroAnimator->moveTo(battleHero->getCoordinate()));
        } else if (battleAction->getSkillId() == Skill::JUMP_ID) {
            heroAnimator->stop();
            container->runAction(heroAnimator->jumpTo(container, battleHero->getCoordinate()));
        } else if (battleAction->getSkillId() == Skill::DAMAGE_ID) {
            heroAnimator->hurt(container, battleAction);
        } else {
            heroAnimator->stop();
            heroAnimator->action();
        }
    }
    heroHitPointsView->update();
    if (battleAction->getSkillId() != Skill::EXTRA_SHOT_ID && battleHero->isActive && !battleHero->hasMoved()) {
        heroAnimator->move();
    }
    if (!battleHero->isDead()) {
        container->setOpacity(battleHero->isVisible() ? 255 : 140);
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
}

void HeroView::setLocalZOrder()
{
    container->setLocalZOrder(Z_ORDER_HEROES - battleHero->getCoordinate()->y);
}
