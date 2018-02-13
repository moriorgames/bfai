#ifndef MORIOR_GAMES_GRID_GRID_SD_H
#define MORIOR_GAMES_GRID_GRID_SD_H

#include "../Vendor/Grid/Grid.h"

namespace MoriorGames {

class GridSD: public Grid
{
public:
    static const int FACTOR;

public:
    virtual int getFactor() override;
};

}

#endif
