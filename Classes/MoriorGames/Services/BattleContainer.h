#ifndef MORIOR_GAMES_SERVICES_BATTLE_CONTAINER_H
#define MORIOR_GAMES_SERVICES_BATTLE_CONTAINER_H

#include "cocos2d.h"
#include "../Grid/GridSystem.h"
#include "../Vendor/Services/PathFinder.h"
#include "../View/Battle/HeroView.h"
USING_NS_CC;

using MoriorGames::GridSystem;
using MoriorGames::PathFinder;
using MoriorGames::HeroView;

class BattleContainer
{
public:
    BattleContainer(Layer *layer);
    ~BattleContainer();
    GridSystem *getGridSystem() const;
    PathFinder *getPathFinder() const;
    void addHeroView(HeroView *);
    const std::vector<HeroView *> &getHeroViews() const;

private:
    Layer *layer;
    GridSystem *gridSystem;
    PathFinder *pathFinder;
    std::vector<HeroView *> heroViews;
};

#endif
