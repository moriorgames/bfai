#include "BattleButton.h"
#include "../../Scenes/BattleScene.h"
#include "../../Services/SoundPlayer.h"
#include "../../Services/FontCreator.h"

using MoriorGames::BattleButton;
using MoriorGames::SoundPlayer;

const std::string BattleButton::NAME = "battle-button-node";

BattleButton::BattleButton(Layer *layer)
    : ViewHelper(layer)
{
    addView();
}

void BattleButton::addView()
{
    auto button = ui::Button::create("ui/button-battle.png", "", "");
    button->setScale(scale);
    button->setPosition(centerPosition);
    button->setPositionY(centerPosition.y + BUTTON_Y * scale);
    button->setName(NAME);

    // Translator: translator->tr("menu_" + key)
    auto label = (new FontCreator)->buttonLabel("BATTLE");
    button->setTitleLabel(label);
    button->addTouchEventListener(
        [&](Ref *sender, ui::Widget::TouchEventType type)
        {
            if (type == ui::Widget::TouchEventType::ENDED) {
                SoundPlayer::playEffect("sounds/button.mp3");
                auto scene = BattleScene::createScene();
                Director::getInstance()->replaceScene(TransitionFade::create(SCENES_TRANSITION_TIME, scene));
            }
        });

    layer->addChild(button, Z_ORDER_MENU_ITEMS);
}
