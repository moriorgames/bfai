#include "BattleContainer.h"

BattleContainer::BattleContainer(Layer *layer, const std::string &json)
    : layer{layer}
{
    battle = (new BattleFactory)->execute(json, heroRepo);
    gridSystem = new GridSystem(layer);
    pathFinder = new PathFinder(gridSystem->getGrid());

    init();
}

void BattleContainer::buildPathScopeView()
{
    for (auto path:pathFinder->buildPathScope(battle->getActiveHero())) {
        gridSystem->drawTile(path.coordinate, GridSystem::MOVE_FILL_COLOR, GridSystem::MOVE_NAME);
    }
}

GridSystem *BattleContainer::getGridSystem() const
{
    return gridSystem;
}

Battle *BattleContainer::getBattle() const
{
    return battle;
}

const std::vector<HeroView *> &BattleContainer::getHeroViews() const
{
    return heroViews;
}

void BattleContainer::init()
{
    addHeroViews();
    buildPathScopeView();
}

void BattleContainer::addHeroViews()
{
    for (auto battleHero:battle->getHeroes()) {
        heroViews.push_back(new HeroView(layer, gridSystem, battleHero));
    }
}
