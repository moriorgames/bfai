#ifndef MORIOR_GAMES_CONTAINERS_BATTLE_CONTAINER_H
#define MORIOR_GAMES_CONTAINERS_BATTLE_CONTAINER_H

#include "cocos2d.h"
#include "../EventListeners/BattleEventPublishable.h"
#include "../Containers/GridContainer.h"
#include "../Vendor/Services/PathFinder.h"
#include "../Vendor/Services/BattleProcessor.h"
#include "../Vendor/Factories/BattleFactory.h"
#include "../View/Battle/HeroView.h"
USING_NS_CC;

class BattleContainer
{
public:
    BattleContainer(Layer *layer, const std::string &json);
    GridContainer *getGridContainer() const;
    Battle *getBattle() const;
    BattleEventPublishable *getEventPublisher() const;
    void buildPathScopeView();

private:
    Layer *layer;
    Battle *battle;
    GridContainer *gridContainer;
    BattleProcessor *battleProcessor;
    BattleEventPublishable *eventPublisher;
    std::vector<HeroView *> heroViews;

    void addHeroViews();
    BattleProcessor *addBattleProcessor();
};

#endif
