#include "BattleParser.h"

BattleParser::BattleParser(std::string json)
    : JsonParser(json)
{
}

Battle *BattleParser::parse()
{
    auto battle = new Battle;

    addBattleData(battle, document);
    addHeroesData(battle, document);
    addSkillsHeroesData(battle, document);

    return battle;
}

void BattleParser::addBattleData(Battle *battle, const rapidjson::Value &data)
{
    battle->setToken(getString(document, "token"));
    battle->setOnline(getBool(document, "online"));
    battle->setStatus(getString(document, "status"));
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

    battleHero->setUserToken(getString(data, "userToken"));
    battleHero->setBattleHeroId(getInt(data, "battleHeroId"));
    battleHero->setId(getInt(data, "heroId"));
    battleHero->setSide(getString(data, "side"));
    battleHero->setCoordinate(coordinate);

    battle->addHero(battleHero);
}

void BattleParser::addSkillsHeroesData(Battle *battle, const rapidjson::Value &data)
{
    if (document.HasMember(SKILLS) && document[SKILLS].IsArray()) {

        const Value &data = document[SKILLS];
        for (auto itr = data.Begin(); itr != data.End(); ++itr) {
            if ((*itr).IsObject()) {
                addSkillHeroData(battle, *itr);
            }
        }
    }
}

void BattleParser::addSkillHeroData(Battle *battle, const rapidjson::Value &data)
{
    auto skillHero = new SkillHero;
    skillHero->setSkillId(getInt(data, "skillId"));
    skillHero->setBattleHeroId(getInt(data, "battleHeroId"));

    battle->addSkillHero(skillHero);
}
