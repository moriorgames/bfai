#include "BattleContainer.h"
#include "../Factories/BattleEventPublisherFactory.h"
#include "../View/Battle/BattleBackgroundView.h"

BattleContainer::BattleContainer(Layer *layer, const std::string &json)
    : layer{layer}
{
    new BattleBackgroundView(layer);

    battle = (new BattleFactory)->execute(json, heroRepo, skillRepo);
    gridContainer = new GridContainer(layer, battle);
    battleProcessor = new BattleProcessor(battle, gridContainer->getGrid());
    eventPublisher = BattleEventPublisherFactory::execute(BattleEventPublisherFactory::OFFLINE, battleProcessor);
    skillsView = new SkillsView(layer, battle, eventPublisher, gridContainer->getGridView());

    addHeroViews();
    registerObservers();
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

void BattleContainer::registerObservers()
{
    for (auto heroView:heroViews) {
        battleProcessor->registerObserver(heroView);
    }
    battleProcessor->registerObserver(gridContainer->getGridView());
    battleProcessor->registerObserver(skillsView);
    battleProcessor->processBattleAction(new BattleAction);
}
