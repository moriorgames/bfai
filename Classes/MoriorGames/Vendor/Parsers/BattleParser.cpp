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
    if (document.HasMember(ROW) && document[ROW].IsArray()) {

        const Value &data = document[ROW];
        for (auto itr = data.Begin(); itr != data.End(); ++itr) {
            if ((*itr).IsObject()) {
                addHeroData(battle, *itr);
            }
        }
    }
}

void BattleParser::addHeroData(Battle *battle, const rapidjson::Value &data)
{
    auto hero = new BattleHero;
    auto coordinate = new Coordinate(getInt(data, "x"), getInt(data, "y"));

    hero->setId(getInt(data, "id"));
    hero->setSide(getString(data, "side"));
    hero->setCoordinate(coordinate);

    battle->addHero(hero);
}
