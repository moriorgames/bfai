#include "HeroesConfig2Json.h"
#include "../Vendor/Utils/TextUtils.h"

std::string HeroesConfig2Json::transform(HeroesConfig *heroesConfig)
{
    std::string heroesJson = heroesRows(heroesConfig);
    std::string skillsHeroesJson = skillsHeroesRows(heroesConfig);
    std::string json =
        "{\"token\": \"Miu_tTgazSW6OkSFAYyBxT4DbUpgQ-hQwZlatQV8auY\", "
        " \"online\": false, "
        + heroesJson
        + skillsHeroesJson
        + "}";

    return json;
}

std::string HeroesConfig2Json::heroesRows(HeroesConfig *heroesConfig)
{
    std::string json = "\"heroes\": [";

    // Local Heroes
    int battleHeroId = 1;
    for (auto hero:heroesConfig->getHeroes()) {

        short x = coords[battleHeroId].first;
        short y = coords[battleHeroId].second;

        json += heroRow(
            "j54tfg4AeMP4O8z9FgtWJEZeFYmmrtS3LpoaKbQ47FA",
            "local",
            battleHeroId,
            hero->getId(),
            x,
            y
        );
        battleHeroId++;
    }

    // Enemy Heroes
    json += heroRow("j54tfg4AeMP4O8z9FgtWJEZeFYmmrtS3LpoaKbQ47FB", "visitor", battleHeroId, 4, 5, -3);
    battleHeroId++;
    json += heroRow("j54tfg4AeMP4O8z9FgtWJEZeFYmmrtS3LpoaKbQ47FB", "visitor", battleHeroId, 11, 7, -2);
    battleHeroId++;
    json += heroRow("j54tfg4AeMP4O8z9FgtWJEZeFYmmrtS3LpoaKbQ47FB", "visitor", battleHeroId, 1, 5, 0);
    battleHeroId++;
    json += heroRow("j54tfg4AeMP4O8z9FgtWJEZeFYmmrtS3LpoaKbQ47FB", "visitor", battleHeroId, 10, 5, 3);
    battleHeroId++;
    json += heroRow("j54tfg4AeMP4O8z9FgtWJEZeFYmmrtS3LpoaKbQ47FB", "visitor", battleHeroId, 11, 7, 2);

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
    int battleHeroId = 1;
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
