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
    auto button = ui::Button::create("ui/back-button.png", "", "");
    button->setScale(scale);
    button->setPosition(
        Point(
            position->getLeftTopPosition().x + BUTTON_X * scale,
            position->getLeftTopPosition().y + BUTTON_Y * scale
        )
    );

    button->addTouchEventListener(
        [&](Ref *sender, ui::Widget::TouchEventType type)
        {
            if (type == ui::Widget::TouchEventType::ENDED) {
                SoundPlayer::playEffect("sounds/button.mp3");
                auto scene = MainMenuScene::createScene();
                Director::getInstance()->replaceScene(TransitionFade::create(SCENES_TRANSITION_TIME, scene));
            }
        });

    layer->addChild(button, Z_ORDER_OVER_POPUP);
}
