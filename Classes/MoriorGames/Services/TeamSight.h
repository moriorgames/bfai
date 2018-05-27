#ifndef MORIOR_GAMES_SERVICES_TEAM_SIGHT_H
#define MORIOR_GAMES_SERVICES_TEAM_SIGHT_H

#include <string>
#include "../Vendor/Grid/Grid.h"
#include "../Vendor/Observer/BattleObservable.h"
#include "../View/Battle/GridView.h"
#include "../View/Battle/HeroView.h"

class TeamSight: public BattleObservable
{
public:
    const short RANGE = 8;

    TeamSight(std::string side, std::vector<HeroView *> &, Grid *, GridView *);
    void update(BattleAction *) override;

private:
    std::string side;
    Grid *grid;
    GridView *gridView;
    std::vector<Coordinate *> hiddenCoordinates;
    std::vector<HeroView *> heroViews;
};

#endif
