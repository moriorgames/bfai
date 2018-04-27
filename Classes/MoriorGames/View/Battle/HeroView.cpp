#include "HeroView.h"
#include "../../Vendor/Repository/SkillRepository.h"

HeroView::HeroView(Layer *layer, Coordinate2Screen *coordinate2Screen, BattleHero *battleHero)
    : ViewHelper(layer), coordinate2Screen{coordinate2Screen}, battleHero{battleHero}
{
    heroAnimator = new HeroAnimator(battleHero, coordinate2Screen);
    addView();
}

void HeroView::update(BattleAction *battleAction)
{
    battleHero->print();
    heroAnimator->stop();
    if (battleAction->getBattleHeroId() == battleHero->getBattleHeroId()) {
        auto skill = skillRepo->findById(battleAction->getSkillId());
        if (skill->getType() == Skill::TYPE_MOVE) {
            container->runAction(heroAnimator->moveTo(battleHero->getCoordinate()));
        }
        if (skill->getType() == Skill::TYPE_SHOT) {
            heroAnimator->action();
        }
    }
    if (battleHero->isActive) {
        heroAnimator->move();
    }
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
    auto position = coordinate2Screen->execute(battleHero->getCoordinate());
    container->setPosition(position);
    container->addChild(heroAnimator->createSprite());
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
