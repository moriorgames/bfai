#include "BattleContainer.h"
#include "../Factories/BattleEventPublisherFactory.h"

BattleContainer::BattleContainer(Layer *layer, const std::string &json)
    : layer{layer}
{
    initServices(json);
    initViews();
}

void BattleContainer::buildPathScopeView()
{
    for (auto path:pathFinder->buildPathScope(battle->getActiveBattleHero())) {
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

PathFinder *BattleContainer::getPathFinder() const
{
    return pathFinder;
}

BattleEventPublishable *BattleContainer::getEventPublisher() const
{
    return eventPublisher;
}

void BattleContainer::initServices(const std::string &json)
{
    battle = (new BattleFactory)->execute(json, heroRepo);
    gridSystem = new GridSystem(layer);
    pathFinder = new PathFinder(gridSystem->getGrid());
    battleProcessor = addBattleProcessor();
    eventPublisher = BattleEventPublisherFactory::execute(BattleEventPublisherFactory::OFFLINE, battleProcessor);
}

void BattleContainer::initViews()
{
    addHeroViews();
    buildPathScopeView();
}

void BattleContainer::addHeroViews()
{
    for (auto battleHero:battle->getBattleHeroes()) {
        heroViews.push_back(new HeroView(layer, gridSystem, battleHero));
    }
}

BattleProcessor *BattleContainer::addBattleProcessor()
{
    auto battleProcessor = new BattleProcessor(battle);

    for (auto heroView:heroViews) {
        battleProcessor->registerObserver(heroView);
    }

    return battleProcessor;
}
