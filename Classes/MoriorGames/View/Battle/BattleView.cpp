#include "BattleView.h"
#include "../../Containers/BattleContainer.h"
#include "../../EventListeners/BattleEventListener.h"
#include "../../Transformers/HeroesConfig2Json.h"
#include "../../Vendor/Containers/HeroesConfig.h"
#include "../../Vendor/Parsers/BattleActionParser.h"

const std::string BattleView::NAME = "battle-node";

BattleView::BattleView(Layer *layer, Socket *socket)
    : ViewHelper(layer), socket{socket}
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

void BattleView::addView()
{
    // @TODO we have to determine if its OFFline or ONline battle to get local or server data
    auto json = (new HeroesConfig2Json)->transform(heroesConfig);
    battleContainer = new BattleContainer(layer, socket, json);

    new BattleEventListener(
        layer, battleContainer->getBattle(), battleContainer->getEventPublisher(), battleContainer->getGridContainer()
    );
}
void BattleView::ai()
{
    battleContainer->getAI()->process();
}
