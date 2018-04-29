#include "BattleFactory.h"
#include "../Parsers/BattleParser.h"
#include "../Repository/HeroRepository.h"
#include "../Repository/SkillRepository.h"

Battle *BattleFactory::execute(const std::string &json)
{
    auto battleParser = new BattleParser(json);
    auto battle = battleParser->parse();
    for (auto battleHero:battle->getBattleHeroes()) {
        initBattleHero(battleHero);
    }

    return battle;
}

void BattleFactory::initBattleHero(BattleHero *battleHero)
{
    auto hero = heroRepo->findById(battleHero->getId());
    addBaseSkills(hero);
    if (hero) {
        battleHero->copy(hero);
        battleHero->flip(battleHero->getCoordinate());
    }
}

void BattleFactory::addBaseSkills(Hero *hero)
{
    hero->addSkill(skillRepo->findById(Skill::NEXT_TURN_ID));
    hero->addSkill(skillRepo->findById(Skill::MOVE_ID));
    hero->addSkill(skillRepo->findById(Skill::SINGLE_ATTACK_ID));

    // @TODO temporary assignation of skill this has to be managed automatically
    if (hero->getSlug() == "fractal") {
        hero->addSkill(skillRepo->findById(6));
    }
}
