#include "SkillsView.h"
#include "../../Vendor/Entity/BattleAction.h"
#include "../../Vendor/Repository/SkillRepository.h"

SkillsView::SkillsView(Layer *layer, BattleEventPublishable *eventPublisher)
    : ViewHelper(layer), eventPublisher{eventPublisher}
{
    addView();
}

void SkillsView::addSkillButtons(BattleHero *battleHero)
{
    float x = 70;
    float y = -70;
    for (auto skill:battleHero->getSkills()) {

        auto skillModel = skillRepo->findById(skill->getId());
        auto button = ui::Button::create("ui/" + skillModel->getSlug() + ".png", "", "");
        button->setPosition(Point(x, y));
        button->addTouchEventListener(
            [&, battleHero, skillModel](Ref *sender, ui::Widget::TouchEventType type)
            {
                if (type == ui::Widget::TouchEventType::ENDED) {
                    if (skillModel->getType() == Skill::TYPE_NEXT_TURN) {
                        auto battleAction = new BattleAction;
                        battleAction->setBattleHeroId(
                            battleHero->getBattleHeroId()
                        );
                        battleAction->setSkillId(
                            skillModel->getId()
                        );
                        battleAction->setCoordinate(battleHero->getCoordinate());
                        eventPublisher->publish(battleAction);
                    }
                }
            });
        container->addChild(button);
        x += 110;
    }
}

void SkillsView::addView()
{
    container = new Node;
    container->setScale(scale);
    container->setPosition(position->getTopLeftPosition());
    container->removeAllChildren();

    layer->addChild(container, Z_ORDER_MENU_ITEMS);
}
