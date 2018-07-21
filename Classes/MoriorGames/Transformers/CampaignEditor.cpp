#include "CampaignEditor.h"
#include "../Vendor/Entity/BattleHero.h"
#include "../Vendor/Entity/User.h"
#include "../Vendor/Services/AI.h"
#include "../Vendor/Utils/TextUtils.h"

CampaignEditor::CampaignEditor()
{
}

std::string CampaignEditor::transform(HeroesConfig *heroesConfig)
{
    std::string heroesJson = heroesRows(heroesConfig);
    std::string skillsHeroesJson = skillsHeroesRows(heroesConfig);
    std::string json = "{" + heroesJson + skillsHeroesJson + "}";

    printf("\n=== CampaignEditor \n%s\n", json.c_str());

    return json;
}

std::string CampaignEditor::heroesRows(HeroesConfig *heroesConfig)
{
    std::string json = "\"heroes\": [";

    // Nexus
    int battleHeroId = 7;
    int index = 0;
    for (auto hero:heroesConfig->getHeroes()) {
        short x = coords[index].first * -1;
        short y = coords[index].second;
        json += heroRow(AI::AI_TOKEN, BattleHero::SIDE_VISITOR, battleHeroId, hero->getId(), x, y);
        battleHeroId++;
        index++;
    }

    removeLastComma(json);
    json += "],";

    return json;
}

std::string
CampaignEditor::heroRow(std::string userToken, std::string side, int battleHeroId, int heroId, short x, short y)
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

std::string CampaignEditor::skillsHeroesRows(HeroesConfig *heroesConfig)
{
    std::string json = "\"skillsHeroes\": [";

    bool hasToRemoveLastComma = false;
    int battleHeroId = 7;
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

std::string CampaignEditor::skillHeroRow(int battleHeroId, int skillId)
{
    std::string json = "{ \"battleHeroId\":" + to_string(battleHeroId) + ", \"skillId\":" + to_string(skillId) + " },";

    return json;
}

void CampaignEditor::removeLastComma(std::string &json)
{
    json = json.substr(0, json.size() - 1);
}
