#ifndef MORIOR_GAMES_SERVICES_BATTLE_CONTAINER_H
#define MORIOR_GAMES_SERVICES_BATTLE_CONTAINER_H

#include "../View/Battle/HeroView.h"

using MoriorGames::HeroView;

class BattleContainer
{
public:
    BattleContainer();
    ~BattleContainer();
    void addHeroView(HeroView *);
    const std::vector<HeroView *> &getHeroViews() const;

private:
    std::vector<HeroView *> heroViews;
};

#endif
