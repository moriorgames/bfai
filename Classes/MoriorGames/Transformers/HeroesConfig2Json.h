#ifndef MORIOR_GAMES_TRANSFORMERS_HEROES_CONFIG_2_JSON_H
#define MORIOR_GAMES_TRANSFORMERS_HEROES_CONFIG_2_JSON_H

#include <vector>
#include <string>
#include "CampaignEditor.h"
#include "../Vendor/Containers/HeroesConfig.h"

class HeroesConfig2Json
{
public:
    std::string transform(HeroesConfig *);

private:
    CampaignEditor *campaignEditor;
    std::vector<std::pair<short, short>> coords{
        {-8, 2}, {-7, 1}, {-7, -1}, {-8, -2},
    };

    std::string heroesRows(HeroesConfig *);
    std::string heroRow(std::string userToken, std::string side, int battleHeroId, int heroId, short x, short y);
    std::string skillsHeroesRows(HeroesConfig *);
    std::string skillHeroRow(int battleHeroId, int skillId);
    void removeLastComma(std::string &json);
};

#endif
