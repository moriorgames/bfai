#include "BattleContainer.h"
#include "../Factories/BattleEventPublisherFactory.h"
#include "../View/Battle/BattleBackgroundView.h"

BattleContainer::BattleContainer(Layer *layer, const std::string &json)
    : layer{layer}
{
    new BattleBackgroundView(layer);

    gridContainer = new GridContainer(layer);

    battle = (new BattleFactory)->execute(json, heroRepo, skillRepo);
    addHeroViews();
    battleProcessor = addBattleProcessor();
    eventPublisher = BattleEventPublisherFactory::execute(BattleEventPublisherFactory::OFFLINE, battleProcessor);
}

Battle *BattleContainer::getBattle() const
{
    return battle;
}

GridContainer *BattleContainer::getGridContainer() const
{
    return gridContainer;
}

BattleEventPublishable *BattleContainer::getEventPublisher() const
{
    return eventPublisher;
}

void BattleContainer::addHeroViews()
{
    for (auto battleHero:battle->getBattleHeroes()) {
        heroViews.push_back(new HeroView(layer, gridContainer->getCoordinate2Screen(), battleHero));
    }
}

BattleProcessor *BattleContainer::addBattleProcessor()
{
    auto battleProcessor = new BattleProcessor(battle, gridContainer->getPathFinder(), gridContainer->getGrid());

    for (auto heroView:heroViews) {
        battleProcessor->registerObserver(heroView);
    }
    battleProcessor->registerObserver(gridContainer->getGridView());
    battleProcessor->processBattleAction(new BattleAction);

    return battleProcessor;
}
