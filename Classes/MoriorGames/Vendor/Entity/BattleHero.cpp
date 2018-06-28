#include "BattleHero.h"

const std::string BattleHero::SIDE_LOCAL = "local";

const std::string BattleHero::SIDE_VISITOR = "visitor";

BattleHero::BattleHero()
{
    coordinate = new Coordinate(0, 0);
}

int BattleHero::getBattleHeroId() const
{
    return battleHeroId;
}

void BattleHero::setBattleHeroId(int battleHeroId)
{
    this->battleHeroId = battleHeroId;
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

void BattleHero::move()
{
    moved = true;
}

bool BattleHero::hasMoved()
{
    return moved;
}

void BattleHero::addInjury(int injury)
{
    this->_visible = true;
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

bool BattleHero::isVisible()
{
    return _visible;
}

void BattleHero::setVisible(bool visible)
{
    this->_visible = visible;
}

void BattleHero::setCoordinate(Coordinate *coordinate)
{
    this->coordinate = coordinate;
}

Coordinate *BattleHero::getCoordinate() const
{
    return coordinate;
}

void BattleHero::startTurn()
{
    moved = false;
}

void BattleHero::copy(Hero *hero)
{
    id = hero->getId();
    name = hero->getName();
    slug = hero->getSlug();
    damage = hero->getDamage();
    ranged = hero->getRanged();
    health = hero->getHealth();
    movement = hero->getMovement();
    cost = hero->getCost();
    moveFrames = hero->getMoveFrames();
    attackFrames = hero->getAttackFrames();
    size = hero->getSize();
    enabled = hero->isEnabled();
    skills = hero->getSkills();
}

void BattleHero::flip(Coordinate *coordinate)
{
    flipped = side == BattleHero::SIDE_VISITOR;
    if (this->coordinate->x > coordinate->x) {
        flipped = true;
    } else if (this->coordinate->x < coordinate->x) {
        flipped = false;
    }
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

    Hero::print();
    for (auto skill:skills) {
        skill->print();
    }
}
