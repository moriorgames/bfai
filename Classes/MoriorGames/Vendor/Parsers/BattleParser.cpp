#include "BattleParser.h"

BattleParser::BattleParser(std::string json)
    : JsonParser(json)
{
}

Battle *BattleParser::parse()
{
    auto battle = new Battle;

    addHeroesData(battle, document);

    return battle;
}

void BattleParser::addHeroesData(Battle *battle, const rapidjson::Value &data)
{
    if (document.HasMember(HEROES) && document[HEROES].IsArray()) {

        const Value &data = document[HEROES];
        for (auto itr = data.Begin(); itr != data.End(); ++itr) {
            if ((*itr).IsObject()) {
                addHeroData(battle, *itr);
            }
        }
    }
}

void BattleParser::addHeroData(Battle *battle, const rapidjson::Value &data)
{
    auto battleHero = new BattleHero;
    auto coordinate = new Coordinate(getInt(data, "x"), getInt(data, "y"));

    battleHero->setBattleHeroId(getInt(data, "battleHeroId"));
    battleHero->setId(getInt(data, "heroId"));
    battleHero->setSide(getString(data, "side"));
    battleHero->setCoordinate(coordinate);

    battle->addHero(battleHero);
}

std::vector<SkillHero> BattleParser::parseSkills()
{
    std::vector<SkillHero> skillHeroes;

    if (document.HasMember(SKILLS) && document[SKILLS].IsArray()) {

        const Value &data = document[SKILLS];
        for (auto itr = data.Begin(); itr != data.End(); ++itr) {
            if ((*itr).IsObject()) {
                SkillHero skillHero;
                skillHero.skillId = getInt(*itr, "skillId");
                skillHero.battleHeroId = getInt(*itr, "battleHeroId");
                skillHeroes.push_back(skillHero);
            }
        }
    }

    return skillHeroes;
}
