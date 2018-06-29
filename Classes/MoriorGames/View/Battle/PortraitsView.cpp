#include "PortraitsView.h"

PortraitsView::PortraitsView(Layer *layer, Battle *battle)
    : ViewHelper(layer), battle{battle}
{
    addView();
}

void PortraitsView::update(BattleAction *)
{
    removeButtons();
    addButtons();
}

void PortraitsView::addView()
{
    container = new Node;
    container->setScale(scale);
    container->setPosition(position->getRightBotPosition());
    container->removeAllChildren();

    layer->addChild(container, Z_ORDER_MENU_ITEMS);
}

void PortraitsView::addButtons()
{
    auto activeHero = battle->getActiveBattleHero();
    float x = -80;
    float y = 80;
    for (auto battleHero:battle->getBattleHeroes()) {
        if (battleHero->getSlug() != "nexus") {


            auto button = ui::Button::create("portraits/" + battleHero->getSlug() + ".png", "", "", uiTexture::PLIST);
            button->setPosition(Point(x, y));
            if (battleHero->getBattleHeroId() == activeHero->getBattleHeroId()) {
                button->setScale(button->getScale() * .75f);
            } else {
                button->setScale(button->getScale() * .6f);
            }
            button->addTouchEventListener(
                [&](Ref *sender, ui::Widget::TouchEventType type)
                {
                    if (type == ui::Widget::TouchEventType::ENDED) {

                    }
                });

            container->addChild(button);
            x -= 140;
        }
    }
}

void PortraitsView::removeButtons()
{
    container->removeAllChildren();
}
