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
    if (battleAction->getBattleHeroId() == battleHero->getBattleHeroId()) {
        if (battleAction->getSkillId() == Skill::NEXT_TURN_ID) {
            heroAnimator->stop();
        } else if (battleAction->getSkillId() == Skill::MOVE_ID) {
            heroAnimator->stop();
            container->runAction(heroAnimator->moveTo(battleHero->getCoordinate()));
        } else if (battleAction->getSkillId() == Skill::DAMAGE_ID) {
            heroAnimator->hurt(battleAction);
            buildHealthBar();
        } else {

            auto skill = skillRepo->findById(battleAction->getSkillId());
            if (skill->getType() == Skill::TYPE_SINGLE_ATTACK) {
                heroAnimator->stop();
                heroAnimator->action();
            }

        }
    }
    if (battleHero->isActive) {
        heroAnimator->move();
    }
}

void HeroView::addView()
{
    hitPoints = new Node;
    container = new Node;
    container->setScale(scale);
    container->addChild(hitPoints);

    addHero();
    buildHealthBar();

    layer->addChild(container, Z_ORDER_HEROES);
}

void HeroView::addHero()
{
    auto position = coordinate2Screen->execute(battleHero->getCoordinate());
    container->setPosition(position);
    container->addChild(heroAnimator->createSprite());
}

void HeroView::buildHealthBar()
{
    hitPoints->removeAllChildren();
    int position = 37;
    for (int i = 0; i < battleHero->getCurrentHealth(); ++i) {
        auto hitPoint = Sprite::create("img/hit-point.png");
        hitPoint->setPosition(position, 110);
        hitPoints->addChild(hitPoint);
        position -= 18;
    }
}
