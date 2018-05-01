#include "BattleFactory.h"
#include "../Repository/HeroRepository.h"
#include "../Repository/SkillRepository.h"

Battle *BattleFactory::execute(const std::string &json)
{
    battleParser = new BattleParser(json);
    auto battle = battleParser->parse();
    for (auto battleHero:battle->getBattleHeroes()) {
        initBattleHero(battleHero);
    }

    return battle;
}

void BattleFactory::initBattleHero(BattleHero *battleHero)
{
    auto hero = heroRepo->findById(battleHero->getId());
    if (hero) {
        battleHero->copy(hero);
        battleHero->flip(battleHero->getCoordinate());
        addBaseSkills(battleHero);
    }
}

void BattleFactory::addBaseSkills(BattleHero *battleHero)
{
    battleHero->addSkill(skillRepo->findById(Skill::NEXT_TURN_ID));
    battleHero->addSkill(skillRepo->findById(Skill::MOVE_ID));
    battleHero->addSkill(skillRepo->findById(Skill::SINGLE_ATTACK_ID));

    for (auto skillHero:battleParser->parseSkills()) {
        if (battleHero->getBattleHeroId() == skillHero.battleHeroId) {
            auto skill = skillRepo->findById(skillHero.skillId);
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
