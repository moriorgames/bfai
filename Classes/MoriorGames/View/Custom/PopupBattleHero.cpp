#include "PopupBattleHero.h"

PopupBattleHero::PopupBattleHero(Layer *layer, Hero *hero)
    : AbstractFrame(layer), hero{hero}
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

void PopupBattleHero::addFrame()
{
    auto frame = Sprite::create("ui/frame-battle-heroes.png");
    auto sprite = heroRow(0, hero);
    scrollView->addChild(sprite);
    frame->addChild(scrollView);
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
