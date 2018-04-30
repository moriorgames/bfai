#include "EndOfBattle.h"
#include "../../Scenes/BattleScene.h"

EndOfBattle::EndOfBattle(Layer *layer)
    : ViewHelper(layer)
{
    addView();
}

void EndOfBattle::addView()
{
    Layer *layerTmp = layer;
    auto scaleTo = ScaleTo::create(1.5f, 0.80f);
    auto callback = CallFunc::create(
        [this, layerTmp]()
        {
            auto sprite = Sprite::create("img/end-of-battle.png");
            sprite->setScale(scale);
            sprite->setPosition(centerPosition);

            layerTmp->addChild(sprite, Z_ORDER_MENU_ITEMS);
        }
    );
    auto redirect = CallFunc::create(
        [this]()
        {
            BattleScene::goToMainMenuScene(.0f);
        }
    );

    layer->runAction(
        Sequence::create(
            DelayTime::create(2.0f),
            Spawn::createWithTwoActions(EaseQuinticActionInOut::create(scaleTo), callback),
            DelayTime::create(2.0f),
            redirect,
            nullptr
        )
    );
}
