#include "HeroesConfig2Json.h"
#include "../Vendor/Entity/BattleHero.h"
#include "../Vendor/Entity/User.h"
#include "../Vendor/Utils/TextUtils.h"

std::string HeroesConfig2Json::transform(HeroesConfig *heroesConfig)
{
    std::string heroesJson = heroesRows(heroesConfig);
    std::string skillsHeroesJson = skillsHeroesRows(heroesConfig);
    std::string json =
        "{\"token\": \"some-uuid4-battle-token\", "
        " \"online\": false, "
        + heroesJson
        + skillsHeroesJson
        + "}";

    printf("\n%s\n", json.c_str());

    return json;
}

std::string HeroesConfig2Json::heroesRows(HeroesConfig *heroesConfig)
{
    std::string json = "\"heroes\": [";

    // Nexus
    int battleHeroId = 1;
    json += heroRow("", "local", battleHeroId, 1, -8, 0);
    battleHeroId++;
    json += heroRow("", "visitor", battleHeroId, 1, 8, 0);
    battleHeroId++;

    // Local Heroes
    int index = 0;
    for (auto hero:heroesConfig->getHeroes()) {
        short x = coords[index].first;
        short y = coords[index].second;
        json += heroRow(playerUser->getToken(), BattleHero::SIDE_LOCAL, battleHeroId, hero->getId(), x, y);
        battleHeroId++;
        index++;
    }

    // @TODO this has to be managed by a kind of Campaign creator
    // Enemy Heroes
    index = 0;
    json += heroRow("j54tfg4AeMP4O8z9FgtWJEZeFYmmrtS3LpoaKbQ47FB", BattleHero::SIDE_VISITOR, battleHeroId, rand() % 8 + 2, abs(coords[index].first), coords[index].second);
    battleHeroId++; index++;
    json += heroRow("j54tfg4AeMP4O8z9FgtWJEZeFYmmrtS3LpoaKbQ47FB", BattleHero::SIDE_VISITOR, battleHeroId, rand() % 8 + 2, abs(coords[index].first), coords[index].second);
    battleHeroId++; index++;
    json += heroRow("j54tfg4AeMP4O8z9FgtWJEZeFYmmrtS3LpoaKbQ47FB", BattleHero::SIDE_VISITOR, battleHeroId, rand() % 8 + 2, abs(coords[index].first), coords[index].second);
    battleHeroId++; index++;
    json += heroRow("j54tfg4AeMP4O8z9FgtWJEZeFYmmrtS3LpoaKbQ47FB", BattleHero::SIDE_VISITOR, battleHeroId, rand() % 8 + 2, abs(coords[index].first), coords[index].second);

    removeLastComma(json);
    json += "],";

    return json;
}

std::string
HeroesConfig2Json::heroRow(std::string userToken, std::string side, int battleHeroId, int heroId, short x, short y)
{
    std::string json =
        "{ \"userToken\":\"" + userToken + "\", "
        "\"side\":\"" + side + "\", "
        "\"battleHeroId\":" + to_string(battleHeroId) + ", "
        "\"heroId\":" + to_string(heroId) + ", "
        "\"x\":" + to_string(x) + ", "
        "\"y\":" + to_string(y) + " },";

    return json;
}

std::string HeroesConfig2Json::skillsHeroesRows(HeroesConfig *heroesConfig)
{
    std::string json = "\"skillsHeroes\": [";

    bool hasToRemoveLastComma = false;
    int battleHeroId = 3;
    for (auto hero:heroesConfig->getHeroes()) {
        for (auto skill:hero->getSkills()) {
            json += skillHeroRow(battleHeroId, skill->getId());
            hasToRemoveLastComma = true;
        }
        battleHeroId++;
    }

    if (hasToRemoveLastComma) {
        removeLastComma(json);
    }
    json += "]";

    return json;
}

std::string HeroesConfig2Json::skillHeroRow(int battleHeroId, int skillId)
{
    std::string json =
        "{ \"battleHeroId\":" + to_string(battleHeroId) + ", "
        "\"skillId\":" + to_string(skillId) + " },";

    return json;
}

void HeroesConfig2Json::removeLastComma(std::string &json)
{
    json = json.substr(0, json.size() - 1);
}
