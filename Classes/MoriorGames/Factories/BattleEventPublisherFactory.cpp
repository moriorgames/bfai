#include "BattleEventPublisherFactory.h"
#include "../EventListeners/BattleEventOnlinePublisher.h"
#include "../EventListeners/BattleEventOfflinePublisher.h"

const short BattleEventPublisherFactory::ONLINE = 1;

const short BattleEventPublisherFactory::OFFLINE = 2;

BattleEventPublishable *BattleEventPublisherFactory::execute(short connectionType)
{
    BattleEventPublishable *battleEventPublishable;

    switch (connectionType) {
    case ONLINE:
        battleEventPublishable = new BattleEventOnlinePublisher;
        break;
    case OFFLINE:
    default:
        battleEventPublishable = new BattleEventOfflinePublisher;
    }

    return battleEventPublishable;
}
