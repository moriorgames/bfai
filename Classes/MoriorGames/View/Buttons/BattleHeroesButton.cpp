#include "BattleHeroesButton.h"
#include "../../Scenes/BattleHeroesScene.h"
#include "../../Services/SoundPlayer.h"
#include "../../Services/FontCreator.h"

const std::string BattleHeroesButton::NAME = "battle-heroes-button-node";

BattleHeroesButton::BattleHeroesButton(Layer *layer)
    : ViewHelper(layer)
{
    addView();
}

void BattleHeroesButton::addView()
{
    auto button = ui::Button::create("ui/button-battle-heroes.png", "", "");
    button->setScale(scale);
    button->setPosition(position->getLeftCenterPosition());
    button->setPositionX(position->getLeftCenterPosition().x + BUTTON_X * scale);
    button->setName(NAME);

    button->addTouchEventListener(
        [&](Ref *sender, ui::Widget::TouchEventType type)
        {
            if (type == ui::Widget::TouchEventType::ENDED) {
                SoundPlayer::playEffect("sounds/button.mp3");
                auto scene = BattleHeroesScene::createScene();
                Director::getInstance()->replaceScene(TransitionFade::create(SCENES_TRANSITION_TIME, scene));
            }
        });

    layer->addChild(button, Z_ORDER_MENU_ITEMS);
}
