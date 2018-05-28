#ifndef MORIOR_GAMES_SERVICES_TEAM_SIGHT_H
#define MORIOR_GAMES_SERVICES_TEAM_SIGHT_H

#include <string>
#include "../Vendor/Entity/Battle.h"
#include "../Vendor/Grid/Grid.h"
#include "../Vendor/Observer/BattleObservable.h"
#include "../View/Battle/GridView.h"
#include "../View/Battle/HeroView.h"

class TeamSight: public BattleObservable
{
public:
    const short RANGE = 7;

    TeamSight(std::string side, Battle *, Grid *, GridView *, std::vector<HeroView *> &);
    void update(BattleAction *) override;

private:
    std::string side;
    Battle *battle;
    Grid *grid;
    GridView *gridView;
    std::vector<HeroView *> heroViews;
    std::vector<Coordinate *> hiddenCoordinates;
};

#endif
