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
        gridContainer->getGridView()->drawTile(path.coordinate, GridView::MOVE_FILL_COLOR, GridView::MOVE_NAME);
    }
}

GridContainer *BattleContainer::getGridContainer() const
{
    return gridContainer;
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
    gridContainer = new GridContainer(layer);
    addHeroViews();
    pathFinder = new PathFinder(gridContainer->getGrid());
    battleProcessor = addBattleProcessor();
    eventPublisher = BattleEventPublisherFactory::execute(BattleEventPublisherFactory::OFFLINE, battleProcessor);
    buildPathScopeView();
}

void BattleContainer::addHeroViews()
{
    for (auto battleHero:battle->getBattleHeroes()) {
        heroViews.push_back(new HeroView(layer, gridContainer, battleHero));
    }
}

BattleProcessor *BattleContainer::addBattleProcessor()
{
    auto battleProcessor = new BattleProcessor(battle, pathFinder, gridContainer->getGrid());

    for (auto heroView:heroViews) {
        battleProcessor->registerObserver(heroView);
    }
    battleProcessor->registerObserver(gridContainer->getGridView());

    return battleProcessor;
}
