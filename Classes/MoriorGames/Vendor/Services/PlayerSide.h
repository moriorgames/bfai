#ifndef MORIOR_GAMES_VENDOR_SERVICES_PLAYER_SIDE_H
#define MORIOR_GAMES_VENDOR_SERVICES_PLAYER_SIDE_H

#include "../Entity/Battle.h"

class PlayerSide
{
public:
    std::string calculate(std::string userToken, Battle *);
};

#endif
