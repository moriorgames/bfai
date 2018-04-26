#include "SkillsView.h"
#include "../../Vendor/Entity/BattleAction.h"
#include "../../Vendor/Repository/SkillRepository.h"

SkillsView::SkillsView(Layer *layer, Battle *battle, BattleEventPublishable *eventPublisher, GridView *gridView)
    : ViewHelper(layer), battle{battle}, eventPublisher{eventPublisher}, gridView{gridView}
{
    addView();
}

void SkillsView::update(BattleAction *)
{
    removeSkillButtons();
    addSkillButtons();
}

void SkillsView::addView()
{
    container = new Node;
    container->setScale(scale);
    container->setPosition(position->getTopLeftPosition());
    container->removeAllChildren();

    layer->addChild(container, Z_ORDER_MENU_ITEMS);
}

void SkillsView::removeSkillButtons()
{
    container->removeAllChildren();
}

void SkillsView::addSkillButtons()
{
    auto battleHero = battle->getActiveBattleHero();
    float x = 70;
    float y = -70;
    auto gridViewLambda = gridView;
    for (auto skill:battleHero->getSkills()) {

        auto skillModel = skillRepo->findById(skill->getId());
        auto button = ui::Button::create("ui/" + skillModel->getSlug() + ".png", "", "");
        button->setPosition(Point(x, y));
        button->addTouchEventListener(
            [&, battleHero, skillModel, gridViewLambda](Ref *sender, ui::Widget::TouchEventType type)
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
                    if (skillModel->getType() == Skill::TYPE_MOVE) {

                        gridViewLambda->removeActionGrid();
                        gridViewLambda->buildPathForMove(battleHero);

                    }
                    if (skillModel->getType() == Skill::TYPE_SHOT) {

                        gridViewLambda->removeActionGrid();
                        gridViewLambda->buildPathForAction(battleHero);

                    }
                }
            });
        container->addChild(button);
        x += 110;
    }
}
