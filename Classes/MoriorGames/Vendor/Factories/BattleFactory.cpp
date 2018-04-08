#include "BattleFactory.h"
#include "../Parsers/BattleParser.h"

Battle *BattleFactory::execute(const std::string &json, HeroRepository *heroRepository)
{
    auto battleParser = new BattleParser(json);
    auto battle = battleParser->parse();
    for (auto battleHero:battle->getBattleHeroes()) {
        auto hero = heroRepository->findById(battleHero->getId());
        if (hero) {
            battleHero->copy(hero);
        }
    }

    return battle;
}
