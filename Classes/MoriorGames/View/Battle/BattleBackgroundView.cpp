#include "BattleBackgroundView.h"
#include "../Custom/BattleInitCustomActions.h"
#include "../../Services/SoundPlayer.h"

const std::string BattleBackgroundView::NAME = "battle-background-node";

BattleBackgroundView::BattleBackgroundView(Layer *layer)
    : ViewHelper(layer)
{
    addView();
}

void BattleBackgroundView::addView()
{
    auto pos = position->getCenterBotPosition();

    auto background = Sprite::create("img/battle-background.jpg");
    background->setScale(scale);
    background->setAnchorPoint({0.5, 0});
    background->setPosition(pos.x, pos.y - PADDING_BATTLE_FIELD * scale);
    background->setName(NAME);
    layer->addChild(background, Z_ORDER_BACKGROUND);

    auto middleObstacle = Sprite::create("img/middle-obstacle.png");
    middleObstacle->setScale(scale);
    middleObstacle->setPosition(pos.x, pos.y + PADDING_MIDDLE_OBSTACLE * scale);
    layer->addChild(middleObstacle, Z_ORDER_HEROES);

    auto localNexus = Sprite::create("img/nexus.png");
    localNexus->setAnchorPoint(ANCHOR_NEXUS);
    localNexus->setScale(scale);
    localNexus->setPosition(pos.x - PADDING_NEXUS * scale, pos.y + PADDING_MIDDLE_OBSTACLE * scale);
    layer->addChild(localNexus, Z_ORDER_HEROES);

    auto visitorNexus = Sprite::create("img/nexus.png");
    visitorNexus->setAnchorPoint(ANCHOR_NEXUS);
    visitorNexus->setScale(scale);
    visitorNexus->setPosition(pos.x + PADDING_NEXUS * scale, pos.y + PADDING_MIDDLE_OBSTACLE * scale);
    layer->addChild(visitorNexus, Z_ORDER_HEROES);

    new BattleInitCustomActions(layer);

    SoundPlayer::playBackgroundMusic("sounds/main-menu-theme.mp3");
}
