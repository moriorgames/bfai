#include "HeroParser.h"

HeroParser::HeroParser(std::string json)
    : JsonParser(json)
{
}

std::vector<Hero *> HeroParser::parse()
{
    std::vector<Hero *> items;

    if (document.HasMember(ROW) && document[ROW].IsArray()) {

        const Value &data = document[ROW];
        for (auto itr = data.Begin(); itr != data.End(); ++itr) {
            if ((*itr).IsObject()) {
                auto hero = new Hero;
                addData(hero, *itr);
                items.push_back(hero);
            }
        }
    }

    return items;
}

std::vector<BattleHero *> HeroParser::parseForBattle()
{
    std::vector<BattleHero *> items;

    if (document.HasMember(ROW) && document[ROW].IsArray()) {

        const Value &data = document[ROW];
        for (auto itr = data.Begin(); itr != data.End(); ++itr) {
            if ((*itr).IsObject()) {
                auto hero = new BattleHero;
                addData(hero, *itr);
                items.push_back(hero);
            }
        }
    }

    return items;
}

void HeroParser::addData(Hero *item, const rapidjson::Value &data)
{
    item->setId(getInt(data, "id"));
    item->setName(getString(data, "name"));
    item->setSlug(getString(data, "slug"));
    item->setDamage(getInt(data, "damage"));
    item->setRanged(getInt(data, "ranged"));
    item->setHealth(getInt(data, "health"));
    item->setMovement(getInt(data, "movement"));
    item->setCost(getInt(data, "cost"));
    item->setMoveFrames(getInt(data, "moveFrames"));
    item->setAttackFrames(getInt(data, "attackFrames"));
    item->setSize(getInt(data, "size"));
    item->setEnabled(getBool(data, "enabled"));
}
