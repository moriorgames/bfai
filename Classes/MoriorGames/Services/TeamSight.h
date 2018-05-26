#ifndef MORIOR_GAMES_SERVICES_TEAM_SIGHT_H
#define MORIOR_GAMES_SERVICES_TEAM_SIGHT_H

#include <string>
#include "../Vendor/Entity/Battle.h"
#include "../Vendor/Observer/BattleObservable.h"
#include "../View/Battle/GridView.h"

class TeamSight: public BattleObservable
{
public:
    const short RANGE = 6;

    TeamSight(std::string side, Battle *, GridView *);
    void update(BattleAction *) override;

private:
    std::string side;
    Battle *battle;
    GridView *gridView;
};

#endif
