#ifndef MORIOR_GAMES_GRID_GRID_HD_H
#define MORIOR_GAMES_GRID_GRID_HD_H

#include "../Vendor/Grid/Grid.h"

namespace MoriorGames {

class GridHD: public Grid
{
public:
    static const int FACTOR;

public:
    virtual int getFactor() override;
};

}

#endif
