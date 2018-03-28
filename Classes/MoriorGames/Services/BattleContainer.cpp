#include "BattleContainer.h"

BattleContainer::BattleContainer(Layer *layer)
    : layer{layer}
{
    gridSystem = new GridSystem(layer);
    pathFinder = new PathFinder(gridSystem->getGrid());
}

BattleContainer::~BattleContainer()
{
    delete gridSystem;
    delete pathFinder;
}

GridSystem *BattleContainer::getGridSystem() const
{
    return gridSystem;
}

PathFinder *BattleContainer::getPathFinder() const
{
    return pathFinder;
}

void BattleContainer::addHeroView(HeroView *heroView)
{
    heroViews.push_back(heroView);
}
const std::vector<HeroView *> &BattleContainer::getHeroViews() const
{
    return heroViews;
}
