#include "BattleButton.h"
#include "../../Scenes/MatchMakerScene.h"
#include "../../Services/SoundPlayer.h"
#include "../../Services/FontCreator.h"

BattleButton::BattleButton(Layer *layer)
    : ViewHelper(layer)
{
    addView();
}

void BattleButton::addView()
{
    auto button = ui::Button::create("ui/button-battle.png", "", "");
    button->setScale(scale);
    button->setPosition(position->getRightCenterPosition());
    button->setPositionX(position->getRightCenterPosition().x + BUTTON_X * scale);
    button->setPositionY(position->getRightCenterPosition().y + BUTTON_Y * scale);

    auto label = (new FontCreator)->buttonLabel(translator->tr("main_menu_battle"));
    button->setTitleLabel(label);
    button->addTouchEventListener(
        [&](Ref *sender, ui::Widget::TouchEventType type)
        {
            if (type == ui::Widget::TouchEventType::ENDED) {
                SoundPlayer::playEffect("sounds/button.mp3");
                auto scene = MatchMakerScene::createScene();
                Director::getInstance()->replaceScene(TransitionFade::create(SCENES_TRANSITION_TIME, scene));
            }
        });

    layer->addChild(button, Z_ORDER_MENU_ITEMS);
}
