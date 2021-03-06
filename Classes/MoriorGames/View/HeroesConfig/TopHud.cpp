#include "TopHud.h"
#include "../Buttons/MainMenuButton.h"
#include "../../Services/SoundPlayer.h"
#include "../../Vendor/Utils/TextUtils.h"
#include "../../Vendor/Containers/HeroesConfig.h"

TopHud::TopHud(Layer *layer, HeroesConfigPublisher *publisher)
    : ViewHelper(layer), publisher{publisher}
{
    fontCreator = new FontCreator;
    addView();
}

void TopHud::update(HeroConfigPayload *)
{
    auto remainingCost = BATTLE_TOTAL_COST - heroesConfig->countBattleHeroesCost();
    costLabel->setString(to_string(remainingCost));
}

void TopHud::addView()
{
    new MainMenuButton(layer);

    node = new Node;
    node->setScale(scale);
    node->setPosition(
        Point(
            position->getLeftTopPosition().x + ITEM_X * scale,
            position->getLeftTopPosition().y + ITEM_Y * scale
        )
    );

    auto label = fontCreator->titleLabel(translator->tr("battle_heroes_remaining_points"));
    label->setAnchorPoint(Point(1, 0.5));
    label->setPositionX(label->getPosition().x - 60);
    node->addChild(label);

    auto remainingCost = BATTLE_TOTAL_COST - heroesConfig->countBattleHeroesCost();
    auto sprite = ui::Button::create("ui/cost.png", "", "");
    costLabel = fontCreator->numberLabel(to_string(remainingCost), "fonts/title.otf", 30);
    sprite->setTitleLabel(costLabel);
    sprite->setScale(1.25f);
    node->addChild(sprite);

    addResetButton();

    layer->addChild(node, Z_ORDER_OVER_POPUP);
}

void TopHud::addResetButton()
{
    auto button = ui::Button::create("ui/action-button.png", "", "");
    button->setPositionX(-550);

    auto label = fontCreator->buttonLabel(translator->tr("battle_heroes_reset"), "fonts/buttons-label.otf", 50);
    button->setTitleLabel(label);
    button->addTouchEventListener(
        [&, this](Ref *sender, ui::Widget::TouchEventType type)
        {
            if (type == ui::Widget::TouchEventType::ENDED) {
                publisher->notifyObservers(
                    new HeroConfigPayload(HeroConfigPayload::CLEAR)
                );
                SoundPlayer::playEffect("sounds/button.mp3");
            }
        });

    node->addChild(button);
}
