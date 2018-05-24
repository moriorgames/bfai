#include "BattleFactory.h"
#include "BattleHeroInitializer.h"

Battle *BattleFactory::execute(const std::string &json)
{
    auto battleHeroInitializer = new BattleHeroInitializer;
    auto battle = (new BattleParser(json))->parse();
    for (auto battleHero:battle->getBattleHeroes()) {
        battleHeroInitializer->init(battle, battleHero);
    }

    return battle;
}
