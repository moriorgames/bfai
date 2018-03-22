#include "BattleFactory.h"
#include "../Parsers/BattleParser.h"

using MoriorGames::BattleFactory;
using MoriorGames::Battle;

Battle *BattleFactory::execute(const std::string &json, HeroRepository *heroRepository)
{
    auto battleParser = new BattleParser(json);
    auto battle = battleParser->parse();
    for (auto battleHero:battle->getHeroes()) {
        battleHero->copy(
            heroRepository->findById(battleHero->getId())
        );
    }

    return battle;
}
