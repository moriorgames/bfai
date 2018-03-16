#include "HeroParser.h"

using MoriorGames::HeroParser;
using MoriorGames::Hero;

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
                items.push_back(
                    create(*itr)
                );
            }
        }
    }

    return items;
}

Hero *HeroParser::create(const rapidjson::Value &data)
{
    auto item = new Hero;

    item->setId(getInt(data, "id"));
    item->setName(getString(data, "name"));
    item->setSlug(getString(data, "slug"));
    item->setDamage(getInt(data, "damage"));
    item->setRanged(getInt(data, "ranged"));
    item->setHealth(getInt(data, "health"));
    item->setMovement(getInt(data, "movement"));
    item->setMoveFrames(getInt(data, "moveFrames"));
    item->setAttackFrames(getInt(data, "attackFrames"));

    return item;
}

