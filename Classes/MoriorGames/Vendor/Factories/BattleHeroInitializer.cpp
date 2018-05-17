#include "BattleHeroInitializer.h"
#include "../Repository/HeroRepository.h"
#include "../Repository/SkillRepository.h"

void BattleHeroInitializer::init(Battle *battle, BattleHero *battleHero)
{
    auto hero = heroRepo->findById(battleHero->getId())->clone();
    if (hero) {
        battleHero->copy(hero);
        battleHero->flip(battleHero->getCoordinate());
        addBaseSkills(battle, battleHero);
    }
}

void BattleHeroInitializer::addSkillToHero(Skill *skill, Hero *hero)
{
    if (skill->getType() == Skill::TYPE_BOOST_HEALTH) {
        hero->setHealth(hero->getHealth() + 1);
    }
    if (skill->getType() == Skill::TYPE_BOOST_DAMAGE) {
        hero->setDamage(hero->getDamage() + 1);
    }
    if (skill->getType() == Skill::TYPE_BOOST_RANGED) {
        hero->setRanged(hero->getRanged() + 1);
    }
    if (skill->getType() == Skill::TYPE_BOOST_MOVE) {
        hero->setMovement(hero->getMovement() + 1);
    }
}

void BattleHeroInitializer::addBaseSkills(Battle *battle, BattleHero *battleHero)
{
    battleHero->addSkill(skillRepo->findById(Skill::NEXT_TURN_ID));
    battleHero->addSkill(skillRepo->findById(Skill::MOVE_ID));
    battleHero->addSkill(skillRepo->findById(Skill::SINGLE_ATTACK_ID));

    for (auto skillHero:battle->getSkillHeroes()) {
        if (battleHero->getBattleHeroId() == skillHero->getBattleHeroId()) {
            auto skill = skillRepo->findById(skillHero->getSkillId());
            addSkillToHero(skill, battleHero);
            battleHero->addSkill(skill);
        }
    }
}
