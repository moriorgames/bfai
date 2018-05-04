#include "BattleHeroInitializer.h"
#include "../Repository/HeroRepository.h"
#include "../Repository/SkillRepository.h"

void BattleHeroInitializer::init(Battle *battle, BattleHero *battleHero)
{
    auto hero = heroRepo->findById(battleHero->getId());
    if (hero) {
        battleHero->copy(hero);
        battleHero->flip(battleHero->getCoordinate());
        addBaseSkills(battle, battleHero);
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
            if (skill->getType() == Skill::TYPE_BOOST_HEALTH) {
                battleHero->setHealth(battleHero->getHealth() + 1);
            }
            if (skill->getType() == Skill::TYPE_BOOST_DAMAGE) {
                battleHero->setDamage(battleHero->getDamage() + 1);
            }
            if (skill->getType() == Skill::TYPE_BOOST_RANGED) {
                battleHero->setRanged(battleHero->getRanged() + 1);
            }
            if (skill->getType() == Skill::TYPE_BOOST_MOVE) {
                battleHero->setMovement(battleHero->getMovement() + 1);
            }
            battleHero->addSkill(skill);
        }
    }
}
