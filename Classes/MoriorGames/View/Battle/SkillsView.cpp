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
                    battle->setActiveSkill(skillModel->getId());
                    if (skillModel->getId() == Skill::NEXT_TURN_ID) {
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
                    if (skillModel->getId() == Skill::MOVE_ID) {

                        gridViewLambda->removeActionGrid();
                        gridViewLambda->buildPathForMove(battleHero);

                    }
                    if (skillModel->getId() == Skill::SINGLE_ATTACK_ID) {

                        gridViewLambda->removeActionGrid();
                        gridViewLambda->buildPathForAction(battleHero);

                    }

                    if (skillModel->getType() == Skill::TYPE_SPAWN) {
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
        x += 130;
    }
}
