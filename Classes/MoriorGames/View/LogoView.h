#ifndef MORIOR_GAMES_VIEW_LOGO_VIEW_H
#define MORIOR_GAMES_VIEW_LOGO_VIEW_H

#include "ViewHelper.h"

namespace MoriorGames {

class LogoView: public ViewHelper
{
public:
    explicit LogoView(Layer *layer);
    void addLogo();
};

}

#endif