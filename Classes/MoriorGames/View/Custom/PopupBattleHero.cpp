#include "PopupBattleHero.h"

PopupBattleHero::PopupBattleHero(Layer *layer, Hero *hero)
    : ViewHelper(layer), hero{hero}
{
    addView();
}

void PopupBattleHero::addView()
{
    node = new Node;
    node->setScale(scale);
    node->setPosition(centerPosition);

    addBackground();
    addFrame();

    layer->addChild(node, Z_ORDER_POPUP);
}

void PopupBattleHero::addFrame() const
{
    auto frame = Sprite::create("ui/frame-battle-heroes.png");
    node->addChild(frame);
}

void PopupBattleHero::addBackground() const
{
    auto background = ui::Button::create("img/black.png", "", "");
    background->setOpacity(190);
    auto nodeToRemove = node;
    background->addTouchEventListener(
        [&, nodeToRemove](Ref *sender, ui::Widget::TouchEventType type)
        {
            if (type == ui::Widget::TouchEventType::ENDED) {
                nodeToRemove->removeAllChildren();
            }
        });

    node->addChild(background);
}
