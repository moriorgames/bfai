#include "BattleContainer.h"
#include "../Factories/BattleEventPublisherFactory.h"
#include "../Vendor/Entity/User.h"
#include "../Vendor/Repository/SkillRepository.h"
#include "../View/Battle/BattleBackgroundView.h"
#include "../View/Battle/EndOfBattle.h"

BattleContainer::BattleContainer(Layer *layer, Socket *socket, const std::string &json)
    : layer{layer}, socket{socket}
{
    new BattleBackgroundView(layer);

//    battle = (new BattleFactory)->execute(json);
    battle = (new BattleFactory)->execute("{\"token\": \"Miu_tTgazSW6OkSFAYyBxT4DbUpgQ-hQwZlatQV8auY\",  \"online\": false, \"heroes\": [{ \"userToken\":\"\", \"side\":\"local\", \"battleHeroId\":1, \"heroId\":1, \"x\":-8, \"y\":0 },{ \"userToken\":\"\", \"side\":\"visitor\", \"battleHeroId\":2, \"heroId\":1, \"x\":8, \"y\":0 },{ \"userToken\":\"j54tfg4AeMP4O8z9FgtWJEZeFYmmrtS3LpoaKbQ47FA\", \"side\":\"local\", \"battleHeroId\":3, \"heroId\":2, \"x\":-8, \"y\":2 },{ \"userToken\":\"j54tfg4AeMP4O8z9FgtWJEZeFYmmrtS3LpoaKbQ47FB\", \"side\":\"visitor\", \"battleHeroId\":4, \"heroId\":2, \"x\":8, \"y\":2 },{ \"userToken\":\"j54tfg4AeMP4O8z9FgtWJEZeFYmmrtS3LpoaKbQ47FB\", \"side\":\"visitor\", \"battleHeroId\":5, \"heroId\":4, \"x\":7, \"y\":1 },{ \"userToken\":\"j54tfg4AeMP4O8z9FgtWJEZeFYmmrtS3LpoaKbQ47FB\", \"side\":\"visitor\", \"battleHeroId\":6, \"heroId\":5, \"x\":7, \"y\":-1 },{ \"userToken\":\"j54tfg4AeMP4O8z9FgtWJEZeFYmmrtS3LpoaKbQ47FB\", \"side\":\"visitor\", \"battleHeroId\":7, \"heroId\":3, \"x\":8, \"y\":-2 }],\"skillsHeroes\": []}");
    battle->setUserToken(playerUser->getToken());
    gridContainer = new GridContainer(layer, battle);
    battleProcessor = new BattleProcessor(battle, gridContainer->getGrid());
    short connectionType = BattleEventPublisherFactory::OFFLINE;
    if (battle->isOnline()) {
        connectionType = BattleEventPublisherFactory::ONLINE;
    }
    eventPublisher = BattleEventPublisherFactory::execute(connectionType, battleProcessor, socket);
    skillsView = new SkillsView(layer, battle, eventPublisher, gridContainer->getGridView());
    artificialIntelligence = new AI(battle, gridContainer->getGrid(), eventPublisher);

    addHeroViews();

    teamSight = new TeamSight(
        BattleHero::SIDE_LOCAL, heroViews, gridContainer->getGrid(), gridContainer->getGridView()
    );
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

BattleProcessor *BattleContainer::getBattleProcessor() const
{
    return battleProcessor;
}

AI *BattleContainer::getAI() const
{
    return artificialIntelligence;
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
    battleProcessor->registerObserver(teamSight);
    battleProcessor->registerObserver(this);
    auto battleStart = new BattleAction("", "", 0, Skill::START_BATTLE_ID);
    battleProcessor->processBattleAction(battleStart);
}

void BattleContainer::update(BattleAction *battleAction)
{
    auto skill = skillRepo->findById(battleAction->getSkillId());
    if (skill != nullptr) {
        if (skill->getId() == Skill::END_OF_BATTLE_ID) {
            if (battle->isOnline()) {
                socket->close();
            }
            new EndOfBattle(layer);
        }
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
