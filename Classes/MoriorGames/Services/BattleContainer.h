#ifndef MORIOR_GAMES_SERVICES_BATTLE_CONTAINER_H
#define MORIOR_GAMES_SERVICES_BATTLE_CONTAINER_H

#include "cocos2d.h"
#include "../Grid/GridSystem.h"
#include "../Vendor/Services/PathFinder.h"
#include "../Vendor/Services/BattleProcessor.h"
#include "../Vendor/Factories/BattleFactory.h"
#include "../View/Battle/HeroView.h"
USING_NS_CC;

class BattleContainer
{
public:
    BattleContainer(Layer *layer, const std::string &json);
    void buildPathScopeView();
    GridSystem *getGridSystem() const;
    Battle *getBattle() const;
    const std::vector<HeroView *> &getHeroViews() const;
    PathFinder *getPathFinder() const;

private:
    Layer *layer;
    Battle *battle;
    GridSystem *gridSystem;
    PathFinder *pathFinder;
    BattleProcessor *battleProcessor;
    std::vector<HeroView *> heroViews;

    void init();
    void addHeroViews();
    void addBattleProcessor();
};

#endif
