#include "BattleBackgroundView.h"
#include "Custom/BattleInitCustomActions.h"
#include "../Services/SoundPlayer.h"

using MoriorGames::BattleBackgroundView;
using MoriorGames::SoundPlayer;

const std::string BattleBackgroundView::NAME = "battle-background-node";

BattleBackgroundView::BattleBackgroundView(Layer *layer)
    : ViewHelper(layer)
{
    addView();
}

void BattleBackgroundView::addView()
{
    auto background = Sprite::create("img/battle-background.jpg");

    auto pos = position->getBottomCenteredPosition();
    background->setScale(scale);
    background->setAnchorPoint({0.5, 0});
    background->setPosition(
        pos.x, pos.y - PADDING_BATTLE_FIELD * scale
    );
    background->setName(NAME);

    layer->addChild(background, Z_ORDER_BACKGROUND);

    new BattleInitCustomActions(layer);

    SoundPlayer::playBackgroundMusic("sounds/main-menu-theme.mp3");
}
