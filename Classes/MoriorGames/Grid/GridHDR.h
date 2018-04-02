#ifndef MORIOR_GAMES_GRID_GRID_HDR_H
#define MORIOR_GAMES_GRID_GRID_HDR_H

#include "../Vendor/Grid/Grid.h"

class GridHDR: public Grid
{
public:
    static const int FACTOR;

public:
    virtual int getFactor() override;
};

#endif
