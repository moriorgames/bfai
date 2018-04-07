#ifndef MORIOR_GAMES_VENDOR_SERVICES_PATH_FINDER_H
#define MORIOR_GAMES_VENDOR_SERVICES_PATH_FINDER_H

#include <vector>
#include "../Containers/Path.h"
#include "../Grid/Grid.h"
#include "../Entity/BattleHero.h"

class PathFinder
{
public:
    PathFinder(Grid *grid);
    const std::vector<Path> &buildPathScope(BattleHero *);
    const std::vector<Path> &getPathScope() const;

private:
    Grid *grid;
    std::vector<Path> pathScope;

    std::vector<Coordinate *> moveAxis(Coordinate *current);
};

#endif
