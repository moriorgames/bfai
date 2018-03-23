#include "BattleFactory.h"
#include "../Parsers/BattleParser.h"

using MoriorGames::BattleFactory;
using MoriorGames::Battle;

Battle *BattleFactory::execute(const std::string &json, HeroRepository *heroRepository)
{
    auto battleParser = new BattleParser(json);
    auto battle = battleParser->parse();
    for (auto battleHero:battle->getHeroes()) {
        auto hero = heroRepository->findById(battleHero->getId());
        if (hero) {
            battleHero->copy(hero);
        }
    }

    return battle;
}
