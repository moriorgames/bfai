#ifndef MORIOR_GAMES_VIEW_BACKGROUND_VIEW_H
#define MORIOR_GAMES_VIEW_BACKGROUND_VIEW_H

#include "ViewHelper.h"

namespace MoriorGames {

class BackgroundView: public ViewHelper
{
public:
    static const std::string BACKGROUND_NAME;

public:
    explicit BackgroundView(Layer *layer);

private:
    void addView() override;
};

}

#endif
