#ifndef MORIOR_GAMES_VENDOR_SERVICES_PATH_FINDER_H
#define MORIOR_GAMES_VENDOR_SERVICES_PATH_FINDER_H

#include <vector>
#include "../Grid/Grid.h"
#include "../Entity/BattleHero.h"

namespace MoriorGames {

struct Path
{
    int level = 0;
    Coordinate *coordinate = nullptr;
};

class PathFinder
{
public:
    PathFinder(Grid *grid);
    const std::vector<Path> &buildPathScope(BattleHero *);

private:
    Grid *grid;
    std::vector<Path> pathScope;

    std::vector<Coordinate *> moveAxis(Coordinate *current);
};

}

#endif
