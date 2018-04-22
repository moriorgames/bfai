#include "SkillsView.h"

SkillsView::SkillsView(Layer *layer)
    : ViewHelper(layer)
{
    addView();
}

void SkillsView::addView()
{
    container = new Node;
    container->setScale(scale);
    container->setPosition(position->getTopLeftPosition());

    auto button1 = ui::Button::create("ui/next-turn.png", "", "");
    button1->setPosition(Point(50, -50));
    auto button2 = ui::Button::create("ui/movement.png", "", "");
    button2->setPosition(Point(150, -50));

    container->addChild(button1);
    container->addChild(button2);

    layer->addChild(container, Z_ORDER_MENU_ITEMS);
}
