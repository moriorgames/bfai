#ifndef MORIOR_GAMES_SERVICES_TEAM_SIGHT_H
#define MORIOR_GAMES_SERVICES_TEAM_SIGHT_H

#include <string>
#include "../Vendor/Entity/Battle.h"
#include "../Vendor/Services/PathFinder.h"
#include "../Vendor/Observer/BattleObservable.h"

class TeamSight: public BattleObservable
{
public:
    const short RANGE = 6;

    TeamSight(std::string side, Battle *);
    void update(BattleAction *) override;

private:
    std::string side;
    Battle *battle;
};

#endif
