#ifndef MORIOR_GAMES_VENDOR_CONTAINERS_PATH_H
#define MORIOR_GAMES_VENDOR_CONTAINERS_PATH_H

#include "../ValueObjects/Coordinate.h"

struct Path
{
    int level = 0;
    Coordinate *coordinate = nullptr;
};

#endif
