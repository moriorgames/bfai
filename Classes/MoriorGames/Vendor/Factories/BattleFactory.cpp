#include "BattleFactory.h"
#include "../Parsers/BattleParser.h"

Battle *BattleFactory::execute(const std::string &json, HeroRepository *heroRepository, SkillRepository *skillRepo)
{
    auto battleParser = new BattleParser(json);
    auto battle = battleParser->parse();
    for (auto battleHero:battle->getBattleHeroes()) {
        auto hero = heroRepository->findById(battleHero->getId());
        addBaseSkills(hero);
        if (hero) {
            battleHero->copy(hero);
        }
    }

    return battle;
}

void BattleFactory::addBaseSkills(Hero *hero)
{
    hero->addSkill(skillRepo->findById(Skill::NEXT_TURN_ID));
    hero->addSkill(skillRepo->findById(Skill::MOVE_ID));

    hero->addSkill(skillRepo->findByType(Skill::TYPE_SINGLE_ATTACK));
}
