#ifndef MORIOR_GAMES_VENDOR_FACTORIES_PATH_BUILDER_H
#define MORIOR_GAMES_VENDOR_FACTORIES_PATH_BUILDER_H

#include <vector>
#include "../Containers/Path.h"
#include "../Services/PathFinder.h"
#include "../Entity/Skill.h"
#include "../Entity/BattleHero.h"

class PathBuilder
{
public:
    explicit PathBuilder(PathFinder *);
    const std::vector<Path> &build(Skill *, BattleHero *);

private:
    PathFinder *pathFinder;
};

#endif
