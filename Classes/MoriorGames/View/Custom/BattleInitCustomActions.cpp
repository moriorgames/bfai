#include "BattleInitCustomActions.h"

BattleInitCustomActions::BattleInitCustomActions(Layer *layer)
{
    runActions(layer);
}

void BattleInitCustomActions::runActions(Layer *layer)
{
    layer->setScale(layer->getScale() * 0.80f);

    auto scaleTo = ScaleTo::create(1.5f, 1.0f);
    auto callback = CallFunc::create([this]() {});

    layer->runAction(
        Sequence::create(
            DelayTime::create(3.0f),
            Spawn::createWithTwoActions(EaseQuinticActionInOut::create(scaleTo), callback),
            nullptr
        )
    );
}
