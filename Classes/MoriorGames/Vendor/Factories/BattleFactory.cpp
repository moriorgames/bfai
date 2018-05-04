#include "BattleFactory.h"
#include "BattleHeroInitializer.h"

Battle *BattleFactory::execute(const std::string &json)
{
    auto battleParser = new BattleParser(json);
    auto battleHeroInitializer = new BattleHeroInitializer;
    auto battle = battleParser->parse();
    for (auto battleHero:battle->getBattleHeroes()) {
        battleHeroInitializer->init(battle, battleHero);
    }

    return battle;
}
