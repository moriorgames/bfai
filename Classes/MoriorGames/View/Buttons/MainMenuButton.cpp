#include "MainMenuButton.h"
#include "../../Scenes/MainMenuScene.h"
#include "../../Services/SoundPlayer.h"
#include "../../Services/FontCreator.h"

MainMenuButton::MainMenuButton(Layer *layer)
    : ViewHelper(layer)
{
    addView();
}

void MainMenuButton::addView()
{
    auto button = ui::Button::create("ui/button-battle.png", "", "");
    button->setScale(scale);
    button->setPosition(centerPosition);
    button->setPositionY(centerPosition.y + BUTTON_Y * scale);

    // Translator: translator->tr("menu_" + key)
    auto label = (new FontCreator)->buttonLabel("MAIN MENU");
    button->setTitleLabel(label);
    button->addTouchEventListener(
        [&](Ref *sender, ui::Widget::TouchEventType type)
        {
            if (type == ui::Widget::TouchEventType::ENDED) {
                SoundPlayer::playEffect("sounds/button.mp3");
                auto scene = MainMenuScene::createScene();
                Director::getInstance()->replaceScene(TransitionFade::create(SCENES_TRANSITION_TIME, scene));
            }
        });

    layer->addChild(button, Z_ORDER_MENU_ITEMS);
}
