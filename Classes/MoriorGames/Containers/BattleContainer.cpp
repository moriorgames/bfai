#include "BattleContainer.h"
#include "../View/Battle/BattleBackgroundView.h"
#include "../Factories/BattleEventPublisherFactory.h"

BattleContainer::BattleContainer(Layer *layer, const std::string &json)
    : layer{layer}
{
    init(json);
}

void BattleContainer::buildPathScopeView()
{
    for (auto path:pathFinder->buildPathScope(battle->getActiveBattleHero())) {
        gridSystem->getGridView()->drawTile(path.coordinate, GridView::MOVE_FILL_COLOR, GridView::MOVE_NAME);
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

PathFinder *BattleContainer::getPathFinder() const
{
    return pathFinder;
}

BattleEventPublishable *BattleContainer::getEventPublisher() const
{
    return eventPublisher;
}

void BattleContainer::init(const std::string &json)
{
    new BattleBackgroundView(layer);

    battle = (new BattleFactory)->execute(json, heroRepo);
    gridSystem = new GridSystem(layer);
    addHeroViews();
    pathFinder = new PathFinder(gridSystem->getGrid());
    battleProcessor = addBattleProcessor();
    eventPublisher = BattleEventPublisherFactory::execute(BattleEventPublisherFactory::OFFLINE, battleProcessor);
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
    auto battleProcessor = new BattleProcessor(battle, pathFinder, gridSystem->getGrid());

    for (auto heroView:heroViews) {
        battleProcessor->registerObserver(heroView);
    }
    battleProcessor->registerObserver(gridSystem->getGridView());

    return battleProcessor;
}
