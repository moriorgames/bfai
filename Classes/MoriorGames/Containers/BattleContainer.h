#ifndef MORIOR_GAMES_CONTAINERS_BATTLE_CONTAINER_H
#define MORIOR_GAMES_CONTAINERS_BATTLE_CONTAINER_H

#include "cocos2d.h"
#include "../Containers/GridContainer.h"
#include "../EventListeners/BattleEventPublishable.h"
#include "../Vendor/Factories/BattleFactory.h"
#include "../Vendor/Services/BattleProcessor.h"
#include "../Vendor/Services/PathFinder.h"
#include "../View/Battle/HeroView.h"
#include "../View/Battle/SkillsView.h"
USING_NS_CC;

class BattleContainer
{
public:
    BattleContainer(Layer *layer, const std::string &json);
    Battle *getBattle() const;
    GridContainer *getGridContainer() const;
    BattleEventPublishable *getEventPublisher() const;

private:
    Layer *layer;
    Battle *battle;
    GridContainer *gridContainer;
    BattleProcessor *battleProcessor;
    BattleEventPublishable *eventPublisher;
    std::vector<HeroView *> heroViews;
    SkillsView *skillsView;

    void addHeroViews();
    void registerObservers();
};

#endif
