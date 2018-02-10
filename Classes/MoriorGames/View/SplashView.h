#ifndef MORIOR_GAMES_VIEW_SPLASH_VIEW_H
#define MORIOR_GAMES_VIEW_SPLASH_VIEW_H

#include "ViewHelper.h"

namespace MoriorGames {

class SplashView: public ViewHelper
{
public:
    explicit SplashView(Layer *layer);

private:
    void addView() override;
};

}

#endif
