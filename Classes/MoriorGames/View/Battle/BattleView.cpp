#include "BattleView.h"
#include "../../Containers/BattleContainer.h"
#include "../../EventListeners/BattleEventListener.h"
#include "../../Transformers/HeroesConfig2Json.h"
#include "../../Vendor/Containers/HeroesConfig.h"
#include "../../Vendor/Parsers/BattleActionParser.h"

#include "../../Services/StringFileReader.h"

const std::string BattleView::NAME = "battle-node";

BattleView::BattleView(const std::string &json, Layer *layer, Socket *socket)
    : json{json}, ViewHelper(layer), socket{socket}
{
    addView();
}

Battle *BattleView::getBattle()
{
    return battleContainer->getBattle();
}

void BattleView::processOnlineAction(std::string json)
{
    auto battleAction = (new BattleActionParser(json))->parse();
    battleAction->print();
    battleContainer->getBattleProcessor()->processBattleAction(battleAction);
}

void BattleView::ai()
{
    battleContainer->getAI()->update();
}

void BattleView::addView()
{
    battleContainer = new BattleContainer(layer, socket, json);

    new BattleEventListener(
        layer, battleContainer->getBattle(), battleContainer->getEventPublisher(), battleContainer->getGridContainer()
    );
}
