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
    container->setPosition(position->getLeftBotPosition());
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
    float x = 80;
    float y = 80;
    auto gridViewLambda = gridView;
    for (auto skill:battleHero->getSkills()) {

        auto skillBackground = Sprite::create("ui/selected-skill.png");
        skillBackground->setPosition(Point(x, y));
        if (skill->getId() == battle->getActiveSkill()) {
            skillBackground->setScale(skillBackground->getScale() * 1.15f);
        }

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
                    } else if (skillModel->getId() == Skill::MOVE_ID) {

                        gridViewLambda->removeActionGrid();
                        gridViewLambda->buildPathForMove(battleHero);

                    } else if (skillModel->getId() == Skill::SINGLE_ATTACK_ID) {

                        gridViewLambda->removeActionGrid();
                        gridViewLambda->buildPathForAction(battleHero);

                    } else {

                        gridViewLambda->removeActionGrid();
                        gridViewLambda->buildPathForSkill(battleHero, skillModel);
                    }

                    update(new BattleAction);
                }
            });
        container->addChild(skillBackground);
        container->addChild(button);
        x += 140;
    }
}
