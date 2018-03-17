#include "BattleHero.h"

using MoriorGames::BattleHero;
using MoriorGames::Coordinate;

const std::string BattleHero::SIDE_PLAYER = "side-player";

const std::string BattleHero::SIDE_ENEMY = "side-enemy";

BattleHero::BattleHero()
{
    coordinate = new Coordinate(0, 0);
}

const std::string &BattleHero::getSide() const
{
    return side;
}

void BattleHero::setSide(const std::string &side)
{
    this->side = side;
}

int BattleHero::getCurrentHealth() const
{
    return health - injury;
}

void BattleHero::addInjury(int injury)
{
    this->injury += injury;
    if (this->injury >= health) {
        this->injury = health;
        dead = true;
    }
}

bool BattleHero::isDead()
{
    return dead;
}

void BattleHero::setCoordinate(Coordinate *coordinate)
{
    this->coordinate = coordinate;
}

Coordinate *BattleHero::getCoordinate() const
{
    return coordinate;
}

void BattleHero::print()
{
    printf("========= BattleHero: \n"
               " - side %s\n"
               " - injury %i\n"
               " - dead %i\n"
               " - X %i\n"
               " - Y %i\n"
               " \n",
           side.c_str(),
           injury,
           dead,
           coordinate->x,
           coordinate->y
    );
}
