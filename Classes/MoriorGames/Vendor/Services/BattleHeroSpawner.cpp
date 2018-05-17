#include "BattleHeroSpawner.h"

BattleHeroSpawner::BattleHeroSpawner(Battle *battle, Grid *grid)
    : battle{battle}, grid{grid}
{
    battleHeroInitializer = new BattleHeroInitializer;
}

void BattleHeroSpawner::spawn(Skill *skill, BattleHero *battleHero, BattleAction *battleAction)
{
    auto spawnHero = new BattleHero;
    spawnHero->setId(skill->getExtra());
    spawnHero->setSide(battleHero->getSide());
    spawnHero->setBattleHeroId(battle->getBattleHeroes().size() + 1);
    auto coordinate = grid->findByXY(battleAction->getCoordinate()->x, battleAction->getCoordinate()->y);
    coordinate->occupied = true;
    spawnHero->setCoordinate(coordinate);
    battleHeroInitializer->init(battle, spawnHero);

    battle->addHero(spawnHero);
}
