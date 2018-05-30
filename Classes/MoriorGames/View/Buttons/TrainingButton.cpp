#include "TrainingButton.h"
#include "../../Scenes/BattleScene.h"
#include "../../Services/SoundPlayer.h"
#include "../../Services/FontCreator.h"
#include "../../Transformers/HeroesConfig2Json.h"

TrainingButton::TrainingButton(Layer *layer)
    : ViewHelper(layer)
{
    addView();
}

void TrainingButton::addView()
{
    auto button = ui::Button::create("ui/button-training.png", "", "");
    button->setScale(scale);
    button->setPosition(position->getRightCenterPosition());
    button->setPositionX(position->getRightCenterPosition().x + BUTTON_X * scale);
    button->setPositionY(position->getRightCenterPosition().y + BUTTON_Y * scale);

    auto label = (new FontCreator)->buttonLabel(translator->tr("main_menu_training"));
    button->setTitleLabel(label);
    button->addTouchEventListener(
        [&](Ref *sender, ui::Widget::TouchEventType type)
        {
            if (type == ui::Widget::TouchEventType::ENDED) {
                SoundPlayer::playEffect("sounds/button.mp3");
                auto json = (new HeroesConfig2Json)->transform(heroesConfig);
                auto scene = BattleScene::createScene(json);
                Director::getInstance()->replaceScene(TransitionFade::create(SCENES_TRANSITION_TIME, scene));
            }
        });

    layer->addChild(button, Z_ORDER_MENU_ITEMS);
}
