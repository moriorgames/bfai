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

        if (skill->getType() == Skill::TYPE_BOOST_HEALTH ||
            skill->getType() == Skill::TYPE_BOOST_DAMAGE ||
            skill->getType() == Skill::TYPE_BOOST_RANGED ||
            skill->getType() == Skill::TYPE_BOOST_MOVE) {
            continue;
        }

        auto skillBackground = Sprite::create("ui/selected-skill.png");
        skillBackground->setPosition(Point(x, y));
        if (skill->getId() == battle->getActiveSkill()) {
            skillBackground->setScale(skillBackground->getScale() * 1.15f);
        }

        auto battle = this->battle;
        auto skillModel = skillRepo->findById(skill->getId());

        auto button = ui::Button::create("portraits/" + skillModel->getSlug() + ".png", "", "", uiTexture::PLIST);
        button->setPosition(Point(x, y));
        button->addTouchEventListener(
            [&, battleHero, skillModel, gridViewLambda, battle](Ref *sender, ui::Widget::TouchEventType type)
            {
                if (type == ui::Widget::TouchEventType::ENDED) {
                    battle->setActiveSkill(skillModel->getId());
                    if (skillModel->getId() == Skill::NEXT_TURN_ID) {
                        auto battleAction = new BattleAction;
                        battleAction->setBattleToken(battle->getToken());
                        battleAction->setUserToken(battle->getUserToken());
                        battleAction->setBattleHeroId(
                            battleHero->getBattleHeroId()
                        );
                        battleAction->setSkillId(
                            skillModel->getId()
                        );
                        battleAction->setCoordinate(battleHero->getCoordinate());
                        eventPublisher->publish(battleAction);

                    } else {

                        gridViewLambda->removeActionGrid();
                        gridViewLambda->drawPath(skillModel, battleHero);
                    }

                    update(new BattleAction);
                }
            });
        container->addChild(skillBackground);
        container->addChild(button);
        x += 140;
    }
}
