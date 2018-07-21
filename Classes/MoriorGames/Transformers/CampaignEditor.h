#ifndef MORIOR_GAMES_TRANSFORMERS_CAMPAIGN_EDITOR_H
#define MORIOR_GAMES_TRANSFORMERS_CAMPAIGN_EDITOR_H

#include <vector>
#include <string>
#include "../Vendor/Containers/HeroesConfig.h"

class CampaignEditor
{
public:
    explicit CampaignEditor();
    std::string transform(HeroesConfig *);

private:
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
