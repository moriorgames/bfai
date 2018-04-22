#include "SkillsView.h"
#include "../../Vendor/Repository/SkillRepository.h"

SkillsView::SkillsView(Layer *layer)
    : ViewHelper(layer)
{
    addView();
}

void SkillsView::addSkillButtons(Hero *hero)
{
    float x = 70;
    float y = -70;
    for (auto skill:hero->getSkills()) {

        auto skillModel = skillRepo->findById(skill->getId());
        auto button = ui::Button::create("ui/" + skillModel->getSlug() + ".png", "", "");
        button->setPosition(Point(x, y));
        button->addTouchEventListener(
            [&, skillModel](Ref *sender, ui::Widget::TouchEventType type)
            {
                if (type == ui::Widget::TouchEventType::ENDED) {
                    CCLOG("Skill: %s", skillModel->getName().c_str());
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
