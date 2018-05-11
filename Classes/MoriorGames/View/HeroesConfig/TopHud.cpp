#include "TopHud.h"
#include "../Buttons/MainMenuButton.h"
#include "../../Scenes/HeroesConfigScene.h"
#include "../../Services/SoundPlayer.h"
#include "../../Vendor/Utils/TextUtils.h"
#include "../../Vendor/Containers/BattleHeroesConfig.h"

TopHud::TopHud(Layer *layer)
    : ViewHelper(layer)
{
    fontCreator = new FontCreator;
    addView();
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

    auto remainingCost = BATTLE_TOTAL_COST - battleHeroesConfig->countBattleHeroesCost();
    auto sprite = ui::Button::create("ui/cost.png", "", "");
    auto costLabel = fontCreator->numberLabel(to_string(remainingCost), "fonts/title.otf", 30);
    sprite->setTitleLabel(costLabel);
    sprite->setScale(1.25f);
    node->addChild(sprite);

    addResetButton();

    layer->addChild(node, Z_ORDER_MENU_ITEMS);
}

void TopHud::addResetButton()
{
    auto button = ui::Button::create("ui/action-button.png", "", "");
    button->setPositionX(-550);

    auto label = fontCreator->buttonLabel(translator->tr("battle_heroes_reset"), "fonts/buttons-label.otf", 50);
    button->setTitleLabel(label);
    button->addTouchEventListener(
        [&](Ref *sender, ui::Widget::TouchEventType type)
        {
            if (type == ui::Widget::TouchEventType::ENDED) {
                battleHeroesConfig->clear();
                SoundPlayer::playEffect("sounds/button.mp3");
                auto scene = HeroesConfigScene::createScene();
                Director::getInstance()->replaceScene(scene);
            }
        });

    node->addChild(button);
}
