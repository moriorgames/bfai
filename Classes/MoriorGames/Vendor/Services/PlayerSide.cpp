#include "PlayerSide.h"

std::string PlayerSide::calculate(std::string userToken, Battle *battle)
{
    auto playerSide = BattleHero::SIDE_LOCAL;
    for (auto hero:battle->getBattleHeroes()) {
        if (hero->getUserToken() == userToken) {

            return hero->getSide();
        }
    }

    return playerSide;
}
