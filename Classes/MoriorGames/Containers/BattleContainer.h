#ifndef MORIOR_GAMES_CONTAINERS_BATTLE_CONTAINER_H
#define MORIOR_GAMES_CONTAINERS_BATTLE_CONTAINER_H

#include "cocos2d.h"
#include "../Containers/GridContainer.h"
#include "../EventListeners/BattleEventPublishable.h"
#include "../Http/Client.h"
#include "../Services/TeamSight.h"
#include "../Vendor/Factories/BattleFactory.h"
#include "../Vendor/Services/AI.h"
#include "../Vendor/Services/BattleProcessor.h"
#include "../Vendor/Services/PathFinder.h"
#include "../View/Battle/HeroView.h"
#include "../View/Battle/PortraitsView.h"
#include "../View/Battle/SkillsView.h"
USING_NS_CC;

class BattleContainer: public BattleObservable
{
public:
    BattleContainer(Layer *, Socket *, const std::string &json);
    Battle *getBattle() const;
    GridContainer *getGridContainer() const;
    BattleEventPublishable *getEventPublisher() const;
    BattleProcessor *getBattleProcessor() const;
    AI *getAI() const;
    void update(BattleAction *) override;

private:
    Layer *layer;
    Socket *socket;
    Battle *battle;
    GridContainer *gridContainer;
    TeamSight *teamSight;
    BattleEventPublishable *eventPublisher;
    AI *artificialIntelligence;
    BattleProcessor *battleProcessor;
    std::vector<HeroView *> heroViews;
    PortraitsView *portraitsView;
    SkillsView *skillsView;

    void addHeroViews();
    void registerObservers();
};

#endif
