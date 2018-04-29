#include "BattleContainer.h"
#include "../Factories/BattleEventPublisherFactory.h"
#include "../Vendor/Repository/SkillRepository.h"
#include "../View/Battle/BattleBackgroundView.h"

BattleContainer::BattleContainer(Layer *layer, const std::string &json)
    : layer{layer}
{
    new BattleBackgroundView(layer);

    battle = (new BattleFactory)->execute(json);
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
        heroViews.push_back(new HeroView(layer, battleHero, gridContainer->getCoordinate2Screen()));
    }
}

void BattleContainer::registerObservers()
{
    for (auto heroView:heroViews) {
        battleProcessor->registerObserver(heroView);
    }
    battleProcessor->registerObserver(gridContainer->getGridView());
    battleProcessor->registerObserver(skillsView);
    battleProcessor->registerObserver(this);
    battleProcessor->processBattleAction(new BattleAction);
}

void BattleContainer::update(BattleAction *battleAction)
{
    auto skill = skillRepo->findById(battleAction->getSkillId());
    if (skill != nullptr) {
        if (skill->getType() == Skill::TYPE_SPAWN) {
            for (auto battleHero:battle->getBattleHeroes()) {
                if (!battleHero->spawned) {
                    auto heroView = new HeroView(layer, battleHero, gridContainer->getCoordinate2Screen());
                    heroViews.push_back(heroView);
                    battleProcessor->registerObserver(heroView);
                }
            }
        }
    }
}
